/*
 * 시스템 프로그래밍 lab3 과제 실습 8번
 * 파일 이름: readfifo.c
 * 개발자 : 20183152 정민수
 */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define MSGSIZE 64

char *testfifo = "fifo";

int main(int argc, char **argv)
{
    int fd;
    char buf[MSGSIZE];
    if (mkfifo(testfifo, 0666) == -1)
    {
        perror("mkfifo failed");
        exit(1);
    }
    /* open testfifo, setting O_RDWR */
    if ((fd = open(testfifo, O_RDWR)) < 0)
    {
        perror("fifo open failed");
        exit(1);
    }
    /* receive message */
    while (1)
    {
        if (read(fd, buf, MSGSIZE) < 0)
        {
            perror("fifo read failed");
            exit(1);
        }
        printf("received message: %s\n", buf);
    }
}