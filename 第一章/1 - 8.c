// 编写一个统计空格、制表符与换行符个数的程序
#include <stdio.h>
int main()
{
    // 输入字符，空格、制表、换行
    int c, spaceCount, tabCount, lineFeedCount;
    spaceCount = tabCount = lineFeedCount = 0;
    while ((c = getchar()) != EOF)
    {
        // 分别统计输入中 空格、制表、换行的个数
        if (c == ' ')
        {
            spaceCount++;
        }
        else if (c == '\t')
        {
            tabCount++;
        }
        else if (c == '\n')
        {
            lineFeedCount++;
        }
        else
            ;
    }
    printf(" spaceCount : %d , tabCount : %d , lineFeedCount : %d ", spaceCount, tabCount, lineFeedCount);
    return 0;
}
