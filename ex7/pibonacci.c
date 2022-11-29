/* 
 * 시스템 프로그래밍 lab3 과제 실습 7번
 * 파일 이름: pibonacci.c
 * 개발자 : 20183152 정민수
 */

#include <stdio.h>
#include <signal.h>
#include <setjmp.h>

void start(int signo);
sigjmp_buf jbuf;
int main() {
    struct sigaction act;
    int cur_i, past_i, tmp_i;
    /* 현재 위치를 저장 */
    if (sigsetjmp(jbuf, 1) == 0) {
        act.sa_handler = start;
        sigaction(SIGINT, & act, NULL);
    }
    cur_i = past_i = 1;
    while (1) {
        printf("%d\n", cur_i);
        tmp_i = cur_i;
        cur_i += past_i;
        past_i = tmp_i;
        sleep(1);
    }
}
void start(int signo) {
    fprintf(stderr, "Interrupted\n");
    siglongjmp(jbuf, 1); /* 저장된 곳으로 복귀 */
}