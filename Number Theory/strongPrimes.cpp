#include <bits/stdc++.h>
using namespace std;

void sieve(vector<int> &isPrimes) {
  int n = isPrimes.size();
  for (int i = 0; i < n; i++) {
    isPrimes[i] = 1;
  }
  isPrimes[0] = 0;
  isPrimes[1] = 0;
  for (int i = 4; i < n; i += 2) {
    isPrimes[i] = 0;
  }

  for (int i = 3; i < n; i += 2) {
    for (int j = 2 * i; j < n; j += i) {
      isPrimes[j] = 0;
    }
  }
}

int findPos(vector<int> &nums, int low, int high, int target,
            bool first = true) {
  int ans = -1;
  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (nums[mid] == target) {
      if (first) {
        ans = mid;
        high = mid - 1;
      } else {
        ans = mid;
        low = mid + 1;
      }
    } else if (nums[mid] < target) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }
  return ans;
}

vector<int> preCompute(vector<int> &isPrimes) {
  int n = isPrimes.size();
  vector<int> strongPrimes(n, 0);

  vector<int> prefix(n, 0);
  prefix[0] = isPrimes[0];
  for (int i = 1; i < n; i++) {
    prefix[i] = prefix[i - 1] + isPrimes[i];
  }
  // for (int i = 0; i < 20; i++) {
  //   cout << prefix[i] << " ";
  // }
  // cout << endl;

  for (int i = 3; i < n; i++) {
    if (!isPrimes[i]) continue;
    int prevStrongPrime = findPos(prefix, 0, i - 1, prefix[i] - 1);
    int nextStrongPrime = findPos(prefix, i + 1, n - 1, prefix[i] + 1);

    if (prevStrongPrime == -1 || nextStrongPrime == -1) continue;

    int mean = (prevStrongPrime + nextStrongPrime) / 2;
    if (i > mean) {
      strongPrimes[i] = 1;
    }
  }
  // for (int i = 0; i < 20; i++) {
  //   cout << strongPrimes[i] << " ";
  // }
  // cout << endl;
  for (int i = 1; i < n; i++) {
    strongPrimes[i] += strongPrimes[i - 1];
  }
  return strongPrimes;
};

signed main() {
  int q;
  cin >> q;
  int n = 1e6;
  vector<int> isPrimes(n + 1);
  sieve(isPrimes);
  // for (int i = 0; i < 20; i++) {
  //   cout << isPrimes[i] << " ";
  // }
  // cout << endl;
  vector<int> strongPrimes = preCompute(isPrimes);

  // for (int i = 0; i < 20; i++) {
  //   cout << strongPrimes[i] << " ";
  // }
  // cout << endl;

  while (q--) {
    int l, r;
    cin >> l >> r;

    cout << strongPrimes[r] - strongPrimes[l] << endl;
  }
}