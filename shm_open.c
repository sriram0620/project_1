// shm_open.c
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "mmu.h"
#include "proc.h"
#include "x86.h"

// Create or open a shared memory segment
void* shm_open(int size) {
    void *shmem = sbrk(size);
    if (shmem == (void*)-1) {
        return 0; // Allocation failed
    }
    return shmem;
}
