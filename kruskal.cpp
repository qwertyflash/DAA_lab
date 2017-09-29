#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>

using namespace std;
const int MAX = 1e4 + 5;
int id[MAX],edges,nodes;
pair<long long,pair<int ,int> >p[MAX];
//-------------------- complete---------------------------------------------------------------------------------------

void makeSet()
{
    for(int i=0;i<MAX;i++)
        id[i]=i;

}

int findSet(int x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}


void Union(int x, int y)
{
        id[x] = id[y];
}


void kruskal(pair<long long,pair<int ,int> > p[])
{
    makeSet();
    for(int i=0;i<edges;i++)
    {
        int x=p[i].second.first;
        int y=p[i].second.second;
        if(findSet(x)!=findSet(y))
        {
            Union(findSet(x),findSet(y));
            cout<<p[i].second.first<<" --> "<<p[i].second.second<<" " ;
        }
    }
}


int main()
{
    int x,y;
    long long weight;
    cout<<"enter no of nodes and edges";
    cin>>nodes>>edges;
    for(int i=0;i<edges;i++)
    {
        cout<<"\nenter edge (x,y)and weight :";
        cin>>x>>y>>weight;
        p[i]=make_pair(weight,make_pair(x,y));
    }
    //list print
    cout<<"\ngraph";
    for(int i=0;i<edges;i++)
    {
        cout<<p[i].second.first<<" -> "<<p[i].second.second<<endl;
    }
    sort(p,p+edges);//sort according to weight
    cout<<"\n edge in kruskal: ";
    kruskal(p);


    return 0;
}


