#include <unistd.h>  
#include <sys/types.h>
#include <stdio.h>   
int main ()   
{   
    pid_t fpid; //fpid表示fork函数返回的值   
    fpid=fork();   
    if (fpid < 0)   
        printf("error in fork!");   
    else if (fpid == 0) {  
        printf("Child process is running\n");   
        printf("Execve pid = %d ,parentpid = %d\n",getpid(),getppid());   
        printf("Execve uid = %d ,gid =%d\n",getuid(),getgid());   
        execlp("vi",0); 
    }  
    else {  
        while(1){
        }
    }  
    return 0;  
}  

