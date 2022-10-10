#include <stdio.h>
#define MAXLINE 1000
#define LONGLINE 80
int getLine(char line[], int maxLine);
void copy(char from[], char to[]);
// 打印长度大于80个字符的所有输入行
int main()
{
    int len;               //当前行长度
    int max;               //目前的最长行长度
    char line[MAXLINE];    //当前输入行
    char longest[MAXLINE]; //最长输入行
    max = 0;
    while ((len = getLine(line, MAXLINE)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(line, longest);
        }
        //打印长度大于80个字符的所有输入行
        //--！还以为可以输入多行，然后在ctrl z 后打印所有大于的，但是太耗内存了吧
        //。
        if (len > LONGLINE)
            printf("%s", line);
    }

    return 0;
}
// 将字符读入 字符数组 line中，返回其长度
// maxLine 最大长度 1000
int getLine(char line[], int maxLine)
{
    int c, i, j = 0;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; i++)
    {
        // 下标是0~999，用998存'\n' 999存'\0'
        if (i < maxLine - 2)
        {
            line[j] = c;
            ++j;
        }
    }
    if (c == '\n')
    {
        line[j] = c;
        ++j;
        // 这里i++ 是为了在最后添加 空字符'\0',代表读取结束
        i++;
    }
    line[j] = '\0';
    // 如果读到EOF 直接返回0
    return i;
}
// 将字符数组 from 复制到 to
void copy(char from[], char to[])
{
    for (int i = 0; (to[i] = from[i]) != '\0'; i++)
        ;
}
