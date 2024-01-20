  #include<iostream>
  #include<vector>
using namespace std;
int main()
{
    int a1[5]={1,2,2,3,4};
    int a2[4]={2,3,5};
    vector<int>ans;
    for(int i=0;i<5;i++)
    {
     for(int j=0;j<4;j++)
     { if(a1[i]<a2[j])
     {
        break;
     }
        if(a1[i]==a2[j])
        {
            ans.push_back(a2[j]);
            a2[j]=INT16_MIN;
            break;
        }
     }  
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }

}