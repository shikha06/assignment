#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MIN_PID 100
#define MAX_PID 1000
#define cb CHAR_BIT

int sz = MAX_PID - MIN_PID + 1;

unsigned char *b;

int allocate_mp();
int allocate_pid();
void release_pid(int pid);
