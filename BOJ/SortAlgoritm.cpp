#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
/*
    Sort
    1. 안정 정렬 : 정렬 이후 동일 한 값에 대해 기존 순서 유지 
    1) 삽입 정렬 (insertion sort)
    - 시간 복잡도  O(N^2)
    - 보조 공간 (Auxiliary Space)  O(1)
    2) 버블 벙렬 (bubble sort)
    2) 병합 정렬 (merge sort), O(NlogN)

    2. 불안정 정렬 :정렬 이후 동일 한 값에 대해 기존 순서가 바뀔 수 있음
    1) 선택 정렬
    - 시간 복잡도  O(N^2)
    - 보조 공간 (Auxiliary Space)  O(1)
    5) 퀵 소트 (quick sort), O(NlogN)
*/
const int MAX = 10;
// 선택 정렬
void selectionSort(vector<int> &v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        int now = i;
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[now] > v[j])
                now = j;
        }
        // swap
        int temp = v[i];
        v[i] = v[now];
        v[now] = temp;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> v(MAX);
    srand((unsigned int)time(NULL));
    cout << "정렬 전 : ";
    for (int i = 0; i < MAX; i++)
    {
        int num = (rand() % 100) + 1;
        v[i] = num;
        cout << v[i] << ' ';
    }
    cout << '\n';
    // 선택 정렬
    selectionSort(v);

    cout << "정렬 후 : ";
    for (int i = 0; i < MAX; i++)
    {
        cout << v[i] << ' ';
    }
    cout << '\n';
}
/*
    참고

    - 기본 정렬 요약 정리, 안정 정렬/불안정 정렬 -
    https://hsp1116.tistory.com/33
    https://hellowoori.tistory.com/48

    - 선택 정렬 - 
    https://gmlwjd9405.github.io/2018/05/06/algorithm-selection-sort.html
    선택정렬이 불안정 정렬인 이유 https://mygumi.tistory.com/94

    - 삽입 정렬 - 
    https://blockdmask.tistory.com/98
    
    - STL에서 채택한 정렬방식 -
    https://debugjung.tistory.com/entry/stl%EC%97%90%EC%84%9C-%EA%B5%AC%ED%98%84%ED%95%9C-intro-sort-%EC%B0%B8%EC%A1%B0
*/