// 스택
// https://www.acmicpc.net/problem/10828
#include <iostream>
using namespace std;

template<typename T> class ListNode{
public:
	T value;
	ListNode *next;

	// 생성자
	ListNode<T>(): next(nullptr){}
	ListNode<T>(T data, ListNode<T> *tail):value(data), next(tail){}
};

template<typename T> class Stack{
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
	// push()
	void push(T value){
		tail = new ListNode<T>(value, tail);
		size++;
	}
	// pop()
	T pop(){
		if (size == 0)
			return -1;

		T data = tail->value;
		ListNode <T> *temp = tail->next;
		delete tail;
		tail = temp;
		size--;
		return data;
	}
	T stackSize(){
		return size; 
	}
	T empty(){
		if (size == 0)
			return 1;
		else
			return 0;
	}
	// top()
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
	Stack<int> st;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++){
		string cmd;
		cin >> cmd;
		if (cmd == "push"){
			int num;
			cin >> num;
			st.push(num);
		}
		else if (cmd == "pop")
			cout << st.pop() << '\n';
		else if (cmd == "size")
			cout << st.stackSize() << '\n';
		else if (cmd == "empty")
			cout << st.empty() << '\n';
		else if (cmd == "top")
			cout << st.top() << '\n';
	}
}