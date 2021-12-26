import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;

public class Java_2178 {
    static int N, M;
    static int [] dr = {-1, 1, 0, 0};
    static int [] dc = {0, 0, -1, 1};

    static int [][] map;
    static boolean [][] visited;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String [] param = br.readLine().split(" ");

        N = Integer.parseInt(param[0]);
        M = Integer.parseInt(param[1]);

        map = new int[N][M];
        visited = new boolean [N][M];

        for (int r = 0; r < N; r++){
            String [] token = br.readLine().split("");
            for (int c = 0; c < M; c++){
                map[r][c] = Integer.parseInt(token[c]);
            }
        }

        System.out.println(bfs(0, 0));
    }

    public static int bfs(int r, int c){
        int minCount = N * M;
        Queue <int []> que = new LinkedList<>();

        que.offer(new int [] {r,c, 1});
        visited[r][c] = true;

        while(!que.isEmpty()){
            int [] cur = que.poll();
            int row = cur[0];
            int col = cur[1];
            int count = cur[2];

            if (row == N - 1 && col == M - 1){
                minCount = Math.min(minCount, count);
            }

            for (int dir = 0; dir < 4; dir++){
                int nextRow = row + dr[dir];
                int nextCol = col + dc[dir];

                if (nextRow >= 0 && nextRow < N && nextCol >= 0 && nextCol < M){
                    if (!visited[nextRow][nextCol] && map[nextRow][nextCol] == 1){
                        visited[nextRow][nextCol] = true;
                        que.offer(new int [] {nextRow, nextCol, count + 1});
                    }
                }
            }
            
        }
        return minCount;
    }
}