#pragma once
#ifndef _MYSORT_H
#define _MYSORT_H

class MySort{
public:
    int len;
    clock_t t_start,over;

    string sr;

    MySort(int len);

    double InsertSort(int R[],int len);

    double ShellSort(int a[],int len);

    double BubbleSort(int R[],int len);

    void QuickSort(int R[],int l,int r);

    double mergeSort(int R[],int len);

    double selectSort(int R[],int len);

    string heapSort(int R[],int len);

    bool judge(int J[]);



};

#endif
