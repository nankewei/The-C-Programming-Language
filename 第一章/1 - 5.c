#include <stdio.h>
// 分别为 温度下限、温度上限、步长
#define LOWER 0
#define UPPER 300
#define STEP 20

int main()
{
    double fahr, celsius;
    // 顺、逆序打印华氏温度 - 摄氏温度 对照表
    printf("Fahrenheit to Celsius\n");
    for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
    {
        printf("%10.0f %10.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
    }
    printf("Fahrenheit to Celsius\n");
    for (fahr = UPPER; fahr >= LOWER; fahr -= STEP)
    {
        printf("%10.0f %10.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
    }
    // 顺、逆序打印摄氏温度 - 华氏温度 对照表
    printf("Celsius to Fahrenheit\n");
    for (celsius = LOWER; celsius <= UPPER; celsius += STEP)
    {
        printf("%10.0f %10.1f\n", celsius, celsius * (9.0 / 5.0) + 32.0);
    }
    printf("Celsius to Fahrenheit\n");
    for (celsius = UPPER; celsius >= LOWER; celsius -= STEP)
    {
        printf("%10.0f %10.1f\n", celsius, celsius * (9.0 / 5.0) + 32.0);
    }
    return 0;
}
