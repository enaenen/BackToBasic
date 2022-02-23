#include "get_next_line.h"

static int get_one_line(char *ptr, char **ret,char **mem)
{
    char *tmp;
    
    //개행이 있는경우
    if (ptr)
    {
        //리턴값에 메모리에 개행까지의 내용 복사/할당
        *ret = gnl_strndup(*mem, ptr - *mem + 1);
        //개행 이후의 내용을 복사/할당
        tmp = gnl_strndup(ptr + 1, gnl_strlen(ptr));
        //예외처리
        if (!tmp)
        {
            free(ret);
            return (ERROR);
        }
        //메모리 내용 해제
        free(*mem);
        //메모리에 개행 이후의 내용을 넣기
        *mem = tmp;
        //성공 리턴
        return (SUCCESS);
    }
    //개행이 없는경우
    else
    {
        //메모리와 메모리 주소값 확인 후 널 문자일경우
        if (!*mem || **mem == '\0')
        {
            //리턴값 댕글링 포인터
            ret = NULL;
            //메모리 해제해제
            free(*mem);
        }
        //메모리에 값이 있을경우
        else
        {
         //리턴값에 메모리의 내용을 넣고
         ret = *mem;
         //메모리 댕글링 포인터
         *mem = NULL;
        }
        //파일 끝남을 리턴
        return (END_OF_FILE);
    }
}

static int read_fd(int fd, char **ret, char **buf, char **mem)
{
    char *ptr;
    char *tmp;
    ssize_t read_len;

    while (1)
    {
        //개행 찾기
        ptr = gnl_strchr(*mem, '\n');
        //개행이 있다면 나감
        if(ptr)
            break;
        //파일 읽기
        read_len = read(fd, *buf, BUFFER_SIZE);
        //파일 끝 혹은 에러 확인
        if (read_len == 0)
            break; 
        if (read_len == -1)
            return (ERROR);
        //읽어온 문자열 끝에 널 문자 넣기
        (*buf)[read_len] = '\0';
        //메모리에 있는 문자열과 읽어온 문자열 붙여서 임시공간에 놓기
        tmp = gnl_strjoin(*mem, *buf);
        //할당 예외 처리
        if (!tmp)
            return (ERROR);
        //기존 메모리에 있던 내용 해제
        free(*mem);
        //메모리에 합친 문자열 넣기
         *mem = tmp;
    }
    return (get_one_line(ptr, ret, mem));
}

char    *get_next_line(int fd)
{
    char            *ret;
    char            *buf;
    int             status;
    static char     *mem[OPEN_MAX + 1];

    //리턴값 초기화
    ret = NULL;
    //fd openmax buffersize 에외처리
    if (fd < 0 || OPEN_MAX < fd || BUFFER_SIZE <= 0)
        return (NULL);
    //메모리에 아무것도 들어있지않다면 빈내용 추가
    if (!mem[fd])
        mem[fd] = gnl_strndup("", 0);
    //버퍼에 버퍼사이즈+1 만큼 할당
    buf = malloc(BUFFER_SIZE + 1);
    //버퍼와 메모리의 메모리할당 예외처리
    if (!buf || !mem[fd])
        return (NULL);
    //파일 읽기
    status = read_fd(fd, &ret, &buf, &mem[fd]);
    //버퍼 내용 해제

    //읽어온 상태값에 대한 예외처리
    if (status == ERROR)
    {
        free(mem[fd]);
        mem[fd] = NULL;
    }
    //return
    return SUCCESS;
}