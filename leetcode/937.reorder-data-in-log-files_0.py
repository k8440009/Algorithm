"""
    937. 로그 파일 재정렬
    - 로그 배열을 받았다. 각각의 로그는 구분 문자로 공백을 사용하여, 첫번째 단어는 식별자다.
    - 두개의 타입의 로그가 있다.
        - 문자 로그 : 모든 단어(식별자 제외)가 영어 소문자이다.
        - 숫자 로그 : 모든 단어(식별자 제외)가 숫자이다.
    - 이 로그는 아래와 같은 방식으로 재 정렬 되어야한다.
        1. 문자 로그가 숫자 로그보다 앞에 온다.
        2. 문자 로그는 사전식으로 정렬되어 있다. 그들의 내용이 동일 할 경우, 식별자의 사전식 순서로 정렬되어야한다.
        - 기본으로는 내용으로 정렬, 동일한 경우 식별자로 정렬
        3. 숫자로그는 입력 순서대로한다.

    https://leetcode.com/problems/reorder-data-in-log-files/

    lexicographically : 사전식 순서
    delimited : 구분문자
"""
from typing import List


class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        digit_logs = []
        letter_logs = []
        answer_logs = []

        for log in logs:
            split_log = log.split(" ")
            # print("split_log=", split_log)
            # print("len=", len(split_log))
            digit = True
            for index in range(1, len(split_log)):
                # print("data=", split_log[index])
                if split_log[index].isalpha():
                    digit = False
                    break
            if digit:
                digit_logs.append(log)
            else:
                letter_logs.append(log)

        # print("letter_logs=", letter_logs)
        tuples = []
        for log in letter_logs:
            split_log = log.split(" ")
            # print("identifier=", split_log[0])
            # print("datas=", log[len(split_log[0])::])
            tmp = [split_log[0], log[len(split_log[0])::]]
            # value = split_log + log[len(split_log[0]) + 1::]
            value = tuple(tmp)
            # print("value=", value)
            tuples.append(value)
        # print("===== 정렬 전 =====")
        # print(tuples)
        # print("===== 정렬 후 =====")
        new_tuples = sorted(tuples, key=lambda data: (data[1], data[0]))
        # print(new_tuples)
        ## 튜플을 리스트로
        new_letter_logs = []
        for new_tuple in new_tuples:
            # 튜플을 문자열로
            new_letter_logs.append(''.join(new_tuple))
        # print(new_letter_logs)

        for log in new_letter_logs:
            answer_logs.append(log)
        for log in digit_logs:
            answer_logs.append(log)

        # print("===== 리턴 =====")
        return answer_logs