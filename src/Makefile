CC=gcc
CFLAGS=
OPTFLAGS=-O3
DBFLAGS=-DDEBUG

EXEC=kylang

all: 
	${CC} ${CFLAGS} ${OPTFLAGS} *.c -o ${EXEC}

debug:
	${CC} ${CFLAGS} ${DBFLAGS} *.c -o ${EXEC}

clean:
	rm -rf *.o kylang
