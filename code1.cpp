#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        if(x==y)
        {
            cout<<-1<<endl;
        }
        else if(x < y)
        {
            cout<<2<<endl;
        }
        else
        {
            int remSteps = y - 1;
            if(remSteps == 0)
                cout<<-1<<endl;
            else if((x-remSteps) < y)
                cout<<-1<<endl;
            else
                cout<<3<<endl;
        }

    }

}
