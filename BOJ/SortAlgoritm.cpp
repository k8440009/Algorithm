#include <iostream>
#include <vector>
using namespace std;
/*
    Sort
    1. 안정 정렬 : 정렬 이후 동일 한 값에 대해 기존 순서 유지 
    1) 삽입 정렬 (selection sort), O(N^2)
    2) 병합 정렬 (merge sort), O(NlogN)
    
    2. 불안정 정렬 :정렬 이후 동일 한 값에 대해 기존 순서가 바뀔 수 있음
    1) 퀵 소트 (quick sort), O(NlogN)
*/
// 선택 정렬
void selectionSort(vector<int> &v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        int now = i;
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[now] >= v[j])
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
}