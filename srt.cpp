#include<bits/stdc++.h>

using namespace std;

int main()
{
	int remain=0,  smallest, i, time,endtime, sumwait=0;
	float wait_time=0.0, sum_turnaround=0.0;
	//int rt[10];
	
	cout<<"Enter number of processes :: ";
	int n;
	cin>>n;
	int wt[n], bt[n], at[n],rt[n];
	cout<<"Enter the burst time ";
	for(i=0;i<n;i++)
	{
		cout<<"\nenter the P["<<i+1<<"]  burst  time :: ";
		cin>>bt[i];
		cout<<"\nenter the P["<<i+1<<"] arrival time :: ";
		cin>>at[i];
		rt[i]=bt[i];
	}
	cout<<"\nProcess\tTurnaroundtime\tWaiting time";
	rt[9]=9999;
	remain=0;
	for(time=0; remain!=n; time++)
	{
		smallest=9;
		for(i=0;i<n;i++)
		{
			if(at[i]<=time && rt[i]<rt[smallest] && rt[i]>0)
				{
				smallest=i;
				}
		}			
			rt[smallest]--;
			if(rt[smallest]==0)
			{
				remain++;
				endtime=time+1;
				printf("\nP[%d]\t\t%d\t%d", smallest+1, endtime-at[smallest], endtime-bt[smallest]-at[smallest]);
				sumwait=(float)endtime-(float)bt[smallest]-(float)at[smallest];
				sum_turnaround+=(float)endtime-(float)at[smallest];
			}
		}
	
	cout<<"\n The average waiting time is    :: "<<sumwait/n;
	cout<<"\n The average turnaround time is :: "<<sum_turnaround/n;
	return 0;
}
