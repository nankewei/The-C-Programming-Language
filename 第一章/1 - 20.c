#include <stdio.h>
#define ENDPOSITON 8
#define MAXLINE 100
int getLine(char line[], int maxLine);
int tabToSpace(char line[], int lineLength);
//编写程序detab，将输入中的制表符替换成适当数目的空格，使空格充满到下一个制表符终止位的地方。
//假设制表符终止位的位置是固定的，比如每隔n列就会出现一个制表终止位。n应该作为变量还是符号常量呢？
//起初并没有理解这道题的意思，主要是由于不清楚制表符和空格的区别以及什么是制表符终止位，之前只是简单的理解为制表符占用四个空格。
//系统地查了下制表符，才知道引入制表符的含义。百度百科的解释为：制表符（也叫制表位）的功能是在不使用表格的情况下在垂直方向按列对齐文本。

int main()
{
    int len;
    char line[MAXLINE];
    while ((len = getLine(line, MAXLINE)) > 0)
    {
        tabToSpace(line, len);
    }
    // tabToSpace(line, ENDPOSITON);
    return 0;
}

int getLine(char line[], int maxLine)
{
    int c, i;
    // 如果没有换行符且输入长度过长，则只录入maxLine-1 个，maxLine 为空字符
    for (i = 0; i < maxLine - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        line[i] = c;
    }
    // printf("%s\n", line);
    if (c == '\n')
    {
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    // printf("%d\n", i);
    return i;
}
int tabToSpace(char line[], int lineLength)
{
    // 当前位置 :第几列
    int indexPositon, blankNumber;
    indexPositon = 1;
    blankNumber = 0;
    for (int i = 0; i < lineLength - 1; i++)
    {
        // 如果一开始就遇到\t
        if (line[i] == '\t')
        {
            blankNumber = ENDPOSITON - (indexPositon - 1) % ENDPOSITON;
            while (blankNumber > 0)
            {
                putchar('#');
                indexPositon++;
                blankNumber--;
            }
        }
        else if (line[i] == '\n')
        {
            putchar(line[i]);
            indexPositon = 1;
        }
        else
        {
            putchar(line[i]);
            indexPositon++;
        }
    }
}
