import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

class Location {
    int r, c;

    Location(int r, int c) {
        this.r = r;
        this.c = c;
    }
}
public class Java_16234 {
    static int N, L, R;
    static int [] dr = {-1, 0, 1, 0};
    static int [] dc = {0, 1, 0, -1};
    static int [][] board = null;
    static boolean [][] visited = null;
    static boolean peopleMoveYn = false;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String [] params = br.readLine().split(" ");
        N = Integer.parseInt(params[0]);
        L = Integer.parseInt(params[1]);
        R = Integer.parseInt(params[2]);

        board = new int[N][N];
        for (int r = 0; r < N; r++) {
            String [] tokens = br.readLine().split(" ");
            for (int c = 0; c < N; c++) {
                board[r][c] = Integer.parseInt(tokens[c]);
            }
        }

        int time = 0;
        while (true) {
            peopleMoveYn = false;
            // 시간 초과
            if (time > 2000) {
                break;
            }

            int [][] moveBoard = new int [N][N];
            boolean [][] visited = new boolean[N][N];

            for (int r = 0; r < N; r++) {
                for (int c= 0; c < N; c++) {
                    if (!visited[r][c]) {
                        bfs(r, c, moveBoard, board, visited);
                    }
                }
            }
            // 인구이동 여부
            if (!peopleMoveYn) {
                break;
            }
            // 인구이동한 경우
            time += 1;
            boardCopy(board, moveBoard);
        }

        System.out.println(time);
    }
    public static void bfs(int sr, int sc, int [][] nextBoard, int [][] nowBoard, boolean [][] visited) {
        Queue <Location> que = new LinkedList<Location>();
        ArrayList <Location> arrList = new ArrayList<Location>();
        int peopleCnt = nowBoard[sr][sc];
        int alianceSize = 1;
        que.add(new Location(sr, sc));
        arrList.add(new Location(sr, sc)); // 위치만 저장
        visited[sr][sc] = true;

        while(!que.isEmpty()) {
            Location cur = que.poll();

            for (int dir = 0; dir < 4; dir++) {
                int nr = cur.r + dr[dir];
                int nc = cur.c + dc[dir];

                if (nr < 0 || nr >= N || nc < 0 || nc >= N || visited[nr][nc])
                    continue;
                
                int diff = Math.abs(board[nr][nc] - board[cur.r][cur.c]);
                if (diff >= L && diff <= R) {
                    que.add(new Location(nr, nc));
                    arrList.add(new Location(nr, nc)); // 위치만 저장
                    visited[nr][nc] = true;
                    peopleCnt += nowBoard[nr][nc];
                    alianceSize += 1;
                }
            }
        }

        int people = peopleCnt / alianceSize;
        for (Location location : arrList) {
            nextBoard[location.r][location.c] = people;
        }
        // 인구이동 했으면 체크
        if (arrList.size() > 1) {
            peopleMoveYn = true;
        }
    }
    // 복사
    public static void boardCopy(int [][] copy, int [][] src) {
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                copy[r][c] = src[r][c];
            }
        }
    }
}