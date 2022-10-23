#include <stdio.h>
// 还能这样宏定义 ?函数
#define abs(x) ((x) < 0 ? -(x) : (x))
// 在数的二进制补码表示中，我们编写的itoa函数不能处理最大的负数，即n等于-(2^(字长-1))
// 的情况。请解释原因。修改该函数，使它在任何机器上运行时都能打印出正确的值
void intToString(int n, char s[]);
void reverse(char s[]);
void intToString(int n, char s[])
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
