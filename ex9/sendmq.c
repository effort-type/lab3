/*
 * 시스템 프로그래밍 lab3 과제 실습 9번
 * 파일 이름: sendmq.c
 * 개발자 : 20183152 정민수
 */

#include <sys/types.h>
#include <mqueue.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFSIZE 32
#define QNAME "/my_queue"
#define PRIORITY 1

int main()
{
    mqd_t qd;
    struct mq_attr q_attr;
    char send_data[BUFSIZE];
    int status;
    pid_t pid;

    q_attr.mq_maxmsg = 10;       /* max message number in queue */
    q_attr.mq_msgsize = BUFSIZE; /* max message size */

    while (1)
    {
        if ((pid = fork()) == 0)
        {

            memset(send_data, 0, BUFSIZE);
            printf("Input > ");
            scanf("%[^\n]", &send_data);

            if ((qd = mq_open(QNAME, O_CREAT | O_RDWR, 0600, &q_attr)) == -1)
            {
                perror("mq_open failed");
                exit(1);
            }

            if (mq_send(qd, send_data, strlen(send_data), PRIORITY) == -1)
            {
                perror("mq_send failed");
                exit(1);
            }

            if (mq_close(qd) == -1)
            {
                perror("mq_close failed");
                exit(1);
            }
            exit(0);
        }
        else if (pid > 0)
        {
            pid = wait(&status);
            sleep(1);
        }
        else
        {
            perror("fork failed");
            exit(1);
        }
    }
    return 0;
}