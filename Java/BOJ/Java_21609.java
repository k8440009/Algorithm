import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;

class BlockGroup implements Comparable<BlockGroup>{
	int index, r, c, rainBow, size;
	
	BlockGroup(int index, int r, int c, int rainBow, int size) {
		this.index = index;
		this.r = r;
		this.c = c;
		this.rainBow = rainBow;
		this.size = size;
	}

	@Override
	public int compareTo(BlockGroup o) {
		if (this.size == o.size) {
			if (this.rainBow == o.rainBow) {
				if (this.r == o.r) {
					return Integer.compare(this.c, o.c) * -1;
				} else {
					return Integer.compare(this.r, o.r) * -1;
				}
			} else {
				return Integer.compare(this.rainBow, o.rainBow) * -1;
			}
		} else {
			return Integer.compare(this.size, o.size) * -1;
		}
	}
	
	
}

class Location {
	int r, c;
	Location(int r, int c) {
		this.r = r;
		this.c = c;
	}
}

public class Java_21609 {
	static boolean printFlag = false;
	static int totalPoint;
	static int index;
	static int N, M;
	static ArrayList<Location> rainBows;
	static int [][] board;
	static boolean [][] visited;
	static int [] dr = {-1 ,0, 1, 0};
	static int [] dc = {0 ,1, 0, -1};
	public static void main(String[] args) throws IOException{
		/**
		 * 0. 블록
		 * -2 : 공백
		 * -1 : 검정
		 * 0 : 무지개
		 * 1 ~ M : 일반
		 * 
		 * 1. 블록 그룹 
		 * - r, c
		 * - 무지개 갯수
		 * - 블록 r, c
		 * - 전체 블록 갯수
		 * 
		 * 2. 중력
		 * - 아래로 한칸
		 * - 검은색 빼고
		 * 3. 격자 역시계
		 * 
		 * 4. 중력
		 * 
		 * 5. 반복
		 */
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String [] tokens = br.readLine().split(" ");
	
		N = Integer.parseInt(tokens[0]);
		M = Integer.parseInt(tokens[1]);
		board = new int [N][N];
		rainBows = new ArrayList<>();
		for (int r = 0; r < N; r++) {
			tokens = br.readLine().split(" ");
			for (int c = 0; c < N; c++) {
				board[r][c] = Integer.parseInt(tokens[c]);
			}
		}
		
		
		while(true) {
			index = 0;
			ArrayList<BlockGroup> blockGroups = new ArrayList<>();
			ArrayList <ArrayList<Location>> locations = new ArrayList<>();
			visited = new boolean[N][N];
			
			rainBows.clear();
			for (int r = 0; r < N; r++) {
				for (int c = 0; c < N; c++) {
					if (board[r][c] == 0) {
						rainBows.add(new Location(r, c));
					}
				}
			}
			// 1. 가장 큰 블록
			for (int r = 0; r < N; r++) {
				for (int c = 0; c < N; c++) {
					setRainBow();
					if (board[r][c] > 0 && !visited[r][c]) {
						findBlockGroup(r, c, blockGroups, locations);
					}
				}
			}
			
			Collections.sort(blockGroups);
			// index, r, c, rainBow, size;
//			for (BlockGroup bg : blockGroups) {
//				System.out.println("r=" + bg.r + " c=" + bg.c + " index=" + bg.index + " rainBow=" + bg.rainBow + " size=" + bg.size);
//			}
//			
			if (blockGroups.size() == 0) {				
				break;
			} else {
				//System.out.println("start");
				BlockGroup big = blockGroups.get(0);
				ArrayList<Location> location = locations.get(big.index);
				// 2. 블록 제거
				//System.out.println("removeBlock");
				removeBlock(big, location);
				printBoard(board);
				// 3. 중력
				//System.out.println("gravity");
				gravity();
				printBoard(board);
				// 4. 반시계
				//System.out.println("rotate_back");
				rotate_back();
				printBoard(board);
				// 5. 중력
				//System.out.println("gravity");
				gravity();
				printBoard(board);
			}
		}
		
		System.out.println(totalPoint);
	}
	
	static void rotate_back() {
		int [][] tmp = new int [N][N];
		
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				tmp[r][c] = board[c][N - 1 - r];
			}
		}
		
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				board[r][c] = tmp[r][c];
			}
		}
	}
	
	static void gravity() {
		int [][] tmp = new int [N][N];
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				tmp[r][c] = -2;
			}
		}
		
		for (int c = 0; c < N; c++) {			
			int chkR = N - 1;
			for (int r = N - 1; r >= 0; r--) {
				if (board[r][c] == -1) { // 검정
					chkR = r - 1;
					tmp[r][c] = -1;
					continue;
				} else if (board[r][c] == -2) { // 공백
					continue;
				} else {
					tmp[chkR][c] = board[r][c];
					board[r][c] = -2;
					chkR -= 1;
				}
			}
		}
		
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				board[r][c] = tmp[r][c];
			}
		}
	}
	
	static void removeBlock(BlockGroup big, ArrayList<Location> location) {
		int point = big.size * big.size;
		
		totalPoint += point;
		
		for (Location loc : location) {
			board[loc.r][loc.c] = -2; // 공백
		}
	}
	
	static void findBlockGroup(int sr, int sc, ArrayList<BlockGroup> blockGroups, ArrayList <ArrayList<Location>> locations) {
		Queue<Location> queue = new LinkedList<>();
		queue.add(new Location(sr, sc));
		visited[sr][sc] = true;
		
		int basis = board[sr][sc];
		int size = 1;
		int rainBow = 0;
		// locations.add(new ArrayList<>());
		ArrayList<Location> locs = new ArrayList<>();
		locs.add(new Location(sr, sc));
		
		while (!queue.isEmpty()) {
			Location cur = queue.poll();
			
			for (int dir = 0; dir < 4; dir++) {
				int nr = cur.r + dr[dir];
				int nc = cur.c + dc[dir];
				// 바깥, 공백, 검은색, 이전방문
				if (nr < 0 || nr >= N || nc < 0 || nc >= N
						|| board[nr][nc] == -2 || board[nr][nc] == -1 || visited[nr][nc])
					continue;
				
				if (board[nr][nc] == basis || board[nr][nc] == 0) {
					queue.add(new Location(nr, nc));
					visited[nr][nc] = true;
					locs.add(new Location(nr, nc));
					size += 1;
					if (board[nr][nc] == 0) {
						rainBow += 1;
					}
				}
			}
		}
		if (size >= 2) {
			blockGroups.add(new BlockGroup(index, sr, sc, rainBow, size));
			locations.add(locs);
			index += 1;
		}
	}
	
	static void setRainBow() {
		for (Location loc : rainBows) {
			visited[loc.r][loc.c] = false;
		}
	}
	static void printBoard(int [][] src) {
		if (!printFlag) {
			return ;
		}
		System.out.println();
		for (int r = 0; r < src.length; r++) {
			for (int c = 0; c < src[0].length; c++) {
				System.out.print(src[r][c] + " ");
			}
			System.out.println();
		}
	}
}
