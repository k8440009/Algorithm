// 큐
// https://www.acmicpc.net/problem/10845
#include <iostream>
#include <string>
using namespace std;

template<typename T> class ListNode{
public:
	T value;
	ListNode<T> *next;

	ListNode<T>():next(nullptr){}
	ListNode<T>(T data, ListNode *tail):value(data), next(tail){}
};

template<typename T> class Queue{
public:
	int size;
	ListNode<T> *head, *tail;
	
	Queue<T>(): size(0), head(nullptr), tail(nullptr){};
	~Queue<T>(){
		ListNode <T> *t1 = head, *t2;
		while (t1 != nullptr){
			t2 = t1->next;
			delete t1;
			t1 = t2;
		}
	}
	void push(T value){
		if (size == 0){
			tail = new ListNode<T>(value, nullptr);
			head = tail;
		}
		else{
			tail->next = new ListNode<T>(value, nullptr);
			tail = tail->next;
		}
		size++;
	}
	T pop(){
		if (size == 0)
			return -1;
		T data = head->value;
		ListNode<T> *temp = head;
		head = head->next;
		delete temp;
		size--;
		return data;
	}
	T queueSize(){
		return size;
	}
	T empty(){
		if (size == 0)
			return 1;
		else
			return 0;
	}
	T front(){
		if (size == 0)
			return -1;
		return head->value;
	}
	T back(){
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
	Queue<int> q;

	int N;
	cin >> N;
	for (int i = 0; i < N; i++){
		string cmd;
		cin >> cmd;
		if (cmd == "push"){
			int data;
			cin >> data;
			q.push(data);
		}
		else if (cmd == "pop")
			cout << q.pop() << '\n';
		else if (cmd == "size")
			cout << q.queueSize() << '\n';
		else if (cmd == "empty")
			cout << q.empty() << '\n';
		else if (cmd == "front")
			cout << q.front() << '\n';
		else if (cmd == "back")
			cout << q.back() << '\n';
	}
}