import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Collections;

/**
 * 상어
 * - 번호
 * - 위치
 * - 방향
 * 
 * 우선선위
 * 
 * 격자
 * - 상어 여러 마리 가능
 * 
 * 냄새
 * - 상어번호, 값
 * @author k8440
 *
 */
class Location {
	int r, c, d;
	
	Location(int r, int c, int d) {
		this.r = r;
		this.c = c;
		this.d = d;
	}
	
}
class Smell {
	int index, smell;
	Smell (int index, int smell) {
		this.index = index;
		this.smell = smell;
	}
}

class Shark implements Comparable<Shark>{
	int r, c, d, index;
	
	Shark(int r, int c, int d, int index) {
		this.r = r;
		this.c = c;
		this.d = d;
		this.index = index;
	}
	
	@Override
	public int compareTo(Shark o) {
		return Integer.compare(this.index, o.index);
	}
	
}


public class Java_19237 {
	static boolean printFlag = false;
	static int N; // 격자
	static int M; // 상어
	static int K; // 냄시
	static int [] dr = {-1, 1 ,0, 0};
	static int [] dc = {0, 0, -1, 1};
	static Smell [][] smBoard;
	static ArrayList<Shark> [][] shBoard;
	static ArrayList<Shark> sharks;
	static int [][][] priority;
	//static ArrayList<Integer> [][] priority;
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String [] tokens = br.readLine().split(" ");
		N = Integer.parseInt(tokens[0]);
		M = Integer.parseInt(tokens[1]);
		K = Integer.parseInt(tokens[2]);
		
		smBoard = new Smell[N][N];
		shBoard = new ArrayList [N][N];
		sharks = new ArrayList<>();
		priority = new int [M + 1][4][4];
		// 0. 입력
		for (int r = 0; r < N; r++) {
			tokens = br.readLine().split(" ");
			for (int c = 0; c < N; c++) {
				shBoard[r][c] = new ArrayList<>();
				smBoard[r][c] = new Smell(0, 0);
				
				int num = Integer.parseInt(tokens[c]);
				if (num > 0) {
					sharks.add(new Shark(r, c, -1, num));
					shBoard[r][c].add(new Shark(r, c, -1, num));
				}
			}
		}
		

		tokens = br.readLine().split(" ");
		for (int i = 0; i < M; i++) {
			
			for (Shark sh : sharks) {
				int num = sh.index;
				if (i == num - 1) {
					sh.d = Integer.parseInt(tokens[i]) - 1;
					shBoard[sh.r][sh.c].get(0).d = sh.d;
					break;
				}
			}
		}
		
		for (int i = 1; i <= M; i++) {
			for (int j = 0; j < 4; j++) {
				tokens = br.readLine().split(" ");
				for (int k = 0; k < 4; k++) {
					int dir = Integer.parseInt(tokens[k]) - 1;
					priority[i][j][k] = dir;
				}
			}
		}
		
		int time = 1;
		printBoard();
		while (time <= 1000) {
			//System.out.println("time=" + time);
			// 1. 냄새 뿌림
			spreadSmell();
//			System.out.println("spreadSmell1");
//			printSmellIndex();
//			printSmell();
			// 2. 이동
			moveShark();
			//System.out.println("moveShark");
			printBoard();
			// 3. 냄새 감소
			downSmell();
//			System.out.println("downSmell");
//			printSmellIndex();
//			printSmell();
//			printSmellIndex();
//			printSmell();
//			// 4. 냄새뿌림
			spreadSmell();
//			System.out.println("spreadSmell2");
//			printBoard();
//			printSmellIndex();
//			printSmell();
			
			if (sharks.size() == 1) {
				break;
			}
			
			time += 1;
		}
		
