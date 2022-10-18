#include <stdio.h>
// 编写一个函数setbits(x, p, n, y)，该函数返回对x执行下列操作后的结果值：将x中从第p位开始的n个（二进制）位设置为y中最右边n位的值，x的其余各位保持不变。
/* setbits: set n bits of x at position p with bits of y                */
unsigned int setbits(unsigned int x, int p, int n, unsigned int y)
{

    return x & ~(~(~0 << n) << (p + 1 - n)) | (y & ~(~0 << n)) << (p + 1 - n);
}
int main()
{
    printf("0x%x\n", setbits(0xF, 3, 2, 0x10));
}
