
CFLAGS=-g

all:	generate

macros.o:	macros.c macros.h
	gcc ${CFLAGS} -c macros.c

print.o:	print.c print.h
	gcc ${CFLAGS} -c print.c

generate:	generate.c print.o macros.o
	gcc ${CFLAGS} -o generate macros.o print.o generate.c -lm

clean:
	rm -f generate *.o

