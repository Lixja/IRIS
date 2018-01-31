CC=gcc
STD=-std=c99

iris:
	$(CC) iris.c -o iris $(STD)
graph:
	doxygen Doxyfile
clean:
	rm -r iris
debug:
	$(CC) -g iris.c -o iris $(STD)
rebuild: clean iris
