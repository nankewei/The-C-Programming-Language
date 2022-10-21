// 编写一个函数invert(x, p, n)，该函数返回对x执行下列操作后的结果值：将x中从第p位开始的n个（二进制）位求反（即1变0,0变1），x的其余各位保持不变。
#include <stdio.h>

unsigned int invert(unsigned int x, int p, int n)
{
    return x ^ (~(~0 << n) << (p + 1 - n));
}
int main()
{
    printf("0x%x\n", setbits(0xF, 3, 2, 0x10));
}
