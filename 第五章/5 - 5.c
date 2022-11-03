
void strncpy(char *s, char *t, int n)
{
    while(n-- && *t)
        *s++ = *t++;
    *s = '\0';
}

void strncat(char *s, char *t, int n)
{
    void strncpy(char *s, char *t, int n);
    int strlen(char *);
    
    strncpy(s + strlen(s), t, n);
}


int strncmp(char *s, char *t, int n)
{
    for(; *s == *t; s++, t++)
        if(*s == '\0' || --n <= 0)
            return 0;
    return *s - *t;
}
