#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    int ok = 0;
    char command [50];

    while (!ok) {

        scanf("%s", command);

        if(strcmp(command , "exit") == 0) {

            ok = 1;

        }

        else {

            system(command);

        }

    }

    return 0;
}
