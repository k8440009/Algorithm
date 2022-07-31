import java.util.LinkedList;
import java.util.Queue;

public class Java_1829 {
    public static void main(String[] args) {
        Solution_1829 test = new Solution_1829();
        int [] answers = new int[2];
        int m = 6;
        int n = 4;
        int [][] picture = {
            {1, 1, 1, 0}, 
            {1, 2, 2, 0}, 
            {1, 0, 0, 1}, 
            {0, 0, 0, 1}, 
            {0, 0, 0, 3}, 
            {0, 0, 0, 3}
        };
        answers = test.solution(m, n, picture);

        for (int answer : answers) {
            System.out.println(answer);
        }
    }
}

class Data {
    int r;
    int c;

    Data(int r, int c) {
        this.r = r;
        this.c = c;
    }
}

class Solution_1829 {
    static int [] dr = {-1, 1, 0, 0};
    static int [] dc = {0, 0, -1, 1};
    static int N;
    static int M;
    static int numberOfArea = 0;
    static int maxSizeOfOneArea = 0;

    public int[] solution(int m, int n, int[][] picture) {
        int[] answer = new int[2];
        boolean [][] visited = new boolean[m][n];

        M = m;
        N = n;
        numberOfArea = 0;
        maxSizeOfOneArea = 0;

        for (int r = 0; r < M; r++) {
            for (int c = 0; c < N; c++) {
                if (picture[r][c] != 0 && visited[r][c] == false) {
                    bfs(r, c, picture, visited);
                    numberOfArea += 1;
                }
            }
        }

        answer[0] = numberOfArea;
        answer[1] = maxSizeOfOneArea;
        return answer;
    }

    private void bfs(int r, int c, int[][] picture, boolean [][] visited) {
        Queue<Data> que = new LinkedList<Data>();
        que.add(new Data(r, c));
        visited[r][c] = true;
        int cnt = 1;
        int nowData = picture[r][c];

        while(!que.isEmpty()) {
            Data now = que.poll();

            for (int dir = 0; dir < 4; dir++) {
                int nr = now.r + dr[dir];
                int nc = now.c + dc[dir];

                if (nr < 0 || nr >= M || nc < 0 || nc >= N || picture[nr][nc] == 0 || visited[nr][nc] == true) {
                    continue;
                }

                if (picture[nr][nc] == nowData){
                    que.add(new Data(nr, nc));
                    visited[nr][nc] = true;
                    cnt += 1;
                }
            }
        }

        if (cnt > maxSizeOfOneArea) {
            maxSizeOfOneArea = cnt;
        }
    }
}
