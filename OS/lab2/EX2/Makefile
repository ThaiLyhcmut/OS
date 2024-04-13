sum_serial: sum_serial.c
	gcc -o sum_serial sum_serial.c

sum_multi-thread: sum_multi-thread.c
	gcc -o sum_multi-thread sum_multi-thread.c -pthread

all: sum_serial sum_multi-thread

clean:
	rm -f sum_serial sum_multi-thread

