#
# PCSX Makefile for Linux
#

all: sexypsf sexycat sexyao

RM = rm -f
STRIP = strip

FLAGS = -D__LINUX__ -DPSS_STYLE=1 
#-DTIMEO
LIBS = -lz

OBJS = ../PsxBios.o ../PsxCounters.o ../PsxDma.o \
       ../Spu.o ../PsxHw.o ../PsxMem.o ../Misc.o \
       ../R3000A.o ../PsxInterpreter.o \
       ../PsxHLE.o ../spu/spu.o

CFLAGS += -Wall -Winline -I. -I.. ${FLAGS}
#CFLAGS+= $(shell pkg-config gtk+-2.0 --cflags)

sexypsf:	${OBJS} LnxMain.o oss.o
		${CC} ${LDFLAGS} $^ -o sexypsf ${LIBS}

sexycat:	${OBJS} sexycat.o
		${CC} ${LDFLAGS} $^ -o sexycat ${LIBS}

sexyao:		${OBJS} sexyao.o
		gcc $^ ${LDFLAGS} -lao -o sexyao ${LIBS}

.PHONY: clean sexypsf sexycat sexyao

clean:
	${RM} *.o ../*.o ../spu/*.o sexypsf sexycat sexyao

../%.o: ../%.c
	${CC} ${CFLAGS} -c -o $@ $<

%.o: %.c
	${CC} ${CFLAGS} -c -o $@ $<
