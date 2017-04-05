#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;

int cost[10][10],i,j,k,n,m,c,visit,visited[10],count,count1,vst,p;
int main()
{
    int dup1,dup2;
    cout<<"Enter no of vertices";
    cin>>n;
    cout<<"Enter no of edges";
    cin>>m;
    cout<<"EDGE Cost";
    for(int k=1;k<=m;k++)
    {
        cin>>i>>j>>c;
       cost[i][j]=c;
        cost[j][i]=c;

    }
    for(int i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        if(cost[i][j]==0)
        cost[i][j]=31999;
    visit=1;
    while(visit<n)
    {
      int  v=31999;
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            if(cost[i][j]!=31999&&cost[i][j]<v&&cost[i][j]!=-1)
        {
            int count=0;
            for(p=1;p<=n;p++)
            {
                if(visited[p]==i||visited[p]==j)
                    count++;
            }
            if(count>=2)
            {
                for(p=1;p<=n;p++)
                    if(cost[i][p]!=31999&&p!=j)
                    dup1=p;
                for(p=1;p<=n;p++)
                    if(cost[j][p]!=31999&&p!=i)
                    dup2=p;
                if(cost[dup1][dup2]==-1)
                    continue;
            }
            int l=i;
            int k=j;
            v=cost[i][j];
        cout<<"edge from" <<l<<"-->"<<k;
        cost[l][k]=-1;
        cost[k][l]=-1;
        visit++;
        int count1 = 0;
        int count2= 0;
        for(i=1;i<=n;i++)
        {
            if(visited[i]==l)
                count1++;
            if (visited[i]==k)
                count1++;
        }
        if (count1==0)
            visited[++vst]=1;
        if (count2==0)
            visited[++vst]=k;
    }

}
}

