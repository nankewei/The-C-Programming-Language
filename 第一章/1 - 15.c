#include <stdio.h>
// 分别为 温度下限、温度上限、步长
#define LOWER 0
#define UPPER 300
#define STEP 20
// 打印华氏温度 - 摄氏温度 对照表,使用函数实现温度转换计算

// 函数原型，也就是函数声明
double fahrToCelsius(int fahr);

int main()
{
    int fahr;
    printf("Fahrenheit to Celsius\n");
    for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
    {
        printf("%10d %10.1f\n", fahr, fahrToCelsius(fahr));
    }
    return 0;
}
// 函数定义
double fahrToCelsius(int fahr)
{
    double result;
    result = (5.0 / 9.0) * (fahr - 32);
    return result;
}
