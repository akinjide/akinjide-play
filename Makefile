.PHONY: all build

all: build clean

build: clean
	@echo Building..
	gcc -Wall -ansi -pedantic source/*.c main.c -o bin/main

clean:
	@echo Cleaning bin/ directory... && \
	cd bin/ && rm -vf *

copy:
	@echo Copying... && \
	cp source/*.txt bin/
