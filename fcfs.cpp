#include<bits/stdc++.h>

using namespace std;

int main()
{
	int remain=0, wait_time=0, sum_turnaround=0, smallest, i, time,endtime, sumwait=0;
	//int rt[10];
	
	cout<<"Enter number of processes :: ";
	int n;
	cin>>n;
	int wt[n], bt[n], at[n],rt[n];
	cout<<"Enter the burst time \n";
	for(i=0;i<n;i++)
	{
		cout<<"Enter the P["<<i+1<<"]  burst  time :: ";
		cin>>bt[i];
		
	}
	wt[0]=0;
	for(int i=0;i<n;i++)
	{
		wt[i]=0;
		for(int j=0;j<i;j++)
		{
			wt[i]+=bt[j];
		}
	}
	int tat[n];static float avgwt=0.0;static float avgtat=0.0;
	printf("\nProcess|Bursttime|Waittime|turnaroundtime\n");
	for(int i=0;i<n;i++)
	{
		tat[i]=bt[i]+wt[i];
		
		avgwt+=wt[i];
		
		avgtat+=tat[i];
		printf("\nP[%d]\t\t%d\t%d\t%d",i+1,bt[i],wt[i],tat[i]);
	}
	cout<<"\nAverage waiting time is    :: "<<avgwt/n;
	cout<<"\nAverage turnaround time is :: "<<avgtat/n;
	return 0;
	
	}
