#include<iostream>
#include<algorithm>
#include<ctime>
#include<string>
#include"MySort.h"


MySort::MySort(int len)
{
MySort::len=len;

}

//�ж��Ƿ�ɹ��ĺ���
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
    //�������ڵ�ָ����ӽڵ�ָ��
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) { //���ӽڵ�ָ���ڷ�Χ�ڲ����Ƚ�
        if (son + 1 <= end && arr[son] < arr[son + 1]) //�ȱȽ������ӽڵ��С��ѡ������
            son++;
        if (arr[dad] > arr[son]) //������ڵ�����ӽڵ���������ϣ�ֱ����������
            return;
        else { //���򽻻����������ټ����ӽڵ����ڵ�Ƚ�
            std::swap(arr[dad], arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}



//��������
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

//ϣ������
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



//ð������
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



//��������
void MySort::QuickSort(int s[],int l,int r)
{

    if (l < r)
    {
        //Swap(s[l], s[(l + r) / 2]); //���м��������͵�һ��������
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while(i < j && s[j] >= x) // ���������ҵ�һ��С��x����
                j--;
            if(i < j)
                s[i++] = s[j];

            while(i < j && s[i] < x) // ���������ҵ�һ�����ڵ���x����
                i++;
            if(i < j)
                s[j--] = s[i];
        }
        s[i] = x;
        QuickSort(s, l, i - 1); // �ݹ����
        QuickSort(s, i + 1, r);
    }


}

//�鲢����
double MySort::mergeSort(int R[],int len)
{
    t_start = clock();

int* a = R;//��R[0]�׵�ַ����a
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


//��ѡ������
double MySort::selectSort(int R[],int len)
{
    t_start = clock();
    int tem;//��Ϊ�����Ǵ�1��ʼ��
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
//������
string  MySort::heapSort(int R[],int len)
{
        int t=0;
  do{
      t++;//����
        t_start = clock();

     //��ʼ����i�����һ�����ڵ㿪ʼ����
    for (int i = len / 2 - 1; i >= 0; i--)
        max_heapify(R, i, len - 1);
    //�Ƚ���һ��Ԫ�غ��Ѿ��źõ�Ԫ��ǰһλ���������ٴ��µ���(�յ�����Ԫ��֮ǰ��Ԫ��)��ֱ���������
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


