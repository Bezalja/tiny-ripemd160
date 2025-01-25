CFLAGS = -Os

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

tests: tests.o ripemd160.o

check: tests
	./tests

check-size:
	readelf -s ripemd160.o | grep GLOBAL | awk '{SUM+=$$3}END{print SUM}'

.PHONY: clean

clean:
	rm -f *.o *~ core tests