#include<bits/stdc++.h>
using namespace std;

vector<int> two_sum(vector<int>&v,int target)
{
    vector<int>ans;
    unordered_map<int,int>m;
    for(int i=0;i<v.size();i++)
    {
        auto it=m.find(target-v[i]);
        if(it==m.end())
        {
            m.insert(make_pair(v[i],i));
        }
        else if(it!=m.end())
        {
            ans.push_back(i);
            ans.push_back(it->second);
            break;
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}

int main()
{
    int n;
    std::cin >> n;
    vector<int>v;
    for(int i=0;i<n;i++)
    {
        int x;
        std::cin >> x;
        v.push_back(x);
    }
    std::cout << "Enter the target element " << endl;
    int target;
    cin >> target;
    vector<int>ans=two_sum(v,target);
    for(int i=0;i<v.size();i++)
    {
        std::cout << "v[" << i << "]" << "=" << v[i] << endl;
    }
    std::cout << endl << "The required indexes are" << endl;
    for(auto &value:ans)
    {
        std::cout << value << " ";
    }

}