/*  sexyPSF - PSF1 player
 *  Copyright (C) 2002-2004 xodnizel
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ao/ao.h>
#include "driver.h"

ao_device *device;
ao_sample_format format;
int default_driver;

// pass-through to ao
void sexyd_update(unsigned char *Buffer, long count)
{
  ao_play(device, Buffer, count);
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "No input file specified.\n");
    return 1;
  }

  ao_initialize();
  default_driver = ao_default_driver_id();
  memset(&format, 0, sizeof(format));
  format.bits = 16;
  format.channels = 2;
  format.rate = 44100;
  format.byte_format = AO_FMT_LITTLE;

  device = ao_open_live(default_driver, &format, NULL /* no options */);
  if (device == NULL) {
    fprintf(stderr, "Error opening device.\n");
    return 1;
  }

  PSFINFO *info = sexy_load(argv[1]);
  if (!info) {
    fprintf(stderr, "Load unsuccessful\n");
    return 1;
  }

  sexy_execute();

  ao_close(device);
  ao_shutdown();
  return 0;
}
