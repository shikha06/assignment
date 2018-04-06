#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MIN_PID 500
#define MAX_PID 3000
#define cb CHAR_BIT

int sz = MAX_PID - MIN_PID + 1;

unsigned char *b;

int allocate_map();
int allocate_pid();
void release_pid(int pid);
