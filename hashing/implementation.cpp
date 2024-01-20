#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> m;

    //insertion
    pair<string,int>p1 = make_pair("amogh",1);
    m.insert(p1);

    pair<string,int>p2("madan",2);
    m.insert(p2);

    m["love"] = 5;

    //update
    m["love"] = 3;

    //search
    cout<<m["amogh"]<<endl;
    cout<<m.at("madan")<<endl;
     
    // cout<<m.at("unknown")<<endl;
    cout<<m["unknown"]<<endl;

    //size
    cout<<m.size()<<endl;

    //to check presence
    cout<<m.count("amogh")<<endl;
    cout<<m.count("ii")<<endl;

    //erase
    m.erase("unknown");
    cout<<m.size()<<endl;

    //iterate

    unordered_map<string,int> :: iterator it = m.begin();

    while (it != m.end())
    {
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }
    

    }