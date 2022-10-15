#include <stdio.h>
// 编写一个程序，把较长的输入行“折”成短一些的两行或多行，折行的位置在输入行的第n列之前的最后一个非空格符之后。
// 要保证程序能智能地处理输入行很长以及在指定的列前没有空格或制表符的情况。
// 实际上 折行的位置在输入行的第n列之前的最后一个空格符之后。

#define THISPOSITON 10  //输入行的第n列
#define TABTOBLANK 8    //制表符转为空格的长度
char line[THISPOSITON]; /* 保存输入行 */
// 把tab拓展成空格
int expTab(int pos);
// 寻找输入行的第n列之前的最后一个空格符
int findBlnk(int pos);
// “折”短后的新行的开始位置
int newPositon(int pos);
// 打印“折”成短一些行
void printLine(int pos);
int main()
{
    int c, pos;
    pos = 0;
    while ((c = getchar()) != EOF)
    {
        line[pos] = c; //存储当前字符
        if (c == '\t') /* 拓展tab 符 */
            pos = expTab(pos);
        else if (c == '\n')
        {
            printLine(pos); /* 输出当前输入行 */
            pos = 0;        //重置pos
        }
        else if (++pos >= THISPOSITON) //输入行大于THISPOSITON则需要折断
        {
            pos = findBlnk(pos);
            printLine(pos);
            pos = newPositon(pos);
        }
    }
    return 0;
}
int expTab(int pos)
{
    line[pos] = ' '; /* tab is at least one blanks           */
    // pos % TABTOBLANK 确定输出的空格个数
    for (++pos; pos < THISPOSITON && pos % TABTOBLANK != 0; ++pos)
        line[pos] = ' ';
    if (pos < THISPOSITON) /* room left in current line            */
        return pos;
    else /* current line is full                 */
    {
        printLine(pos);
        return 0; /* reset current position               */
    }
}
int findBlnk(int pos)
{
    while (pos > 0 && line[pos] != ' ')
        --pos;
    if (pos == 0) /* no blanks in the line? 直接从THISPOSITON折断 */
        return THISPOSITON;
    else /* at least one blank                   */
        return pos + 1;
}
int newPositon(int pos)
{
    int i, j;

    if (pos <= 0 || pos >= THISPOSITON)
        return 0; /* nothing to rearrange                 */
    else
    {
        i = 0;
        for (j = pos; j < THISPOSITON; ++j)
        {
            line[i] = line[j];
            ++i;
        }
        return i; /* new position in line                 */
    }
}
void printLine(int pos)
{
    int i;
    // 打印pos之前的字符
    for (i = 0; i < pos; ++i)
        putchar(line[i]);
    if (pos > 0) /* any chars printed?                   */
        putchar('\n');
}
