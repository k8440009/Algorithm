"""
    태스크 스케쥴러
    https://leetcode.com/problems/task-scheduler/

    우선순위 큐 아이디어를 채용하되, Counter를 이용하여 구현
"""
import collections
from typing import List


class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        counter = collections.Counter(tasks)
        result = 0

        while True:
            sub_count = 0
            # 개수 순 추출
            for tasks, _ in counter.most_common(n + 1):
                sub_count += 1
                result += 1

                counter.subtract(tasks)
                # 0 이하힌 아이템을 목록에서 완전히 제거
                counter += collections.Counter()

            if not counter:
                break

            result += n - sub_count + 1

        return result
