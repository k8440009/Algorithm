// 국영수
// https://www.acmicpc.net/problem/10825
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct STUDENT
{
    string name;
    int language, english, math;
};
int N;
vector<STUDENT> stu;
bool cmp(STUDENT &a, STUDENT &b)
{
    if (a.language == b.language)
    {
        if (a.english == b.english)
        {
            if (a.math == b.math)
            {
                return a.name < b.name;
            }
            else
                return a.math > b.math;
        }
        else
            return a.english < b.english;
    }
    else
        return a.language > b.language;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    stu.resize(N);
    for (int i = 0; i < N; i++)
    {
        STUDENT student;
        cin >> student.name >> student.language >> student.english >> student.math;
        stu[i] = student;
    }

    sort(stu.begin(), stu.end(), cmp);

    for (int i = 0; i < N; i++)
        cout << stu[i].name << '\n';
    return 0;
}