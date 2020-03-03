#include <iostream>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
 
static bool flag = true;
void create_daemon();
void handler(int);
 
int main()
{
	time_t t;
	int fd;
	create_daemon();
	struct sigaction act;
	act.sa_handler = handler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	if(sigaction(SIGQUIT, &act, NULL))
	{
		printf("sigaction error.\n");
		exit(0);
	}
	while(flag)
	{
		fd = open("/home/mick/daemon.log", O_WRONLY | O_CREAT | O_APPEND, 0644);
		if(fd == -1)
		{
			printf("open error\n");
		}
		t = time(0);
		char *buf = asctime(localtime(&t));
		write(fd, buf, strlen(buf));
		close(fd);
		sleep(60);
	}
	return 0;
}
void handler(int sig)
{
	printf("I got a signal %d\nI'm quitting.\n", sig);
	flag = false;
}
void create_daemon()
{
	pid_t pid;
	/*(1)-----创建一个进程来用作守护进程-----*/
	pid = fork();
	
	if(pid == -1)
	{
		printf("fork error\n");
		exit(1);
	}
	/*(1.1)-----------原父进程退出-------------*/
	else if(pid)
	{
		exit(0);
	}
 	/*(2)---setsid使子进程独立。摆脱会话控制、摆脱原进程组控制、摆脱终端控制----*/
	if(-1 == setsid())
	{
		printf("setsid error\n");
		exit(1);
	}
  	/*(3)---通过再次创建子进程结束当前进程，使进程不再是会话首进程来禁止进程重新打开控制终端----*/
	pid = fork();
	if(pid == -1)
	{
		printf("fork error\n");
		exit(1);
	}
	else if(pid)
	{
		exit(0);
	}
  	/*(4)---子进程中调用chdir()让根目录成为子进程工作目录----*/
	chdir("/");
	int i;
	/*(6)---关闭文件描述符(常说的输入，输出，报错3个文件)----*/
	for(i = 0; i < 3; ++i)
	{
		close(i);
	}
	/*(5)---重设文件掩码为0（将权限全部开放）----*/
	umask(0);
	return;
}
