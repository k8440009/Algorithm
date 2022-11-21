import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

/**
 * 0. 데이터
 * 0) 격자
 * - N * N
 * - 빈칸, 벽 바이러스 
 * - M : 활성으로 바꿀 바이러스
 *  
 * 1) 바이러스
 * - 활성, 비활성
 * - 복제
 * - 활성 바이러스가 비활성쪽으로 가면 증식이 
 * 
 * 2. 시뮬레이션
 * 1) 전체 바이러스 중 M개를 조합으로 선택
 * 2) 바이러스 queue에 넣기
 * 3) bfs
 * 4) 전체 칸 체크
 *
 */
class Location {
	int r, c, t;
	Location(int r, int c, int t) {
		this.r = r;
		this.c = c;
		this.t = t;
	}
}

public class Java_17142 {
	static boolean printFlag = false;
	
	static int N; // 격자 크기
	static int M; // 바이러스
	static int minTime = Integer.MAX_VALUE;
	static boolean success = false;
	static int saveArea = 0;
	static int [][] board;
	static int [] dr = {-1, 0, 1, 0};
	static int [] dc = {0, -1, 0, 1};
	static ArrayList<Location> virus = new ArrayList<>();
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String [] tokens = br.readLine().split(" ");
		N = Integer.parseInt(tokens[0]);
		M = Integer.parseInt(tokens[1]);
		
		board = new int [N][N];
		
		for (int r = 0; r < N; r++) {
			tokens = br.readLine().split(" ");
			for (int c = 0; c < N; c++) {
				board[r][c] = Integer.parseInt(tokens[c]);
				
				if (board[r][c] == 2) {
					virus.add(new Location(r, c, 0));
				} else if (board[r][c] == 0) {
					saveArea += 1;
				}
			}
		}
		// 0 ~ 4
		boolean [] selected = new boolean[virus.size()];
		
		// 1. 활성 바이러스 선택
		dfs(0, 0, selected);
		// 3. 정리
		if (success) {
			System.out.println(minTime);
		} else {
			System.out.println(-1);
		}
		
	}
	static void bfs(boolean [] selected) {
		Queue<Location> queue = new LinkedList<>();
		int [][] visited = new int[N][N];
		int usedTime = 0;
		boolean flag = true;
		int saveCnt = saveArea;
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				visited[r][c] = -1;
			}
		}
		
		for (int i = 0; i < virus.size(); i++) {
			if (selected[i]) {
				int r = virus.get(i).r;
				int c = virus.get(i).c;
				queue.add(new Location(r, c, 0));
				visited[r][c] = 0;
			}
		}
		// 2. 바이러스 퍼트리기
		while (!queue.isEmpty()) {
			Location cur = queue.poll();
			
			if (saveCnt == 0)
				break;
			
			for (int dir = 0; dir < 4; dir++) {
				int nr = cur.r + dr[dir];
				int nc = cur.c + dc[dir];
				
				if (nr < 0 || nr >= N || nc < 0 || nc >= N || visited[nr][nc] > -1 || board[nr][nc] == 1)
					continue;
				
				if (board[nr][nc] == 0) {
					queue.add(new Location(nr, nc, cur.t + 1));
					visited[nr][nc] = cur.t + 1;
					saveCnt -= 1;
				} else if (board[nr][nc] == 2) { // 바이러스
					queue.add(new Location(nr, nc, cur.t + 1));
					visited[nr][nc] = cur.t + 1;
				}
			}
		}
		// 바이러스 퍼짐 체크
		if (flag) {			
			for (int r = 0; r < N; r++) {
				for (int c = 0; c < N; c++) {
					
					if (visited[r][c] > -1) {
						if (visited[r][c] > usedTime)
							usedTime = visited[r][c];
					}
					
					if (board[r][c] == 0 && visited[r][c] == -1) {
						flag = false;
						break;
					}
				}
				
				if (!flag)
					break;
			}
		}
		// 모두 다 퍼진 경우
		if (flag) {
			success = true;
			if (minTime > usedTime)
				minTime = usedTime;
		}
	}
	
	static void dfs(int index, int cnt, boolean [] selected) {
		if (cnt == M) { // 선택 M개
			// 2. bfs 탐색
			bfs(selected);
			return ;
		}
		
		for (int i = index; i < virus.size(); i++) {
			if (selected[i])
				continue;
			
			selected[i] = true;
			dfs (i, cnt + 1, selected);
			selected[i] = false;
		}
	}
	
	static void printBoard(int [][] src) {
		if (!printFlag)
			return ;
		
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				System.out.print(src[r][c] + " ");
			}
			System.out.println();
		}
	}
}
