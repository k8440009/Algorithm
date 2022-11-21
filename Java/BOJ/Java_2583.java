import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;

public class Java_2583 {
    static int N, M, K, areaCnt, totalCnt = 0;
    static int [][] board = null;
    static boolean [][] visited = null;
    static int [] dr = {-1, 0, 1, 0};
    static int [] dc = {0, -1, 0, 1};

    static ArrayList <Integer> arrayList = new ArrayList<Integer>();
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String [] tokens = br.readLine().split(" ");
        M = Integer.parseInt(tokens[0]);
        N = Integer.parseInt(tokens[1]);
        K = Integer.parseInt(tokens[2]);

        board = new int [N][M];
        visited = new boolean[N][M];

        for (int i = 0; i < K; i++){
            tokens = br.readLine().split(" ");

            int r1 = Integer.parseInt(tokens[0]);
            int c1 = Integer.parseInt(tokens[1]);
            int r2 = Integer.parseInt(tokens[2]);
            int c2 = Integer.parseInt(tokens[3]);

            for (int r = r1; r < r2; r++){
                for (int c = c1; c < c2; c++){
                    board[r][c] = 1;
                }
            }
        }
        for (int r = 0; r < N; r ++){
            for (int c = 0; c < M; c ++){
                if (board[r][c] == 0 && visited[r][c] == false){
                    areaCnt = 0;
                    totalCnt += 1;
                    dfs(r, c);
                    arrayList.add(areaCnt);
                }
            }
        }
        Collections.sort(arrayList);
        System.out.println(totalCnt);
        Iterator iter = arrayList.iterator();
        while(iter.hasNext()){
            System.out.print(iter.next() + " ");
        }
    }

    public static void dfs(int r, int c) {
        visited[r][c] = true;
        areaCnt += 1;
        for (int dir = 0; dir < 4; dir++){
            int nr = r + dr[dir];
            int nc = c + dc[dir];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M){
                continue;
            }
            if (board[nr][nc] == 1 || visited[nr][nc] == true){
                continue;
            }
            dfs(nr, nc);
        }
    }
}