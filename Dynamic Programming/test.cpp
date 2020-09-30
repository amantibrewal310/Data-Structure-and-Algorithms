class Solution
{
public:
    struct trie
    {
        trie *arr[26];
        bool end;
    };
    unordered_set<int> dp;
    void insert(trie *root, string &A)
    {
        trie *p = root;
        for (int i = 0; i < A.length(); i++)
        {
            int k = A[i] - 'a';
            if (!root->arr[k])
            {
                root->arr[k] = new trie;
                for (int i = 0; i < 26; i++)
                    root->arr[k]->arr[i] = NULL;
                root->arr[k]->end = false;
            }
            root = root->arr[k];
        }
        root->end = true;
    }

    bool solve(string &A, int i, trie *root)
    {
        if (i == A.length())
            return true;
        if (dp.find(i) != dp.end())
            return false;
        trie *p = root;

        while (i < A.length())
        {
            int k = A[i] - 'a';
            p = p->arr[k];
            if (p == NULL)
                return false;
            if (p->end)
            {
                if (solve(A, i + 1, root))
                    return true;
            }
            i++;
        }
        dp.insert(i);
        return false;
    }

    bool wordBreak(string s, vector<string> &dict)
    {
        trie *root = new trie;
        for (int i = 0; i < 26; i++)
            root->arr[i] = NULL;
        root->end = false;
        for (int i = 0; i < dict.size(); i++)
        {
            insert(root, dict[i]);
        }
        return solve(s, 0, root);
    }
};