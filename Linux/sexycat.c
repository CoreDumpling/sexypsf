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
#include "driver.h"

// trivial pass-through for debugging purposes
void sexyd_update(unsigned char *Buffer, long count)
{
  fwrite(Buffer, 1, count, stdout);
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "No input file specified.\n");
    return 1;
  }
  PSFINFO *info = sexy_load(argv[1]);
  if (!info) {
    fprintf(stderr, "Load unsuccessful\n");
    return 1;
  }

  sexy_execute();
  return 0;
}
