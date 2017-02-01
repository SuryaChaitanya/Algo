#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;


int main() {

    int n,m;
    cin>>n>>m;
    char a[500][500];
    for(int i=0;i<n;i++)
        {
        scanf("%s",a[i]);
    }
    for(int i=0;i<n;i++)
        {
        printf("%s \n",a[i]);
    }
    int coun=0;
    int maxi=0;
    for(int i=0;i<n;i++)
        {
        for(int j=i+1;j<n;j++)
            {
                for(int k=0;k<m;k++)
                    if(a[i][k]=='1' || a[j][k]=='1' )
                        coun++;
                if(coun>maxi)
                    maxi=coun;

                coun=0;
                //cout<<coun;
        }

    }
    int count2=0;
    for(int i=0;i<n;i++)
        {
        for(int j=i+1;j<n;j++)
            {
                for(int k=0;k<m;k++)
                    if(a[i][k]=='1' || a[j][k]=='1' )
                        coun++;
                if(coun==maxi)
                        count2++;

                coun=0;
                //cout<<coun;
        }

    }
    cout<<endl;
    cout<<maxi<<endl<<count2;;

    return 0;
}
