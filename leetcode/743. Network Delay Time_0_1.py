"""
    네트워크 딜레이 타임
    https://leetcode.com/problems/network-delay-time/

    K부터 출발해 모든 노드가 신호를 받을 수 있는 시간을 계산하라. 불가능할 경우 -1을 리턴한다.
    입력값 (u, v, w)는 각각 출발지, 도착지, 소요 시간으로 구성되며, 전체 노드의 개수는 N으로 입력 받는다.
    u : 출발지
    v : 도착지
    w : 소요시간

    다익스트라 알고리즘 구현
"""
import collections
import heapq
from typing import List


class Solution:
    def networkDelayTime(self, times: List[List[int]], N: int, K: int) -> int:
        graph = collections.defaultdict(list)

        for u, v, w in times:
            graph[u].append((v, w))

        # 소요시간, 정점
        Q = [(0, K)]
        dist = collections.defaultdict(int)

        # 우선 순위 큐 최솟값 기준으로 정점까지 최단 경로 삽입
        while Q:
            time, node = heapq.heappop(Q)
            if node not in dist:
                dist[node] = time
                for v, w in graph[node]:
                    alt = time + w
                    heapq.heappush(Q, (alt, v))

        # 모든 노드의 최단 경로 존재 여부 판별
        if len(dist) == N:
            return max(dist.values())
        return -1