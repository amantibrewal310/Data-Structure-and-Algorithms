class Solution
{
public:
    unordered_map<string, bool> m;
    unordered_map<int, bool> dp;
    bool solve(string A, int l)
    {
        if (l >= A.length())
            return true;
        //
        if (dp.find(l) != dp.end())
            return false;
        string s;
        bool ans = false;
        for (int i = l; i < A.length(); i++)
        {
            s.push_back(A[i]);
            if (m.find(s) != m.end())
                ans = ans || solve(A, i + 1);
            if (ans)
                return ans;
        }
        dp[l] = false;
        return false;
    }

    bool wordBreak(string s, vector<string> &D)
    {
        m.clear();
        dp.clear();
        for (int i = 0; i < D.size(); i++)
            m[D[i]] = true;
        return solve(s, 0);
    }
};