#include <bits/stdc++.h>
using namespace std;

vector<string> solution(vector<string> record)
{
    vector<string> answer;
    map<string, string> chat;
    for (string str : record)
    {
        string command, id, nickName;
        stringstream ss;
        ss.str(str);

        ss >> command;
        ss >> id;
        ss >> nickName;

        map<string, string>::iterator iter = chat.find(id);

        if (command == "Enter")
        {
            if (iter == chat.end())
                chat.insert(make_pair(id, nickName));
            else
                iter->second = nickName;
        }
        else if (command == "Change")
        {
            iter->second = nickName;
        }
    }

    for (string str : record)
    {
        string command, id, nickName;
        stringstream ss;
        ss.str(str);
        ss >> command;
        ss >> id;
        ss >> nickName;
        string name = (*chat.find(id)).second;
        if (command == "Enter")
            answer.push_back(name + "님이 들어왔습니다.");

        else if (command == "Leave")
            answer.push_back(name + "님이 나갔습니다.");
    }

    return answer;
}