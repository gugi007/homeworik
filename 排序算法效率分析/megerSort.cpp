#include<iostream>
#include<ctime>
#include"MySort.h"

double MySort::mergeSort(int R[],int len)
{
    t_start = clock();

int* a = R;//将R[0]首地址给了a
    int* b = (int*) malloc(len * sizeof(int));
    int seg, start;
    for (seg = 1; seg < len; seg += seg) {
        for (start = 0; start < len; start += seg + seg) {
            int low = start, mid = std::min(start + seg, len), high =std::min(start + seg + seg, len);
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;
            while (start1 < end1 && start2 < end2)
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            while (start1 < end1)
                b[k++] = a[start1++];
            while (start2 < end2)
                b[k++] = a[start2++];
        }
        int* temp = a;
        a = b;
        b = temp;
    }
    if (a != R) {
        int i;
        for (i = 0; i < len; i++)
            b[i] = a[i];
        b = a;
    }
     over = clock();
 free(b);
    if(judge(R))return (over*1.0-t_start*1.0)/1000;
    else return -1;





}
