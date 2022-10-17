enum loop {NO, YES};
enum loop okloop = YES;
// 在不使用&&或||的条件下写一个与上面的for循环语句等价的循环语句。 
i = 0;
while(okloop == YES)
{
    if(i >= lim - 1)            /* outside of valid range?      */
        okloop = NO;
    else if((c = getchar()) == '\n')
        okloop = NO;
    else if(c == EOF)
        okloop = NO;
    else
    {
        s[i] = c;
        ++i;
    }
}
