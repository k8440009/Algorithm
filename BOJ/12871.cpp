// 무한 문자열
// https://www.acmicpc.net/problem/12871
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
ll GCD(ll a, ll b) { return b ? GCD(b, a % b) : a; }
bool check(string &s, string &period)
{
    int g = period.length();
    for (int i = 0; i < s.length(); i += g)
    {
        if (s.substr(i, g) != period)
            return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    int g = GCD(s.length(), t.length());
    string period = s.substr(0, g);
    if (check(s, period) && check(t, period))
        cout << 1 << '\n';
    else
        cout << 0 << '\n';
    return 0;
}