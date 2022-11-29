/* 
 * 시스템 프로그래밍 lab3 과제 실습 7번
 * 파일 이름: raisesignal.c
 * 개발자 : 20183152 정민수
 */

#include <signal.h>

int main() {
    int a, b;
    a = 10;
    b = 0;
    if (b == 0) /* preempt divide by zero error */
        raise(SIGFPE);
    a = a / b;
}