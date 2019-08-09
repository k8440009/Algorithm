// 가운데를 말해요
// https://www.acmicpc.net/problem/1655
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    // 최대 힙, 최소 힙
    priority_queue<int, vector<int>, less<int>> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    while (n--)
    {
        int value;
        cin >> value;

        if (maxHeap.empty())
            maxHeap.push(value);
        else if (maxHeap.size() == minHeap.size())
            maxHeap.push(value);
        else
            minHeap.push(value);

        if (!maxHeap.empty() && !minHeap.empty() && !(maxHeap.top() <= minHeap.top()))
        {
            int a = maxHeap.top();
            int b = minHeap.top();

            maxHeap.pop();
            minHeap.pop();

            minHeap.push(a);
            maxHeap.push(b);
        }

        int answer = maxHeap.top();
        cout << answer << '\n';
    }

    return 0;
}