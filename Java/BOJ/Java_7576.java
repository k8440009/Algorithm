import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;

class tomato {
    int r;
    int c;

    tomato(int r, int c){
        this.r = r;
        this.c = c;
    }
}

public class Java_7576 {
    static int N, M;
    static int board [][] = null;
    static int visited[][] = null;
    static Queue <tomato> que = null;
    static int [] dr = {1, 0, -1, 0};
    static int [] dc = {0, 1, 0, -1};
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String [] params = br.readLine().split(" ");
        N = Integer.parseInt(params[1]);
        M = Integer.parseInt(params[0]);

        board = new int [N][M];
        visited = new int [N][M];
        que = new LinkedList<tomato>();

        for (int r = 0; r < N; r++){
            String [] tokens = br.readLine().split(" ");
            Arrays.fill(visited[r], -1);

            for (int c = 0; c < M; c++){
                board[r][c] = Integer.parseInt(tokens[c]);
                if (board[r][c] == 1){
                    que.offer(new tomato(r,c));
                    visited[r][c] = 0;
                }
            }
        }

        bfs();

        int maxCnt = -1;
        boolean flag = false;
        for (int r = 0; r < N; r++){
            for (int c = 0; c < M; c++){
                if (board[r][c] != -1){
                    if (visited[r][c] > maxCnt) {
                        maxCnt = visited[r][c];
                    }

                    if (visited[r][c] == -1) {
                        flag = true;
                        break;
                    }
                }

                if (flag) {
                    maxCnt = -1;
                    break;
                }
            }
        }
        System.out.println(maxCnt);
    }
    
    private static void bfs(){
        while(!que.isEmpty()){
            tomato t = que.poll();

            int r = t.r;
            int c = t.c;

            for (int dir = 0; dir < 4; dir++){
                int nr = r + dr[dir];
                int nc = c + dc[dir];

                if (nr < 0 || nr >= N || nc < 0 || nc >= M) {
                    continue;
                }

                if (board[nr][nc] == 0 && visited[nr][nc] == -1){
                    que.add(new tomato(nr, nc));
                    visited[nr][nc] = visited[r][c] + 1;
                }

            }
        }
    }
}
