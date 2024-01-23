#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> maxMeetings(int N, vector<int>& S, vector<int>& F) {
    vector<pair<int, int>> tmp;

    // Create a vector of pairs (finish time, meeting index)
    for (int i = 0; i < N; i++) {
        tmp.push_back(make_pair(F[i], i + 1));
    }

    // Sort the vector of pairs based on finish time
    sort(tmp.begin(), tmp.end());

    vector<int> ans;
    ans.push_back(tmp[0].second);
    int last = tmp[0].first;

    // Iterate through sorted pairs and select meetings
    for (int i = 1; i < N; i++) {
        if (S[tmp[i].second - 1] > last) {
            ans.push_back(tmp[i].second);
            last = tmp[i].first;
        }
    }

    // Sort the final result
    sort(ans.begin(), ans.end());
    return ans;
}
bool cmp(pair<int,int>a,pair<int,int>b)
{
    return a.second<b.second;
}

vector<int> maxMeeting(int N, vector<int>& S, vector<int>& F)
{
    vector<pair<int,int>>temp;
    for(int i=0;i<N;i++)
    {
        temp.push_back(make_pair(S[i],F[i]));
    }
    sort(temp.begin(),temp.end(),cmp);

    vector<int>ans;
    ans.push_back(1);
    int ansEnd = temp[0].second;

    for(int i=1;i<N;i++)
    {
        if(temp[i].first > ansEnd)
        {
            // count++;
            ans.push_back(i+1);
            ansEnd = temp[i].second;
        }
    }
    return ans;
}

int main() {
    int N = 6;
    vector<int> S = {1, 3, 0, 5, 8, 5};
    vector<int> F = {2, 4, 6, 7, 9, 9};

    vector<int> result = maxMeeting(N, S, F);

    cout << "Selected meetings: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;
    // cout<<"MAX meetings "<<maxMeeting(N,S,F);

    return 0;
}
