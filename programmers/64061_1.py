# 크레인 인형뽑기 게임
# https://programmers.co.kr/learn/courses/30/lessons/64061
def solution(board, moves):
    answer = 0
    st = list()
    R = len(board)
    for move in moves:
        move -=1
        for r in range(R):
            if board[r][move] != 0:
                if len(st) > 0:
                    if st[-1] == board[r][move] :
                        st.pop()
                        answer += 2
                    else :
                        st.append(board[r][move])
                else:
                    st.append(board[r][move])
                board[r][move] = 0
                break
    return answer