// 编写一个将输入复制到输出的程序，并将其中的制表符替换成\t，将回退符替换成\b。将反斜杠替换成\\。
#include <stdio.h>

// 可视化 输入中的制表符和回退符
int main()
{
    // 输入字符，是否为空格
    int c;
    while ((c = getchar()) != EOF)
    {
        // 输入为制表符时
        if (c == '\t')
        {
            printf("\\t");
        }
        // 输入为回退符时
        else if (c == '\b')
        {
            printf("\\b");
        }
        // 输入为\时
        else if (c == '\\')
        {
            printf("\\\\");
        }
        else
            putchar(c);
    }
    return 0;
}
