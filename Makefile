.PHONY: all build build_asm clean copy

all: build

build: clean build_asm
	@echo Building..
	gcc -Wall -ansi -pedantic source/*.c main.c -o bin/main

build_asm:
	@echo Building assembly code
	gcc -S -fverbose-asm -Wall -ansi -pedantic source/*.c main.c
	mv *.s bin/

clean:
	@echo Cleaning bin/ directory... && \
	cd bin/ && rm -vf *

copy:
	@echo Copying... && \
	cp source/*.txt bin/
