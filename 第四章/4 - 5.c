#include <stdio.h>
#include <string.h>     
#include <math.h>            /* for atof()     */
 
#define MAXOP       100     /* max size of operand or operator */
#define NUMBER      '0'     /* signal that a number was found   */
#define NAME        'n'     /* signal that a name was found     */
 
int getop(char []);
void push(double);
double pop(void);
void mathfnc(char []);
 
/* reverse Polish calculator                                     */
int main()
{
    int type;
    double op2;
    char s[MAXOP];
    
    while((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case NAME:
            mathfnc(s);
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if(op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}
 
/* mathfnc: check string s for supported math function          */
void mathfnc(char s[])
{
    double op2;
    
    if(strcmp(s, "sin") == 0)
        push(sin(pop()));
    else if(strcmp(s, "cos") == 0)
        push(cos(pop()));
    else if(strcmp(s, "exp") == 0)
        push(exp(pop()));
    else if(strcmp(s, "pow") == 0)
    {
        op2 = pop();
        push(pow(pop(), sp2));
    }
    else
        printf("error: %s not supported\n", s);
}

#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
#define NUMBER      '0'     /* signal that a number was found   */
#define NAME        'n'     /* signal that a name was found     */
 
int getch(void);
void ungetch(int);
/* getop: get next operator, numbric operand, or math fnc       */
int getop(char s[])
{
    int i, c;
    
    while((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    i = 0;
    if(ispower(c))      /* command or NAME                      */
    {
        while(islower(s[++i] = c = getch()));
        s[i] = '\0';
        if(c != EOF)
            ungetch(c);     /* went one char too far            */
        if(strlen(s) > 1)
            return NAME;    /* >1 char; it is NAME              */
        else
            return c;       /* it may be a command              */
    }
    if(!isdigit(c) && c != '.')
        return c;           /* not a number                     */
    i = 0;
    if(isdigit(c))          /* collect integer part             */
        while(isdigit(s[++i] = c = getch()));
        
    if(c == '.')            /* collect fraction part            */
        while(isdigit(s[++i] = c = getch()));
    
    s[i] = '\0';
    if(c != EOF)
        ungetch(c);
    return NUMBER;
}
