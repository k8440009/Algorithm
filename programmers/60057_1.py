def solution(s):
	answer = len(s)
	for size in range(1, len(s) + 1):
		# 분할
		tmp, union = [], []
		start = 0
		while start + size <= len(s):
			tmp.append(s[start:start + size])
			start += size
		if len(s) - start > 0:	
			tmp.append(s[start:])
		# 갯수 세기
		idx, u_idx = 0, -1
		prev = ""
		while idx < len(tmp):
			data = tmp[idx]
			if prev == data:
				union[u_idx][1] += 1
			else :
				union.append([data, 1])
				u_idx += 1
			prev = data
			idx += 1
		# 합침
		word = ""
		for i in range(len(union)):
			cnt = str(union[i][1])
			if cnt == '1':
				word += union[i][0]
			else :
				word += (cnt + union[i][0])
		answer = min(answer,len(word))
	return answer