#include <string>
#include <vector>
typedef long long ll;
ll GCD (ll a, ll b) {
    return b ? GCD(b,a%b) : a;
}
ll LCM (ll a, ll b){
    if(a == 0 || b == 0){
        return a + b;
    }
    return a / GCD(a, b) * b;
}
using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    int lcm = LCM(arr[0], arr[1]);
    for(int i = 2; i < arr.size(); i++){
        lcm = LCM(lcm, arr[i]);
    }
    return lcm;
}