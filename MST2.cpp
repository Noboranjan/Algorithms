#include<iostream>
using namespace std;

#define SIZE 5


class MST
{
    int from;
    int to;
    int minwt;

public:
    void set(int a,int b,int c);
    void disp();
};
void MST :: set(int a,int b,int c)
{
    from=a;
    to=b;
    minwt=c;
}
void MST::disp()
{
    cout<<"\n"<<from<<"<--("<< minwt<<")-->"<<to;
}
class Graph
{
    int vertex[SIZE];
    int adjMat[SIZE][SIZE];
    int n;

public:
    Graph();
    void create();
    void disp();
    void prims();
};
Graph::Graph()
{
    n=0;
}
void Graph::disp()
{
    int i,j;
    for(i=0;i<n;i++)
    {
        cout<<"\n"<<vertex[i]<<" ";
        for(j=0;j<n;j++)
        {
            cout<<""<<adjMat[i][j];
        }
    }
}
void Graph::create()
{
    char ch;
    int i,j;

    n=0;

    cout<<"\n creating vertices ";
    do
    {
        cout<<"\n enter data for vertex ";
        cin>>vertex[n];
        n++;

        cout<<"\n create more vertices ";
        cin>>ch;
    }
    while(n< SIZE && ch=='y');

    cout<<"\n creating EDGES ";
    for(i=0;i<n;i++)
    {
        adjMat[i][i]=999;
        for(j=i+1;j<n;j++)
        {
            cout<<"\n is there an edge between ";
            cout<<vertex[i]<<" and "<<vertex[j];
            cin>>ch;
            if(ch=='y')
            {
                cout<<"\n enter distance: ";
                cin>>adjMat[i][j];
                adjMat[j][i]=adjMat[i][j];
            }
            else
            {
                adjMat[i][j]=999;
                adjMat[j][i]=999;
            }
        }
    }
}
void Graph::prims()
{
    int x,i,j,k,l,current;
    int flag;
    int visited[SIZE],v;
    int min;
    int to,from,wt;
    MST primsMST(SIZE);
    int mstindex = 0;
}
int main()
{
    Graph g;
    g.create();
    g.disp();
}
