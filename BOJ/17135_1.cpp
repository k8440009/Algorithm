// 캐슬 디펜스
// https://www.acmicpc.net/problem/17135
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 15;
int N, M, D;
int board[MAX][MAX];
int copyBoard[MAX][MAX];
vector<pair<int, int>> v;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M >> D;
    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < M; x++)
        {
            cin >> board[y][x];
            if (board[y][x] == 1)
                v.push_back(make_pair(y, x));
        }
    }

    vector<int> select;
    for (int i = 0; i < M - 3; i++)
        select.push_back(0);
    for (int i = 0; i < 3; i++)
        select.push_back(1);

    int result = 0;
    do
    {
        int cnt = 0;
        // 적들의 좌표 복사
        vector<pair<int, int>> enemy = v;

        vector<int> archer;
        for (int i = 0; i < select.size(); i++)
        {
            // 궁수 위치
            if (select[i] == 1)
                archer.push_back(i);
        }

        while (!enemy.empty())
        {
            int y = N;
            vector<int> target;
            for (int i = 0; i < archer.size(); i++)
            {
                int x = archer[i];
                int index = 0;
                int enemyX = enemy[0].second;
                int dist = abs(y - enemy[0].first) + abs(x - enemy[0].second);

                // 최단거리 타겟 찾기
                for (int j = 1; j < enemy.size(); j++)
                {
                    int temp = abs(y - enemy[j].first) + abs(x - enemy[j].second);

                    if (dist > temp)
                    {
                        enemyX = enemy[j].second;
                        dist = temp;
                        index = j;
                    }
                    // 거리가 같으면 왼쪽의 적
                    else if (dist == temp && enemyX > enemy[j].second)
                    {
                        enemyX = enemy[j].second;
                        index = j;
                    }
                }
                //  D이내에 있는 적만 처치 가능
                if (dist <= D)
                    target.push_back(index);
            }

            sort(target.begin(), target.end());
            target.erase(unique(target.begin(), target.end()), target.end());

            int index = 0;
            vector<pair<int, int>> copyEnemy;
            for (int i = 0; i < enemy.size(); i++)
            {
                bool flag = true;
                for (int j = index; j < target.size(); j++)
                {
                    if (i == target[j])
                    {
                        flag = false;
                        index++;
                        cnt++;
                    }
                }

                if (flag)
                {
                    if (enemy[i].first < N - 1)
                        copyEnemy.push_back(make_pair(enemy[i].first + 1, enemy[i].second));
                }
            }

            if (copyEnemy.empty())
                break;

            enemy = copyEnemy;
        }

        result = max(result, cnt);

    } while (next_permutation(select.begin(), select.end()));

    cout << result << '\n';
    return 0;
}