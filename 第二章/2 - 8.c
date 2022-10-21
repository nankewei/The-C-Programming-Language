#include <stdio.h>
// 编写一个函数rightrot(x, n)，该函数返回将x循环右移（即从最右端移出的位将从最左端移入）n（二进制）位后所得到的值。
/* rightrot: rotate x to the right by n positions   */
unsigned int rightrot(unsigned int x, int n)
{
    int wordlength(void);
    int rbit; /* rightmost bit                    */

    while (n-- > 0)
    {
        rbit = (x & 1) << (wordlength() - 1);
        x = x >> 1;   /* shift x 1 position right         */
        x = x | rbit; /* complete one rotation            */
    }
    return x;
}
