#include <iostream>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int num = 1;                // 1: 0000 0001
    cout << (num << 2) << '\n'; // 4: 0000 0100: 2^2
}

/*
    참고 
    https://dojang.io/mod/page/view.php?id=181
*/