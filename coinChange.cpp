#include<iostream>
using namespace std;

int minCoins(int n,int coin[],int V)
{
    if (V == 0) return 0;
    int res = INT_MAX;
   for (int i=1; i<=n; i++)
   {
     if (coin[i] <= V)
     {
         int sub_res = minCoins(n,coin, V-coin[i]);
        if (sub_res + 1 < res)
            res = sub_res + 1;
     }
   }
   return res;
}
int main()
{
    int n;
    cout<<"\nenter no of coin: ";
    cin>>n;
    int coin[n+1];
    for(int i=1;i<=n;i++)
        cin>>coin[i];
    int V;
    cout<<"\nenter value";
    cin>>V;
    cout<<"\nmin no of coin need: "<<minCoins(n,coin,V);
}
