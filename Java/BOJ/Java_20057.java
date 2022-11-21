import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Java_20057 {
	static boolean printFlag = false;
	static int N;
	static int [][] board;
	static int outSand;
	static int [] dr = {0, 1, 0, -1};
	static int [] dc = {-1, 0, 1, 0};
	static int [][] wdr = {{-2, -1, -1, -1, 0, 1, 1, 1, 2, 0}, {-1, -1, 0, 0, 0, 0, 1, 1, 2, 1}, {-2, -1, -1, -1, 0, 1, 1, 1, 2, 0}, {-2, -1, -1, 0, 0, 0, 0, 1, 1, -1}};
	static int [][] wdc = {{0, -1, 0, 1, -2, -1, 0, 1, 0, -1}, {-1, 1, -2, -1, 1, 2, -1, 1, 0, 0}, {0, -1, 0, 1, 2, -1, 0, 1, 0, 1}, {0, -1, 1, -2, -1, 1, 2, -1, 1, 0}};
	static int [][] wdp = {{2, 10, 7, 1, 5, 10, 7, 1, 2, 55}, {1, 1, 2, 7, 7, 2, 10, 10, 5, 55}, {2, 1, 7, 10, 5, 1, 7, 10, 2, 55}, {5, 10, 10, 2, 7, 7, 2, 1, 1, 55}};

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int totalSand = 0;
		N = Integer.parseInt(br.readLine());
		board = new int [N][N];
		for (int r = 0; r < N; r++) {
			String [] tokens = br.readLine().split(" ");
			for (int c = 0; c < N; c++) {
				board[r][c] = Integer.parseInt(tokens[c]);
				if (board[r][c] > 0) 
					totalSand += board[r][c];
			}
		}
		
		int mid = N / 2;
		tonado(mid, mid);
		//moveSand(0, 0, 0);
		System.out.println(outSand);
		// printBoard(board);
	}
	static void moveSand(int sr, int sc, int dir) {
		int sand = board[sr][sc];
		int tmp = sand;
		board[sr][sc] = 0;
		int nr = -1;
		int nc = -1;
		/**
		 * 비율칸 move : y의 모래 * 비율
		 * a : 비율이 적힌 칸 이동 (sand - 비율칸 모래)
		 */
		for (int i = 0; i <= 9; i++) {
			nr = sr + wdr[dir][i];
			nc = sc + wdc[dir][i];
			
			if (i == 9) {
				if (nr < 0 || nr >= N || nc < 0 || nc >= N) {
					outSand += sand;
				} else {					
					board[nr][nc] += sand;
				}
			} else {				
				int b = (int)(tmp * (wdp[dir][i] / 100.0));
				if (nr < 0 || nr >= N || nc < 0 || nc >= N) {
					outSand += b;
				} else {					
					board[nr][nc] += b;
				}
				sand -= b;
			}
			
			// newBoard[nr][nc] += (board[nr][nc] + b);
		}
		
		board[sr][sc] = 0;
		printBoard(board);
		// copyBoard(newBoard, newBoard)
	}
	
	static void tonado (int sr, int sc) {
		boolean flag = true;
		
		int num = 0;
		int cnt = 0;
		int r = sr;
		int c = sc;
		while(true) {
			
			for (int dir = 0; dir < 4; dir++) {
				
				if (dir == 0 || dir == 2) {
					cnt += 1;
					num += 1;
				}
				
				for (int i = 0; i < cnt; i++) {
					int nr = r + dr[dir];
					int nc = c + dc[dir];
					
					if (nr < 0 || nr >= N || nc < 0 || nc >= N) {
						flag = false;
						break;
					}
					
					moveSand(nr, nc, dir);
					r = nr;
					c = nc;
				}
				
				if (!flag)
					break;
				
			}
			
			if (!flag || cnt > N)
				break;
		}
	}
	static void copyBoard(int [][] desc, int [][] src) {
		
		for (int r= 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				desc[r][c] = src[r][c];
			}
		}
		
	}
	
	static void printBoard (int [][] src) {
		if (!printFlag)
			return ;
		
		System.out.println();
		for (int r = 0; r < src.length; r++) {
			for (int c = 0; c < src[0].length; c++) {
				System.out.print(src[r][c] + " ");
			}
			System.out.println();
		}
	}
}
