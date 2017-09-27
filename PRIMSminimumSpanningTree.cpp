#include<iostream>
#include<vector>
#include<queue>

//---------------   complete--------------------------------
using namespace std;
//const int MAX=1e9+5;

int key[100];
int p[100];//parent
int a[100][100];//adjency matrix


int minKey(int key[], bool mstSet[],int n)
{

   int mini=INT_MAX, min_index;

   for (int v=1;v<=n;v++)
     if (mstSet[v]==false && key[v] < mini)
         mini=key[v],min_index = v;

   return min_index;
}
void prims(int n ,int s)//no of nodes and root node
{

    bool mstSet[n];
    for(int i=1;i<=n;i++)
    {
       mstSet[i]=false;
        key[i]=INT_MAX;
        p[i]=-1;
    }

    key[s]=0;
    p[s]=-1;

   for(int i=1;i<=n;i++)
    {
        int u = minKey(key, mstSet,n);
        mstSet[u]=true;

        for(int v=1;v<=n;v++)
        {
            if(a[u][v]!=0&&mstSet[v]==false&&a[u][v]<key[v])//for all v adjecent to u and in queue
                                            //and waight<key
            {
                p[v]=u;
                key[v]=a[u][v];
            }
        }
        cout<<u<<"->";

    }
}


int main()
{
    int n,e;
    cout<<"\nenter no of nodes";
    cin>>n;
    cout<<"\nenter no of edge";
    cin>>e;

     for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            a[i][j]=0;

    for(int i=1;i<=e;i++)
    {
        int u,v,w;
        cout<<"\nenter edge u,v: ";
        cin>>u>>v;
        cout<<"\nenter edge weight: ";
        cin>>w;
        a[u][v]=w;
        a[v][u]=w;
    }

     int s;
    cout<<"\nenter source node";
    cin>>s;
    cout<<"\nminimum spanning tree: ";
    prims(n,s);

    cout<<"\nedge          weight : \n";
    for(int i=1;i<=n;i++)
    {
        cout<<p[i]<<"->"<<i<<"   "<<a[p[i]][i]<<endl;

    }


return 0;
}
