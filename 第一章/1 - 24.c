/*
    编写一个程序，查找C语言中的基本语法错误，如圆括号、方括号、花括号不配对等。
    要正确处理引号（包括单引号和双引号）、转义字符序列与注释。
    如果读者想把该程序编写成完全通用的程序，难度会比较大
*/
#include <stdio.h>
// 大括号 中括号 小括号
int brace, bracket, paren;
//--！ --！
void in_quote(int c);
void in_comment(char deChar);
void search(int c);

/* rudimentary syntax checker for C programs            */
int main()
{
    int c;
    extern int brace, bracket, paren;
    while ((c = getchar()) != EOF)
    {
        if (c == '/')
        {
            if ((c = getchar()) == '*' || (c = getchar()) == '/')
                in_comment(c); /* inside comment           */
            else
                search(c);
        }
        else if (c == '\'' || c == '"')
            in_quote(c); /* inside quote             */
        else
            search(c);
        if (brace < 0) /*output errors             */
        {
            printf("Unbalanced braces\n");
            brace = 0;
        }
        else if (bracket < 0)
        {
            printf("Unbalanced brackets\n");
            bracket = 0;
        }
        else if (paren < 0)
        {
            printf("Unbalanced parentheses\n");
            paren = 0;
        }
    }
    if (brace > 0) /* output errors                */
        printf("Unbalanced braces\n");
    if (bracket > 0)
        printf("Unbalanced brackets\n");
    if (paren > 0)
        printf("Unbalanced parentheses");
}

/* search: search for rudimentary syntax errors                         */
void search(int c)
{
    extern int brace, bracket, paren;

    if (c == '{')
        ++brace;
    else if (c == '}')
        --brace;
    else if (c == '[')
        ++bracket;
    else if (c == ']')
        --bracket;
    else if (c == '(')
        ++paren;
    else if (c == ')')
        --paren;
}

/* in_comment: inside of a valid comment                                */
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
/* in_quote: inside quote                                               */
void in_quote(int c)
{
    int d;

    while ((d = getchar()) != c) /* search end quote             */
        if (d == '\\')
            getchar(); /* ignore escape seq            */
}
