#include <stdio.h>

void escape(char s[], char t[]);
void reverse_escape(char s[], char t[]);

int main()
{
    char source[] = "This\nis\nthe best of time;\n\tthis is the.\\worst of time.";
    char to[100];
    char toto[100];

    printf("%s", source);

    printf("\n\nEscaped\n");
    escape(source, to);
    printf("%s", to);

    printf("\n\nReverse-escaped\n");
    reverse_escape(to, toto);
    printf("%s", toto);

    return 0;
}

void escape(char s[], char t[])
{
    int i, j;
    for (i = j = 0; s[i] != '\0';)
    {
        switch (s[i])
        {
        case '\n':
            t[j] = '\\';
            t[++j] = 'n';
            break;
        case '\t':
            t[j] = '\\';
            t[++j] = 't';
            break;
        case '\\':
            t[j] = '\\';
            t[++j] = '\\';
            break;
        default:
            t[j] = s[i];
            break;
        }
        ++i;
        ++j;
    }
    t[j] = '\0';
}

void reverse_escape(char s[], char t[])
{
    int i, j;
    for (i = j = 0; s[i] != '\0';)
    {
        if (s[i] == '\\')
        {
            switch (s[i + 1])
            {
            case 't':
                t[j] = '\t';
                i += 2;
                break;
            case 'n':
                t[j] = '\n';
                i += 2;
                break;
            case '\\':
                t[j] = '\\';
                i += 2;
                break;
            default:
                t[j] = s[i];
                i++;
                break;
            }
            j++;
        }
        else
        {
            t[j++] = s[i++];
        }
    }
    t[j] = '\0';
}