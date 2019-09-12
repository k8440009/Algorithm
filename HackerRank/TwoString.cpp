// TwoString
#include <bits/stdc++.h>

using namespace std;

// Complete the twoStrings function below.
string twoStrings(string s1, string s2)
{
    map<char, int> m1;
    map<char, int> m2;

    for (auto c : s1)
        m1[c]++;

    for (auto c : s2)
        m2[c]++;

    int cnt = 0;
    for (auto iter1 : m1)
    {
        for (auto iter2 : m2)
        {
            if (iter2.first == iter1.first)
                cnt++;
        }
    }
    /*
    map<char, int>::iterator iter1;
    map<char, int>::iterator iter2;
    for (iter1 = m1.begin(); iter1 != m1.end(); iter1++)
    {
        for (iter2 = m2.begin(); iter2 != m2.end(); iter2++)
        {
            if (iter2->first == iter1->first)
                cnt++;
        }
    }
    */
    if (cnt == 0)
        return "NO";
    else
        return "YES";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++)
    {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
