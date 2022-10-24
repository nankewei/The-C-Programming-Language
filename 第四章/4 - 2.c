#include <stdio.h>
#include <string.h>
#include <ctype.h>
// 对 函数进行扩充，使它可以处理形如 123.45e-6的科学表示法，其中，浮点数后面可能会紧跟一个e或者E以及一个指数（可能有正负号）
// 科学记数法
double stringToDouble(char s[]);
int main()
{
    
    printf("%.0lf\n", stringToDouble("-123.456e8"));
    return 0;
}

// 科学记数法
double stringToDouble(char s[])
{
    double val, power;
    int i, sign;
    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
    }
    if (s[i] == '.')
    {
        i++;
    }
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }
    double result = sign * val / power;
    if (s[i] == 'e' || s[i] == 'E')
    {
        i++;
        int signE, powerNumber, powerTen;
        signE = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
            i++;
        //e 后面的数字
        for (powerNumber = 0; isdigit(s[i]); i++)
        {
            powerNumber = 10 * powerNumber + (s[i] - '0');
        }
        for (powerTen = 1; powerNumber > 0; powerNumber--)
        {
            powerTen *= 10;
        }
        return (signE > 0) ? (result *= powerTen) : (result /= powerTen);
    }
    else
    {
        return result;
    }
}
