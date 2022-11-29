/* 
 * 시스템 프로그래밍 lab3 과제 실습 7번
 * 파일 이름: alarmsignal.c
 * 개발자 : 20183152 정민수
 */

#include <stdio.h>
#include <signal.h>

void alarm_handler(int);

int alarm_flag = 0;

int main() {
    struct sigaction act;
    act.sa_handler = alarm_handler;

    sigaction(SIGALRM, & act, NULL);
    alarm(5); /* Turn alarm on. */
    pause(); /* pause */

    if (alarm_flag)
        printf("Passed a 5 secs.\n");
    
    return 0;
}

void alarm_handler(int sig) {
    printf("Received a alarm signal.\n");
    alarm_flag = 1;
}