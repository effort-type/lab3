/* 
 * 시스템 프로그래밍 lab3 과제 실습 8번
 * 파일 이름: pipetest.c
 * 개발자 : 20183152 정민수
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MSGSIZE 16

int main()
{
    char buf[MSGSIZE];
    int p[2], i;
    int pid;

    if(pipe(p) == -1) {
        perror("pipe call failed");
        exit(1);
    }

    pid = fork();
    if(pid == 0) {
        close(p[0]);
        
        for(i = 0; i < 2; i++) {
            sprintf(buf, "Hello, world #%d", i+1);
            write(p[1], buf, MSGSIZE);
        }
    } else if (pid > 0) {
        close(p[1]);

        for(i = 0; i < 2; i++) {
            read(p[0], buf, MSGSIZE);
            printf("%s\n", buf);
        }
    }
    else
        perror("fork failed");

}