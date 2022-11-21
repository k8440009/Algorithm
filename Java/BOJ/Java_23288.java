import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

class Location {
	int r, c;
	
	Location(int r, int c) {
		this.r = r;
		this.c = c;
	}
}
class Dice {
	/**
	 * 	 1
	 * 3 0 2
	 *   4
	 *   5
	 */
	int [] data = {1,2,3,4,5,6};
	int d = 1;
	int r = 0;
	int c = 0;
	
}
public class Java_23288 {
	static int [][] board;
	static int N, M, K;
	static int [] dr = {-1, 0, 1, 0};
	static int [] dc = {0, 1, 0, -1};
	static boolean flag = false;
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String [] tokens = br.readLine().split(" ");
		
		N = Integer.parseInt(tokens[0]);
		M = Integer.parseInt(tokens[1]);
		K = Integer.parseInt(tokens[2]);
		
		
		board = new int [N][M];
		for (int r = 0; r < N; r++) {
			tokens = br.readLine().split(" ");
			for (int c = 0; c < M; c++) {
				board[r][c] = Integer.parseInt(tokens[c]);
			}
		}
		
		System.out.println(simulation());
		
	}
	
	public static int simulation() {
		// 초기화
		Dice dice = new Dice();
		int totalPoint = 0;
		int k = 0;
		
		printBoardDice(dice, 0);
		while (true) {
			if (k == K)
				break;
			// 1. 주사위가 이동 방향으로 한 칸 굴러간다. 만약, 이동 방향에 칸이 없다면, 이동 방향을 반대로 한 다음 한 칸 굴러간다.
			int nr = dice.r + dr[dice.d];
			int nc = dice.c + dc[dice.d];
			if (nr < 0 || nr >= N || nc < 0 || nc >= M) {
				// 역
				// 0 -> 2
				// 1 -> 3
				// 2 -> 0
				// 3 -> 1
				if (dice.d == 0) {
					dice.d = 2;
				} else if (dice.d == 1) {
					dice.d = 3;
				} else if (dice.d == 2) {
					dice.d = 0;
				} else if (dice.d == 3) {
					dice.d = 1;
				}
				nr = dice.r + dr[dice.d];
				nc = dice.c + dc[dice.d];
			}
			// 2. 주사위가 도착한 칸 (x, y)에 대한 점수를 획득한다.
			totalPoint += bfs(nr, nc);
			// 3. 굴러간 방향에 따라 점수 이동
			moveDice(dice, dice.d);
			if (dice.data[5] > board[nr][nc]) {
				if (dice.d == 0) { // 북 -> 동
					dice.d = 1;
				} else if (dice.d == 1) {
					dice.d = 2;
				} else if (dice.d == 2) {
					dice.d = 3;
				} else if (dice.d == 3) {
					dice.d = 0;
				}
			} else if (dice.data[5] < board[nr][nc]) {
				if (dice.d == 0) { // 북 -> 서
					dice.d = 3;
				} else if (dice.d == 1) { // 동 -> 북
					dice.d = 0;
				} else if (dice.d == 2) { // 남
					dice.d = 1;
				} else if (dice.d == 3) {
					dice.d = 2;
				}
			}
			dice.r = nr;
			dice.c = nc;
			
			k++;
			printBoardDice(dice, k);
		}
		
		return totalPoint;
	}
	
	public static int bfs(int r, int c) {
		Queue<Location> queue = new LinkedList<>();
		boolean [][] visited = new boolean[N][M];
		queue.add(new Location(r, c));
		visited[r][c] = true;
		
		int basis = board[r][c];
		
		int cnt = 1;
		while(!queue.isEmpty()) {
			Location cur = queue.poll();
			
			for (int dir = 0; dir < 4; dir++) {
				int nr = cur.r + dr[dir];
				int nc = cur.c + dc[dir];
				
				if (nr < 0 || nr >= N || nc < 0 || nc >= M) {
					continue;
				}
				
				if (visited[nr][nc] || board[nr][nc] != basis) {
					continue;
				}
				
				queue.add(new Location(nr, nc));
				visited[nr][nc] = true;
				cnt += 1;
			}
		}
		
		return basis * cnt;
	}
	public static void moveDice(Dice dice, int d) {
		/**
		 * 	 1
		 * 3 0 2
		 *   4
		 *   5
		 */
		int [] nx = new int [6];
		if (d == 0) { // 북
			/**
			 * 	 0
			 * 3 4 2
			 *   5
			 *   1
			 */
			nx[1] = dice.data[0];
			nx[5] = dice.data[1];
			nx[2] = dice.data[2];
			nx[3] = dice.data[3];
			nx[0] = dice.data[4];
			nx[4] = dice.data[5];
		} else if (d == 1) { // 동
			/**
			 * 	 1
			 * 5 3 0
			 *   4
			 *   2
			 */
			nx[2] = dice.data[0];
			nx[1] = dice.data[1];
			nx[5] = dice.data[2];
			nx[0] = dice.data[3];
			nx[4] = dice.data[4];
			nx[3] = dice.data[5];
		} else if (d == 2) { // 남
			/**
			 * 	 5
			 * 3 1 2
			 *   0
			 *   4
			 */
			nx[4] = dice.data[0];
			nx[0] = dice.data[1];
			nx[2] = dice.data[2];
			nx[3] = dice.data[3];
			nx[5] = dice.data[4];
			nx[1] = dice.data[5];
		} else { // 서
			/**
			 * 	 1
			 * 0 2 5
			 *   4
			 *   3
			 */
			nx[3] = dice.data[0];
			nx[1] = dice.data[1];
			nx[0] = dice.data[2];
			nx[5] = dice.data[3];
			nx[4] = dice.data[4];
			nx[2] = dice.data[5];
		}
		
		for (int i = 0; i < 6; i++) {
			dice.data[i] = nx[i];
		}
	}
	
	public static void printBoardDice(Dice dice, int k) {
		if (!flag)
			return ;
		
		System.out.println("k=" + k);
		for (int i = 0; i < 6; i++) {
			System.out.println("i=" + (i) + " diec[i]=" + dice.data[i]);
		}
		System.out.println("r=" + (dice.r + 1) + " c=" + (dice.c + 1) + " dice.d=" + dice.d + " num=" + board[dice.r][dice.c]);
	}

}
