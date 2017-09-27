#include<iostream>
#include<vector>
#include<queue>

//---------------complete--------------------------------
using namespace std;
const int MAX=1e9+5;
char color[MAX];
int d[100];
int p[100];
int main()
{
    int n,e;
    cout<<"\nenter no of nodes";
    cin>>n;
    cout<<"\nenter no of edge";
    cin>>e;
    int a[n+1][n+1];
     for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            a[i][j]=0;

    for(int i=1;i<=e;i++)
    {
        int u,v,el;
        cout<<"\nenter edge u,v: ";
        cin>>u>>v;
        cout<<"\nenter edge length: ";
        cin>>el;
        a[u][v]=el;
        a[v][u]=el;
    }
//-------BFS CODE-----
    for(int i=1;i<=n;i++)
    {
        d[i]=INT_MAX;
        color[i]='w';//white color
        p[i]=0;

    }

    int s;
    cout<<"\nenter source node";
    cin>>s;


    d[s]=0;
    color[s]='g';
    queue <int > q;
    q.push(s);

    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(int v=1;v<=n;v++)
        {
            if(a[u][v]!=0&&color[v]=='w')//for all v adjecent to u and not visited
            {
                color[v]='g';//green
                p[v]=u;
                d[v]=d[u]+1;
                q.push(v);
            }
        }

        color[u]='b';//black
        cout<<u<<"->";

    }
//------print level of node--------
    for(int i=1;i<=n;i++)
    {
        cout<<"\nlevel of "<<i<<" = "<<d[i];

    }
return 0;
}
