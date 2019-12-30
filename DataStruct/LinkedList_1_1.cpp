/*
    링크드 리스트
    동적 할당
*/
#include <iostream>
#include <cstdlib>
using namespace std;
class InvalidIndexException
{
};

template <typename T>
// 1. 리스트 노드 클래스
class ListNode
{
public:
    T value;           // 값
    ListNode<T> *next; // 마지막 노드인 경우 nullptr
    // 생성자
    ListNode<T>() : next(nullptr) {}
    ListNode<T>(T value1, ListNode<T> *next1) : value(value1), next(next1) {}
};
// 2. 연결리스트 클래스
template <typename T>
class LinkedList
{
public:
    int size;
    ListNode<T> *head; // head 부분
    // 생성자
    LinkedList<T>() : size(0), head(nullptr) {}
    // 소멸자
    ~LinkedList<T>()
    {
        ListNode<T> *t1 = head, *t2;
        while (t1 != nullptr)
        {
            t2 = t1->next;
            delete t1;
            t1 = t2;
        }
    }
    // 멤버 함수
    // 삽입 :k번째 원소 앞에 새 원소
    void insert(int k, T value)
    {
        try
        {
            // 예외처리: 잘못된 인덱스
            if (k < 0 || k > size)
                throw InvalidIndexException();
            // 처음 삽입
            if (k == 0)
            {
                head = new ListNode<T>(value, head);
            }
            // k번째 원소 앞에 삽입
            else
            {
                ListNode<T> *dest = head;
                for (int i = 0; i < k - 1; i++)
                    dest = dest->next;
                dest->next = new ListNode<T>(value, dest->next);
            }
            size++;
        }
        catch (InvalidIndexException e)
        {
            cerr << "잘못된 인덱스 입니다." << endl;
            exit(1);
        }
    }
    // 삭제 : k 번째 원소를 제거
    void erase(int k)
    {
        try
        {
            // 예외 처리 : 잘못된 인덱스
            if (k < 0 || k >= size)
                InvalidIndexException();
            // head 삭제
            if (k == 0)
            {
                ListNode<T> *temp = head->next;
                delete head;
                head = temp;
            }
            else
            {
                ListNode<T> *dest = head, *temp;
                for (int i = 0; i < k - 1; i++)
                    dest = dest->next;
                temp = dest->next->next;
                delete dest->next;
                dest->next = temp;
            }
            size--;
        }
        catch (InvalidIndexException e)
        {
            cerr << "잘못된 인덱스 입니다." << endl;
            exit(2);
        }
    }
    // 검색 : 값을 찾아 첫번째 인덱스 리턴, 없으면 -1 리턴
    int search(T value)
    {
        ListNode<T> *temp = head;
        for (int i = 0; i < size; i++)
        {
            if (temp->value == value)
                return i;
            temp = temp->next;
        }
        return -1; // 못 찾음
    }
};

template <typename T>
// 원소들을 한 줄에 차례대로 출력
ostream &operator<<(ostream &out, const LinkedList<T> &LL)
{
    ListNode<T> *temp = LL.head;
    out << '[';
    for (int i = 0; i < LL.size; i++)
    {
        out << temp->value;
        temp = temp->next;
        if (i < LL.size - 1)
            out << ", ";
    }
    out << ']';
    return out;
}
int main()
{
    LinkedList<int> LL;
    LL.insert(0, 1);
    cout << LL << endl;
    LL.insert(1, 2);
    cout << LL << endl;
    LL.insert(2, 3);
    cout << LL << endl;
    LL.insert(0, 4);
    cout << LL << endl;
    LL.insert(0, 5);
    cout << LL << endl;
    LL.insert(5, 6);
    cout << LL << endl;
    LL.insert(4, 7);
    cout << LL << endl;
    LL.insert(1, 8);
    cout << LL << endl;
    LL.erase(4);
    cout << LL << endl;
    LL.erase(0);
    cout << LL << endl;
    LL.erase(5);
    cout << LL << endl;
    LL.insert(3, 9);
    cout << LL << endl;
    LL.erase(1);
    cout << LL << endl;
    LL.insert(1, 10);
    cout << LL << endl;
}

/*
    참고
    https://blog.naver.com/PostView.nhn?blogId=kks227&logNo=220781402507&parentCategoryNo=&categoryNo=299&viewDate=&isShowPopularPosts=false&from=menu
    c++ 생성자
    https://hashcode.co.kr/questions/629/%EC%83%9D%EC%84%B1%EC%9E%90%EC%97%90%EC%84%9C-%EC%BD%9C%EB%A1%A0%EC%9D%80-%EC%99%9C-%EC%93%B0%EB%8A%94-%EA%B1%B4%EA%B0%80%EC%9A%94
*/