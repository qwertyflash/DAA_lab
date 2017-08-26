#include<iostream>
using namespace std;
//correct
int max(int a,int b)
{
    return (a>b)?a:b;
}
int knapsak(int w, int a[5][2],int n)
{
    if (n==0||w==0)
        return 0;
    if(a[n][1]>w)
        return  knapsak(w,a,n-1);
    else return max(knapsak(w,a,n-1),knapsak(w-a[n][1],a,n-1)+a[n][0]);
}
int main()
{
    int a[5][2];
    for(int i=1;i<=5;i++)
    {
        cout<<"\nenter val of "<<i<<":";
        cin>>a[i][0];
        cout<<"\nenter wait of"<<i<<":";
        cin>>a[i][1];
    }
    int w;
    cout<<"\nenter capacity :";
    cin>>w;
    int m=knapsak(w,a,5);
    cout<<"max value"<<m;
    return 0;
}
