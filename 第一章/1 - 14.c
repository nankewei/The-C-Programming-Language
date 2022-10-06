// 编写一个程序，打印输入中各个字符出现频率的直方图。

#include <stdio.h>
#define MAXSTAR 50      //可以打印的最大星星数量
#define ASCIILENGTH 127 // 128个 ASCII 字符

int main()
{
    int c, i, len;
    int maxValue = 0; //最大频率次数
    int charArray[ASCIILENGTH];
    len = maxValue = 0;
    // 初始化 字符数组
    for (i = 0; i < ASCIILENGTH; i++)
    {
        charArray[i] = 0;
    }
    // 获取字符输入
    while ((c = getchar()) != EOF)
    {
        //输入的字符 c 就有一个ASCII值，所以可以当作数组的下标！！！
        // 我的想法 ：两个数组一个存 字符 ，一个存出现的次数 --！ 好烂
        // 比如输入的是：abc a
        // 读到a 后找一个charArray[i] 为 0的charArray[i] 存起来，再到B数组对应下标++
        // 第二个a 判断存不存在。。。。。。。。效率好低

        charArray[c]++;
    }
    // 找出数组中长度 为i且数量最多 的单词的频率
    // 防止除0
    for (i = 0; i < ASCIILENGTH; i++)
    {
        // 次数
        if (charArray[i] > maxValue)
            maxValue = charArray[i];
    }
    // 打印*
    for (i = 0; i < ASCIILENGTH; i++)
    {
        // 有次数才输出，只打印有频率的
        if (charArray[i] > 0)
        {
            // 字符格式输出
            // 当字符为 \n 时 输出会自动换行 ，所以要判断下
            if (i == '\n')
            {
                printf("the char: \'\\n\'  has %6d times   ", charArray[i]);
            }
            else
                printf("the char: \'%c\'   has %6d times   ", i, charArray[i]);
            // 打印的星号长度
            // 当前频率 * 最大星数 / 最大频率
            len = charArray[i] * MAXSTAR / maxValue;
            // 只要有次数，不管多小都要打印一个 '*'
            if (!len) //即 charArray[i] * MAXSTAR / maxValue==0 && wordLength[i] > 0，  0<值<1 会被向下取整为0
            {
                len = 1;
            }
            while (len--)
                putchar('*');
            putchar('\n');
        }
    }
    return 0;
}
