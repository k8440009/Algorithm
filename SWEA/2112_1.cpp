// 2112. [모의 SW 역량테스트] 보호 필름, 시간초과
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 987654321;
int D,W,K, answer;
int board[15][22];
int test_board[15][22];
int selected[15];

void print_board(int desc[15][22])
{
    cout << '\n';
    for(int r = 0; r < D; r++)
    {
        for(int c = 0; c < W; c++)
        {
            cout << desc[r][c] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}
void copy_board(int desc[12][22] ,int src[12][22])
{
    for(int r = 0; r < D; r++)
        for(int c = 0; c < W; c++)
            desc[r][c] = src[r][c];
}

bool test()
{
    for(int c = 0; c < W; c++)
    {
        int base = test_board[0][c];
        int r = 1, cnt = 1, flag = 0;
        while (r < D)
        {
            // 기준
            if(test_board[r][c] == base)
                cnt++;
            else
            {
                base = test_board[r][c];
                cnt = 1;
            }
            // 조건 만족
            if(cnt == K)
            {
                flag = 1;
                break;
            }
            r++;
        }
        if(!flag)
            return false;
    }
    return true;
}
void solve(int cnt)
{
    vector <int> node, medi;
    for(int i = 0; i < D; i++)
    {
        if(selected[i])
            node.push_back(i);
    }
    int N = node.size();
    // 약품 a,b 선택
    for(int a = 0; a <= N; a++)
    {
        int b = N - a;
        for(int i = 0; i < a; i++)
            medi.push_back(0);
        for(int i = 0; i < b; i++)
            medi.push_back(1);
        do
        {
            copy_board(test_board, board);
            for(int i = 0; i < node.size(); i++)
            {
                int idx = node[i], data = medi[i];
                for(int c = 0; c < W; c++)
                    test_board[idx][c] = data;
            }
            if(test())
            {
                answer = cnt;
                return;
            }
        } while (next_permutation(medi.begin(), medi.end()));
        medi.clear();     
    }
}

void dfs(int curr, int prev, int cnt)
{
    if(cnt >= answer)
        return ;
    else if(curr == cnt)
    {
        solve(cnt);
        return ;
    }
    // 조합
    for(int i = 0 ; i < D; i++)
    {
        if(selected[i] || prev > i)
            continue;
        selected[i] = 1;
        dfs(curr + 1, i, cnt);
        selected[i] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int tc;
    cin >> tc;
    for(int ts = 1; ts <= tc; ts++)
    {
        fill_n(selected, 15, 0);
        cin >> D >> W >> K;
        answer = K;
        for(int r = 0; r < D; r++)
            for(int c = 0; c < W; c++)
                cin >> board[r][c];
        for(int cnt = 0; cnt < K; cnt++)
        {
            if (cnt < answer)
                dfs(0, 0, cnt);
        }
        cout << "#" << ts << ' ' << answer << '\n';
    }
}