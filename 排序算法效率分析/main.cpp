#include <iostream>
#include<cstdlib>
#include<random>
#include<ctime>
#include<cstring>
//保存文本的头文件
#include<fstream>

#include<iomanip>//设置输出格式

#include"MySort.h"

using namespace std;

const int N=1e6;

int len=1e4;

int S[N];//初始数组

int R[N];//进行排序的数组

int num,cnt=0;

clock_t start,over;

//生成随机数数组
void Random(int a[])
{
srand((unsigned)time(NULL));

for(int i=0;i<N;i++)
{
 a[i]=rand();
}

}

void txtwriter(int n,string name)
{

    string str="D:\\experimentalData\\",txtname="\\data000",lat=".txt";

    ofstream outfile;

    str+=name;

    int co =cnt;

    int tnt=7;
    while(co)
    {
        int tem=cnt%10;
        co/=10;
        txtname[tnt]=tem+'0';
        tnt--;
    }
    str+=txtname;
    str+=lat;
    outfile.open(str,ios::out);

    outfile<<"S数组"<<endl;


    for(int i=0;i<n;i++)
        outfile<<S[i]<<" ";

    outfile<<"R数组"<<endl;

    for(int i=0;i<n;i++)
        outfile<<R[i]<<" ";

  outfile.close();

}





int main()
{

int cont=1;
cout<<"start"<<endl;
cout<<"输入你要测试的次数"<<endl;
cin>>num;

Random(S);

memcpy(R,S,sizeof(S));



ofstream outFile;//写入csv文件，存储不同排序的时间



outFile.open("D:\\experimentalData\\data.csv", ios::out);//将实验结果储存在一个特定的文件夹内



outFile <<"数据规模"<<','<<"冒泡选择排序"<<','<<"直接插入算法" << ',' << "希尔排序" << ',' << "简单选择排序" <<','<<"快速排序"<<','<<"归并排序"<<','<<"堆排序"<<endl;

for( cnt=1;cnt<=num;cnt++)
{

outFile<<len<<',';


MySort mysort(len);

//cout<<"start"<<endl;


//1.冒泡排序
memcpy(R,S,sizeof(S));

outFile<<mysort.BubbleSort(R,len)<<',';

txtwriter(len,"冒泡排序");

//2.插入排序

memcpy(R,S,sizeof(S));

outFile<<mysort.InsertSort(R,len)<<',';

txtwriter(len,"插入排序");

//3.希尔排序
memcpy(R,S,sizeof(S));

outFile<<mysort.ShellSort(R,len)<<',';

txtwriter(len,"希尔排序");

//4.简单选择排序
memcpy(R,S,sizeof(S));

outFile<<mysort.selectSort(R,len)<<',';

txtwriter(len,"简单选择排序");

//for(int i=0;i<10;i++)cout<<R[i]<<" ";

//puts("");

//5.快速排序

memcpy(R,S,sizeof(S));

start = clock();

mysort.QuickSort(R,0,N-1);

over = clock();

if(mysort.judge(R))outFile<<(over-start)/1000<<',';
    else outFile<<"排序失败"<<',';

txtwriter(len,"快速排序");

//6.归并排序

memcpy(R,S,sizeof(S));


outFile<<mysort.mergeSort(R,len)<<',';

txtwriter(len,"归并排序");
//7.堆排序

memcpy(R,S,sizeof (S));

outFile<<mysort.heapSort(R,len)<<',';


outFile<<endl;

txtwriter(len,"堆排序");

len+=1e4;

printf("完成第%d次排序\n",cont++);
}
outFile.close();
cout<<"End"<<endl;
}
