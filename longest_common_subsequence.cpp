#include<iostream>
#include<string.h>
using namespace std;
int max(int a,int b){return (a<b)?b:a;}

int lcs(char *a,int m,char *b,int n)
{
    if (m<=0||n<=0)
        return 0;
    if (a[m]==b[n])
        return lcs(a,m-1,b,n-1)+1;
    else
        return max(lcs(a,m-1,b,n),lcs(a,m,b,n-1));
}
int main()
{
    char a[]={"abcdaf"};
    char b[]={"acbcf"};
    cout<<"\nlargest: "<<lcs(a,strlen(a),b,strlen(b));
}
