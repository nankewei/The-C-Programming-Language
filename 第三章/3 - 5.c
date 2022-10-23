#include <stdio.h>
// 还能这样宏定义 ?函数
#define abs(x) ((x) < 0 ? -(x) : (x))
// 编写函数intToAnotherNumberSystem(n, s, b)，将整数n转换为以b为底的数，并将转换结果以字符的形式保存到字符串s中。
// 例如intToAnotherNumberSystem(n, s, 16)把整数n格式化成十六进制整数保存在s中。
void intToAnotherNumberSystem(int n, char s[], int b);
void reverse(char s[]);
void intToAnotherNumberSystem(int n, char s[], int b)
{
    // sign 记录
    int i, j, sign;
    sign = n;
    i = 0;
    do
    {
        // 将最后一个数字转为字符
        j = abs(n) % b;
        // 16进制中 a（A） 为10

        s[i++] = (j <= 9) ? j + '0' : j + 'a' - 10;

    } while ((n /= b) > 0);
    if (sign < 0)
        s[i++] = '-';
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
