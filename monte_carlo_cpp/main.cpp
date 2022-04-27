#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <cmath>

double rnd();

double function (double x);

void Monte_Carlo_1 (long* s);
void Monte_Carlo_2 (long* d);
void Monte_Carlo_3 (double x, long* f);

int main()
{
    double x;
    long max = 5, n = 0, s = 0, d = 0, f = 0;
    printf("\n*** Integralas ( I - 0.5 ): Monte Karlo metodas ***\n");
    printf("\nTikslus rezultatas = 0.0250 \n \n");
    printf("Iter. \t I \t II \t III \n \n");

    for (int j=0; j < 13; j++)
    {
        for (int i = 0; i < max; i++)
        {
            Monte_Carlo_1(&s);
            Monte_Carlo_2(&d);
            Monte_Carlo_3(x,&f);
            n++;
        }
        printf("%6ld %7.4lf %7.4lf %7.4lf \n", max, (double)s / n - 0.5, (double)d / n - 0.5, f / n - 0.5);
        max *= 2;
    }
}

double rnd()
{
    return (double)rand() / ( RAND_MAX );
}

void Monte_Carlo_1 (long* s)
{
    double x = rnd();
    double y = rnd();
    if(y < function(x))
    {
        (*s)++;
    }
}

void Monte_Carlo_2 (long* d)
{
    (*d) += rnd();
}

void Monte_Carlo_3 (double x, long* f)
{
    x = sqrt(rnd());
    *f += (x / (1 + 0.3 * x * (1 - x)) / x);
}

double function (double x)
{
    return (x + 0.3 * x * x - 0.3 * x * x * x);
}