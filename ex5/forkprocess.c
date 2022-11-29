/* 
 * 시스템 프로그래밍 lab3 과제 실습 5번
 * 파일 이름: forkprocess.c
 * 개발자 : 20183152 정민수
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {

    pid_t pid; /* 부모에서 프로세스 식별번호 저장 */
    printf("Calling fork \n");

    pid = fork(); /* 새로운 프로세스 생성 */

    if (pid == 0) /* 자식 프로세스면 fork()가 0을 반환*/
        printf("I'm the child process\n");
    else if (pid > 0)
        printf("I'm the parent process\n");
    else /* 비정상적인 실행이면 음수 값을 반환 */
        printf("fork failed\n");

}