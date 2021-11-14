CC=gcc -g -Wall
CFILES=$(wildcard src/*/*.c)
HFILES=$(CFILES:.c=*/*.h)
OBJFILES=$(CFILES:.c=.o)
OBJPATH=src/objects/
EXEFILE=bin/main

all:$(OBJFILES)
	$(CC) $(OBJFILES) -o $(EXEFILE)

%.o: %.c $(HFILES)%.h
	$(CC) -c $(CFILES) $< -o $@

executables:

vim:
	vim src/*.c src/include/*.h

run:
	$(EXEFILE)

debug:
	gdb -q $(EXEFILE)

memcheck:
	valgrind $(EXEFILE) --leak-check=full

git-update:
	git add Makefile README.md src/ config/quotes/quotes_test.txt config/ascii_art/picture_test.txt
	git commit -m "update commit"
	git push origin main

install: all
	mv bin/main /usr/bin/terminal_startup_rice

clean:
	rm $(OBJFILES)
