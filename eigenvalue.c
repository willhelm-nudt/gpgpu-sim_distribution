#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define M 3
#define epsion0 0.00000001
#define N 100000

void printMatrix(double a[][3],int m,int n);
void printVector(double a[],int m);
double dotVector(double a[],double b[],int m);
void dotMatrVect(double a[][3],double yk[],double uk1[],int m);
void unitVector(double a[],double yeta,int m);
double relaError(double lambda1,double lambda2);

int main(void)
{
    double a[M][M] = { { 6,-12,6},{-21,-3,24},{-12,-12,51}};
    double uk0[M]={2.0,1.0,6.0};
    double uk1[M]={0.0,0.0,0.0};
    double beta0=0.0;
    double beta1=0.0;
    double yita0=0.0;
    double epsion=0.0;
    printMatrix(a,M,M);
    printVector(uk0,M);
    int i=0;
    for(i=0;i<N;i++)
    {
        printVector(uk0,M);
        yita0 =sqrt(dotVector(uk0,uk0,M));
        unitVector(uk0,yita0,M);
        dotMatrVect(a,uk0,uk1,M);
        beta1=dotVector(uk0,uk1,M);
        if(i>0)
            printf("%lf",beta1);
        epsion = relaError(beta0,beta1);
        if(epsion<epsion0)
        {
            break;
        }
        else{
            int q;
            for(q=0;q<M;q++)
            {
                uk0[q]=uk1[q];
                uk1[q]=0.0;
            }
            beta0=beta1;
        }
    }
    system("pause");
}

void printMatrix(double a[][M],int m,int n)
{
    int i;
    for(i=0;i<m;i++)
    {
        int j;
        for(j=0;j<n;j++)
        {
            printf("%lf ",a[i][j]);
        }
    }
}

void printVector(double a[],int m)
{
    int i;
    for(i=0;i<m;i++)
        printf("%lf ",a[i]);
}

double dotVector(double a[],double b[],int m)
{
    double dotsum=0.0;
    int i;
    for(i=0;i<m;i++)
    {
        dotsum=dotsum+a[i]*b[i];
    }
    return(dotsum);
}

void dotMatrVect(double a[][M],double yk0[],double uk1[],int m)
{
    double a1,b,c;
    int i;
    for(i=0;i<m;i++)
    {
        uk1[i]=0;
        int j;
        for(j=0;j<m;j++)
        {
            uk1[i]=uk1[i]+a[i][j]*yk0[j];
            a1=a[i][j];
            b=yk0[j];
            c=uk1[i];
        }
    }
}

void unitVector(double a[],double yita,int m)
{
    int i;
    for(i=0;i<m;i++)
    {
        a[i]=a[i]/yita;
    }
}
double relaError(double beta1,double beta2)
{
    double epsion;
    epsion=fabs(beta2-beta1)/fabs(beta2);
    return epsion;
}