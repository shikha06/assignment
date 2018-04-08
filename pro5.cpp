//obtaining and releasing pid
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

int main() 
{
    int mp = allocate_mp();
    if (mp == 1) {
        printf("\n Initialized Data Structure.\n");
        int id = 0, i = 0;
        while (i < 15)
		{
            int val = allocate_pid();
            printf("\nProcess %d: pid = %d", i+1, val);
            i++;
        }
        release_pid(103); 
		printf("\nProcess 103 released.");
        release_pid(105); 
		printf("\nProcess 105 released.");
        int val = allocate_pid(); 
		printf("\nProcess %d : pid = %d\n", i+1, val);
    }
    else 
	printf("\nFailed to initialize data structure.\n");
}

int allocate_mp()                         /*for representation of pids ,a data structure is created and initialized, return 1 for successful and -1 for unsuccessful */
 {           
    b = (unsigned char*)malloc((sz+cb-1)/cb * sizeof(char));
    if (b) return 1;
    return -1;
}

int allocate_pid() 
{
    int i = 0;                                 /* pid is allocated and returned here; it return -1 allocation of pid is not possible (pids is in use) */
    int pid = b[i/cb] & (1 << (i & (cb-1)));
    while (pid != 0)
	    {
           i++;
           pid = b[i/cb] & (1 << (i & (cb-1)));
        }

    if (i+MIN_PID > MAX_PID)
	return -1;
    b[i/cb] |= 1 << (i & (cb-1));
    return i+MIN_PID;
}


void release_pid(int pid)      /* pid released here */
 {
    if (pid < 100)
    {
        printf("\nInvalid PID: It should lie between 100 and 1000.");
        return;
    }
    int i = pid - MIN_PID;
    b[i/cb] &= ~(1 << (i & (cb-1)));
}
