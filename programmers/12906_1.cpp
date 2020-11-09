#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    arr.erase(unique(arr.begin(), arr.end()),arr.end());
    for(auto i : arr){
        answer.push_back(i);
    }
    return answer;
}