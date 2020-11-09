#include <string>
#include <vector> 
#include <algorithm>

using namespace std;
#define rep1(i,a,b) for(int i = a; i < b; i++)
bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(), phone_book.end());
    rep1(i,0,phone_book.size()){
        rep1(j,0,phone_book.size()){
            if(i==j) continue;
            if (phone_book[j].find(phone_book[i]) == 0){
                answer = false;
                return answer;
            }
        }
    }
    return answer;
}