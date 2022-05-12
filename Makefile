.PHONY: all build build_asm clean copy

all: build

build: clean
	@echo Building..
	gcc -Wall -ansi -pedantic -o bin/main main.c lib/*.c src/*.c

build_asm:
	@echo Building assembly code
	gcc -S -fverbose-asm -Wall -ansi -pedantic src/*.c main.c
	mv *.s bin/

clean:
	@echo Cleaning bin/ directory... && \
	cd bin/ && rm -vf *

copy:
	@echo Copying... && \
	cp src/*.txt bin/
