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
            int remSteps = x - y;
            if(remSteps >= 2 && y >=2)
                cout<<3<<endl;
            else
                cout<<-1<<endl;
        }

    }

}
