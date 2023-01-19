"""
    일정 재구성
    [from, to]로 구성된 항공권 목록을 이용해 JFK에서 출발하는 여행 일정을 구성하라
    여러 일정이 있는 경우 사전 어휘순으로 방문한다.

    일정 그래프 반복
"""
from typing import List
class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
