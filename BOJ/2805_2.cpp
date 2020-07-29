#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
vector <int> tree_height;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    tree_height.resize(N);
    for(int i = 0; i < N; i++)
        cin >> tree_height[i];
    int left = 0, right = 1000000000;
    while (left + 1 < right)
    {
        long long mid = (left + right) / 2;
        long long total = 0;
        for (int i = 0; i < tree_height.size(); i++)
        {
            if (tree_height[i] > mid)
                total += (tree_height[i] - mid);
        }
        if (total >= M) left = mid;
        else right = mid;
    }
    cout << left;
}