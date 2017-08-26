#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int Maximum(int a[],int n){

int max=a[0],i;
for(i=1;i<n;i++){
    if(max<a[i])
        max=a[i];

}
cout<<"Max is: "<<max<<endl;
return max;
}

void CountingSort(int a[],int n,int digit,int b[]){
int i,c[10],l,k=digit-1;

k==0 ? (k=1,l=1) : (k=k,l=pow(10,k));

for(i=0;i<=9;i++){
    c[i]=0;
}
for(i=0;i<n;i++){
    c[(a[i]/l)%10]+=1;
}
for(i=1;i<=9;i++){
    c[i]=c[i]+c[i-1];
}
for(i=n-1;i>=0;i--){
    b[c[(a[i]/l)%10]-1]=a[i];
    c[(a[i]/l)%10]--;
}

for(i=0;i<n;i++){
    a[i]=b[i];
}

}

void RadixSort(int a[],int n){
int i,digit=0,b[n];

int max=Maximum(a,n);

while(max!=0){
    digit+=1;
    max=max/10;

}
cout<<"Max no. of digits= "<<digit<<endl;

for(i=1;i<=digit;i++){
    CountingSort(a,n,i,b);
}
cout<<"Sorted array is :"<<endl;
for(i=0;i<n;i++){
    cout<<b[i]<<" ";
}
}

int main(){

int i,n;
cout<<"Enter the total no of elements: "<<endl;
cin>>n;
int a[n];
cout<<"Enter the elements: "<<endl;
for(i=0;i<n;i++){
    cin>>a[i];
}

RadixSort(a,n);

return 0;
}
