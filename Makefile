# Author(s): Kevin Ton
# Edoras_username: cssc0846
# REDID(s): 817314271
# Class: CS480, Summer 2022
# Project #1: POSIX Threads
# Filename: Makefile

msha: main.cpp forking.cpp piping.cpp forking.h piping.h
	g++ -pthread $(CFLAGS) $? $(LDFLAGS) -o $@ -lpthread

clean:
	rm -f *.o core msha $(EXEC)

