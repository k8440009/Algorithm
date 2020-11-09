
// 스킬트리
// https://programmers.co.kr/learn/courses/30/lessons/49993
#include <string>
#include <vector>
#include <queue>
using namespace std;
int solution(string skill, vector<string> skill_trees) {
    int answer = skill_trees.size();
    for(string s : skill_trees){
        queue <char> q;
        for(char c : s){
            if(skill.find(c) != string::npos)
             q.push(c);
        }
        int index = 0;
        while(!q.empty()){
            if(skill[index] != q.front()){
                answer -= 1;
                break;
            }
            index++;
            q.pop();
        }
    }
    return answer;
}