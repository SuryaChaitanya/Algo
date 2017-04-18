#include<iostream>

using namespace std;
int adj[15][15];
int cost(int stage, int node, int v ,int n[])
{
	if(stage==n[v-1])
		return 0;
	if(n[node]==n[v-1]-1)
		return adj[node][v-1];
	else
		{
			int min=9999;
			for(int i=0;i<v;i++)
			{
				if(adj[node][i]!=-1)
				{
					if(min> adj[node][i]+cost(stage+1,i,v,n))
						min=adj[node][i]+cost(stage+1,i,v,n);
				}
			}
			if(min !=9999)
				return min;
			else
				return 0;
		}
}
		

int main()
{
	int v;
	cin>>v;
	int n[v];
	//int adj[v][v];
	for(int i=0;i<v;i++)
	{	n[i]=0;
		for(int j=0;j<v;j++)
			adj[i][j]=-1;
	}
	for(int i=0;i<v*v;i++)
	{
		int from;
		int to;
		cout<<"From :: ";cin>>from;
		cout<<"To :: ";cin>>to;
		n[to]=n[from]+1;
		if(from ==-1 || to==-1)
			break;
		cout<<"Val :: ";cin>>adj[from][to];
		
			
		
	}
	/*for(int i=0;i<v;i++)
	{
	if(n[i]==0)
		{		cout<<"Enter stage of "<<i<<" = ";
			cin>>n[i];
		}
	}
		*/
	
	cout<<"The min cost of node 0 to node "<<v<<" is "<<cost(0,0,v,n);
	return 0;
}
