#include <stdio.h>
void naturalLog(double *, int accuracy); // Prototype of function, to be used later.
int main()
{
    double l; // Variable which stores the number whose log is to be calculated.
    int intervals; // Stores the value of number of intervals.
    printf("Enter the number to calculate natural log and even number of intervals with space between the two.\n");
    scanf("%lf %d", &l, &intervals);
    if (l < 0)
    {
        printf("log is not defined for negative numbers\n");
        return 0; // If users enters a negative number than function returns zero value and program gets terminated.
    }
    else
        naturalLog(&l, intervals);
    printf("ans is %lf\n", l); // This print statement prints required answer because it's contents has been modified by function.
    return (0);
}

void naturalLog(double *y, int n)
{
    int i;
    double h = (*y - 1) / n;
    double w = (1 + h);
    double store = 0.0;
    int toggle = 1;
    // In these for loop if and else statements are used alternatively for the terms multiplied 4 and 2 respectively 
    for (i = 1; i < (n); i++)
    {
        if (toggle)
        {
            store = store + 4 * (1 / w);
            toggle--;
        }
        else
        {
            store = store + 2 * (1 / w);
            toggle++;
        }
        w = w + h;
    }
    store = (h / 3.0) * (store + 1 + (1 / (*y))); // Here remaining first and last term is added separatly.
    *y = store; // Result of whole computation is stored in the memory address of variable l.
}
