#include "types.h"
#include "defs.h"
#include "param.h"
#include "mmu.h"
#include "x86.h"
#include "proc.h"

struct spinlock mutex[MAX_MUTEXES];

int sys_mutex_lock(void) {
    int lock_id;
    if (argint(0, &lock_id) < 0 || lock_id < 0 || lock_id >= MAX_MUTEXES)
        return -1;

    acquire(&mutex[lock_id]);
    return 0;
}

int sys_mutex_unlock(void) {
    int lock_id;
    if (argint(0, &lock_id) < 0 || lock_id < 0 || lock_id >= MAX_MUTEXES)
        return -1;

    release(&mutex[lock_id]);
    return 0;
}
