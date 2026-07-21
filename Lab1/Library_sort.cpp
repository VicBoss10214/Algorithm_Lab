#include <bits/stdc++.h>
using namespace std;

bool comp(int a,int b)
{
    return a%10 <= b%10;
}

int main()
{
    vector <int> v = {5, 2, 9, 1, 5, 6};
    sort(v.begin(),v.end()); //ascending
    vector<int> va=v;
    sort(va.begin(),va.end(),greater<int>()); //descending
    for(auto i:v)
    {
        cout<<i<<" ";
    }

    cout<<endl;

    for(auto i:va)
    {
        cout<<i<<" ";
    }

    cout<<endl;

    vector<int> vs={15,56,3243,434,4544767,53524769};

    sort(vs.begin(),vs.end(),comp);

    for(auto i:vs)
    {
        cout<<i<<" ";
    }



}