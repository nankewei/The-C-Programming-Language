// 编写一个程序，以每行一个单词的形式打印其输入
#include <stdio.h>
#define YES 1
#define NO 0
int main()
{
    int c, isWord;
    isWord = NO;
    while ((c = getchar()) != EOF)
    {
        // 如果是字母字符 ,非数字 非空白字符
        if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
        {
            isWord = YES;
            putchar(c);
        }
        else
        {
            if (isWord)
                putchar('\n');
            // 开始获取新的单词
            isWord = NO;
        }
    }
    return 0;
}
