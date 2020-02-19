
.PHONY: build run

EXE_FILE := hangman.out

build:
	@gcc  -o ${EXE_FILE} hangman.c

run: build
	@./${EXE_FILE}
