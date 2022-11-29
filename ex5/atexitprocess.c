
/* 
 * 시스템 프로그래밍 lab3 과제 실습 5번
 * 파일 이름: atexitprocess.c
 * 개발자 : 20183152 정민수
 */

#include <stdlib.h>
#include <stdio.h>

void exitfunc1(void);
void exitfunc2(void);

int main() {
    atexit(exitfunc1);
    atexit(exitfunc2);
    printf("This is main function.\n");
}

void exitfunc1(void) {
    printf("This is exit function 1.\n");
}

void exitfunc2(void) {
    printf("This is exit function 2.\n");
}