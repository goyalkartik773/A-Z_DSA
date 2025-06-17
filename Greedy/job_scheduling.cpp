#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class comparator
{
public:
    bool operator()(pair<int,int> a,pair<int,int> b)
    {
        int p1 = a.first;
        int p2 = b.first;
        return p1<p2;
    }
};
int job_scheduling(vector<int>& deadline,vector<int>& profit)
{
    int n = deadline.size();
    int max_deadline = INT_MIN;
    for(int i=0; i<n; i++)
    {
        if(max_deadline < deadline[i])
            max_deadline = deadline[i];
    }
    vector<int> assign_job(max_deadline,0);
    priority_queue<pair<int,int>,vector<pair<int,int>>,comparator> pq;
    for(int i=0; i<n; i++)
    {
        pq.push({profit[i],deadline[i]});
    }
    int ans = 0;
    while(pq.size()!=0)
    {
        int prof = pq.top().first;
        int dead = pq.top().second;
        pq.pop();
        for(int i=dead; i>=0; i--)
        {
            if(!assign_job[i])
            {
                assign_job[i]=1;
                ans+=prof;
                break;
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> profit= {20,15,10,5,1};
    vector<int> deadlines = {2,2,1,3,3};
    cout<<job_scheduling(deadlines,profit);

}
