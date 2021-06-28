# -*- MakeFile -*-

CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g
INC = -lm
EXEC = prog

SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=obj/%.o)

PRINT = echo
CREATE_FOLDER = mkdir -p
DELETE_FOLDER = rm -rf

lib: $(OBJ)
	ar rcs bin/libents.a $^

sandbox: sandbox/main.c src/ents.h lib
	$(CC) $< -L/home/radam/repos/ents/bin -lents -o bin/$@ $(CFLAGS)
	./bin/$@

obj/%.o: src/%.c folders
	$(CC) -c $< -o $@ $(CFLAGS)

val: sandbox
	valgrind --leak-check=full --track-origins=yes ./bin/sandbox

.PHONY: clean folders help

help:
	@$(PRINT) "make sandbox : building the lib and execute and sandbox program for experimenting."
	@$(PRINT) "make lib     : creating a lib .a from sources."
	@$(PRINT) "make clean   : deleting all non-source files."
	@$(PRINT) "make folders : creating the necessary folders."
	@$(PRINT) "make help    : get help for the commands."

folders:
	$(CREATE_FOLDER) bin
	$(CREATE_FOLDER) obj

clean:
	$(DELETE_FOLDER) bin
	$(DELETE_FOLDER) obj

# $(EXEC): $(OBJ)
# 	$(CC) $^ -o bin/$@ $(CFLAGS)

# lib: $(OBJ)
# 	$(CC) $(CFLAGS) -fPIC -shared -o bin/libents.so $(OBJ) -lc
