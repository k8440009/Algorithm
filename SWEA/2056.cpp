// 2056. 연월일 달력
/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;
// float b = 1.0, c = 2.0;
// double d = 3.0, e = 0.0; f = 1.0;
// char g = &apos;b&apos;;
// char var[256] = &quot;ABCDEFG&quot;;
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << &quot; &quot; << c;               // float 변수 2개 출력하는 예제
// cout << d << &quot; &quot; << e << &quot; &quot; << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;

int mon[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int main(int argc, char **argv)
{
    int test_case;
    int T;

    // freopen("input.txt", "r", stdin);
    cin >> T;
    /*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
    for (test_case = 1; test_case <= T; ++test_case)
    {
        string str, temp = "";
        bool check = false;
        int year, month, day;
        scanf("%4d", &year);
        scanf("%2d", &month);
        scanf("%2d", &day);

        // cout << year << ' ' << month << ' ' << day << '\n';

        for (int i = 1; i < 13; i++)
        {
            if (i == month)
            {
                if (0 < day && day <= mon[i])
                {
                    check = true;
                    break;
                }
            }
        }

        if (check)
        {
            string yyyy = "", mm = "", dd = "";
            if (year < 1000)
                yyyy = "0";
            yyyy += to_string(year);

            if (month < 10)
                mm = "0";
            mm += to_string(month);

            if (day < 10)
                dd = "0";

            dd += to_string(day);

            cout << "#" << test_case << " " << yyyy << "/" << mm << "/" << dd << '\n';
        }
        else
        {
            cout << "#" << test_case << " "
                 << "-1" << '\n';
        }
    }
    return 0; //정상종료시 반드시 0을 리턴해야합니다.
}