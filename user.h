#ifndef USER_H
#define USER_H

#include "types.h"
#include "stat.h"

// System calls for user space
int fork(void);
int u_exit(void) __attribute__((noreturn));  // Renamed to avoid conflict
int wait(void);
int pipe(int*);
int write(int, const void*, int);
int read(int, void*, int);
int close(int);
int kill(int);
int exec(char*, char**);
int open(const char*, int);
int mknod(const char*, short, short);
int unlink(const char*);
int fstat(int fd, struct stat*);
int link(const char*, const char*);
int mkdir(const char*);
int chdir(const char*);
int dup(int);
int getpid(void);
char* sbrk(int);
int u_sleep(int);                         // Renamed to avoid conflict
int uptime(void);

// Custom system calls for project
int spawn(char *name, int priority);
void* shm_open(int size);
char *shm_attach(int shmid);
int thread_create(void (*fn)(void *), void *arg);
int thread_join(int tid);
void mutex_lock(void);                    // User-level lock and unlock
void mutex_unlock(void);
int signal(int pid, int signum);

// User-space utilities
int stat(const char*, struct stat*);
char* strcpy(char*, const char*);
void *u_memmove(void*, const void*, int); // Renamed to avoid conflict
char* strchr(const char*, char c);
int strcmp(const char*, const char*);
void printf(int, const char*, ...);
char* gets(char*, int max);
uint u_strlen(const char*);               // Renamed to avoid conflict
void* memset(void*, int, uint);
void* malloc(uint);
void free(void*);
int atoi(const char*);

// System call function for internal use in ulib.c
int u_syscall(int num, ...);              // Renamed to avoid conflict

#endif // USER_H
