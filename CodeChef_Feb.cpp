    #include<iostream>
    using namespace std;
    int main()
    {
    	int t;

    	cin>>t;
    	int b[t];
    	for(int i=0;i<t;i++)
    	{
    		int n;
    		cin>>n;
    		int a[n]={-1};
    		//int count2=0;
    		//int count1=0;
    		int sum=0;
    		int flag=0;
    		for(int j=0;j<n;j++)
    		{
    			cin>>a[j];
    			if(a[j]==0)
    			{
    		//	    count2++;
    			    flag=1;
    			    sum+=1100;
    			}

    			if(a[j]==1 && flag==1)
                    sum+=100;

    		}

    		b[i]=sum;



    	}
    	for(int i=0;i<t;i++)
    	cout<<b[i]<<endl;

    	return 0;
    }
