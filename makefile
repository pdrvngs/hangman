
.PHONY: build run

EXE_FILE := hangman.out

build:
	@gcc -w -o ${EXE_FILE} hangman.c

run:
	@./${EXE_FILE}
