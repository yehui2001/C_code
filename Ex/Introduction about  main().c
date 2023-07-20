#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    while(--argc > 0)
        printf("%s",argv[argc]);    //argc 是参数的个数，argv[]是参数，argv[0]是文件名，argv[1]是第一个参数...
    printf("\n");
    return 0;
}