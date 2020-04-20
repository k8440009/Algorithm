// 2477. [모의 SW 역량테스트] 차량 정비소
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, K, A, B;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc;
	cin >> tc;
	for (int ts = 1; ts <= tc; ts++)
	{
		cin >> N >> M >> K >> A >> B;
		int time, answer = 0;
		int a[12], b[12];
		vector<int> customer;
		vector<pair<int, int>> reception[12], repair[12], state;
		queue<pair<int, int>> wait_reception, wait_repair;

		customer.resize(K + 1), state.resize(K + 1);
		for (int i = 1; i <= N; i++)
			cin >> a[i];
		for (int i = 1; i <= M; i++)
			cin >> b[i];
		for (int i = 1; i <= K; i++)
		{
			int tmp;
			cin >> tmp;
			customer[i] = tmp;
			state[i].first = 0, state[i].second = 0;
		}
		time = customer[1];
		int start = 1;
		while (true)
		{
			while (start <= K) // 접수 창구에 값을 넣음
			{
				if (time == customer[start])
				{
					wait_reception.push(make_pair(start, customer[start])); // 번호, 시간
					start++;
				}
				else
					break;
			}
			// 접수 창구
			for (int i = 1; i <= N; i++)
			{
				if (reception[i].size() == 1)
				{
					int idx = reception[i][0].first, t = reception[i][0].second;
					if (t == 0)
					{
						wait_repair.push(make_pair(idx, time)); // 번호, 시간
						reception[i].pop_back();
					}
				}
			}
			// 2. 빈공간 접수
			for (int i = 1; i <= N; i++)
			{
				if (wait_reception.empty())
					break;
				if (reception[i].size() == 0)
				{
					pair<int, int> cur = wait_reception.front(); // 번호, 시간
					wait_reception.pop();
					cur.second = a[i];
					reception[i].push_back(cur);
					state[cur.first].first = i;
				}
			}
			// 3. 수리창구 정리
			for (int j = 1; j <= M; j++)
			{
				if (repair[j].size() == 1)
				{
					int t = repair[j][0].second; // 시간
					if (t == 0)
						repair[j].pop_back();
				}
			}
			// 4. 수리 창구 접수
			for (int j = 1; j <= M; j++)
			{
				if (wait_repair.empty())
					break;
				if (repair[j].size() == 0)
				{
					pair<int, int> cur = wait_repair.front(); // 번호, 시간
					wait_repair.pop();
					cur.second = b[j];
					repair[j].push_back(cur);
					state[cur.first].second = j;
				}
			}
			// 5. 접수 창구 수리창구 시간 빼주기
			for (int i = 1; i <= N; i++)
			{
				if (reception[i].size() == 1)
					reception[i][0].second -= 1;
			}
			for (int j = 1; j <= M; j++)
			{
				if (repair[j].size() == 1)
					repair[j][0].second -= 1;
			}
			// 종료
			if (wait_reception.empty() && wait_repair.empty())
			{
				bool flag = 0;
				for (int i = 1; i <= N; i++)
				{
					if (reception[i].size() == 1)
					{
						flag = 1;
						break;
					}
				}
				for (int i = 1; i <= M; i++)
				{
					if (flag || repair[i].size() == 1)
					{
						flag = 1;
						break;
					}
				}
				if (!flag)
					break;
			}
			time++;
		}
		for (int i = 1; i <= K; i++)
		{
			if (state[i].first == A && state[i].second == B)
				answer += i;
		}
		if (answer == 0)
			answer = -1;
		cout << '#' << ts << ' ' << answer << '\n';
	}
}