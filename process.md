进程

1.进程控制原语

fork:

fork () 通过复制调用进程产生一个新进程。新进程称为子进程 。调用进程称为父进程 。

fork时子进程获得父进程数据空间、堆和栈的复制，所以变量的地址也是一样的。

返回值

成功时，父级返回子级的 PID，子级返回 0。错误时，父级返回 -1，不创建子级，设置 errno以指示错误。

cow 在fork之后exec之前两个进程用的是相同的物理空间（内存区），子进程的代码段、数据段、堆栈都是指向父进程的物理空间，也就是说，两者的虚拟空间不同，但其对应的物理空间是同
一个。当父子进程中有更改相应段的行为发生时，再为子进程相应的段分配物理空间。

fork时资源复制时复制页表项并且将其都设置为只读，缺页异常中识别COW引发的错误并实际分配资源实现地址空间隔离。

vfork

由vfork创造出来的子进程还会导致父进程挂起，除非子进程exit或者execve才会唤起父进程
由vfok创建出来的子进程共享了父进程的所有内存，包括栈地址，直至子进程使用execve启动新的应用程序为止
由vfork创建出来得子进程不应该使用return返回调用者，或者使用exit()退出，但是它可以使用_exit()函数来退出

vfork()保证子进程先运行，在她调用exec或_exit之后父进程才可能被调度运行。如果在
调用这两个函数之前子进程依赖于父进程的进一步动作，则会导致死锁。
fork() 子进程拷贝父进程的数据段，代码段.
vfork() 子进程与父进程共享数据段.|
fork() 父子进程的执行次序不确定.
vfork():保证子进程先运行，

exec:
执行一个文件

函数将内存中的当前程序代码替换为新的进程映像。

wait:

父进程一旦调用了wait就立即阻塞自己，由wait自动分析是否当前进程的某个子进程已经退出，如果让它找到了这样一个已经变成僵尸的子进程，wait就会收集这个子进程的信息，并把它彻底销毁后返回；如果没有找到这样一个子进程，wait就会一直阻塞在这里，直到有一个出现为止。

waitpid
等待并回收任意或特定子进程。

孤儿进程：一个父进程退出，而它的一个或多个子进程还在运行，那么那些子进程将成为孤儿进程。孤儿进程将被init进程(进程号为1)所收养，并由init进程对它们完成状态收集工作。


僵尸进程：一个进程使用fork创建子进程，如果子进程退出，而父进程并没有调用wait或waitpid获取子进程的状态信息，那么子进程的进程描述符仍然保存在系统中。这种进程称之为僵死进程。

 在每个进程退出的时候,内核释放该进程所有的资源,包括打开的文件,占用的内存等。但是仍然为其保留一定的信息(包括进程号the process ID,退出状态the termination status of the process,运行时间the amount of CPU time taken by the process等)。直到父进程通过wait / waitpid来取时才释放。如果大量的产生僵死进程，将因为没有可用的进程号而导致系统不能产生新的进程. 此即为僵尸进程的危害，应当避免。

 2.进程关系
 进程组 pgid:
每个进程都属于一个进程组，创建进程组的目的是用于简化向组内所有进程发送信号的操作，即如果一个信号是发给一个进程组，则这个组内的所有进程都会受到该信号
进程组的生命周期到组中最后一个进程终止或其加入其他进程组（离开本进程组）为止。

会话 sid:
一般一个用户登录后新建一个会话，每个会话也有一个ID来标识（SID）。登录后的第一个进程叫做会话领头进程（session leader），通常是一个shell/bash。对于会话领头进程，其PID=SID。

控制终端
一个会话一般会拥有一个控制终端用于执行IO操作。会话的领头进程打开一个终端之后, 该终端就成为该会话的控制终端。与控制终端建立连接的会话领头进程也称为控制进程 (controlling process) 。一个会话只能有一个控制终端。

前台进程组
该进程组中的进程能够向终端设备进行读、写操作的进程组。

后台进程组
该进程组中的进程只能够向终端设备写。

 守护进程：

 守护进程（daemon）是生存期长的一种进程，没有控制终端。它们常常在系统引导装入时启动，仅在系统关闭时才终止。UNIX系统有很多守护进程，守护进程程序的名称通常以字母“d”结尾：例如，syslogd 就是指管理系统日志的守护进程。
思考：怎么使普通进程变成守护进程？

 3信号

实际信号是软中断，许多重要的程序都需要处理信号。信号，为 Linux 提供了一种处理异步事件的方法。比如，终端用户输入了 ctrl+c 来中断程序，会通过信号机制停止一个程序。

常见信号

|取值	|名称	|解释	|
|-------|-------|-------|
1|SIGHUP|挂起|	 
2|SIGINT|中断|	 
3|SIGQUIT|退出|

信号的处理：
信号的处理有三种方法，分别是：忽略、捕捉和默认动作

kill 发送信号
kill -9 杀死进程

信号处理函数的注册

signal
sigaction
```c
#include <signal.h>
typedef void (*sighandler_t)(int);
sighandler_t signal(int signum, sighandler_t handler);
```
handler信号捕捉函数，用于处理信号

