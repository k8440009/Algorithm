"""
    K 경유지 내 가장 저렴한 항공권

    시작점에서 도착점까지의 가장 저렴한 가격을 계산하되, K개의 경유지 이내에 도착하는 가격을 리턴하라
    경로가 존재하지 않을 경우 -1을 리턴한다.

    n : 노드
    fligts : [start, end, price]
    src : 시작
    dst : 목적지
    k :
    다익스트라 응용
    타임아웃 발생 (사이클 체크 필요) => visited 변수 추가
    ## 참고
    https://ryuwc.tistory.com/124
"""
import collections
import heapq
from typing import List


class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, K: int) -> int:
        graph = collections.defaultdict(list)

        for u, v, w in flights:
            graph[u].append((v, w))

        # 사이클 방문 여부 체크
        visited = collections.defaultdict(int)
        # (가격, 정점, 경유지)
        Q = [(0, src, 0)]

        while Q:
            price, node, k = heapq.heappop(Q)

            if node == dst:
                return price
            # visit에 있어도 방문 해도 됨
            # 하지만, 그 거리가 현재 거리보다 더 크면 안됨, 비용은 이미 최소화 되있음
            if node not in visited or visited[node] > k:
                visited[node] = k
                if k <= K:
                    for v, w in graph[node]:
                        alt = price + w
                        heapq.heappush(Q, (alt, v, k + 1))
        return -1
