#include <bits/stdc++.h>
using namespace std;

const string ADD_USER = "add-user";
const string CREATE_EVENT = "create-event";
const string SHOW_EVENT = "show-event";
const string SUGGEST_SLOT = "suggest-slot";
const string SUCCESS = "success";
const string FAILURE = "failure";

struct Event {
  int start;
  int end;
  int duration;
  string date;
  vector<string> attendees;
};

set<string> userList;
vector<Event> eventList;
map<string, map<string, vector<int>>> userEventLog;

string registerUser(string user) {
  if (userList.find(user) == userList.end()) {
    userList.insert(user);
    return SUCCESS;
  }
  return FAILURE;
}

bool isLeapYear(int year) {
  return (((year % 4 == 0) and (year % 100 != 0)) || (year % 400 == 0));
}

bool validateDate(string date) {
  int len = date.length();
  if (len != 10) return false;
  if (date[4] != '-' or date[7] != '-') return false;

  try {
    int year = stoi(date.substr(0, 4));
    int month = stoi(date.substr(5, 2));
    int day = stoi(date.substr(8));

    if (month < 1 || month > 12) return false;
    if (day < 1 || day > 31) return false;

    if (month == 2) {
      if (isLeapYear(year)) return day <= 29;
      return day <= 28;
    }

    if (month == 4 || month == 6 || month == 9 || month == 11) return day <= 30;
    return true;

  } catch (exception &e) {
    return false;
  }
}

bool validateTime(string start, string duration) {
  try {
    int s = stoi(start);
    int du = stoi(duration);

    if (s + du >= 0 and s + du <= 1440) return true;
    return false;

  } catch (exception &e) {
    return false;
  }
}

bool validateNum(string num) {
  try {
    int n = stoi(num);
    return true;
  } catch (exception &e) {
    return false;
  }
}

bool validateUsers(vector<string> users, string num) {
  if (users.size() != stoi(num)) return false;
  for (auto user : users) {
    if (userList.find(user) == userList.end()) return false;
  }
  return true;
}

bool validateEventData(vector<string> data) {
  if (data.size() < 5) return false;
  string date, start, duration, numOfUser;
  vector<string> users;

  date = data[0];
  start = data[1];
  duration = data[2];
  numOfUser = data[3];

  for (int i = 4; i < data.size(); i++) {
    users.push_back(data[i]);
  }
  // cout << validateDate(date) << endl;
  // cout << validateTime(start, duration) << endl;
  // cout << validateNum(numOfUser) << endl;
  // cout << validateUsers(users, numOfUser) << endl;

  if (!validateDate(date) || !validateTime(start, duration) ||
      !validateNum(numOfUser) || !validateUsers(users, numOfUser)) {
    return false;
  }
  return true;
}

bool checkUserAvailability(vector<string> users, int start, string date,
                           int duration) {
  for (auto user : users) {
    vector<int> events = userEventLog[user][date];

    for (auto eventIdx : events) {
      Event event = eventList[eventIdx];
      // cout << start << endl;

      if (event.start <= start and start < event.end) return false;
      if (event.start <= start + duration and start + duration < event.end)
        return false;
    }
  }

  return true;
}

string createEvent(string date, int start, int duration, vector<string> users) {
  if (!checkUserAvailability(users, start, date, duration)) {
    // cout << "user not available" << endl;
    return FAILURE;
  }
  Event e;
  e.start = start;
  e.end = start + duration;
  e.duration = duration;
  e.attendees = users;
  e.date = date;

  eventList.push_back(e);

  for (auto user : users) {
    userEventLog[user][date].push_back(eventList.size() - 1);
  }

  return SUCCESS;
}

signed main() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  int n;
  cin >> n;
  while (n--) {
    string operation, query;
    cin >> operation;
    getline(cin, query);
    query = query.substr(1);

    if (operation == ADD_USER) {
      cout << registerUser(query) << endl;
    } else if (operation == CREATE_EVENT) {
      stringstream ss(query);
      vector<string> data;

      string temp;

      while (ss >> temp) {
        data.push_back(temp);
      }
      if (!validateEventData(data)) {
        cout << FAILURE << endl;
      } else {
        string date = data[0];
        int start = stoi(data[1]);
        int duration = stoi(data[2]);
        int numOfUser = stoi(data[3]);
        vector<string> users;
        for (int i = 4; i < data.size(); i++) {
          users.push_back(data[i]);
        }
        cout << createEvent(date, start, duration, users) << endl;
      }

    } else if (operation == SHOW_EVENT) {
    } else if (operation == SUGGEST_SLOT) {
    } else {
      cout << FAILURE << endl;
    }
  }
}

/*
12
add-user user1
add-user user2
add-user user3
add-user user4
create-event 2021-07-21 600 60 2 user1 user2
create-event 2021-07-21 660 30 2 user1 user3
create-event 2021-07-21 615 60 2 user2 user3
create-event 2021-07-21 660 30 2 user2 user4
show-event 2021-07-21 user1
show-event 2021-07-21 user2
suggest-slot 2021-07-21 570 750 45 2 user1 user2
suggest-slot 2021-07-21 570 700 60 2 user2 user3

*/