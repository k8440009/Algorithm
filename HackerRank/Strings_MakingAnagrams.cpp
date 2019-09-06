#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b)
{
    int cnt = 0;
    int alpha1[27];
    int alpha2[27];

    fill_n(alpha1, 27, 0);
    fill_n(alpha2, 27, 0);

    for (char c : a)
        alpha1[c - 'a']++;
    for (char c : b)
        alpha2[c - 'a']++;

    for (int i = 0; i < 27; i++)
    {
        // 1. 둘다 0인 경우 continue;
        // 2. 두개 숫자가 같으면 conintue;
        // 숫자 비교해서 작은 것 쪽으로
        if (alpha1[i] > alpha2[i])
            cnt += alpha1[i] - alpha2[i];
        else if (alpha1[i] < alpha2[i])
            cnt += alpha2[i] - alpha1[i];
    }

    return cnt;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a;
    getline(cin, a);

    string b;
    getline(cin, b);

    int res = makeAnagram(a, b);

    fout << res << "\n";

    fout.close();

    return 0;
}
