#include<bits/stdc++.h>

using namespace std;

struct process
{
	int pno, c, a, f,arr;
};

int q[100];
int f=-1;
int r=-1;
double sum=0.0;
void insert(int item)
{
	if(f==-1)
	{
		f=r=0;
		q[r]=item;
	}
	else
	{
		r++;
		q[r]=item;
	}
}

int del()
{
	if(f<=r)
	{
		int temp;
		temp=q[f];
		f++;
		return temp;
	}
	else
	{
		return -1;
	}
	
}
int main()
{
	int t,n,T,i,cp=-1,temp,tq,q=0,min=1000;
	int count=0;
	//int sum=0;
	process p[100];
	T=0;
	cout<<"Enter the number of processes :: ";
	cin>>n;
	int wt[n], tat[n];
	float avwt=0, avtat=0;
	cout<<"\nEnter the arrival time and burst time :: "; 
	for(int i=0;i<n;i++)
	{
		cout<<"Enter the arrival time of P["<<i+1<<"] :: ";
		cin>>p[i].a;
		p[i].arr=p[i].a;
		if(min>p[i].a)
			min=p[i].a;
		p[i].pno=i+1;
		cout<<"Enter the burst time of   P["<<i+1<<"] :: ";
		cin>>p[i].c;
		T+=p[i].c;
	}
	
	cout<<"\n Enter the time quantum of the round robbin :: ";
	cin>>tq;
	
	q=0;
	cout<<"Process |   Execution time\n";
	for(t=min;t<=T+min; t++)
	{
		for(i=0;i<n;i++)
		{
			if(t==p[i].a)
			{
				insert(i);
				if(cp==-1)
				{
					cp=del();
					q=0;
				}
			}
		}
		
		if(p[cp].c<=0)
		{
			if(q==tq)
			{
				cout<<"  P["<<p[cp].pno<<"]\t|\t"<<tq<<" Sec\n";
				sum=sum+t-tq-p[cp].arr;
				p[cp].arr=t;
				
			}
			else
				{	
				cout<<"  P["<<p[cp].pno<<"]\t|\t"<<q<<" sec\n";
				sum=sum+t-q-p[cp].arr;
				p[cp].arr=t;
				}
			cp=del();
			q=0;
		}
		else if(q==tq && t!=0)
		{
			cout<<"  P["<<p[cp].pno<<"]\t|\t"<<tq<<" sec\n";
			sum=sum+t-tq-p[cp].arr;
				p[cp].arr=t;
			temp=cp;
			insert(temp);
			cp=del();
			q=0;
		}
		q++;
		p[cp].c--;
	}
	
	cout<<"\nAvg waiting time is  :: "<<sum/n;	
}

