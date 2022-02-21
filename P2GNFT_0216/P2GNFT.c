#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    fp=fopen("vezeteknev.txt", "w");

    fprintf(fp,"Takacs Balint\n");
    fprintf(fp,"Programtervezo informatikus\n");
    fprintf(fp, "P2GNFT\n");

    fp=fopen("vezeteknev.txt", "r");



    fclose(fp);

    return 0;
}
