#include<iostream>
using namespace std;
//-------------------------correct--------------------------
const int MAX=1e4+5;
int v[MAX],w[MAX];
int knapsak(int c,int n)
{
    if (n==0||c==0)
        return 0;
    if(w[n]>c)
        return  knapsak(c,n-1);
    else return max(knapsak(c,n-1),knapsak(c-w[n],n-1)+v[n]);
}
int main()
{
    int n;
    cout<<"enter no of ele: ";
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cout<<"\nenter val of "<<i<<":";
        cin>>v[i];
        cout<<"\nenter wait of"<<i<<":";
        cin>>w[i];
    }
    int c;
    cout<<"\nenter capacity :";
    cin>>c;
    int m=knapsak(c,n);
    cout<<"max value"<<m;
    return 0;
}
