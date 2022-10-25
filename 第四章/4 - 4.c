#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP
/* 怎么区分“-”是操作数还是符号。
在逆波兰表达式中，如果-后面紧跟一个数字，则“-”代表负号；如果“-”之后没有紧跟一个数字，则“-”代表减号。
例如：1 -1 + 中的“-”代表负号，1 1 -中的“-”代表减号。 */
#define NUMBER '0'
// 最大栈深
#define MAXDEPTH 100
// 栈顶
int stackIndex = 0;
// 栈 （数组实现）
double values[MAXDEPTH];

#define BUFSIZE 100
// 缓冲区
char buf[BUFSIZE];
// 缓冲区当前字符位置
int bufPosition = 0;

// getOperator 获取下一个字符或者数字运算符
int getOperator(char s[]);
// 入栈
void push(double num);
// 出栈
double pop(void);

int getChar(void);
void unGetChar(int c);
void clear(void)
{
    stackIndex = 0;
}
int main()
{
    int type;
    double op2;
    char s[MAXOP];
    // getOperator 获取下一个字符或者数字运算符
    while ((type = getOperator(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            // 把数字字符数组压进栈
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '*':
            push(pop() * pop());
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error:zero divisor\n");
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push(fmod(pop()) % op2);
            else
                printf("error: zero remainder\n");
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        case '?': /* print top element of the stack       */
            op2 = pop();
            printf("\t%.8g\n", op2);
            push(op2);
            break;
        case 'c': /* clear the stack                      */
            clear();
            break;
        case 'd': /* duplicate top elem. of the stack     */
            op2 = pop();
            push(op2);
            push(op2);
            break;
        case 's': /* swap the top two elements            */
            op1 = pop();
            op2 = pop();
            push(op1);
            push(op2);
            break;
        default:
            printf("unknown command %s \n", s);
            break;
        }
    }
    return 0;
}
int getOperator(char s[])
{
    int i, c;
    //跳过空格 、制表符
    while ((s[0] = c = getChar()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    // 不是数字或者 '.'
    if (!isdigit(c) && c != '.')
        return c;
    i = 0;
    if (c == '-')
    {
        if (isdigit(c = getch()) || c == '.')
        {
            s[++i] = c; /* negative number    */
        }
        else
        {
            if (c != EOF) /* minus sign        */
                ungetch(c);
            return '-';
        }
    }
    // 怎么区分“-”是操作数还是符号。
    if (isdigit(c))
    {
        while (isdigit(s[++i] = c = getChar()))
        {
            ;
        }
    }
    if (c == '.')
    {
        while (isdigit(s[++i] = c = getChar()))
        {
            ;
        }
    }
    s[i] = '\0';
    //
    if (c != EOF)
        unGetChar(c);
    return NUMBER;
}
// 入栈
void push(double num)
{
    if (stackIndex < MAXDEPTH)
        values[stackIndex++] = num;
    else
        printf("error\n");
}
//出栈
double pop(void)
{
    if (stackIndex > 0)
        return values[--stackIndex];
    else
        printf("empty!\n");
    return 0.0;
}
// 缓冲区 不为空，从缓冲区读取字符，当缓冲区为空时，直接getchar()从输入中读取字符
int getChar(void)
{
    return (bufPosition > 0) ? buf[--bufPosition] : getchar();
}
void unGetChar(int c)
{
    if (bufPosition >= BUFSIZE)
        printf("too much \n");
    else
        buf[bufPosition++] = c;
}
