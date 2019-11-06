// Mini Fantasy War
// https://www.acmicpc.net/problem/12790
#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for (int ts = 1; ts <= tc; ts++)
    {
        int hp, mp, attack, defense, a, b, c, d, answer = 0;
        cin >> hp >> mp >> attack >> defense >> a >> b >> c >> d;
        hp += a, mp += b, attack += c, defense += d;

        if (hp < 1)
            hp = 1;
        if (mp < 1)
            mp = 1;
        if (attack < 0)
            attack = 0;

        answer = (1 * hp + 5 * mp + 2 * attack + 2 * defense);

        cout << answer << '\n';
    }

    return 0;
}