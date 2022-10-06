// 编写一个程序，打印输入中单词长度的直方图。

#include <stdio.h>
#define MAXSTAR 15   //可以打印的最大星星数量
#define MAXLENGTH 10 //单词最大长度
// 没用到 --！
#define YES 1 //是单词
#define NO 0  //不是单词

//打印垂直方向的直方图
//双重循环 外层控制行，内层控制列
int main()
{
    int c, i, charNumber, isWord;
    int len, maxValue, overFlow, wordLength[MAXLENGTH];
    isWord = YES;
    charNumber = overFlow = maxValue = 0;
    // 初始化
    for (i = 0; i < MAXLENGTH; i++)
    {
        wordLength[i] = 0;
    }
    // 获取字符输入
    while ((c = getchar()) != EOF)
    {
        if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
        {
            // 单词中的字符数量
            charNumber++;
        }
        else
        {
            if (charNumber <= MAXLENGTH)
            {
                // 存入数组，下标从0 开始
                wordLength[charNumber - 1]++;
            }
            else
            {
                overFlow++;
            }
            charNumber = 0;
        }
    }
    // 找出数组中长度 为i且数量最多 的单词的频率
    // 防止除0
    for (i = 0; i < MAXLENGTH; i++)
    {
        // 次数
        if (wordLength[i] > maxValue)
            maxValue = wordLength[i];
        // 频率最大的单词长度的星数 为 15
    }
    // 所以从 15 开始， i控制行
    for (i = MAXSTAR; i >= 0; i--)
    {
        // putchar('|');
        //  控制列，列输出成一行
        //  j 控制列
        for (int j = 0; j < MAXLENGTH; j++)
        {
            // 什么情况下这一列会打印 * ？
            // 在第 i 行时，wordLength[j] 应该打印的星星数 >= 第 i 行，才会打印 '*' ;
            if (wordLength[j] * MAXSTAR / maxValue >= i)
                printf("  * ");
            // 如果 15/16=0.93175 即 MAXSTAR / maxValue < 1 程序会向下取整 化为0，所以不会打印星号
            // 增加判断语句 wordLength[j] * MAXSTAR / maxValue < 1 并且 wordLength[j]  > 0（也就是不为0）时
            // 在第1行才会打印一个星号（有值的话至少要打印一个星号）
            else if (wordLength[j] * MAXSTAR / maxValue < 1 && wordLength[j] > 0 && i == 1)
                printf("  * ");
            else
                printf("    ");
        }
        putchar('\n');
    }
    printf("-------------------------------------------------->\n");
    for (i = 0; i < MAXLENGTH; i++)
    {
        printf("%3d ", i + 1);
    }
    putchar('\n');
    for (i = 0; i < MAXLENGTH; i++)
    {
        printf("%3d ", wordLength[i]);
    }
    putchar('\n');
    if (overFlow > 0)
    {
        printf("There are %d words > %d\n", overFlow, MAXLENGTH);
    }
    return 0;
}
