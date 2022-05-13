#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{

    int parentPid = getpid();
    int pid = fork();

    if (pid == 0) {


        printf("Gyermek processz: \n");
        printf("A szulo pid-je: %d, A gyermek pid-je: %d\n", parentPid, getpid());
        char* prog = getenv("PROG");
        execl(prog, prog, (char*)NULL );

    }

    else {

        printf("A szulo processz: \n")
        printf("A szulo pid-je: %d, A gyermek pid-je: %d\n", parentPid, pid);
        waitpid(pid,NULL,0);

    }







    return 0;
}
