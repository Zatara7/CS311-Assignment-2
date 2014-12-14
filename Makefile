#
# Assignment 2 Makefile
# Created : Fri Sep 20
# Creator : Hayder Sharhan

# Variables -> assign variables to different commands and file names
CC=gcc
LINK=gcc
CFLAGS=-c -Wall -I.
OBJECT_FILES=a2support.o cmpsc311-f13-assign2.o

# Suffix rules -> Define the file types needed
.SUFFIXES: .c .o

# $@ -> current rule target. $< -> first prerequiset
.c.o.:
	$(CC) -c $(CFLAGS)	-o $@ $<

# Productions -> Define how an item is built
anml : $(OBJECT_FILES)
	$(LINK) $(OBJECT_FILES) -o $@

# Dependancies -> What each object file depend on.
a2support.o : a2support.c a2support.h
cmpsc311-f13-assign2.o : cmpsc311-f13-assign2.c a2support.h
