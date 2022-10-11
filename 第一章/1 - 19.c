#include <stdio.h>
#define MAXLINE 1000
#define LONGLINE 80
int getLine(char line[], int maxLine);
int reverse(char line[]);
// 将字符串s中的字符顺序颠倒过来。使用该函数编写一个程序，每次颠倒一个输入行中的字符顺序。
int main()
{
    int len;            //当前行长度
    char line[MAXLINE]; //当前输入行
    while ((len = getLine(line, MAXLINE)) > 0)
    {

        reverse(line);
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
    // 遇到换行符 就意味着这一行结束了
    if (c == '\n')
    {
        // j本来是保存换行符，最后一个空字符'\0'
        line[j] = c;
        ++j;
        // 这里i++ 是为了在最后添加 空字符'\0',代表读取结束
        i++;
    }
    line[j] = '\0';
    // 如果读到EOF 直接返回0
    return i;
}
int reverse(char line[])
{
    int i = 0;
    int j = 0;
    char temp;
    // 一行输入不是都有换行符吗
    /* 寻找空字符*/
    while (line[i] != '\0')
        i++;
    i--;
    // 换行符
    if (line[i] == '\n')
        i--;
    // 交换字符
    while (j < i)
    {
        temp = line[j];
        line[j] = line[i];
        line[i] = temp;
        i--;
        j++;
    }
}
