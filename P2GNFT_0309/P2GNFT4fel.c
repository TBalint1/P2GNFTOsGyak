#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>


int main()
{
    int pid = fork();

    if (pid == 0) {

        execlp("who", "who", (char*)NULL);

    }

    else {

        waitpid(pid,NULL,0);

    }



    return 0;
}
