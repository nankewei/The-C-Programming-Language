// 编写一个程序，打印输入中单词长度的直方图。

#include <stdio.h>
#define MAXSTAR 15   //可以打印的最大星星数量
#define MAXLENGTH 10 //单词最大长度
// 没用到 --！
#define YES 1 //是单词
#define NO 0  //不是单词
//打印水平方向的直方图
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
        // if (c == ' ' || c == '\b' || c == '\t' || c == '\n') //空白字符
        // {
        //     // 说明不是单词
        //     isWord = NO;
        // }
        // 判断输入字符是否为单词
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
    }
    for (i = 0; i < MAXLENGTH; i++)
    {
        printf("单词长度为 %5d - %5d : ", i + 1, wordLength[i]);
        // 找出该打印的星星数量比例
        len = wordLength[i] * MAXSTAR / maxValue; // 防止除0
        // int 会向下取整 15/16=0.93175  会取整为0
        if ((len = wordLength[i] * MAXSTAR / maxValue) == 0 && wordLength[i] > 0)
        {
            len = 1;
        }
        // 打印星数 为0不执行
        while (len--)
        {
            putchar('*');
        }
        putchar('\n');
    }
    if (overFlow > 0)
    {
        printf("There are %d words > %d\n", overFlow, MAXLENGTH);
    }
    return 0;
}
