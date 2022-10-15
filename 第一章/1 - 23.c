#include <stdio.h>
// 编写一个删除c语言程序中所有的注释语句。要正确的处理带引号的字符串与字符常量。在c语言中注释不允许嵌套
// /* /* this is the comments */ */
// 注释从第一个/*开始，到第一个*/结束。所以最后一个*/不在注释范围内，这种注释是不被允许的，否则会导致编译错误
void removeComment(int c); 
void in_comment(char deChar);
void echo_quote(int c);

/* remove all comments from a valid C program                   */
int main()
{
    int c, d;
    while ((c = getchar()) != EOF)
    {
        removeComment(c);
    }

    return 0;
}

/* rcomment: read each character, remove the comments           */
void removeComment(int c)
{
    int d;

    if (c == '/')
        if ((d = getchar()) == '*') //下一个输入的字符
            in_comment(d);          /* beginning comment            */
        else if (d == '/')
        {
            in_comment(d); /* another slash                */
            // removeComment(d);
        }
        else
        {
            putchar(c); /* not a comment                */
            putchar(d);
        }
    else if (c == '\'' || c == '"')
        echo_quote(c); /* quote begins                 */
    else
        putchar(c); /* not a comment                */
}

/* in_comment: inside of a valid comment                        */
// 在注释中 只读不输出(跳过)
void in_comment(char deChar)
{
    int c, d;
    c = getchar(); /* prev character                */
    d = getchar();
    if (deChar == '*')
    {                                   /* curr character                */
        while (c != deChar || d != '/') /* search for end                */
        {
            c = d;
            d = getchar();
        }
    }
    else
    {
        while (d != '\n') /* search for end                */
        {
            d = getchar();
        }

        putchar(d);
    }
}

/* echo_quote: echo character within quotes                     */
void echo_quote(int c)
{
    int d;

    putchar(c);
    while ((d = getchar()) != c)
    { /* search for end               */
        putchar(d);
        if (d == '\\')
            putchar(getchar()); /* ignore escape seq            */
    }
    putchar(d);
}

