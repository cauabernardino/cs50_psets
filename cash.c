#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float change;
    do
    {
        change = get_float("Change owed: ");
    }
    while (change < 0);

    int cents = round(change * 100);
    int coins = 0;
    do
    {
        if (cents >= 25)
        {
            cents = cents - 25;
            coins++;
        }
        else if (cents >= 10 && cents < 25)
        {
            cents = cents - 10;
            coins++;
        }
        else if (cents >= 5 && cents < 10)
        {
            cents = cents - 5;
            coins++;
        }
        else if (cents > 0 && cents < 5)
        {
            cents = cents - 1;
            coins++;
        }
    }
    while (cents > 0);

    printf("%i\n", coins);
}
