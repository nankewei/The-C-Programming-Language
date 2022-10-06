#include <stdio.h>

int main()
{
    printf("Hello,World\c\ttest!");
    return 0;
}
/* 如果\后紧跟的字符不在指定的字符中，其行为未定义（转义字符）*/
