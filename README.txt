**************************************************************************************************************************
	Author: Kevin Ton,
	Project: MSH Piping and Forking
	Filename: README.txt
**************************************************************************************************************************
LIST OF FILES:

Code Repository:
main.cpp
forking.cpp
piping.cpp
forking.h
piping.h

File Repository:
Makefile
README.txt
msha

**************************************************************************************************************************
COMPILE INSTRUCTIONS:
In directory, type "make"
**************************************************************************************************************************
OPERATION INSTRUCTIONS:
	~/MSH_Kevin_Ton make
	~/MSH_Kevin_Ton msha

	ls -la


List/description of novel/significant design decisions:

	- Formatting and outputting to terminal and output file
	- Read which PID is currently active
	- Have each thread wait for the thread next to it(even/odd) to ensure each thread has enough runtime
**************************************************************************************************************************
List/description of any extra features/algorithms/functionality you included which were not 
required:
N/A
**************************************************************************************************************************
LIST/DESCRIPTION OF ALL KNOWN DEFICIENCIES OR BUGS

Sometimes make does not work on the first try, making an undefined reference to main

**************************************************************************************************************************
LESSONS LEARNED: 
Working with forking and pipe()
Learn how to create a MSH environment
Learn how processes are read from the pipe.
**************************************************************************************************************************
