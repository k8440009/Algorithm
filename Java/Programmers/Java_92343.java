import java.util.ArrayList;
/**
 * https://developer-ellen.tistory.com/166
 * https://velog.io/@topqr123q/%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%A8%B8%EC%8A%A4-2022-KAKAO-BLIND-RECRUITMENT-%EC%96%91%EA%B3%BC-%EB%8A%91%EB%8C%80-by-Java
 * https://lovelyunsh.tistory.com/237
 */
public class Java_92343 {
    public static void main(String[] args) {
        Solution_92343 test = new Solution_92343();

        int [] info = {0,0,1,1,1,0,1,0,1,0,1,1};
        int [][] edges = {
            {0,1},{1,2},{1,4},{0,8},{8,7},{9,10},{9,11},{4,3},{6,5},{4,6},{8,9}
        };
        int answer = test.solution(info, edges);

        System.out.println(answer);
    }
}

class Solution_92343  {
    static int maxSheep;
    static ArrayList <Integer> [] connect;
    static int [] infos;
    static boolean [][][] visited;
    public int solution(int[] info, int[][] edges) {
        int answer = 0;

        infos = info;
        connect = new ArrayList[info.length];
        for (int i = 0; i < info.length; i++) {
            connect[i] = new ArrayList<Integer>();
        }

        for (int i = 0; i < edges.length; i++) {
            int a = edges[i][0];
            int b = edges[i][1];

            connect[a].add(b);
            connect[b].add(a);
        }

        visited = new boolean[info.length][info.length + 1][info.length + 1];

        dfs(0, 0, 0);

        answer = maxSheep;
        return answer;
    }

    public static void dfs(int sheep, int wolf, int now) {
        if (infos[now] == 0) {
            sheep += 1;
        } else if (infos[now] == 1) {
            wolf += 1;
        }

        if (wolf >= sheep) {
            return ;
        }

        if (sheep > maxSheep) {
            maxSheep = sheep;
        }

        for (int i = 0; i < connect[now].size(); i++) {
            int next = connect[now].get(i);
            int temp = infos[now];
            if (!visited[next][sheep][wolf]) {
                infos[now] = -1;
                visited[now][sheep][wolf] = true;
                dfs(sheep, wolf, next);
                infos[now] = temp;
                visited[now][sheep][wolf] = false;
            }
        }
    }
}
