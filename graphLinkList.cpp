#include<iostream>
using namespace std;

struct node
{
  int data;
  struct node *next=NULL;

};

int main()
{
    int V;
    cout<<"\nenter no of nodes/vertex";
    cin>>V;
    struct node *a[V+1],*head;
    int j=1;
    for(int i=1;i<=V;i++)
    {
        a[i]=new node();
        head=a[i];
        a[i]->data=i;
       cout<<"Enter the nodes adjacent to "<<i<<" vertex or press -1 to stop"<<endl;
       while(j!=-1)
       {
           cin>>j;
           if(j==-1)
                break;
            head->next=new struct node();
            head=head->next;
            head->data=j;
       }
        j=1;
    }
    cout<<"\ngraph is: ";
    for(int i=1;i<=V;i++)
    {
        head=a[i];
        while(head!=NULL)
        {
            cout<<head->data<<"->";
            head=head->next;
        }
        cout<<endl;
    }
}
