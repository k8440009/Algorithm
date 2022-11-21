import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Java_1012 {
    static int N, M, K;
    static int [] dr = {-1, 1, 0, 0};
    static int [] dc = {0, 0, -1, 1};

    static int [][] map;
    static boolean [][] visited;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int testCase = Integer.parseInt(br.readLine());

        for (int tc = 0; tc < testCase; tc++){
            String [] tokens = br.readLine().split(" ");
            M = Integer.parseInt(tokens[0]);
            N = Integer.parseInt(tokens[1]);
            K = Integer.parseInt(tokens[2]);

            map = new int[N][M];
            visited = new boolean[N][M];

            for (int k = 0; k < K; k++){
                String [] param = br.readLine().split(" ");
                map[Integer.parseInt(param[1])][Integer.parseInt(param[0])] = 1;
            }

            int count = 0;
            for (int r = 0; r < N; r++){
                for (int c = 0; c < M; c++){
                    if (map[r][c] == 1 && visited[r][c] == false){
                        count += 1;
                        dfs(r, c);
                    }
                }
            }
            System.out.println(count);
        }
    }

    public static void dfs(int r, int c){

        visited[r][c] = true;
        for (int dir = 0; dir < 4; dir ++){
            int nr = r + dr[dir];
            int nc = c + dc[dir];

            if (nr >= 0 && nr < N && nc >= 0 && nc < M){
                if (map[nr][nc] == 1 && visited[nr][nc] == false){
                    dfs(nr, nc);
                }
            }
        }
    }
}