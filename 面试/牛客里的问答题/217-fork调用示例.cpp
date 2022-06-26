// 题目
/*
fork调用示例
*/

// 解答
/*

1、概念：
Fork：创建一个和当前进程映像一样的进程可以通过fork( )系统调用：

成功调用fork( )会创建一个新的进程，它几乎与调用fork( )的进程一模一样，这两个进程都会继续运行。在子进程中，成功的fork( )调用会返回0。在父进程中fork( )返回子进程的pid。如果出现错误，fork( )返回一个负值。

最常见的fork( )用法是创建一个新的进程，然后使用exec( )载入二进制映像，替换当前进程的映像。这种情况下，派生（fork）了新的进程，而这个子进程会执行一个新的二进制可执行文件的映像。这种“派生加执行”的方式是很常见的。

在早期的Unix系统中，创建进程比较原始。当调用fork时，内核会把所有的内部数据结构复制一份，复制进程的页表项，然后把父进程的地址空间中的内容逐页的复制到子进程的地址空间中。但从内核角度来说，逐页的复制方式是十分耗时的。现代的Unix系统采取了更多的优化，例如Linux，采用了写时复制的方法，而不是对父进程空间进程整体复制。

2、fork实例

int main(void)
{
pid_t pid;
signal(SIGCHLD, SIG_IGN);
printf("before fork pid:%d\n", getpid());
int abc = 10;
pid = fork();

if (pid == -1) {           //错误返回
perror("tile");
return -1;
}

if (pid > 0) {              //父进程空间

abc++;
printf("parent:pid:%d \n", getpid());
printf("abc:%d \n", abc);
sleep(20);
}

else if (pid == 0) {       //子进程空间
abc++;
printf("child:%d,parent: %d\n", getpid(), getppid());
printf("abc:%d", abc);
}
printf("fork after...\n");
 }


*/

