# some Tips
## (1)
fork()、vfork()、_clone()均调用clone()实现，且依次调用do_fork()、copy_process()。
fork()子进程的返回值为0。
父进程返回子进程的进程ID。