#include <stdbool.h>
#include <stdio.h>

int main()
{
    bool to_trim = false;
    const int MAXLINE = 9999;
    int line[MAXLINE];
    int c;
    int index = 0;
    int start_trim_index = 0;
    int i;
    int bound;

    while (true)
    {
        c = getchar();

        if (index < MAXLINE)
        {
            line[index] = c;
        }

        if (c != '\n' && c != EOF)
        {
            if (!to_trim && (c == ' ' || c == '\t'))
            {
                to_trim = true;
                start_trim_index = index;
            }

            if (to_trim && c != ' ' && c != '\t')
            {
                to_trim = false;
                start_trim_index = 0;
            }
            index++;
        }
        else
        {

            if (index == 0)
            {
                to_trim = true;
            }

            if (to_trim)
            {
                bound = start_trim_index < MAXLINE ? start_trim_index : MAXLINE;

                for (i = 0; i < bound; i++)
                {
                    putchar(line[i]);
                }
                if (bound > 0)
                {
                    putchar('\n');
                }
            }
            else
            {
                for (i = 0; i <= index; i++)
                {
                    putchar(line[i]);
                }
            }

            for (i = 0; i <= index; i++)
            {
                line[i] = 0;
            }
            index = 0;
            start_trim_index = 0;
            to_trim = false;
        }
        if (c == EOF)
        {
            break;
        }
    }

    return 0;
}
