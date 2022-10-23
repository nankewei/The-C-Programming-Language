#include <stdio.h>
// 还能这样宏定义 ?函数
#define abs(x) ((x) < 0 ? -(x) : (x))
//修改intToString函数，使得该函数可以接收三个参数。其中，第三个参数为最小字符宽度。为了保证转换后所得的结果至少具有第三个参数指定的最小宽度，在必要时在所得结果的左边填充一定的空格。
void intToString(int n, char s[]);
void reverse(char s[]);
void intToString(int n, char s[], int w)
{
    // sign 记录
    int i, sign;
    sign = n;
    i = 0;
    do
    {
        // 将最后一个数字转为字符
        s[i++] = abs(n % 10) + '0';
    } while ((n /= 10) != 0);
    if (sign < 0)
        s[i++] = '-';
    while (i < w)
    {
        s[i++] = ' ';
    }
    s[i] = '\0';
    reverse(s);
}
void reverse(char s[])
{
    int i = 0;
    int j = 0;
    char temp;
    // 一行输入不是都有换行符吗
    /* 寻找空字符*/
    while (s[i] != '\0')
        i++;
    i--;
    // 换行符
    if (s[i] == '\n')
        i--;
    // 交换字符
    while (j < i)
    {
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
        i--;
        j++;
    }
}
