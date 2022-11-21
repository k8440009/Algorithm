import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

class Unit implements Comparable<Unit>{
	int num, cnt;
	
	Unit (int num, int cnt) {
		this.num = num;
		this.cnt = cnt;
	}
	
	@Override
	public int compareTo(Unit o) {
		if (this.cnt == o.cnt) {
			return Integer.compare(this.num, o.num);
		} else {
			return Integer.compare(this.cnt, o.cnt);
		}
	}
}

public class Java_17140 {
	static boolean printFlag = false;
	static int R;
	static int C;
	static int K;
	static int [][] board = new int [100][100];
	
	static int rSize = 3;
	static int cSize = 3;
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String [] tokens = br.readLine().split(" ");
		
		R = Integer.parseInt(tokens[0]) - 1;
		C = Integer.parseInt(tokens[1]) - 1;
		K = Integer.parseInt(tokens[2]);
		
		for (int r = 0; r < 3; r++) {
			tokens = br.readLine().split(" ");
			for (int c = 0; c < 3; c++) {
				board[r][c] = Integer.parseInt(tokens[c]);
			}
		}
		
		int time = 0;
		boolean success = false;
		while(time <= 100) {
			// 0. 보드 체크
			if (board[R][C] == K) {
				success = true;
				break;
			}
			/**
			 * 1.연산
			 */
			if (rSize >= cSize) {
				rCalculate();
			} else {
				cCalculate();
			}
			
			printBoard();
			time += 1;
		}
		
		if (success) {
			System.out.println(time);
		} else {
			System.out.println(-1);
		}
	}
	
	static void cCalculate() {
		ArrayList<Integer> next[] = new ArrayList[cSize];
		ArrayList<Unit> arr[] = new ArrayList[cSize];
		
		int maxSize = 0;
		
		for (int c = 0; c < cSize; c++) {
			Map<Integer, Integer> map = new HashMap<>();
			arr[c] = new ArrayList<>();
			next[c] = new ArrayList<>();
			
			for (int r = 0; r < rSize; r++) {
				int num = board[r][c];
				
				if (num == 0) 
					continue;
				
				if (map.containsKey(num)) {
					map.put(num, map.get(num) + 1);
				} else {
					map.put(num, 1);
				}
			}
			
			// 정렬을 위해 데이터 넣기
			for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
				arr[c].add(new Unit(entry.getKey(), entry.getValue()));
			}
			
			Collections.sort(arr[c]);
			
			for (Unit unit : arr[c]) {
				next[c].add(unit.num);
				next[c].add(unit.cnt);
			}
			
			if (next[c].size() > maxSize) {
				maxSize = next[c].size();
			}	
		}
		
		// 초과하는 경우
		if (maxSize> 100)
			maxSize = 100;
		
		rSize = maxSize;
		
//		System.out.println("rSize=" + rSize + " cSize=" + cSize);
		for (int c = 0; c < cSize; c++) {
			int listSize = next[c].size();
			/**
			 * 길이 조절
			 */
			if (listSize >= maxSize) {
				for (int r = 0; r < maxSize; r++) {
//					System.out.println("test1");
//					System.out.println("r=" + r + " c=" + c);
					board[r][c] = next[c].get(r);
				}
			} else {
				for (int r = 0; r < maxSize; r++) {
					if (r >= listSize) {
//						System.out.println("test2");
//						System.out.println("r=" + r + " c=" + c);
						board[r][c] = 0;
					} else {
//						System.out.println("test3");
//						System.out.println("r=" + r + " c=" + c);
						board[r][c] = next[c].get(r);
					}
				}
			}
		}
	}
	
	static void rCalculate() {
		ArrayList<Integer> next[] = new ArrayList[rSize];
		ArrayList<Unit> arr[] = new ArrayList[rSize];
		
		int maxSize = 0;
		for (int r = 0; r < rSize; r++) {
			Map<Integer, Integer> map = new HashMap<>();
			arr[r] = new ArrayList<>();
			next[r] = new ArrayList<>();
			for (int c = 0; c < cSize; c++) {
				int num = board[r][c];
				
				if (num == 0) 
					continue;
				
				if (map.containsKey(num)) {
					map.put(num, map.get(num) + 1);
				} else {
					map.put(num, 1);
				}
			}
			// 정렬을 위해 데이터 넣기
			for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
				arr[r].add(new Unit(entry.getKey(), entry.getValue()));
			}
			
			Collections.sort(arr[r]);
			
			//System.out.println("r=" + r);
			for (Unit unit : arr[r]) {
				//System.out.println("num=" + unit.num + " cnt=" + unit.cnt);
				
				next[r].add(unit.num);
				next[r].add(unit.cnt);
			}
			
			if (next[r].size() > maxSize) {
				maxSize = next[r].size();
			}
			
		}
		// 2, 1 1 2
		// 1 1 2 1 3 1
		// 3 3 
		// 초과하는 경우
		if (maxSize> 100)
			maxSize = 100;
		
		cSize = maxSize;
		for (int r = 0; r < rSize; r++) {
			int listSize = next[r].size();
			/**
			 * 길이 조절
			 */
			if (listSize >= maxSize) {
				for (int c = 0; c < maxSize; c++) {
					board[r][c] = next[r].get(c);
				}
			} else {
				for (int c = 0; c < maxSize; c++) {
					if (c >= listSize) {
						board[r][c] = 0;
					} else {						
						board[r][c] = next[r].get(c);
					}
				}
			}
		}
	}
	
	static void printBoard() {
		if (!printFlag)
			return ;
		
		System.out.println("rSize=" + rSize + " cSize=" + cSize);
		for (int r = 0; r < rSize; r++) {
			for (int c = 0; c < cSize; c++) {
				System.out.print(board[r][c] + " ");
			}
			System.out.println();
		}
	}
}
