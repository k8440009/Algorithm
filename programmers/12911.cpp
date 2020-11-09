#include <string>
#include <vector>
#include <map>
#include <bitset>
#include <algorithm>

using namespace std;

int solution(int n)
{
    int answer = 0;
    string str;
    map<int, int> m1;
    str = bitset<32>(n).to_string();
    for (int i = 0; i < str.size(); i++)
        m1[str[i]]++;

    for (int i = n + 1; i <= 1000000; i++)
    {
        map<int, int> m2;
        bool check = true;
        string temp = bitset<32>(i).to_string();
        for (int i = 0; i < temp.size(); i++)
            m2[temp[i]]++;

        for (auto iter1 : m1)
        {
            for (auto iter2 : m2)
            {
                if (iter1.first == iter2.first)
                {
                    if (iter1.second != iter2.second)
                    {
                        check = false;
                        continue;
                    }
                }
            }
        }

        if (check)
        {
            answer = i;
            break;
        }
    }
    return answer;
}