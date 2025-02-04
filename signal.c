#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"
#include "mmu.h"
#include "proc.h"
#include "x86.h"
#include "syscall.h"

// Send a signal to a process by setting the signal flag
int sys_signal(void) {
    int pid, sig;
    if (argint(0, &pid) < 0 || argint(1, &sig) < 0)
        return -1;

    struct proc *p = find_proc_by_pid(pid);
    if (p != 0) {
        p->pending_signals |= (1 << sig);  // Set the bit for this signal
        return 0;
    }
    return -1;  // PID not found
}