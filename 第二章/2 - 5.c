
#include <stdio.h>
 
/* any: return the first location in s1 where any char from s2 occurs      */
int any(const char s1[], const char s2[])
{
    int i, j;
    
    for(i = 0; s1[i] != '\0'; i++)
    {
        for(j = 0; s2[j] != '\0'; j++)
        {
            if(s1[i] == s2[j])          /* match found2                     */
                return i;               /* location first match             */
        }
    }
    return -1;                          /* otherwise, no match              */
}
 
int main()
{
    printf("%d\n", any("abcd", "a"));
    printf("%d\n", any("abcd", "d"));
    printf("%d\n", any("abcd", "bc"));
    printf("%d\n", any("abcd", "ef"));
}
