## Hello System Call Implementation

This example demonstrates how to add a `hello` system call to xv6-riscv. The system call accepts four integer arguments, prints them in the kernel, and returns their sum.


Added the following function declaration:

```c
int hello(int, int, int, int);

inside user/user.h-> syscall added .............. int hello(int, int, int, int)
inside user/ usys.pl-> added..................... entry("hello");
inside kernel/syscall.h-> added.................. #define SYS_hello 23
inside kernel/syscall.c-> added.................. extern uint64 sys_hello(void); 
inside kernel/syscall.c-> added.................. [SYS_hello] = sys_hello,
inside kernel/sysproc.c-> added the hello function............................
uint64
sys_hello(void)
{
  int a, b, c, d;

  argint(0, &a);
  argint(1, &b);
  argint(2, &c);
  argint(3, &d);

  printk("hello %d %d %d %d\n", a, b, c, d);

  return a + b + c + d;
}

inside user/hello.c-> implemented the hello function.........................
#include "kernel/types.h"
#include "user/user.h"

int
main(void)
{
  printf("sum = %d\n", hello(1, 2, 3, 4));
  exit(0);
}

add hello to make file....................... $U/_hello\
