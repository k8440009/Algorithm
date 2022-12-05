"""
https://leetcode.com/problems/trapping-rain-water/
"""
from typing import List

class Solution:
    def trap(self, height: List[int]) -> int:
        stack = []
        volume = 0
        for i in range(len(height)):
            # 변곡점
            while stack and height[i] > height[stack[-1]]:
                # 스택에서 꺼낸다.
                top = stack.pop()

                if not len(stack):
                    break

                # 이전과의 차이만큼 물 높이 처리
                distance = i - stack[-1] - 1
                print("i={0}, stack[-1]={1}".format(i, stack[-1]))
                print("distance={0}".format(distance))
                waters = min(height[i], height[stack[-1]]) - height[top]
                print("height[i]={0}, height[statck[-1]]={1}, height[top]={2}".format(height[i], height[stack[-1]], height[top]))
                print("waters={0}".format(waters))
                volume += distance * waters
                print("volume={0}".format(volume))

            stack.append(i)
        return volume

a = Solution()
height = [0,1,0,2,1,0,1,3,2,1,2,1]
print(a.trap(height))