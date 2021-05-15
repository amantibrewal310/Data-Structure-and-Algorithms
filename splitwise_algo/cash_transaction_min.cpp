#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int no_of_transactions, friends;
    cin >> no_of_transactions >> friends;

    int x, y, amount; // x and y is person have  to settle some amount

    // Make a array to store the net amount that each person will have to take at the end

    vector<int> net(friends, 0);

    while(no_of_transactions--) {
        cin >> x >> y >> amount;
        net[x] -= amount;
        net[y] += amount;
    }

    multiset<int> m; // for transaction like -30, -20, -20, 10, 10
    for(int i = 0; i < friends; i++) {
        if(net[i] != 0) {
            m.insert(net[i]); // list in sorted already
        }
    }

    // Pop out two person (left and right) and try to settle them
    int cnt = 0;
    while(!m.empty()) {
        auto low = m.begin();
        auto high = prev(m.end()); // previous iterator to the given iterator
        int debit = *low;
        int credit = *high;

        // Erase this elements from the multiset
        m.erase(low);
        m.erase(high);

        int settlement_amount = min(-debit, credit);

        // settlement_amount from debitor to creditor

        debit += settlement_amount;
        credit -= settlement_amount;
        cnt++;

        if(debit != 0) {
            m.insert(debit);
        } else if(credit != 0) {
            m.insert(credit);
        }

    }
    cout << cnt << endl;

}