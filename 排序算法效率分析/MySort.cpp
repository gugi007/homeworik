#include<iostream>
#include<algorithm>
#include<ctime>
#include<string>
#include"MySort.h"


MySort::MySort(int len)
{
MySort::len=len;

}

//判断是否成功的函数
bool MySort::judge(int J[])
{


for(int i=0;i<len-1;i++)
{
    if(J[i]>J[i+1]){

    return false;
    }
}
return true;
}

void max_heapify(int arr[], int start, int end) {
    //建立父节点指标和子节点指标
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) { //若子节点指标在范围内才做比较
        if (son + 1 <= end && arr[son] < arr[son + 1]) //先比较两个子节点大小，选择最大的
            son++;
        if (arr[dad] > arr[son]) //如果父节点大于子节点代表调整完毕，直接跳出函数
            return;
        else { //否则交换父子内容再继续子节点和孙节点比较
            std::swap(arr[dad], arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}



//插入排序
double  MySort::InsertSort(int R[],int len)
{

t_start =clock();

for(int i=0;i<len;i++)
{
int tem=R[i];
int j;
for( j=i-1;j>=0&&tem<R[j];j--)
{
    R[j+1]=R[j];
}
R[j+1]=tem;
}
over=clock();
if(judge(R))return (over-t_start)/1000;
else return -1;

}

//希尔排序
double MySort::ShellSort(int arr[],int len)
{
    t_start=clock();
int gap, i, j;
    int temp;
    for (gap = len >> 1; gap > 0; gap >>= 1){
        for (i = gap; i < len; i++) {
            temp = arr[i];
            for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
                arr[j + gap] = arr[j];
            arr[j + gap] = temp;
        }
    }

        over=clock();

    if(judge(arr))return (over*1.0-t_start*1.0)/1000;
    else return -1;

}



//冒泡排序
double MySort::BubbleSort(int R[],int len)
{
    t_start = clock();
for(int i=0;i<len;i++)
{
for(int j=i;j<len;j++)
{
    if(R[i]>R[j])std::swap(R[i],R[j]);
}
}

    over = clock();
    if(judge(R))return (over*1.0-t_start*1.0)/1000;
    else return -1;
}



//快速排序
void MySort::QuickSort(int s[],int l,int r)
{

    if (l < r)
    {
        //Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while(i < j && s[j] >= x) // 从右向左找第一个小于x的数
                j--;
            if(i < j)
                s[i++] = s[j];

            while(i < j && s[i] < x) // 从左向右找第一个大于等于x的数
                i++;
            if(i < j)
                s[j--] = s[i];
        }
        s[i] = x;
        QuickSort(s, l, i - 1); // 递归调用
        QuickSort(s, i + 1, r);
    }


}

//归并排序
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


//简单选择排序
double MySort::selectSort(int R[],int len)
{
    t_start = clock();
    int tem;//因为我们是从1开始的
    for(int i=0;i<len;i++){
            tem=i;
        for(int j=i;j<len;j++)
            if(R[j]<R[tem])tem=j;

        std::swap(R[i],R[tem]);
    }
    over = clock();

    if(judge(R))return (over-t_start)/1000;
    else return -1;

}
//堆排序
string  MySort::heapSort(int R[],int len)
{
        int t=0;
  do{
      t++;//计数
        t_start = clock();

     //初始化，i从最后一个父节点开始调整
    for (int i = len / 2 - 1; i >= 0; i--)
        max_heapify(R, i, len - 1);
    //先将第一个元素和已经排好的元素前一位做交换，再从新调整(刚调整的元素之前的元素)，直到排序完毕
    for (int i = len - 1; i > 0; i--) {
      std::swap(R[0], R[i]);
        max_heapify(R, 0, i - 1);
    }

    over = clock();


    }
    while(over-t_start>1000)
    double res=(over*1.0-t_start*1.0)/t/1000;


    if(judge(R))return to_string(res);
    else return "-1";


}


