#include "get_next_line.h"

static int get_one_line(char *ptr, char **ret,char **mem)
{
    char *tmp;
    
    //개행이 있는경우
        //리턴값에 메모리에 개행까지의 내용 복사/할당
        //개행 이후의 내용을 복사/할당
        //예외처리
        //메모리 내용 해제
        //메모리에 개행 이후의 내용을 넣기
        //성공 리턴
    //개행이 없는경우
        //메모리와 메모리 주소값 확인 후 널 문자일경우
            //리턴값 댕글링 포인터
            //메모리 해제해제
        //메모리에 값이 있을경우
         //리턴값에 메모리의 내용을 넣고
         //메모리 댕글링 포인터
        //파일 끝남을 리턴
}

static int read_fd(int fd, char **ret, char **buf, char **mem)
{
    char *ptr;
    char *tmp;
    ssize_t read_len;

        //개행 찾기
        //개행이 있다면 나감
        //파일 읽기
        //파일 끝 혹은 에러 확인
        //읽어온 문자열 끝에 널 문자 넣기
        //메모리에 있는 문자열과 읽어온 문자열 붙여서 임시공간에 놓기
        //할당 예외 처리
        //기존 메모리에 있던 내용 해제
        //메모리에 합친 문자열 넣기
}

char    *get_next_line(int fd)
{
    char            *ret;
    char            *buf;
    int             status;
    static char     *mem[OPEN_MAX + 1];

    //리턴값 초기화
    //fd openmax buffersize 에외처리
    //메모리에 아무것도 들어있지않다면 빈내용 추가
    //버퍼에 버퍼사이즈+1 만큼 할당
    //버퍼와 메모리의 메모리할당 예외처리
    //파일 읽기
    //버퍼 내용 해제

    //읽어온 상태값에 대한 예외처리
    //return
}