#include <bits/stdc++.h>
using namespace std;

int lobo(vector<int>& v,int target)
{
    int left=0;
    int right=v.size()-1;
    int ans=v.size();

    while(left<=right)
    {
        int mid=(left+right)/2;

        if(v[mid]>=target)
        {
            ans=mid;
            right=mid-1;
        }
        else
        {
            left=mid+1;
        }
    }
    return ans;
}

int upbo(vector<int>& v,int target)
{
    int left=0;
    int right=v.size()-1;
    int ans=v.size();

    while(left<=right)
    {
        int mid=(left+right)/2;

        if(v[mid]<=target)
        {
            ans=mid;
            left=mid+1;
        }
        else
        {
            right=mid-1;
        }
    }
    return ans;
}

int another_way(vector<int>& v,int l,int m)
{
    auto L=lower_bound(v.begin(),v.end(),l);
    auto R=upper_bound(v.begin(),v.end(),m);
    return R-L;
}

int main()
{
    vector<int> v = {2, 3, 4, 10, 40,3,5,7,3};

    sort(v.begin(),v.end());

    int l,m;

    l=1;
    m=5;

    int k=upbo(v,m);
    int g=lobo(v,l);

    cout<<k-g+1;

    cout<<endl<<another_way(v,l,m)<<endl;
    
}