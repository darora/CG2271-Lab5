all:
	make clean
	gcc lab1.c -o lab1 -pthread
	gcc lab.c -o lab -pthread
	make mutex
clean:
	rm -f lab1
	rm -f lab
	rm -f mutexExample
mutex:
	gcc lab5b.c -o mutexExample -pthread
