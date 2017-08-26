#include<iostream>
using namespace std;
//complete
// int mini=INT_MAX;
int f(int i,int j,int a[])
{
    if(i==j-1)
        return 0;
    int mini=INT_MAX;

    for(int k=i+1;k<j;k++)
    {
        int p=(f(i,k,a)+f(k+1,j,a)+(a[i]*a[k]*a[j]));
        if(p<mini)
            mini=p;

    }
    return mini;

}
int main()
{
    int n;
    cin>>n;
    int a[2*n];
    for(int i=0;i<2*n;i++)
        cin>>a[i];
    cout<<"min cost: "<<f(0,2*n-1,a);
    return 0;
}
