# -*- MakeFile -*-

CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g -I./include/ -L./bin/ # -DNDEBUG
INC = -lents -ldats
EXEC = prog
PREFIX = /usr/local

SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=obj/%.o)

LIB = libents.a
PRINT = echo
CREATE_FOLDER = mkdir -p
DELETE_FOLDER = rm -rf

lib: $(OBJ)
	ar rcs bin/$(LIB) $^

prog: sandbox/main.c include/ents.h lib
	$(CC) $< $(INC) -o bin/$(EXEC) $(CFLAGS)

run: prog
	./bin/$(EXEC)

val: prog
	valgrind --leak-check=full --track-origins=yes ./bin/$(EXEC)
 
test: lib 
	cmake -S test/ -B test/build
	cmake --build test/build
	ctest --test-dir test/build/ --output-on-failure

obj/%.o: src/%.c folders
	$(CC) -c $< -o $@ $(CFLAGS)

.PHONY: clean folders help uninstall

install: lib
	$(CREATE_FOLDER) $(DESTDIR)$(PREFIX)/lib
	$(CREATE_FOLDER) $(DESTDIR)$(PREFIX)/include/ents/
	cp bin/$(LIB) $(DESTDIR)$(PREFIX)/lib/
	cp include/*.h $(DESTDIR)$(PREFIX)/include/ents/

uninstall:
	rm -f $(DESTDIR)$(PREFIX)/lib/$(LIB)
	rm -rf $(DESTDIR)$(PREFIX)/include/ents/

help:
	@$(PRINT) "make help    : get help for the commands."

folders:
	$(CREATE_FOLDER) bin
	$(CREATE_FOLDER) obj

clean:
	$(DELETE_FOLDER) bin
	$(DELETE_FOLDER) obj
	$(DELETE_FOLDER) test/build
