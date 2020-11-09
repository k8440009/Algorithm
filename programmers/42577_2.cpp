#include <string>
#include <vector>

using namespace std;

bool check_data(string basis, string phone)
{
	if (basis.length() > phone.length())
		return false;
	for (int i = 0; i < basis.length(); i++)
	{
		if (basis[i] != phone[i])
			return false;
	}
	return true;
}

bool solution(vector<string> phone_book) {
    bool answer = true;

	for (int i = 0; i < phone_book.size(); i++)
	{
		for (int j = 0; j < phone_book.size(); j++)
		{
			if (i == j)
				continue;
			if (check_data(phone_book[i], phone_book[j]))
			{
				answer = false;
				return answer;
			}
		}
	}
    return answer;
}