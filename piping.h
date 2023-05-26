/*
	Author: Kevin Ton,
	Project: MSH Piping and Forking
	Filename: piping.h
*/

#ifndef PIPING_H
#define PIPING_H

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <sys/wait.h>

using namespace std;

void pipelink(char*);

#endif
