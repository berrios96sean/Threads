
/**
 * @file thread_test.c
 * @author Sean Berrios
 * @brief Proj 1 CSE 330
 * @version 0.1
 * @date 2022-07-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */


#include <unistd.h>
#include "threads.h"
int global = 0;
int threads, limit;

void fN(void)
{
        int local = 0; 
        for (int i = 1; i <= limit; i++)
        {   
            int t = 1; 
            
            for (int j = 1; j <= threads; j ++)
            {
               printf("\n");
               global = global + t; 
               printf(" This is %d th execution of thread %d with global var value %d \n",
               i, t,global);
               t++;
            }
        }
}



int main()
{
    scanf("%d,%d", &threads, &limit);

    RunQ = (struct Queue *)malloc(sizeof(struct Queue));
    initQueue(RunQ);
        if (threads == 0)
    {
        printf("No Threads\n");
        return 0;
    }
    else
    {
        start_thread(fN);
    }

    run();
    return 0;
}
