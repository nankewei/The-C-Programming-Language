int strend(char *s, char *t)
{
    char *temp = t;
    while (*s)
        s++;
    while (*t)
        t++;
    while (t > temp)
        if (*s == *t)
            s--, t--;
        else
            return 0;
    if (t == temp && *s == *t && *s)
        return 1;
    else
        return 0;
}
