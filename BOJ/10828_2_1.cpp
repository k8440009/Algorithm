// 스택
// https://www.acmicpc.net/problem/10828
#include <iostream>
#include <string>
using namespace std;

template<typename T>
class ListNode{
public:
	T value;
	ListNode <T> *next;

	// 생성자
	ListNode <T>(): next(nullptr){}
	ListNode <T>(T value, ListNode<T> *next):value(value), next(next){}
};

template<typename T>
class Stack{
public:
	int size;
	ListNode<T> *tail;

	// 생성자
	Stack<T>():size(0), tail(nullptr){}
	// 소멸자
	~Stack<T>(){
		ListNode<T> *t1 = tail, *t2;
		while (t1 != nullptr){
			t2 = t1->next;
			delete t1;
			t1 = t2;
		}
	}
	// 멤버 함수
	// 맨위에 새 원소 삽입
	void push(T value){
		tail = new ListNode<T>(value, tail);
		size++;
	}

	// pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 
	// 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
	void pop(){
		if (size == 0){
			cout << -1 << "\n";
			return ;
		}

		cout << tail->value << '\n';
		ListNode<T> *temp = tail->next;
		delete tail;
		tail = temp;
		size--;
	}
	// size: 스택에 들어있는 정수의 개수를 출력한다.
	T stackSize(){
		return size;
	}

	int empty(){
		if (size == 0)
			return 1;
		else
			return 0;
	}
	// empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
	// top: 스택의 가장 위에 있는 정수를 출력한다. 
	// 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
	T top(){
		if (size == 0)
			return -1;
		return tail->value;
	}
};

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	freopen("input.txt", "r", stdin);
	int N;
	cin >> N;
	Stack<int> st;
	for (int i = 0; i < N; i++){
		string str;
		cin >> str;
		if (str == "push"){
			int num;
			cin >> num;
			st.push(num);
		}
		else if (str == "pop"){
			st.pop();
		}
		else if (str == "size"){
			cout << st.stackSize() << '\n';
		}
		else if (str == "empty"){
			cout << st.empty() << '\n';
		}
		else if (str == "top"){
			cout << st.top() << '\n';
		}

	}
}