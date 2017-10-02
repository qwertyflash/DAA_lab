#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n+1],max=INT_MIN;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>max)
                max=a[i];
    }
//--------radix sort code-----

    for(int exp=1; max/exp>0; exp*=10)//no of pases
    {
            int c[10]={0}, b[n+1];
            for(int i=1;i<=n;i++)
                    c[(a[i]/exp)%10]++;
            for(int i=1;i<=9;i++)
                    c[i]+=c[i-1];

            for(int i=n;i>=1;i--)
            {
                b[c[(a[i]/exp)%10]]=a[i];
                c[(a[i]/exp)%10]--;
            }
            for(int i=1;i<=n;i++)
            {
                a[i]=b[i];
            }
    }
    cout<<"\nsorted array: ";
    for(int i=1;i<=n;i++)
            cout<<a[i]<<"-> ";
}
