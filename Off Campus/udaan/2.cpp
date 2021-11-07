#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

string f = "failure";
string s = "success";
string n = "none";

struct eve {
  int st;
  int du;
  int end;
  vector<string> ul;
  string date;  // yyyy-mm-dd
};

set<string> users;

//  user        date    index of events
map<string, map<string, vector<int>>> ma;
vector<struct eve> eveList;

void au(string u) {
  if (users.find(u) == users.end()) {
    users.insert(u);
    cout << s << endl;
  } else {
    cout << f << endl;
  }
}

bool isDate(string date) {
  int len = date.length();
  // YYYY-MM-DD
  if (len != 10) return false;
  if (date[4] != '-' or date[7] != '-') return false;

  try {
    int yy = stoi(date.substr(0, 4));
    int mm = stoi(date.substr(5, 2));
    int dd = stoi(date.substr(8));
    // cout<<yy<<" "<<mm<<" "<<dd<<endl;

    if (yy > 0) {
      if ((mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 ||
           mm == 12) &&
          (dd > 0 && dd <= 31)) {
        return true;
      } else if ((mm == 4 || mm == 6 || mm == 9 || mm == 11) && dd > 0 &&
                 dd <= 30)
        return true;
      else if (mm == 2) {
        if ((yy % 400 == 0 || (yy % 100 != 0 && yy % 4 == 0)) && dd > 0 &&
            dd <= 29)
          return true;
        else if (dd > 0 && dd <= 28)
          return true;
        else
          return false;
      } else {
        return false;
      }
    } else
      return false;
  } catch (exception &e) {
    return false;
  }
}

bool isNum(string st) {
  try {
    int num = stoi(st);
    return 1;
  } catch (exception &err) {
    return 0;
  }
}

bool isTime(string time) {
  try {
    int num = stoi(time);
    if (num >= 0 and num <= 1440) {
      return 1;
    }
    return 0;
  } catch (exception &err) {
    return 0;
  }
}

bool isDu(string time, string duration) {
  try {
    int st = stoi(time);
    int du = stoi(duration);
    if (st >= 0 and st <= 1440 and du >= 0 and st + du <= 1440) {
      return 1;
    }
    return 0;
  } catch (exception &err) {
    return 0;
  }
}

bool isUsersValid(vector<string> ul) {
  for (auto u : ul) {
    if (users.find(u) == users.end()) {
      return 0;
    }
  }
  return 1;
}

bool userAva(string u, string date, int st, int du) {
  auto eves = ma[u][date];
  for (int ind : eves) {
    auto eve = eveList[ind];

    if (eve.st <= st and eve.end > st) {
      return 0;
    } else if (eve.st <= st + du and st + du < eve.end) {
      return 0;
    }
  }
  return 1;
}

// add a new event to eveList and returns its index
int createEve(int st, int du, vector<string> ul, string date) {
  struct eve *ptr = new eve;
  ptr->date = date;
  ptr->st = st;
  ptr->end = du + st;
  ptr->ul = vector<string>();
  for (string u : ul) {
    (ptr->ul).push_back(u);
  }
  eveList.push_back(*ptr);
  return eveList.size() - 1;
}

void failValid() { cout << f << endl; }

void inp() {
  string str;
  getline(cin, str);
  stringstream ss(str);
  // ss<<eveStr;
  vector<string> vec;

  string tmp;
  while (ss >> tmp) {
    vec.push_back(tmp);
  }

  if (vec.size() == 0) {  // empty input string
    failValid();
    return;
  }

  if (vec[0] == "add-user") {
    // cout<<"Add User Called"<<endl;
    if (vec.size() != 2) {
      failValid();
      return;
    }

    string u = vec[1];
    au(u);
  } else if (vec[0] == "create-event") {
    if (vec.size() < 6) {
      failValid();
      return;
    }

    if (isDate(vec[1]) && isTime(vec[2]) && isDu(vec[2], vec[3]) &&
        isNum(vec[4])) {
      string date = vec[1];
      int st = stoi(vec[2]);
      int du = stoi(vec[3]);
      int num = stoi(vec[4]);

      vector<string> ul;
      for (int i = 5; i < vec.size(); i++) {
        ul.push_back(vec[i]);
      }

      if (ul.size() != num or isUsersValid(ul) == 0) {
        failValid();
        return;
      }

      bool isPos = 1;

      for (auto u : ul) {
        if (userAva(u, date, st, du)) {
          continue;
        } else {
          isPos = 0;
          break;
        }
      }

      if (isPos) {
        int ind = createEve(st, du, ul, date);
        for (auto u : ul) {
          ma[u][date].push_back(ind);
        }
        cout << s << endl;
      } else {
        failValid();
        return;
      }
    } else {
      failValid();
      return;
    }
  } else if (vec[0] == "show-event") {
    if (vec.size() != 3) {
      failValid();
      return;
    }
    string date = vec[1];
    string u = vec[2];
    if (isDate(vec[1]) && isUsersValid({u}) == 1) {
      // Do Stuff

      auto eves = ma[u][date];

      for (int ind : eves) {
        auto eve = eveList[ind];
        cout << eve.st << " " << eve.end << " ";
        for (auto u : eve.ul) {
          cout << u << " ";
        }
        cout << endl;
      }
    } else {
      failValid();
      return;
    }

  } else if (vec[0] == "suggest-slot") {
    if (vec.size() <= 7) {
      failValid();
      return;
    }

    if (isDate(vec[1]) && isTime(vec[2]) && isTime(vec[3]) &&
        isDu(vec[2], vec[4]) && isNum(vec[4])) {
      string date = vec[1];
      int rst = stoi(vec[2]);
      int rend = stoi(vec[3]);
      int du = stoi(vec[4]);
      int num = stoi(vec[5]);
      vector<string> ul;
      for (int i = 6; i < vec.size(); i++) {
        ul.push_back(vec[i]);
      }

      if (ul.size() != num or isUsersValid(ul) == 0) {
        failValid();
        return;
      }
      if (rend - rst < du) {
        cout << n << endl;
        return;
      }  // doubt
      // Do Stuff

      int mint[1440];
      for (int i = 0; i < 1440; i++) {
        mint[i] = num;
      }
      // mint[i] represent a minute starting from mint[i]:00 ending just before
      // mint[i]+1:00

      for (auto u : ul) {
        auto &eveInds = ma[u][date];
        for (int ind : eveInds) {
          int st = eveList[ind].st;
          int end = eveList[ind].end;
          for (int i = st; i < end; i++) {
            --mint[i];
          }
        }
      }

      // for(int i=rst;i<=rend-du;i++){
      // 	cout<<i<<" "<<mint[i]<<endl;
      // }

      bool isPos = 0;
      int usersCnt = num;
      int currDu = 0;
      int ans;
      for (int i = rst; i < rend; i++) {
        if (mint[i] == usersCnt) {
          ++currDu;
          if (currDu == du) {
            ans = i - du + 1;
            isPos = 1;
            break;
          }
        } else {
          currDu = 0;
        }
      }

      if (isPos) {
        cout << ans << endl;
      } else {
        cout << n << endl;
      }

    } else {
      failValid();
      return;
    }
  } else {
    cout << f << endl;
  }
}

void solve() {
  ma.clear();
  eveList.clear();
  int n;
  cin >> n;
  string tmp;
  getline(cin, tmp);
  while (--n >= 0) {
    inp();
  }

  // for(auto eve: eveList){
  // 	cout<<eve.st<<" "<<eve.du<<" "
  // }
}

signed main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif

  int t = 1;
  // cin>>t;

  while (--t >= 0) {
    solve();
  }

  return 0;
}