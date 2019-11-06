// 이분 탐색 (반복문)
#include <iostream>
using namespace std;
int binarySearch(int data[], int size, int d)
{
    // 시작과 끝 인덱스 저장
    int s = 0;        // 시작
    int e = size - 1; // 끝
    // 1. 시작 인덱스가 끝 인덱스보다 작을 때까지
    while (s <= e)
    {
        // 중간값
        int mid = (s + e) / 2;
        if (data[mid] == d)
            return mid;
        else if (data[mid] > d)
            e = mid - 1;
        else
            s = mid + 1;
    }

    return -1;
}
int main()
{
    int data[] = {1, 3, 6, 8, 11, 23, 111, 114, 213};
    int dataSize = sizeof(data) / sizeof(int);
    // 데이터 배열, 데이터 크기, 목표
    int answer = binarySearch(data, dataSize, 114);
    cout << answer << '\n';
}