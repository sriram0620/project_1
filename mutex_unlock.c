// mutex_unlock.c
#include "types.h"
#include "user.h"
#include "x86.h"
#include "spinlock.h"

extern struct spinlock lock;

// Unlock a previously locked mutex
void mutex_unlock(void) {
    release(&lock);  // Use the global lock
}