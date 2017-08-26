#include<iostream>
#include<vector>
//--------------------------------------- complete
using namespace std;
int count=0;
vector <int> adj[10];
vector <bool> visited(10,false);
void Dfs(int s)
{
    visited[s]=true;

  cout<<s<<"->";

    for(int i=0;i<adj[s].size();i++)
    {
        if(visited[adj[s][i]]==false)
         {
              Dfs(adj[s][i]);
                //count++;
         }

    }

}



int main()
{
    int u,v,node,edge,s;
    cout<<"\nenter no of node ";
    cin>>node;
    cout<<"\nenter no of edge ";
    cin>>edge;
    for(int i=0;i<edge;i++)
    {
        cout<<"\nenter path from : ";
        cin>>u;
        cout<<"\nto : ";
        cin>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<"\n list representation : ";
    for(int i=1;i<=node;i++)
    {
        cout<<endl;
        for(int j=0;j<adj[i].size();j++)
        {
                cout<<adj[i][j]<<"  ";
        }
    }
    cout<<"\nenter source";
    cin>>s;
    cout<<"\n path is : " ;
     Dfs(s);



    return 0;
}
