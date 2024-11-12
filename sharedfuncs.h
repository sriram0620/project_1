// sharedfuncs.h
#ifndef SHAREDFUNCS_H
#define SHAREDFUNCS_H

int spawn(char *name, int priority);
void* shm_open(int size);
char *shm_attach(int shmid);
int thread_create(void (*fn)(void *), void *arg);
int thread_join(int tid);
void mutex_lock(void);
void mutex_unlock(void);
int signal(int pid, int signum);

#endif
