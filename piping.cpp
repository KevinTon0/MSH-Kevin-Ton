/*
	Author: Kevin Ton,
	Project: MSH Piping and Forking
	Filename: piping.cpp
*/

#include "piping.h"

using namespace std;

//This function will take in at least 1 argument and connect them through a pipe
void pipelink(char* buf) {

//Variable initalization
	int i = 0; 
	int check1, check2;
	string input1, input2;
	char *com1, *com2;
	char *args1[64], *args2[64];
	int pipearguments[2], pid, childPID;

	com1 = strtok(buf, "|");
	com2 = strtok(NULL, "|");
//Wait for input
	while (com1 != NULL) {
		if ( i == 0 ){
			input1 = com1;
			args1[i] = com1;
		}
		else
			args1[i] = com1;
	com1 = strtok(NULL, " ");
	i++;
	}
//Reset variables
	args1[i] = (char *) NULL;
	i = 0;

//Test further Arguments
	while( com2 != NULL) {
		if ( i == 0 ) {
			input2 = com2;
			args2[i] = com2;
		}
		else
			args2[i] = com2;
	com2 = strtok(NULL, " ");
	i++;
	}
//Resetting Variables and linking using pipe() function.
	args2[i] = (char *) NULL;	
	pipe(pipearguments);
//Test errors using fork taken from 
//syscall-Fork slide
	if ((pid = fork()) < 0)
		fprintf(stderr, "Error using fork");
	else if (pid == 0) {
//Function to duplicate two processes
		dup2(pipearguments[1], 1);
		close(pipearguments[0]);
//Execlp is now used to find file path of inputs given like ls -la
		execlp(input1.c_str(), input1.c_str(), args1[1], (char *) NULL);
		printf("Pid id: %s", buf);
		exit(0);
	}
// Forking to parent
	else if (childPID == 0) {
		dup2(pipearguments[0], 0);
		close(pipearguments[1]);
		execlp(input2.c_str(), input2.c_str(), args2[1], (char *) NULL);
		exit(0);
	}
// Closing Pipeline
	close(pipearguments[1]);
}
