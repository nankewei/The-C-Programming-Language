#include <stdio.h>
#include <math.h>            /* for atof()     */
 
#define MAXOP       100     /* max size of operand or operator */
#define NUMBER      '0'     /* signal that a number was found   */
 
int getop(char []);
void push(double);
double pop(void);
 
/* reverse Polish calculator                                     */
int main()
{
    int i, type var = 0;
    double op2, v;
    char s[MAXOP];
    double variable[26];
    
    for(i = 0; i < 26; i++)
        varible[i] = 0;
    
    while((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
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
        case '=':
            pop();
            if(var >= 'A' && var <= 'Z')
                variable[var - 'A'] = pop();
            else
                printf("error: no varible name \n");
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            if(type >= 'A' && type <= 'Z')
                push(varible[type - 'A']);
            else if(type == 'v')
                push(v)
            else
                printf("error: unknown command %s\n", s);
            break;
        }
        var = type;
    }
    return 0;
}