		if (time > 1000) {
			System.out.println(-1);
		} else {
			System.out.println(time);
		}
	}
	
	
	static void moveShark() {
		/**
		 * 이동
		 * - 1. 인접한 칸 중 냄새 없는 칸
		 * - 2. 자신의 냄새가 있는 칸
		 * -- 가능한 칸 여러개인 경우 => 우선순위에 따라 => 상어, 방향
		 * - 3. 상어 제거
		 */
		ArrayList<Shark> [][] tmpBoard = new ArrayList [N][N];
		
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				tmpBoard[r][c] = new ArrayList<>();
			}
		}
		
		for (Shark sh : sharks) {
			int r = sh.r;
			int c = sh.c;
			int i = sh.index;
			int d = sh.d;
			
			boolean noSmell = false;
			boolean mySmell = false;
			ArrayList<Location> noLocations = new ArrayList<>();
			ArrayList<Location> myLocations = new ArrayList<>();
			int sr = -1;
			int sc = -1;
			for (int dir = 0; dir < 4; dir++) {
				int nr = r + dr[dir];
				int nc = c + dc[dir];
				
				if (nr < 0 || nr >= N || nc < 0 || nc >= N)
					continue;
				// 1. 냄새 없는 칸
				if (smBoard[nr][nc].smell == 0) {					
					noSmell = true;
					noLocations.add(new Location(nr, nc, dir));
				} else {
					// 2.  자신의 냄새가 있는 칸
					if (smBoard[nr][nc].index == i) {
						mySmell = true;
						myLocations.add(new Location(nr, nc, dir));
					}
				}
			}
			// 2) 임시 배열 셋팅
			if (noSmell) {
				// priority[i][d][dir]; 인덱스, 방향 
				for (int dir = 0; dir < 4; dir++) {
					boolean chkFlag = false;
					
					int basis = priority[i][d][dir];
					for (Location loc : noLocations) {
						if (basis == loc.d) {
							chkFlag = true;
							sr = loc.r;
							sc = loc.c;
							break;
						}
					}
					
					if (chkFlag) {
						tmpBoard[sr][sc].add(new Shark(sr, sc, basis, i));
						break;
					}
				}
			} else {
				if (mySmell) {
					
					for (int dir = 0; dir < 4; dir++) {
						boolean chkFlag = false;
						
						int basis = priority[i][d][dir];
						for (Location loc : myLocations) {
							if (basis == loc.d) {
								chkFlag = true;
								sr = loc.r;
								sc = loc.c;
								break;
							}
						}
						
						if (chkFlag) {
							tmpBoard[sr][sc].add(new Shark(sr, sc, basis, i));
							break;
						}
					}
				} else { // 미이동시 체크 필요
					tmpBoard[r][c].add(new Shark(r, c, d, i));
				}
			}
		}
		// 3. 상어 제거
		sharks.clear();
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				shBoard[r][c].clear();
				if (tmpBoard[r][c].size() > 1) {
					Collections.sort(tmpBoard[r][c]);
					
					Shark sh = tmpBoard[r][c].get(0);
					shBoard[r][c].add(new Shark(r, c, sh.d, sh.index));
					sharks.add(new Shark(r, c, sh.d, sh.index));
					
				} else if (tmpBoard[r][c].size() == 1) {
					Shark sh = tmpBoard[r][c].get(0);
					shBoard[r][c].add(new Shark(r, c, sh.d, sh.index));
					sharks.add(new Shark(r, c, sh.d, sh.index));
				}
			}
		}
	}
	
	static void downSmell() {
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				if (smBoard[r][c].smell > 0 ) {
					smBoard[r][c].smell -= 1;
				}
			}
		}
		
		for (Shark sh : sharks) {
			smBoard[sh.r][sh.c].smell += 1;
		}
	}
	
	static void spreadSmell() {
		for (Shark sh : sharks) {
			int r = sh.r;
			int c = sh.c;
			int i = sh.index;
			
			smBoard[r][c] = new Smell(i, K);
		}
	}
	
	static void printBoard() {
		if (!printFlag)
			return ;
		
		System.out.println();
		System.out.println("board");
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				if (shBoard[r][c].size() == 0) {
					System.out.print(0 + " ");
				} else {					
					System.out.print(shBoard[r][c].get(0).index + " ");
				}
			}
			System.out.println();
		}
		
	}
	
	static void printSmellIndex() {
		if (!printFlag)
			return ;
		System.out.println();
		System.out.println("smellIndex");
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				System.out.print(smBoard[r][c].index + " ");
			}
			System.out.println();
		}
	}
	
	static void printSmell() {
		if (!printFlag)
			return ;
		System.out.println();
		System.out.println("smell");
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				System.out.print(smBoard[r][c].smell + " ");
			}
			System.out.println();
		}
	}
	
}
