#include<iostream>
using namespace std;
//complete
int memo[1000];
int fibo(int n)
{
    int f;
   // for(int i=0;i<=n;i++)
 //   {
        if(memo[n]==n)
            return memo[n];
   // }
    else if(n==1||n==0)
    {
        f=n;
    }
    else
    {
        f= fibo(n-1)+fibo(n-2);
        memo[n]=f;
    }
    return f;



}

int main()
{

    int n;
    cin>>n;
  //  int memo[n+1];
    cout<<"fibo:"<<fibo(n);

return 0;
}
