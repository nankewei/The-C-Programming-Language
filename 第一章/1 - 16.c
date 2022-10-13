#include <stdio.h>
#define MAXLINE 1000
int getLine(char line[], int maxLine);
void copy(char from[], char to[]);
// 打印任意长度的输入行的长度
// 其实我不知道这代码跟原来的功能上有什么区别。。
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
    }
    if (max > 0)
        printf("最大长度为%d\t%s", max, longest);
    return 0;
}
// 将字符读入 字符数组 line中，返回其长度
// maxLine 最大长度 1000
int getLine(char line[], int maxLine)
{
    int c, i, j = 0;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; i++)
    {
        // 下标是0~999，如果有换行符 则用输入行长度的last but one 存'\n' last存'\0'，否则 直接用last 存'\0' 
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
        // 这里j++ 是为了在最后添加 空字符'\0',代表读取结束
        //i 为长度
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
