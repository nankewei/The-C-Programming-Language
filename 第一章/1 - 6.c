// 验证表达式 getchar() != EOF 的值是 1 还是 0 
#include <stdio.h>

int main()
{
    // 输入字符，是否为空格
    int c;
    // 去掉了 (c = getchar()) 中的小括号 
    // 回车 也会被读取到，所以回车后会打印两个值
    while (c = getchar() != EOF)
    {
        printf("value is %d\n", c);
    }
    return 0;
}
