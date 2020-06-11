#include<bits/stdc++.h>
using namespace std;

vector<string> v;
void bitStrings(int *a, int size, int i)
{
    if (i == size)
    {
        string s = "";
        for (int i = 0; i < size; i++)
        {
            s += to_string(a[i]);
        }
        v.push_back(s);
        return;
    }
    // First assign "0" at the ith position and check rest of the permutations
    a[i] = 0;
    bitStrings(a, size, i + 1);
    // Now assign "1" at the ith position and check rest of the permutations
    a[i] = 1;
    bitStrings(a, size, i + 1);
}

bool hasAllCodes(string s, int k)
{
    int a[k];
    bitStrings(a, k, 0);
    for (int i = 0; i < v.size(); i++)
    {   
        bool flag = 0;
        for (int j = 0; j < s.length() - k + 1; j++)
        {
            string t = s.substr(j, k);
            cout << t << endl;
            if (v[i] == t)
            {   flag = 1;
                break;
            }
        }
        if(flag == 0)
            return false;
    }
    return true;
}

signed main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    cout << hasAllCodes(s, k) << endl;
}