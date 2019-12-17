# some Tips
## (1)
fork()、vfork()、_clone()均调用clone()实现，且依次调用do_fork()、copy_process()。
