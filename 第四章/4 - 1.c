#include <stdio.h>
#include <string.h>
#include <ctype.h>
// 行的最大长度
#define LINELENGTH 1000
int getLine(char s[], int max);
// 第一个版本
int strRightIndex(char s[], char t[]);
// 第二个版本
int strRightIndexAnother(char s[], char t[]);

int main()
{
    char line[LINELENGTH];
    char A[] = "aefg";
    char B[] = "efg";
    printf("%d\n", strRightIndexAnother("abc", "bc"));
    return 0;
}
// 把输入存储到s中，并返回长度
int getLine(char s[], int max)
{
    int c, i;
    i = 0;
    // 最后一个需要存储 '\0' --max 999
    while (--max > 0 && (c = getchar()) != EOF && c != '\n')
    {
        s[i++] = c;
    }
    if (c == '\n')
    {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}
// 返回t在s中最右边出现的位置
int strRightIndex(char s[], char t[])
{
    int i, j, k, pos;
    pos = -1;
    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            pos = i;
    }
    return pos;
}
// 返回t在s中最右边出现的位置
int strRightIndexAnother(char s[], char t[])
{
    int i, j, k;
    // 下标从 strlen(s) - strlen(t) 开始
    for (i = strlen(s) - strlen(t); i >= 0; i--)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}
