
/* 
 * 시스템 프로그래밍 lab3 과제 실습 5번
 * 파일 이름: exitprocess.c
 * 개발자 : 20183152 정민수
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int exit_status;
    printf("enter exit status: ");
    scanf("%d", & exit_status);
    exit(exit_status);
}