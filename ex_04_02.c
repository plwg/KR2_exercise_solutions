#include <ctype.h>
#include <stdio.h>

double atof(char s[]);
int main()
{
    char s[] = "-1.24e3";
    printf("%s\n", s);
    printf("%f\n", atof(s));

    char t[] = "1.24e-3";
    printf("%s\n", t);
    printf("%f\n", atof(t));

    char o[] = "1.24";
    printf("%s\n", o);
    printf("%f\n", atof(o));

    return 0;
}

double atof(char s[])
{
    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++)
    {
        ;
    }

    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
    {
        i++;
    }
    for (val = 0.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
    }
    if (s[i] == '.')
    {
        i++;
    }
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    if (s[i] == 'e' || s[i] == 'E')
    {
        i++;
        int sci_sign, sci_power;

        if (s[i] == '-')
        {
            sci_sign = -1;
            i++;
        }
        else
        {
            sci_sign = 1;
        }

        for (sci_power = 0; isdigit(s[i]); i++)
        {
            sci_power = 10 * sci_power + (s[i] - '0');
        }

        for (; sci_power != 0; sci_power--)
        {
            if (sci_sign > 0)
            {
                power /= 10;
            }
            else
            {
                power *= 10;
            }
        }
    }

    return sign * val / power;
}
