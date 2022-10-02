import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.ArrayList;

class FireBall {
	int r, c, m, d, s;
	FireBall(int r, int c, int m, int s, int d) {
		this.r = r;
		this.c = c;
		this.m = m;
		this.s = s;
		this.d = d;
	}
}

public class Java_20056 {
/**
 * 파이어볼 : r, c, m, d s
 * @param args
 * 
 * 1. 파이어볼 방향 d로 속력 s칸 이동
 * 2. 두개 이상 있는 파이어볼
 * - 이동이 끝난 뒤 모두 합쳐진다.
 * - 4개로 나누어진ㄴ다.
 * - 질량 (전체 질량 / 5)
 * -- 질량 = 0 => delete
 * - 속력 (속력의합 / 파이어볼갯수)
 * 방향
 */
	static boolean printFlag = false;
	static int N, M, K;
	static ArrayList<FireBall> [][] board;
	static ArrayList<FireBall> arr;
	static int [] dr = {-1, -1, 0, 1, 1, 1, 0, -1};
	static int [] dc = {0, 1, 1, 1, 0, -1, -1, -1};
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String [] tokens = br.readLine().split(" ");
		N = Integer.parseInt(tokens[0]);
		M = Integer.parseInt(tokens[1]);
		K = Integer.parseInt(tokens[2]);
		
		board = new ArrayList [N][N];
		arr = new ArrayList<>();
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				board[r][c] = new ArrayList<FireBall>();
			}
		}
		
		for (int i = 0; i < M; i++) {
			tokens = br.readLine().split(" ");
			int r = Integer.parseInt(tokens[0]) - 1;
			int c = Integer.parseInt(tokens[1]) - 1;
			int m = Integer.parseInt(tokens[2]);
			int s = Integer.parseInt(tokens[3]);
			int d = Integer.parseInt(tokens[4]);
			
			board[r][c].add(new FireBall(r, c, m, s, d));
			arr.add(new FireBall(r, c, m, s, d));
		}
		
		for (int i = 0; i < K; i++) {
			// 1. moveFireBall;
			moveFileBall();
			printBall(arr);
			printBoardM(board);
		}
		
		
		
		int answer = 0;
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				if (board[r][c].size() > 0) {
					for (FireBall ball : board[r][c]) {
						answer += ball.m;
					}
				}
			}
		}
		
		System.out.println(answer);
		
	}
	
	static void moveFileBall() {
		ArrayList<FireBall> [][] newBoard = new ArrayList [N][N]; 
		ArrayList<FireBall> newArr = new ArrayList<>();
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				newBoard[r][c] = new ArrayList<FireBall>();
			}
		}
		// 1. 이동
		for (FireBall fireball : arr) {
			int r = fireball.r;
			int c = fireball.c;
			int d = fireball.d;
			int m = fireball.m;
			int s = fireball.s;
			int nr = -1;
			int nc = -1;
			int cnt = 0;
			
			while (cnt < s) {
				nr = r + dr[d];
				nc = c + dc[d];
				
				if (nr < 0 || nr >= N || nc < 0 || nc >= N) {
					if (nr == -1)
						nr = N - 1;
					if (nr == N)
						nr = 0;
					if (nc == -1)
						nc = N - 1;
					if (nc == N)
						nc = 0;
				}
				
				r = nr;
				c = nc;
				cnt += 1;
			}
			newBoard[nr][nc].add(new FireBall(nr, nc, m, s, d));
		}
		// 2. 파이어볼 재구성
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				if (newBoard[r][c].size() == 1) {
					FireBall fb = new FireBall(r, c, newBoard[r][c].get(0).m, 
							 newBoard[r][c].get(0).s,
							 newBoard[r][c].get(0).d); 
					newArr.add(fb);
				} else if (newBoard[r][c].size() > 1) {
					int cnt = newBoard[r][c].size();
					int sumM = 0;
					int sumS = 0;
					
					boolean chkOdd = false;
					boolean chkEvn = false;
					for (FireBall ball : newBoard[r][c]) {
						sumM += ball.m;
						sumS += ball.s;
						
						if (ball.d % 2 == 0) {
							chkEvn = true;
						} else {
							chkOdd = true;
						}
					}
					
					int newM = sumM / 5;
					if (newM != 0) {						
						int newS = sumS / cnt;
						newBoard[r][c].clear();
						if (chkOdd && chkEvn) {
							// 1 3 5 7
							for (int dir = 1; dir <= 7; dir += 2) {
								FireBall fb = new FireBall(r, c, newM, newS, dir); 
								newBoard[r][c].add(fb);
								newArr.add(fb);
							}
						} else {
							for (int dir = 0; dir <= 6; dir += 2) {
								FireBall fb = new FireBall(r, c, newM, newS, dir); 
								newBoard[r][c].add(fb);
								newArr.add(fb);
							}
						}
					} else {
						newBoard[r][c].clear();
					}
				}
			}
		}
		// 복제
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				board[r][c].clear();
				
				if (newBoard[r][c].size() > 0) {
					for (FireBall ball : newBoard[r][c]) {
						board[r][c].add(ball);
					}
				}
			}
		}

		arr.clear();
		for (FireBall ball : newArr) {
			arr.add(ball);
		}
	}
	
	static void printBall(ArrayList<FireBall> src) {
		if (!printFlag)
			return ;
		
		for (FireBall ball : src) {
			System.out.println("r=" + ball.r +  " c=" + ball.c + " m=" + ball.m + " s=" + ball.s + " d=" + ball.d);
		}
	}
	static void printBoardM(ArrayList<FireBall> [][] src) {
		if (!printFlag)
			return ;
		
		for (int r = 0; r < N; r++) {
			for (int c = 0 ;c < N; c++) {
				if (src[r][c].size() == 0) {
					System.out.print(0 + " ");
				} else {
					System.out.print(src[r][c].size() + " ");
				}
			}
			System.out.println();
		}
	}
}
