def solution(board):

    for y in range(1, len(board)):
        for x in range(1, len(board[y])):
            if board[y][x] == 1:
                board[y][x] = min(
                    board[y-1][x-1], min(board[y-1][x], board[y][x-1])) + 1

    answer = 0

    for y in range(len(board)):
        for x in range(len(board[x])):
            answer = max(answer, board[y][x])
    return answer
    # return max([item for row in board for item in row])**2
