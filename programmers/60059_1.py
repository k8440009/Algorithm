# 자물쇠와 열쇠
# https://programmers.co.kr/learn/courses/30/lessons/60059
import copy
def rotate(key):
	R, C = len(key), len(key[0])
	tmp = [[0 for _ in range(C)] for _ in range(R)]
	for r in range(R):
		for c in range(C):
			tmp[c][R - 1 - r] = key[r][c]
	return tmp

def solve(s_r,s_c, k_r, N,M, key, lock):
	tmp_lock = copy.deepcopy(lock)
	k_c = 0
	for r in range(k_r, M):
		for c in range(M):
			if key[r][c] == tmp_lock[r][c]:
				return False
			elif key[r][c] == 1 and tmp_lock[r][c] == 0:
				tmp_lock[r][c] = 1
	for r in range(N):
		for c in range(N):
			if tmp_lock[r][c] == 0:
				return False
	return True

def solution(key, lock):
	answer = False
	M, N = len(key), len(lock)
	for r in range(N):
		for c in range(M):
			tmp = key
			for _ in range(4):
				for k_r in range(M):
					if solve(r,c, k_r, N,M, tmp, lock):
						answer = True
						return answer
				tmp = rotate(tmp)
	return answer
# 참고자료
# https://shoark7.github.io/programming/algorithm/rotate-2d-array