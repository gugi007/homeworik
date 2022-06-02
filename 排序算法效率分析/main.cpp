#include <iostream>
#include<cstdlib>
#include<random>
#include<ctime>
#include<cstring>
//�����ı���ͷ�ļ�
#include<fstream>

#include<iomanip>//���������ʽ

#include"MySort.h"

using namespace std;

const int N=1e6;

int len=1e4;

int S[N];//��ʼ����

int R[N];//�������������

int num,cnt=0;

clock_t start,over;

//�������������
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

    outfile<<"S����"<<endl;


    for(int i=0;i<n;i++)
        outfile<<S[i]<<" ";

    outfile<<"R����"<<endl;

    for(int i=0;i<n;i++)
        outfile<<R[i]<<" ";

  outfile.close();

}





int main()
{

int cont=1;
cout<<"start"<<endl;
cout<<"������Ҫ���ԵĴ���"<<endl;
cin>>num;

Random(S);

memcpy(R,S,sizeof(S));



ofstream outFile;//д��csv�ļ����洢��ͬ�����ʱ��



outFile.open("D:\\experimentalData\\data.csv", ios::out);//��ʵ����������һ���ض����ļ�����



outFile <<"���ݹ�ģ"<<','<<"ð��ѡ������"<<','<<"ֱ�Ӳ����㷨" << ',' << "ϣ������" << ',' << "��ѡ������" <<','<<"��������"<<','<<"�鲢����"<<','<<"������"<<endl;

for( cnt=1;cnt<=num;cnt++)
{

outFile<<len<<',';


MySort mysort(len);

//cout<<"start"<<endl;


//1.ð������
memcpy(R,S,sizeof(S));

outFile<<mysort.BubbleSort(R,len)<<',';

txtwriter(len,"ð������");

//2.��������

memcpy(R,S,sizeof(S));

outFile<<mysort.InsertSort(R,len)<<',';

txtwriter(len,"��������");

//3.ϣ������
memcpy(R,S,sizeof(S));

outFile<<mysort.ShellSort(R,len)<<',';

txtwriter(len,"ϣ������");

//4.��ѡ������
memcpy(R,S,sizeof(S));

outFile<<mysort.selectSort(R,len)<<',';

txtwriter(len,"��ѡ������");

//for(int i=0;i<10;i++)cout<<R[i]<<" ";

//puts("");

//5.��������

memcpy(R,S,sizeof(S));

start = clock();

mysort.QuickSort(R,0,N-1);

over = clock();

if(mysort.judge(R))outFile<<(over-start)/1000<<',';
    else outFile<<"����ʧ��"<<',';

txtwriter(len,"��������");

//6.�鲢����

memcpy(R,S,sizeof(S));


outFile<<mysort.mergeSort(R,len)<<',';

txtwriter(len,"�鲢����");
//7.������

memcpy(R,S,sizeof (S));

outFile<<mysort.heapSort(R,len)<<',';


outFile<<endl;

txtwriter(len,"������");

len+=1e4;

printf("��ɵ�%d������\n",cont++);
}
outFile.close();
cout<<"End"<<endl;
}
