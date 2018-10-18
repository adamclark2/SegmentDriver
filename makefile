
all:
	gcc src/test.c -o test.o

run: all
	./test.o

clean:
	rm ./test.o