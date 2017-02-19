#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    int a[n];
    
    int maxcount=0;
    int mincount=0;
    for(int i=0;i<n;i++)
    {
            cin>>a[i];
        static int max=a[0];
        static int min=a[0];
        if(a[i]>max)
            {
            maxcount++;
            max=a[i];
        }
            
        if(a[i]<min)
            {
            mincount++;
            min=a[i];
        }
        
    }
    cout<<maxcount<<" "<<mincount;
    return 0;
}

