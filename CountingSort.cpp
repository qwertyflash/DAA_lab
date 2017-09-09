#include<iostream>
using namespace std;

//count sort work for non negative values only
int main()
{
    int n;
    cout<<"\nenter no n=of inputs: ";
    cin>>n;
    int a[n+1],max=0;
    cout<<"\nenter array elements : ";
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>max)
            max=a[i];
    }
    int c[max+1]={0};
    for(int i=1;i<=n;i++)
       {
           c[a[i]]=c[a[i]]+1;
       }
    for(int i=1;i<=max;i++)
       {
           c[i]+=c[i-1];
       }
    int b[n+1];
    for(int i=n;i>=1;i--)
    {
        b[c[a[i]]]=a[i];
        c[a[i]]--;
    }
    cout<<"\nsorted array";
    for(int i=1;i<=n;i++)
        cout<<b[i]<<" ";

    return 0;
}
