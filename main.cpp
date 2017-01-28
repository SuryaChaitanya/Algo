#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        {
        int x;
        cin>>x;
        if(x<38)
            cout<<x<<endl;
        else{
            if((x%10>=3 && x%10<5) || (x%10>7 && x%10<=9))
                if(x%10>5)
                cout<<x+(10-x%10)<<endl;
                else
                cout<<x+(5-x%10)<<endl;
            else cout<<x<<endl;
        }
    }
    return 0;
}
