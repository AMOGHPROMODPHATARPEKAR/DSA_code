  #include<iostream>
  #include<vector>
using namespace std;
int main()
{
    int a1[5]={1,2,2,3,4};
    int a2[4]={2,3,5};
    int i=0,j=0;
    vector<int>ans;
   while(i<5 &&j<4)
   {
    if(a1[i]==a2[j])
    {
        ans.push_back(a1[i]);
        i++;
        j++;
    }
    else if(a1[i]<a2[j]){
        i++;
    }
    else{
        j++;
    }
   }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }

}