#include <stdio.h>
#define MAXLINE 1000
#define LONGLINE 80
int getLine(char line[], int maxLine);
// 编写一个程序，删除每个输入行末尾的空格和制表符，并删除完全是空格的行。
// 参考答案 把遇到换行符后的处理放到的一个新函数 remove,我在getLine函数实现了
int main()
{
    int len;               //当前行长度
    int max;               //目前的最长行长度
    char line[MAXLINE];    //当前输入行
    char longest[MAXLINE]; //最长输入行
    max = 0;
    while ((len = getLine(line, MAXLINE)) > 0)
    {
        if (len == 1)
            printf("没有有效输入\n");
        if (len > max)
        {
            max = len;
            copy(line, longest);
        }
        if (len > 10)
            printf("%d\n%s", len, line);
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
        // 下标是0~999，如果有换行符 则用输入行长度的last but one 存'\n' last存'\0'，否则 直接用last 存'\0' 
        if (i < maxLine - 2)
        {
            line[j] = c;
            ++j;
        }
    }
    // 遇到换行符 就意味着这一行结束了
    if (c == '\n')
    {
        // 从后往前 判断
        // 所以 k 的值为 换行符的上一个字符
        for (int k = j - 1; k >= 0; k--)
        {
            if (line[k] == ' ' || line[k] == '\t')
            {
                // line[k] = '\0';
                j--;
                i--;
            }
            else
                break;
            //
        }
        // j本来是保存换行符，最后一个空字符'\0'
        line[j] = c;
        ++j;
        // 这里j++ 是为了在最后添加 空字符'\0',代表读取结束
        // i为长度
        i++;
    }
    line[j] = '\0';
    // 如果读到EOF 直接返回0
    return i;
}
