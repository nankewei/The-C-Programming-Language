#include <stdio.h>
#define ENDPOSITON 8
#define MAXLINE 100
int getLine(char line[], int maxLine);
int spaceToTab(char line[], int lineLength);
//编写程序entab，将空格串替换为最少数量的制表符和空格，但是要保持单词之间的间隔不变。
//假设制表符终止位的位置与练习1-20的detab程序的情况相同。
//当使用一个制表符或者一个空格符都可以到达下一个制表符终止位时，选用哪一种替换字符比较好？
//
int main()
{
    int len;
    char line[MAXLINE];
    while ((len = getLine(line, MAXLINE)) > 0)
    {
        spaceToTab(line, len);
        // printf("\n");
    }
    // tabToSpace(line, ENDPOSITON);
    return 0;
}

int getLine(char line[], int maxLine)
{
    int c, i;
    // 如果没有换行符且输入长度过长，则只录入maxLine-1 个，maxLine 为空字符
    for (i = 0; i < maxLine - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        line[i] = c;
    }
    // printf("%s\n", line);
    if (c == '\n')
    {
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    // printf("%d\n", i);
    return i;
}
int spaceToTab(char line[], int lineLength)
{
    // 当前位置 :第几列, 空格个数 ， 制表符个数
    int indexPositon, blankNumber, tabNumber;
    indexPositon = 1;
    // 需要的tab 个数
    tabNumber = 0;
    // 需要的空格 个数
    blankNumber = 0;
    for (int i = 0; i < lineLength - 1; i++)
    {
        // 如果一开始就遇到' '
        // 每递增到ENDPOSITON的一个倍数时，我们就要把空格串替换为一个制表符。
        if (line[i] == ' ')
        {
            if (indexPositon % ENDPOSITON != 0)
            {
                // 打印的空格数++
                blankNumber++;
            }
            else
            {
                // 空格串替换为一个制表符。
                blankNumber = 0;
                tabNumber++;
            }
        }
        else
        {
            for (; tabNumber > 0; tabNumber--)
                putchar('\t');
            if (line[i] == '\t')
                blankNumber = 0;
            else
                for (; blankNumber > 0; blankNumber--)
                    // 输出空格，用 # 代替
                    putchar('#');
            putchar(line[i]);
            if (line[i] == '\n')
                indexPositon = 0;
            else if (line[i] == '\t')
                ;
                // 为什么遇到制表符要处理这个呢？
                // 如果不处理 
                //当使用一个制表符或者一个空格符都可以到达下一个制表符终止位时，选用哪一种替换字符比较好？
                // 用制表符替换，替换后要重新计算位置
                indexPositon = indexPositon + (ENDPOSITON - (indexPositon - 1) % ENDPOSITON) - 1;
        }
        indexPositon++;
    }
    putchar('\n');
}
