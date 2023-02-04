"""
    해밍 거리
    https://leetcode.com/problems/hamming-distance/

    XOR 풀이
"""
class Solution:
    def hammingDistance(self, x: int, y: int) -> int:
        return bin(x ^ y).count('1')