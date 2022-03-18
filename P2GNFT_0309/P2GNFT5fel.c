#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void)
{
    pid_t pids[3];

    for (int i = 0; i < 3; i++) {
        pids[i] = fork();

        if (pids[i] == 0) {
            if (i == 0)
            {
                printf("exit\n");
                exit(0);
            }

            else if (i == 1)
            {
                printf("abort\n");
                abort();
            }

            else
            {
                printf("osztas 0-val\n");
                printf("1/0 = %d", 1/0);
                return 0;
            }
        }
    }

    int status;

    for (int i = 0; i < 3; i++) {
        wait(&status);
        printf("%d\n", status);
    }

    return 0;
}
