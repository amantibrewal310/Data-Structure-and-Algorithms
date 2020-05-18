#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int, string> a, pair<int, string> b) {
    if (a.first != b.first)
        return a.first < b.first;
    else
        return 1;
}
string arrangeWords(string text) {
    vector<pair<int, string>> ans;
    string s = "";
    for(int i = 0; i < text.length(); i++) {
        if(text[i] == ' ') {
            // cout << s << endl << endl;
            ans.push_back(make_pair(s.length(), s));
            s = "";
            continue;
        }
        s += text[i];
        if(i == 0)
            s[0] = tolower(s[0]);
        // cout << s << endl;
    }
    ans.push_back(make_pair(s.length(), s));

    cout << ans.size();
    for(int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    sort(ans.begin(), ans.end(), cmp);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    string res = "";
    for(int i = 0; i < ans.size(); i++) {
        if(i == 0) {
            res += ans[i].second;
            res[0] = toupper(res[0]);
        }
        else {
            res += ans[i].second;
        }
        res += " ";
    }
    return res;
    
}
// Jlhvvd wfwnphmxoa qcuucx qsvqskq cqwfypww dyphntfz hkbwx xmwohi qvzegb ubogo sbdfmnyeim tuqppyipb llwzeug hrsaebveez aszqnvruhr xqpqd ipwbapd mlghuuwvec xpefyglstj dkvhhgecd kry

    signed
    main()
{
    string s;
    getline(cin, s);
    cout << s << endl;
    string res = arrangeWords(s);
    cout << res << endl;
}