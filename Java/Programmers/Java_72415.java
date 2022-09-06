import java.util.ArrayList;
/**
 * 72415
 * 
 * 못 품
 * 
 * 1시간
 * 
 * @since 2022-09-05
 * @author SungSoo Lee
 */
public class Java_72415 {
    public static void main(String[] args) {
        // [[1,0,0,3],[2,0,0,0],[0,0,0,2],[3,0,1,0]]
        // 1, 0
    }
}

class Location {
    int r, c;
    int num = 0;

    Location(int r, int c, int num) {
        this.r = r;
        this.c = c;
        this.num = num;
    }
}
class Solution_72415 {
    // left, top, right down
    static int [] dr = {-1, 0, 1, 0};
    static int [] dc = {0, -1, 0, 1};
    static int minMove = Integer.MAX_VALUE;
    static ArrayList <Location> arrayList = new ArrayList<Location> ();

    public int solution(int[][] board, int r, int c) {
        int answer = 0;

        for (int sr = 0; sr < 4; r++) {
            for (int sc = 0; sc < 4; c++) {
                if (board[r][c] != 0) {
                    arrayList.add(new Location(r, c, board[r][c]));
                }
            }
        }

        // moveCtrlYn(r, c, , board)

        dfs(r, c, 0, 0, board);
        return answer;
    }

    public void dfs (int r, int c, int d, int cnt, int [][] board) {
        if (cnt >= minMove) {
            return ;
        }

        if (checkBoard(board)) {
            if (minMove > cnt) {
                minMove = cnt;
            }
            return ;
        }


        int nextCnt = cnt;
        int [][] nextBoard = new int [4][4];
        
        for (int dir = 0; dir < 4; dir++) {
            Location location = moveCtrlYn(r, c, dir, board);
            if (location.r != -1 && location.c != -1) {
                copyBoard(nextBoard, board);
                
                deleteCard(location.r, location.c, location.num);
                // 수정

                dfs(r, c, dir, nextCnt, nextBoard);
            } else {
                // int nr = r + dr[dir];
                // int nc = c + dc[dir];

                // if (nr < 0 || nr > 4) {
                //     continue;
                // }

                // if (nc < 0 || nc > 4) {
                //     continue;
                // }

                // dfs(nr, nc, 0, cnt, board);
            }
        }

        // 이동..
    }

    public void deleteCard(int sr, int sc, int num) {
        int cnt = 2; // enter

        int er = -1, ec = -1;
        for (Location location : arrayList) {
            if (location.num == num) {
                if (location.r != sr && location.c != sc) {
                    er = location.r;
                    ec = location.c;
                    break;
                }
            }
        }

        // sr, sc;

        // sr = 1, sc = 0

        // er = 2, sc = 2

        int move = Math.min(Math.abs(sr - er), Math.abs(sr - er));
 

        // sr = er or sc == sc 이여야함


    }


    public Location moveCtrlYn(int sr, int sc, int dir, int [][] board) {
        Location location = new Location(-1, -1, -1);

        if (dir == 0) {
            int r = sr;
            int c = sc;
            while(r >= 0) {
                int nr = r + dr[dir];
                int nc = c + dc[dir];

                if (board[nr][nc] != 0) {
                    location.r = nr;
                    location.c = nc;
                    location.num = board[nr][nc];
                    break;
                }
            }
        } else if (dir == 1) {
            int r = sr;
            int c = sc;
            while(c >= 0) {
                int nr = r + dr[dir];
                int nc = c + dc[dir];

                if (board[nr][nc] != 0) {
                    location.r = nr;
                    location.c = nc;
                    location.num = board[nr][nc];
                    break;
                }
            }
        } else if (dir == 2) {
            int r = sr;
            int c = sc;
            while(r < 4) {
                int nr = r + dr[dir];
                int nc = c + dc[dir];

                if (board[nr][nc] != 0) {
                    location.r = nr;
                    location.c = nc;
                    location.num = board[nr][nc];
                    break;
                }
            }
        } else if (dir == 3) {
            int r = sr;
            int c = sc;
            while(c < 4) {
                int nr = r + dr[dir];
                int nc = c + dc[dir];

                if (board[nr][nc] != 0) {
                    location.r = nr;
                    location.c = nc;
                    location.num = board[nr][nc];
                    break;
                }
            }
        }
        return location;
    }


    public void copyBoard(int [][] desc, int [][] src) {
        for (int r = 0; r < 4; r++) {
            for (int c = 0; c < 4; c++) {
                desc[r][c] = src[r][c];
            }
        }
    }

    public boolean checkBoard(int [][] src) {
        for (int r = 0; r < 4; r++) {
            for (int c = 0; c < 4; c++) {
                if (src[r][c] != 0) {
                    return false;
                }
            }
        }
        return true;
    }
}