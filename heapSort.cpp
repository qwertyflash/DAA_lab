#include<iostream>
#include<math.h>

//complete------------
using namespace std;
const int MAX=1e4+5;
int a[MAX];

void max_heapify(int a[],int i,int n)
{
    int l=2*i,r=(2*i)+1,largest=i;
    if(l<=n&&a[l]>a[largest])
        largest=l;
    if(r<=n&&a[r]>a[largest])
        largest=r;
    if(largest!=i)
    {
        swap(a[i],a[largest]);
        max_heapify(a,largest,n);
    }
}
void heap_sort(int a[],int n)
{  // build heap
    for(int i=floor(n/2);i>=1;i--)
        max_heapify(a,i,n);
    //---------------------
    for(int i=n;i>=2;i--)
    {
        swap(a[1],a[i]);
        max_heapify(a,1,i-1);//dec size of heap
    }
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
           cin>>a[i];
    heap_sort(a,n);
    cout<<"\nsorted array: ";
    for(int i=1;i<=n;i++)
           cout<<a[i]<<"  " ;

    return 0;
}
