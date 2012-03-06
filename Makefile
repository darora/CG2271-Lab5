all:
	gcc lab1.c -o lab1 -pthread
	gcc lab.c -o lab -pthread
clean:
	rm -f lab1
	rm -f lab
