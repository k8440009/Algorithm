import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;

class Bridge implements Comparable<Bridge>{
    int st;
    int en;
    int length;

    Bridge(int st, int en, int length) {
        this.st = st;
        this.en = en;
        this.length = length;
    }

    @Override
    public int compareTo(Bridge o) {
        return this.length - o.length;
    }

    
}
class Position {
    int r;
    int c;

    Position(int r, int c) {
        this.r = r;
        this.c = c;
    }
}

public class Java_17472_2 {
    /*
    * 1. 다리 길이 계산하기
    * 0) 섬 채번
    * 1) 다리 시작점, 종료점 길이 체크
    * 2) 크루스칼 알고리즘 적용
    * 3) 0 보다 작은 경우가 1번 초과하는 경우 연결 안됨
    */
    static int [] dr = {-1, 0, 1, 0};
    static int [] dc = {0, 1, 0, -1};
    static int [] p = new int [8];
    static int [][] board;
    static boolean [][] visited;
    static ArrayList<Bridge> bridges = new ArrayList<>();
    static ArrayList<ArrayList<Position>> islands = new ArrayList<>(); 

    static int islandsCnt = 0;
    static int N;
    static int M;
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String [] tokens = br.readLine().split(" ");
        N = Integer.parseInt(tokens[0]);
        M = Integer.parseInt(tokens[1]);

        board = new int [N][M];
        visited = new boolean [N][M];

        for (int r = 0; r < N; r++) {
            tokens = br.readLine().split(" ");

            for (int c = 0; c < M; c++) {
                board[r][c] = Integer.parseInt(tokens[c]);
            }
        }

        islands.add(new ArrayList<>());
        for (int r = 0; r  < N; r++) {
            for (int c = 0; c < M; c++) {
                if (board[r][c] == 1 && !visited[r][c]) {
                    islandsCnt += 1;
                    islands.add(new ArrayList<>());
                    bfs(r, c);
                }
            }
        }

        for (int i = 0; i < islands.size(); i++) {
            if (i != 0){
                for (Position position : islands.get(i)) {
                    getBridgeLength(position);
                }
            }
        }

        Collections.sort(bridges);
        Arrays.fill(p, -1);

        // printBoard();
        // for (Bridge bridge : bridges) {
        //     System.out.println("st=" + bridge.st + " en=" + bridge.en + " len=" + bridge.length);
        // }

        int answer = 0;
        int cnt = 0;
        for (Bridge bridge : bridges) {
            if (!is_diff_group(bridge.st, bridge.en)) {
                continue;
            }
            answer += bridge.length;
            cnt += 1;

            if (cnt == islandsCnt - 1) {
                break;
            }
        }
        //printBoard();
        cnt = 0;
        for (int i = 1; i <= islandsCnt; i++) {
           //System.out.print(p[i] + " ");
            if (p[i] < 0) {
                cnt += 1;
            }
        }
        //System.out.println();

        if (cnt == 1) {
            System.out.println(answer);
        } else {
            System.out.println(-1);
        }

        // for (int i = 1; i < bridges.size(); i++) {
        //     System.out.println(i);
        //     for (Bridge bridge : bridges.get(i)) {
        //         System.out.println("r=" + bridge.r + " c=" + bridge.c + " length=" + bridge.length + " dir=" + bridge.dir + " node=" + bridge.node);
        //     }
        // }
    }

    public static int find (int x) {
        if (p[x] < 0) {
            return x;
        }
        return p[x] = find(p[x]);
    }

    static boolean is_diff_group (int u, int v) {
        u = find(u);
        v = find(v);

        if (u == v) {
            return false;
        }

        if (p[u] == p[v]) {
            p[u] -= 1;
        }

        if (p[u] < p[v]) {
            p[v] = u;
        } else {
            p[u] = v;
        }

        return true;
    }

    static void getBridgeLength(Position position) {
        int index = board[position.r][position.c];
        for (int dir = 0; dir < 4; dir++) {
            int sr = position.r;
            int sc = position.c;
            boolean flag = false;
            int length = 0;
            int node = 0;

            while(true) {
                int nr = sr + dr[dir];
                int nc = sc + dc[dir];

                if (nr < 0 || nr >= N || nc < 0 || nc >= M || board[nr][nc] == index)
                    break;

                if (board[nr][nc] > 0) {
                    flag = true;
                    node = board[nr][nc];
                    break;
                }

                sr = nr;
                sc = nc;
                length += 1;
            }

            if (flag && length > 1) {
                bridges.add(new Bridge(index, node, length));
                // bridges.get(index).add(new Bridge(position.r, position.c, length, dir, node));
            }
        }
    }

    static void bfs(int sr, int sc) {
        Queue <Position> queue = new LinkedList<>();
        queue.add(new Position(sr, sc));
        board[sr][sc] = islandsCnt;
        visited[sr][sc] = true;

        islands.get(islandsCnt).add(new Position(sr, sc));
        // islands.add(ne)

        while(!queue.isEmpty()) {
            Position cur = queue.poll();

            for (int dir = 0; dir < 4; dir++) {
                int nr = cur.r + dr[dir];
                int nc = cur.c + dc[dir];

                if (nr < 0 || nr >= N || nc < 0 || nc >= M || board[nr][nc] == 0 || visited[nr][nc]) {
                    continue;
                }
                
                queue.add(new Position(nr, nc));
                board[nr][nc] = islandsCnt;
                visited[nr][nc] = true;
                islands.get(islandsCnt).add(new Position(nr, nc));
            }
        }
    }

    static void printBoard() {
        System.out.println();
        for (int r = 0; r < N; r++) {
            for (int c = 0; c < M; c++) {
                System.out.print(board[r][c] + " ");
            }
            System.out.println();
        }
    }
}
