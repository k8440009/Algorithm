def solution(arr):
    answer = []
    for i in range(len(arr) - 1) :
        if(i == 0) :
            answer.append(arr[0])
        if(arr[i] != arr[i+1]) :
            answer.append(arr[i+1])
    return answer