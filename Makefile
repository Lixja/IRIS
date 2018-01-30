CC=gcc
STD=-std=c99

iris:
	$(CC) iris.c -o iris $(STD)
clean:
	rm -r iris
debug:
	$(CC) -g iris.c -o iris $(STD)
rebuild: clean iris
