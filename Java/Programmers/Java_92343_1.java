import java.util.ArrayList;

public class Java_92343_1 {
    public static void main(String[] args) {
        Solution_92343_1 test = new Solution_92343_1();

        int [] info = {0,0,1,1,1,0,1,0,1,0,1,1};
        int [][] edges = {
            {0,1},{1,2},{1,4},{0,8},{8,7},{9,10},{9,11},{4,3},{6,5},{4,6},{8,9}
        };
        int answer = test.solution(info, edges);

        System.out.println(answer);
    }
}

class Solution_92343_1 {
    static ArrayList<ArrayList<Integer>> adj;
    static int MaxSheep = 0;
    static int [] infos;
    public int solution(int[] info, int[][] edges) {
        int answer = 0;

        infos = new int [info.length];

        for (int i = 0; i < info.length; i++)
            infos[i] = info[i];

        adj = new ArrayList<>();
        for (int i = 0; i <= info.length; i++) {
            adj.add(new ArrayList<>());
        }
        for (int [] edge : edges) {
            int a = edge[0];
            int b = edge[1];

            adj.get(a).add(b);
            adj.get(b).add(a);
        }

        ArrayList<Integer> nextNode = new ArrayList<>();
        boolean [] visited = new boolean [info.length + 1];
        visited[0] = true;
        dfs(0, 1, 0, nextNode, visited);

        answer = MaxSheep;
        return answer;
    }
/**
 *  dfs
 * cur : 현재 노드
 * sheep : 현재 양 수
 * wolf : 현재 늑대 수
 * nextNodeList : 다음 노드 리스트
 * visited : 방문 여부
 * 
 * 1. 양 최대값 설정
 * 2. 다음 방문 가능 노드 리스트(nextNodeList)를 만든다.
 * - 정점으로 연결되어 있는 노드이면서 방문하지 않은 경우 노드를 추가한다.
 * - 이전 노드 리스트(curNodeList) 를 방문하면서 노드를 추가한다.
 * 3. nextNodeList에서 dfs를 실행한다.
 * - 방문하지 않은 경우
 * - 다음 지점이 늑대인 경우 wolf + 1 < sheep 보다 커야함
 * - 다음 지점이 양인 경우 아무조건 없이 방문
 * 
 * @param cur
 * @param sheep
 * @param wolf
 * @param nextNodeList
 * @param visited
 * @param infos
 */
    public static void dfs(int cur, int sheep, int wolf, ArrayList<Integer> curNodeList, boolean [] visited) {

        if (sheep > MaxSheep) {
            MaxSheep = sheep;
        }

        ArrayList <Integer> nextNodeList = new ArrayList<>();
        boolean [] chk = new boolean [17];

        for (int next : adj.get(cur)) {
            if (!visited[next]) {
                nextNodeList.add(next);
                chk[next] = true;
            }
        }

        for (int next : curNodeList) {
            if (!visited[next] && !chk[next]) {
                nextNodeList.add(next);
                chk[next] = true;
            }
        }

        for (int next : nextNodeList) {
            if (visited[next] == true)
                continue;

            if (infos[next]  == 1) {
                if (wolf + 1 < sheep) {
                    visited[next] = true;
                    dfs(next, sheep, wolf + 1, nextNodeList, visited);
                    visited[next] = false;
                }
            } else {
                visited[next] = true;
                dfs(next, sheep + 1, wolf, nextNodeList, visited);
                visited[next] = false;
            }
        }
    }
}