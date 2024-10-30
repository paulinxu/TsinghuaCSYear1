#include <iostream>
#include <stdio.h>      /* printf */
#include <time.h>       /* clock_t, clock, CLOCKS_PER_SEC */
#include <math.h> 



using namespace std;

int main()
{
    clock_t t;
    t = clock();
    
    int n = 100000;
    int sum = 0;
    for (int i = 0 ; i < n ; i ++)
    {
        for (int  j = 0 ; j < n ; j ++)
        {
            sum ++;
        }
    }
    cout << sum << endl;


    t = clock() - t;
    printf ("It took me %d clicks (%f seconds).\n",t,((float)t)/CLOCKS_PER_SEC);

}