#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <stdarg.h>
#include <sys/types.h>
#define HASPRO -10
char *a;


int main()
{
    pid_t p1,p2,p3,p4,p5;

    int cnt=0;

    while((p1=fork()) == -1);

    if(!p1)
    {
        while((p2=fork()) == -1);

        if(!p2)
        {
            while ((p4=fork())==-1);
            if (!p4)
            {
                while(1)
                {	sleep(1);
                   printf(" p4 de  pid shi %d,  fu p2 de pid shi%d\n",getpid(),getppid());
                 
                }
            }
            else
            {
                while ((p5=fork())==-1);

                if (!p5)
                {
                    while(1)
                    {sleep(1);
                        printf(" p5 de pid shi%d,  fu p2 de pid shi%d\n",getpid(),getppid());
                     
                    }

                }
                else
                {
                    ;
                }

            }

            while(1)
            {
				sleep(1);
                printf("p2 de pid shi %d,  fu p1 de pid shi %d\n",getpid(),getppid());
                exit(0);
            }
        }
        else
        {
            while ((p3=fork())==-1);

                if (!p3)
                {
                    while(1)
                    {sleep(1);
                       printf("p3 de  pid shi%d,  fu p1 de pid shi %d\n",getpid(),getppid());
                        
                    }

                }
                else
                {
                    ;
                }
        }

        while(1)
        {sleep(1);
           printf("p1  de pid shi %d,  fu de  pid shi %d\n\n",getpid(),getppid());
            
        }
    }
    
    return 0;
}

