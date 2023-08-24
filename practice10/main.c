#include <stdio.h>
#define M 100
#include <stdlib.h>
enum day
{
    mon,
    tues,
    wed,
    thur,
    fri,
    sat,
    sun
};

int main()
{
        /*int a = 0;
        scanf_s("%d",&a);
        switch (a)
        {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                printf("weekday\n");
                break;
            case 6:
            case 7:
                printf("weekend\n");
                break;
        }*/


    FILE * pf = fopen("test.txt","wb");
    fputs("abcdef",pf);
    fclose(pf);
    pf = NULL;


    return 0;
}
