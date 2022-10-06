// 编写一个将输入复制到输出的程序，并将其中连续的多个空格用一个空格代替。
#include <stdio.h>
#define YES 1
#define NO 0
int main()
{
    // 输入字符，是否为空格
    int c, isSpace;
    isSpace = NO;
    while ((c = getchar()) != EOF)
    {
        // 输入为空格时
        if (c == ' ')
        {
            // 只输出第一个空格
            if (isSpace == NO)//可以写成 if(!isSpace)
            {
                putchar(c);
                isSpace = YES;
            }
        }
        // 其他字符照常输出
        else
        {
            isSpace = NO;
            putchar(c);
        }
    }
    return 0;
}
