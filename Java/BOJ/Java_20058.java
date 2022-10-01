import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

class Location {
	int r, c;
	Location(int r, int c) {
		this.r = r;
		this.c = c;
	}
}
public class Java_20058 {
	static boolean printFlag = false;
	static int N, Q, L;
	static int M; // 보드
	static int [][] board;
	static int [] dr = {-1, 0, 1, 0};
	static int [] dc = {0, -1, 0, 1};
	static int iceCnt;
	static int maxIceSize;
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String [] tokens = br.readLine().split(" ");
		N = Integer.parseInt(tokens[0]);
		Q = Integer.parseInt(tokens[1]);
		
		M = 2 << (N - 1);
		board = new int [M][M];
		
		for (int r = 0; r < M; r++) {
			tokens = br.readLine().split(" ");
			for (int c = 0; c < M; c++) {
				board[r][c] = Integer.parseInt(tokens[c]);
			}
		}
		
		tokens = br.readLine().split(" ");
		for (int i = 0; i < tokens.length; i++) {
			int step = Integer.parseInt(tokens[i]);
			
			fireStorm(step);
		}

		System.out.println(iceCnt);
		System.out.println(maxIceSize);
	}
	static void fireStorm(int l) {
		iceCnt = 0;
		maxIceSize = 0;
		ArrayList<Location> arr = new ArrayList<>();
		
		if (l != 0) {			
			int len = 2 << (l - 1);
			
			for (int r = 0; r < M; r +=len) {
				for (int c = 0; c < M; c+= len) {
					rotateBoard(r, c, r + len, c + len);
				}
			}
			
		}
		
		for (int r = 0; r < M; r++) {
			for (int c = 0; c < M; c++) {
				if (board[r][c] > 0) {					
					int cnt = 0;
					for (int dir = 0; dir < 4; dir++) {
						int nr = r + dr[dir];
						int nc = c + dc[dir];
						
						if (nr < 0 || nr >= M || nc < 0 || nc >= M) {
							continue;
						}
						
						if (board[nr][nc] != 0) {
							cnt += 1;
						}
					}
					
					if (cnt < 3) {
						arr.add(new Location(r, c));
					}
				}
				
			}
		}
		
		for (Location loc : arr) {
			if (board[loc.r][loc.c] > 0) {
				board[loc.r][loc.c] -= 1;
			}
		}
		
		
		boolean [][] visited = new boolean[M][M];
		for (int r = 0; r < M; r++) {
			for (int c = 0; c < M; c++) {
				iceCnt += board[r][c];
				if (board[r][c] > 0 && !visited[r][c]) {
					bfs(r, c, visited);
				}
			}
		}
		printBoard(board);
		
	}
	
	static void bfs(int sr, int sc, boolean [][] visited) {
		Queue<Location> queue = new LinkedList<>();
		queue.add(new Location(sr, sc));
		visited[sr][sc] = true;
		int totalSize = 1;
		
		while (!queue.isEmpty()) {
			Location cur = queue.poll();
			
			for (int dir = 0; dir < 4; dir++) {
				int nr = cur.r + dr[dir];
				int nc = cur.c + dc[dir];
				
				if (nr < 0 || nr >= M || nc < 0 || nc >= M || visited[nr][nc] || board[nr][nc] == 0) {
					continue;
				}
				
				queue.add(new Location(nr, nc));
				visited[nr][nc] = true;
				totalSize += 1;
			}
		}
		
		if (totalSize > maxIceSize)
			maxIceSize = totalSize;
	}
	
	static void rotateBoard(int sr, int sc, int er, int ec) {
		int len = er - sr;
		int [][] tmp = new int [len][len];
		int [][] tmp2 = new int [len][len];
		
		for (int r = 0; r < len; r++) {
			for (int c = 0; c < len; c++) {
				tmp2[r][c] = board[sr + r][sc + c];
			}
		}
		
		// printBoard(tmp2);
		
		for (int r = 0; r < len; r++) {
			for (int c = 0; c < len; c++) {
				tmp[r][c] = tmp2[len - c - 1][r];
			}
		}
		
		for (int r = sr; r < er; r++) {
			for (int c = sc; c < ec; c++) {
				board[r][c] = tmp[r - sr][c - sc];
			}
		}
		
	}
	
	static void printBoard(int [][] src) {
		if (!printFlag)
			return ;
		
		System.out.println();
		for (int r = 0; r < src.length; r++) {
			for (int c = 0; c < src[0].length; c++) {
				System.out.print(board[r][c] + " ");
			}
			System.out.println();
		}
	}

}
