/**
 * @file threads.h
 * @author Sean Berrios
 * @brief Proj 1 CSE 330
 * @version 0.1
 * @date 2022-07-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef THREADS_H
#define THREADS_H
#include "q.h"
struct Queue *RunQ;
void start_thread(void (*function)(void))
{
    void *stack = (void *)malloc(8192);
    TCB_t *tcb = newItem();
    init_TCB(tcb, function, stack, 8192);
    addQueue(RunQ, tcb);
}
void run()
{
    // real code
    ucontext_t parent;                            // get a place to store the mainontext, for faking
    getcontext(&parent);                          // magic sauce
    swapcontext(&parent, &(RunQ->head->context)); // start thefirst thread
}

void yield()
{
    ucontext_t from, to; // rotate the run Q;
    getcontext(&from);
    RunQ->head->context = from;
    rotateQueue(RunQ);
    to = RunQ->head->context; // swap the context, from previousthread to the thread pointed to by RunQ
    swapcontext(&from, &to);
}
#endif
