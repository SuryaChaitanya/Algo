#include <iostream>
#include<stack>
#include<queue>
#include <algorithm>
int mat[20][20];
using namespace std;
int visited[20]={0};
stack<int> s;
queue<int> q;
void addEdge(int a, int b)
{
    mat[a][b]=1;
}

void topologicalUtil(int mat[][20], int n, int node)
{
    visited[node]=1;
    for(int i=0;i<n;i++)
    {
        if(mat[node][i]==1 && visited[i]==0)
        {
            //topologicalUtil(mat,n,i);
        }

    }
    s.push(node);
}

void topologicalSort(int mat[][20], int n )
{

    for(int i=0;i<n;i++)
        if(visited[i]==0)
            topologicalUtil(mat,n,i);
    cout<<endl;
    while(!s.empty())
    {

        cout<<s.top()<<"   ";
        s.pop();
    }

}

int main()
{

    int a,b;
    a=0;
    int n=0;
    while(a!=-1)
    {
        cout<<"Enter the 2 Edges (-1 -1 to exit) :: ";
        cin>>a>>b;
        if(a==-1)
            continue;
        n++;
        addEdge(a,b);

    }
    int i,j;
    for(i=0;i<n;i++)
    {

        cout<<endl;
        for(int j=0;j<n;j++)
            cout<<mat[i][j]<<"  ";
    }

    sort
    cout<<endl;
    //topologicalSort(mat,n);
    int z[10];
    for(int i=0;i<10;i++)
    {
        cin>>z[i];

    }
    sort(z,z);

    for(int i=0;i<10;i++)
        cout<<z[i]<<"\t";

    return 0;
}


















