/* 
 * 시스템 프로그래밍 lab3 과제 실습 7번
 * 파일 이름: sendsignal.c
 * 개발자 : 20183152 정민수
 */

#include <stdio.h>
#include <sys/types.h>
#include <signal.h>

int i = 0;
void p_handler(int), c_handler(int);

int main()
{
    pid_t pid, ppid;
    struct sigaction act;
    pid = fork();
    if (pid == 0)
    {
        act.sa_handler = c_handler;
        sigaction(SIGUSR1, &act, NULL);
        ppid = getppid(); /* get parent's process id. */
        while (1)
        {
            sleep(1);
            kill(ppid, SIGUSR1);
            pause();
        }
    }
    else if (pid > 0)
    {
        act.sa_handler = p_handler;
        sigaction(SIGUSR1, &act, NULL);

        while (1)
        {
            pause();
            sleep(1);
            kill(pid, SIGUSR1);
        }
    }
    else
        perror("Error");
    
    return 0;
}

void p_handler(int signo)
{
    printf("Parent handler: call %d times.\n", ++i);
}

void c_handler(int signo)
{
    printf("Child handler: call %d times.\n", ++i);
}
