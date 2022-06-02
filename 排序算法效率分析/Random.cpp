#include<iostream>
#include<random>
#include<ctime>
#include"MySort.h"

void Random(int a[])
{
srand((unsigned)time(NULL));

for(int i=0;i<N;i++)
{
 a[i]=rand();
}

}
