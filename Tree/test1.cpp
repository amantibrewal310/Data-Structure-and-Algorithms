#include<bits/stdc++.h>
using namespace std;

bool cmp(string a, string b)
{
    string ab = a + b;
    string ba = b + a;

    return ab.compare(ba) > 0 ? 1 : 0;
}

string largestNumber(const vector<int> &A)
{

    vector<string> v;
    for (int i = 0; i < A.size(); i++)
    {
        v.push_back(to_string(A[i]));
    }

    sort(v.begin(), v.end(), cmp);
    string ans = "";
    for (int i = 0; i < v.size(); i++)
        ans += v[i];

    int i = 0;
    while (ans[i] == '0')
    {
        i++;
    }

    if (i == ans.length())
        ans = "0";

    return ans;
}