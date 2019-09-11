#include <bits/stdc++.h>

using namespace std;

// Complete the repeatedString function below.
long repeatedString(string s, long n)
{
    long cnt = 0;
    long aCnt = 0;
    string newStr = "";
    for (long i = 0; i < s.size(); i++)
    {
        if (s[i] == 'a')
            aCnt++;
    }

    long repeat1 = n / s.size();
    long repeat2 = n % s.size();

    cnt = aCnt * repeat1;
    for (int i = 0; i < repeat2; i++)
    {
        if (s[i] == 'a')
            cnt++;
    }

    return cnt;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    long result = repeatedString(s, n);

    fout << result << "\n";

    fout.close();

    return 0;
}
