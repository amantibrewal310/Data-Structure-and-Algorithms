//?https://practice.geeksforgeeks.org/problems/find-median-in-a-stream/0
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int n, x;
    cin >> n;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    cin >> x;
    maxHeap.push(x);
    int median = x;
    n = n - 1;
    cout << median << endl;
    while (n--)
    {
        cin >> x;
        if (x > median)
        {
            int diff = minHeap.size() - maxHeap.size();
            if (diff == 1)
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(x);

                median = (maxHeap.top() + minHeap.top()) / 2;
            }
            else if (diff == 0)
            {
                minHeap.push(x);
                median = minHeap.top();
            }
            else
            {
                minHeap.push(x);
                median = (maxHeap.top() + minHeap.top()) / 2;
            }
        }
        else
        {
            int diff = maxHeap.size() - minHeap.size();
            if (diff == 1)
            {
                maxHeap.push(x);
                minHeap.push(maxHeap.top());
                maxHeap.pop();

                median = (maxHeap.top() + minHeap.top()) / 2;
            }
            else if (diff == 0)
            {
                maxHeap.push(x);
                median = maxHeap.top();
            }
            else
            {
                maxHeap.push(x);
                median = (maxHeap.top() + minHeap.top()) / 2;
            }
        }
        cout << median << endl;
    }
}
