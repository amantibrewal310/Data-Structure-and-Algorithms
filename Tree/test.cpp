#include<bits/stdc++.h>
using namespace std;
bool comparator(string s1, string s2)
{
    string s1s2 = s1 + s2;
    string s2s1 = s2 + s1;

    return s1s2.compare(s2s1) > 0 ? 1 : 0;
}

string Solution::largestNumber(const vector<int> &A)
{

    int i;
    vector<string> s;

    for (i = 0; i < A.size(); i++)
    {
        s.push_back(to_string(A[i]));
    }

    sort(s.begin(), s.end(), comparator);

    string ans = "";

    for (i = 0; i < A.size(); i++)
    {
        ans = ans + s[i];
    }

    int cnt = 0;

    for (i = 0; i < A.size(); i++)
    {
        if (A[i] == 0)
            cnt++;

        else
            break;
    }

    if (cnt == A.size())
        ans = "0";

    return ans;
}