// mutex_lock.c
#include "types.h"
#include "user.h"
#include "x86.h"
#include "spinlock.h"

// Implementing a global spinlock (if needed)
static struct spinlock lock;

void mutex_lock(void) {
    acquire(&lock);
}

void mutex_unlock(void) {
    release(&lock);
}
