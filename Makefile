# -*- MakeFile -*-

CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g -I./include/  # -DNDEBUG
INC = 
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

debug: sandbox/main.c lib
	$(CC) $< -lents -ldats -o bin/$@ $(CFLAGS)
	./bin/$@

obj/%.o: src/%.c folders
	$(CC) -c $< -o $@ $(CFLAGS)

val: debug
	valgrind --leak-check=full --track-origins=yes ./bin/debug
 
test: lib 
	cmake -S test/ -B test/build
	cmake --build test/build
	ctest --test-dir test/build/ --output-on-failure

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
	@$(PRINT) "make debug : building the lib and execute and debug program for experimenting."
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
	$(DELETE_FOLDER) test/build
