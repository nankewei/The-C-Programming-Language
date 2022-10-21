// 编写一个函数escape(s,t)，将字符串t复制到字符串s中，并在复制过程中将换行符制表符等不可见字符分别转换为\n、\t等相应的可见的转义字符序列。
// 要求使用switch语句。再编写一个具有相反功能的函数，在复制过程中将转义字符序列转换为实际字符。
void escape(char s[], const char t[])
{
    int i, j;
    for (i = j = 0; t[j] != '\0'; j++)
    {
        switch (t[j])
        {
        case '\n':
            s[i++] = '\\';
            s[i++] = 'n';
            break;
        case '\t':
            s[i++] = '\\';
            s[i++] = 't';
            break;
        default:
            s[i++] = t[j];
            break;
        }
    }
    s[i] = '\0';
}
/* unescape: convert escape sequences into real characters    */
/*         while copying the string t to s                  */
void unescape(char s[], const char t[])
{
    int i, j;
    for (i = j = 0; t[i] != '\0'; i++)
    {
        if (t[i] != '\\')
            s[j++] = t[i];
        else /* it is a backslash    */
        {
            switch (t[++i])
            {
            case 'n':
                s[j++] = '\n'; /* newline              */
                break;
            case 't':
                s[j++] = '\t'; /* tab                  */
                break;
            default: /* all other chars      */
                s[j++] = '\\';
                s[j++] = t[i];
                break;
            }
        }
    }
    s[j] = '\0';
}
