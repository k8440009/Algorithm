#include <iostream>
#include <string>
using namespace std;
/*
    배열을 사용하여 ArrayList 만들기

    fprintf : https://modoocode.com/64
*/

#define MAX 100 // 배열 최대 크기

typedef int element;
struct ArrayListType
{
    element list[MAX];
    int length;
};

// 오류 처리 함수
void Error(string message)
{
    //cout << stderr << '\n';
    cout << message << endl;
    exit(1);
}
// 리스트 초기화
void Init(ArrayListType *L)
{
    L->length = 0;
}
// 리스트 비어 있는지 여부
bool Empty(ArrayListType *L)
{
    // 리스트가 비어 있는 경우 1을 반환
    // 그렇지 않으면 0을 반환
    return L->length == 0;
}
bool Full(ArrayListType *L)
{
    // 리스트가 가득 차 있으면 1 반환
    // 그렇지 않으면 0 반환
    return L->length == MAX;
}
// 리스트 출력
void Display(ArrayListType *L)
{
    for (int i = 0; i < L->length; i++)
    {
        cout << L->list[i] << '\n';
    }
    cout << endl;
}
// 구현 연습
// void clear(list)
// void replace(list, position, item)
// getEntry(list,postion)
// getLegnth(list, position)

// position : 삽입하고자 하는 위치
// item : 삽입하고자 하는 자료
void Add(ArrayListType *L, int position, element item)
{
    if (!Full(L) && (position >= 0) && (position <= L->length))
    {
        for (int i = L->length - 1; i >= position; i--)
        {
            L->list[i + 1] = L->list[i];
        }

        L->list[position] = item;
        L->length++;
    }
}
// position : 삭제하고자 하는 위치
// 반환 값 : 삭제되는 자료
element Delete(ArrayListType *L, int position)
{
    element item;
    if (position < 0 || position >= L->length)
    {
        Error("위치 오류");
    }
    item = L->list[position];
    for (int i = position; i < L->length - 1; i++)
    {
        L->list[i] = L->list[i + 1];
    }
    L->length -= 1;
    return item;
}
int main()
{
    ArrayListType list1;
    ArrayListType *plist;

    // ArrayType의 구조체를 정적으로 생성하고 이 구조체를 가리키는 포인터를 함수의 매개변수로 전달
    Init(&list1);
    Add(&list1, 0, 10);
    Add(&list1, 0, 20);
    Add(&list1, 0, 30);
    Display(&list1);

    //ArrayListType의 구조체를 동적으로 생성하고 이 구조체를 가리키는 포인터를 함수의 매개변수로 전달
    plist = (ArrayListType *)malloc(sizeof(ArrayListType));
    Init(plist);
    Add(plist, 0, 10);
    Add(plist, 0, 20);
    Add(plist, 0, 30);
    Display(plist);
    free(plist);

    return 0;
}