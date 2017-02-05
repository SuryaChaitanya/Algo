#include <iostream>

using namespace std;
int lmissionary;
    int lcannibal;
    int rmissionary;
    int rcannibal;
    int side=1;
void printStatement()
{
        cout<<"\n  LEFT BANK\t\t\t  RIGHT BANK";
        cout<<"\nMissionary-"<<lmissionary<<"\t\t\tMissionary-"<<rmissionary;
        cout<<"\n Cannibal-"<<lcannibal<<"\t\t\t Cannibal-"<<rcannibal;

}

int checkimpossible()
{
    if((rcannibal>rmissionary&&rmissionary>0)||(lcannibal>lmissionary && lmissionary>0))
       return 1;
    return 0;
}
void boat(int m, int c)
{
    if(side==1)
    {
        rmissionary-=m;
        rcannibal-=c;
        lmissionary+=m;
        lcannibal+=c;
    }
    else{
        lmissionary-=m;
        lcannibal-=c;
        rmissionary+=m;
        rcannibal+=c;
    }
    side=side*-1;
}



int main()
{

    //l and r stand for right and left of the river bank
    cout<<"Number of Missionary and cannibal : ";
    lmissionary=0;
    lcannibal=0;
    int n,m;

    cin>>n>>m;
    rmissionary=n;
    rcannibal=m;
    cout<<"--------ONLY 2 PERSON CAN TRAVEL ON THE BOAT-----";
    if(rmissionary!=rcannibal)
        cout<<"\n ---------GAME OVER----------";
    else{
            printStatement();
           lable: while(1)
            {
                int m,c;
                cout<<"\nEnter number of missionary and cannibal in the boat";
                if(side==1)
                    cout<<" Right to left of bank :";
                else
                    cout<<" Left to right of bank :";
                cin>>m>>c;
                if(m>=0&&m<=2 &&c>=0&&c<=2 && c+m<=2){
                    if(side==1)
                        if(m>rmissionary||c>rcannibal)
                        {
                            cout<<"\n\tImpossible move";
                            goto lable;
                        }
                    if(side==-1)
                        if(m>lmissionary||c>lcannibal)
                        {
                            cout<<"\n\tImpossible move";
                            goto lable;
                        }
                boat(m,c);
                printStatement();
            }
            else
            {
                cout<<"\n\tImpossible move";
                goto lable;
            }

        int r=checkimpossible();
        if(r==1)
        {cout<<"\n\n\t\t--------GAME OVER-------\n";
            break;}
        if(lcannibal==n && lmissionary==n){
        cout<<"-------GAME WON------";
        break;
        }

}
    }

    return 0;
}
