"""
    일정 재구성
    [from, to]로 구성된 항공권 목록을 이용해 JFK에서 출발하는 여행 일정을 구성하라
    여러 일정이 있는 경우 사전 어휘순으로 방문한다.

    일정 그래프 반복
"""

import collections
from typing import List

class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        graph = collections.defaultdict(list)
        # 그래프 순서대로 구성
        for a, b in sorted(tickets):
            graph[a].append(b)

        route, stack = [], ['JFK']

        while stack:
            # 반복으로 스택을 구성하되 막히는 부분에서 풀어내는 처리
            while graph[stack[-1]]:
                stack.append(graph[stack[-1]].pop(0))
            route.append(stack.pop())
        # 다시 뒤집어 어휘 순 결과로
        return route[::-1]