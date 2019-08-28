#include <bits/stdc++.h>

using namespace std;

// Complete the countingValleys function below.
int countingValleys(int n, string s)
{
    int cnt = 0; // 계곡 갯수
    int seaLevel = 0;
    int height = seaLevel;

    for (int i = 0; i < n; i++)
    {
        char now = s[i];
        int preHeight = height; // 이전 높이

        if (now == 'U')
            height++;
        else if (now == 'D')
            height--;

        if (height == seaLevel && preHeight < 0)
            cnt++;
    }

    return cnt;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string s;
    getline(cin, s);

    int result = countingValleys(n, s);

    fout << result << "\n";

    fout.close();

    return 0;
}
