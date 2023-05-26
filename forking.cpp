/*
	Author: Kevin Ton,
	Project: MSH Piping and Forking
	Filename: forking.cpp
*/

#include "forking.h"
#include "piping.h"

//Forks and uses pipeline.h to link commands
void forkingpid() {
//While loop to contain whole process
	bool forkingrun = true;
	while (forkingrun) {
//Variable Initalization
		char buf[1024];
		int flag;
		char *args[64];
		char *p;
		pid_t pid;
		int count = 0;
//Taking in an input
		printf("cssc0846%% ");
		string inputTest;
		cin.getline(buf, sizeof(buf));
		string command (buf);
//exit or EXIT command string read to exit gracefully
		if(command.find("exit") != string::npos || command.find("EXIT") != string::npos)
			exit(0);
// | to add more commands
		else if (command.find("|") != string::npos)
    			{
      				pipelink(buf);
    			}
//Taking in an input's variable
		else {
			p = strtok(buf, " ");
			while (p != NULL) {
				if ( count == 0 ) {
					inputTest = p;
					args[count] = p;
					count++;
				}
				else {
					args[count] = p;
					count++;
				}
				p = strtok(NULL, " ");
			}
//Variable reset
			args[count] = (char *) NULL;
			if ( pid  == 0 )
				execvp(inputTest.c_str(), args);
	}
}
}
