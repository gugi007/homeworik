#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;

const int MAX_TIMES=100;//������д���

const double ESP=0.00001;//����������

double c_mis;//��ǰ���

int c_times;//��ǰ���д���

double H[11][11];//ϵ������

double X[110];//��������

double tem1[110];

double tem2[110];

double w[]={1.0,1.25,1.5};//���ų���

void fill_(int n)  // �������
{
    memset(X,0,sizeof X);

       for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                H[i][j]=1.0/(i+j-1)*1.0;


                             }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
                X[i]+=H[i][j];
        }
}

void jac(int n)
{

c_times=0;

c_mis=0;

memset(tem1,0,sizeof tem1);

memset(tem2,0,sizeof tem2);

do{

    for(int i=1;i<=n;i++)
    {
        tem2[i]=tem1[i];
        double sum=0;
        sum=X[i];

        for(int j=1;j<=n;j++)
        {
            if(j!=i)sum-=tem2[j]*H[i][j];

        }
        tem1[i]=sum/H[i][i];

        c_mis=max(c_mis,fabs(tem1[i]-tem2[i]));//��������

    }

}
while((c_times++<MAX_TIMES)&&(c_mis<ESP));

//������
for(int i=1;i<=n;i++)cout<<tem1[i]<<" ";

    puts("");

return ;

}




//sor���ɳڵ���
void sor(int n)
{
for(int i=0;i<3;i++)
{
    c_times=c_mis=0;

    memset(tem1,0,sizeof tem1);

    memset(tem2,0,sizeof tem2);


    double q=w[i];//���÷ųڳ���

    do{

       for(int j=1;j<=n;j++)
       {

           tem2[j]=X[j];

           for(int  k=1;k<=n;k++)
           {
               if(k<j)tem2[j]-=H[j][k]*tem2[k];
               else tem2[j]-=H[j][k]*tem1[j];
           }

           tem2[j]*=q;
           tem2[j]/=H[j][j];
           tem2[j]+=tem1[j];

           c_mis=max(c_mis,fabs(tem2[j]-tem1[j]));

       }

       for(int j=1;j<=n;j++)tem1[j]=tem2[j];


    }
    while((c_times<MAX_TIMES)&&(c_mis<ESP)) ;

    printf("��w=%.4lf\n",w[i]);
    for(int k=1;k<=n;k++)cout<<tem2[k]<<" ";

    puts("");


}

return ;
}

int main()
{
  int n;
  printf("������������Ҫ�ļ���Ľ���(����-1����������)��");
  while(~scanf("%d",&n))
  {
      fill_(n);
      if(n==-1)break;
      printf("jacobi�Ľ��Ϊ��\n");
      jac(n);
      printf("SOR��\n");
      sor(n);


  printf("������������Ҫ�ļ���Ľ���(����-1����������)��");
  }


  return 0;

}
