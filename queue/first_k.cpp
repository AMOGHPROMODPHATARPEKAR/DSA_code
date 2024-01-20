#include <bits/stdc++.h>
using namespace std;
vector<int> printFirstNegativeInteger(int A[],
                                             int N, int K)
{

    deque< int> dq;
    vector<int> ans;

    // process first k window
    for (int i = 0; i < K; i++)
    {
        if (A[i] < 0)
        {
            dq.push_back(i);
        }
    }
    // store answer of first k window
    if (dq.size() > 0)
    {
        ans.push_back(A[dq.front()]);
    }
    else
    {
        ans.push_back(0);
    }

    // process remaining

    for (int i = K; i < N; i++)
    {
        // removal
        if (!dq.empty() && i - dq.front() >= K)
        {
            dq.pop_front();
        }
        // addidtion
        if (A[i] < 0)
        {
            dq.push_back(i);
        }

        if (dq.size() > 0)
        {
            ans.push_back(A[dq.front()]);
        }
        else
        {
            ans.push_back(0);
        }
    }

    return ans;
}

int main()
{
   
    int a[] = {-8,2,6,-5,-10};
    vector<int> ans = printFirstNegativeInteger(a,5,2);
for(int i=0;i<ans.size();i++)
{
    cout<<ans[i]<<" ";
}
}