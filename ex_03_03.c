#include <ctype.h>
#include <stdio.h>

int is_expandable(char a, char b);
void expand(char s[]);

int main()
{
    char test[] = "A-Z|a-z|z-a|0-9|9-0|Z-A";
    printf("%s\n", test);
    expand(test);

    char test2[] = "this is a normal string.";
    printf("%s\n", test2);
    expand(test2);

    char test3[] = "-A-F-S-Z";
    printf("%s\n", test3);
    expand(test3);

    char test4[] = "a-z0-9";
    printf("%s\n", test4);
    expand(test4);

    char test5[] = "-a-z-";
    printf("%s\n", test5);
    expand(test5);

    char test6[] = "a-l-d";
    printf("%s\n", test6);
    expand(test6);

    char test7[] = "a-L-d";
    printf("%s\n", test7);
    expand(test7);

    char test8[] = "a-e-i-o-u-U-O-I-E-A";
    printf("%s\n", test8);
    expand(test8);

    return 0;
}

int is_expandable(char a, char b)
{

    return (islower(a) && islower(b)) || (isupper(a) && isupper(b)) || (isdigit(a) && isdigit(b));
}

void expand(char s[])
{
    int direction;
    int i, j;
    int end_with_expansion = 0;
    for (i = 0; s[i + 2] != '\0';)
    {
        const int start = i;
        int end = i + 2;
        int to_expand = 0;

        for (; is_expandable(s[start], s[end]) && s[end - 1] == '-'; end += 2)
        {
            to_expand = 1;
        }
        if (to_expand)
        {
            end -= 2;
            direction = (s[start] <= s[end]) ? 1 : -1;
            j = s[start];
            do
            {
                putchar(j);
                j += direction;
            } while (j != s[end] + direction);

            if (s[i + end - start + 1] == '\0')
            {
                end_with_expansion = 1;
                break;
            }
            else
            {
                i += end - start + 1;
            }
        }
        else
        {
            putchar(s[i]);
            i++;
        }
    }
    if (!end_with_expansion)
    {
        putchar(s[i]);
        i++;
        putchar(s[i]);
    }
    putchar('\n');
}
