// 최대 공약수와 최소 공배수
// https://programmers.co.kr/learn/courses/30/lessons/12940
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
ll GCD(ll a, ll b) { return b ? GCD(b, a % b) : a; }
ll LCM(ll a, ll b)
{
    if (a == 0 || b == 0)
        return a + b;
    return a / GCD(a, b) * b;
}

vector<int> solution(int n, int m)
{
    vector<int> answer;
    int gcd = GCD(n, m);
    int lcm = LCM(n, m);
    answer.push_back(gcd);
    answer.push_back(lcm);

    cout << 0 ? 2 : 1 << '\n';
    return answer;
}