/* 
 * 시스템 프로그래밍 lab3 과제 실습 7번
 * 파일 이름: handlesignal.c
 * 개발자 : 20183152 정민수
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler(int signo);

int main() {
    struct sigaction act;
    int i = 0;

    act.sa_handler = handler;

    sigfillset( & (act.sa_mask));
    sigaction(SIGINT, & act, NULL);

    printf("SIGINT on\n");

    while (1) {
        sleep(1);
        printf("sleep for %d sec(s).\n", ++i);
    }

    return 0;
}

void handler(int signo) {
    printf("handler: signo=%d\n", signo);
}