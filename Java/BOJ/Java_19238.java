import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Queue;

/**
 * N * N
 * M : 승객
 * 
 * 1. 승객 고른다.
 * - 1) 최단거리
 * - 2) 행 작은 것
 * - 3) 열 작은 것
 * 
 * 2. 승객과 택시 같은 위치 가능
 * - 
 * 
 * 3. 연료
 * - 1씩 감소
 * - 성공 - 소모한 연료량 2배
 */
class Location {
	int r, c, length;
	
	Location(int r, int c, int length) {
		this.r = r;
		this.c = c;
		this.length = length;
	}
}
class Taxi {
	int r, c, save, used;
	Taxi(int r, int c, int save, int used) {
		this.r = r;
		this.c = c;
		this.save = save;
		this.used = used;
	}
}
class User implements Comparable<User>{
	int sr, sc, er, ec, index;
	
	User(int index, int sr, int sc, int er, int ec) {
		this.index = index;
		this.sr = sr;
		this.sc = sc;
		this.er = er;
		this.ec = ec;
	}

	@Override
	public int compareTo(User o) {
		if (this.sr == o.sr) {
			return Integer.compare(this.sc, o.sc);
		} else {
			return Integer.compare(this.sr, o.sr);
		}
	}
	
	
}
public class Java_19238 {
	static boolean printFlag = false;
	static int N; // 격자
	static int M; // 승객
	static int Fuel; // 연료
	static int [][] board; // 지도
	static Taxi taxi;
	static ArrayList<User> users = new ArrayList<>();
	static ArrayList<User> selectedUser = new ArrayList<>();
	static int [] dr = {-1, 1, 0, 0};
	static int [] dc = {0, 0, -1, 1};
	static int taxi_to_User = 0;
	static int user_to_end = 0;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String [] tokens = br.readLine().split(" ");
		N = Integer.parseInt(tokens[0]);
		M = Integer.parseInt(tokens[1]);
		Fuel = Integer.parseInt(tokens[2]);
		
		board = new int [N][N];
		for (int r = 0; r < N; r++) {
			tokens = br.readLine().split(" ");
			for (int c = 0; c < N; c++) {
				board[r][c] = Integer.parseInt(tokens[c]);
			}
		}
		
		tokens = br.readLine().split(" ");
		int r = Integer.parseInt(tokens[0]) - 1;
		int c = Integer.parseInt(tokens[1]) - 1;
		taxi = new Taxi(r, c, Fuel, 0);
		
		for (int i = 0; i < M; i++) {
			tokens = br.readLine().split(" ");
			
			int sr = Integer.parseInt(tokens[0]) - 1;
			int sc = Integer.parseInt(tokens[1]) - 1;
			int er = Integer.parseInt(tokens[2]) - 1;
			int ec = Integer.parseInt(tokens[3]) - 1;
			
			users.add(new User(i, sr, sc, er, ec));
		}
		
		boolean success = true;
		while (true) {
			/**
			 * 0. 초기화
			 */
			// System.out.println("START");
			taxi.used = 0;
			taxi_to_User = 0;
			user_to_end = 0;
			selectedUser.clear();
			/**
			 *  1. 택시에서 가장가까운 거리에 있는 모든 승객 선택 후 한개
			 *  - 선택된 고객이 없으면 성공 체크 후 종료
			 */
			printTaxi();
			bfs();
			/**
			 * 2. 현재 택시부터 -> 승객까지
			 * - 연료 0 보다 작으면 종료
			 */
			taxi.save -= taxi_to_User;
			// taxi.used += taxi_to_User;
			printSelectedUser();
			printTaxiFuel();
			if (taxi.save < 0 || selectedUser.size() == 0) {
				success = false;
				break;
			}
			taxi.r = selectedUser.get(0).sr;
			taxi.c = selectedUser.get(0).sc;
			/**
			 * 3.승객 -> 목적지 까지
			 * 1) 목적지 방문이 불가능한 경우
			 * - 종료
			 * 
			 * 2) 목적지 방문이 가능한 경우
			 * - 연료 0 보다 작으면 종료
			 * - 아닌 경우 연료 2배
			 * - 목적지 셋팅
			 */
			boolean chk = bfs2();
			if (!chk) {
				success = false;
				break;
			}
			taxi.save -= user_to_end;
			taxi.used += user_to_end;
			
			//printSelectedUser();
			printTaxiFuel();
			if (taxi.save < 0) {
				success = false;
				break;
			}
			taxi.save += (taxi.used * 2);
			taxi.r = selectedUser.get(0).er;
			taxi.c = selectedUser.get(0).ec;
			printTaxiFuel();
			if (users.size() == 0) {
				success = true;
				break;
			}
		}
		
		if (success) {
			System.out.println(taxi.save);
		} else {
			System.out.println(-1);
		}
		
	}
	static boolean bfs2() {
		Queue<Location> queue = new LinkedList<>();
		boolean [][] visited = new boolean[N][N];
		boolean finish = false;
		queue.add(new Location(taxi.r, taxi.c, 0));
		visited[taxi.r][taxi.c] = true;
		
		int er = selectedUser.get(0).er;
		int ec = selectedUser.get(0).ec;
		
		int moveLength = -1;
		while (!queue.isEmpty()) {
			Location cur = queue.poll();
			
			if (cur.r == er && cur.c == ec) {
				moveLength = cur.length;
				finish = true;
				break;
			}
			
			for (int dir = 0; dir < 4; dir++) {
				int nr = cur.r + dr[dir];
				int nc = cur.c + dc[dir];
				
				if (nr < 0 || nr >= N || nc < 0 || nc >= N || visited[nr][nc] || board[nr][nc] == 1)
					continue;
				
				queue.add(new Location(nr, nc, cur.length + 1));
				visited[nr][nc] = true;
			}
		}
		// 도착여부
		if (finish) {			
			user_to_end = moveLength;
		}
		
		return finish;
	}
	static void bfs() {
		Queue<Location> queue = new LinkedList<>();
		boolean [][] visited = new boolean[N][N];
		
		queue.add(new Location(taxi.r, taxi.c, 0));
		visited[taxi.r][taxi.c] = true;
		
		boolean findFlag = false;
		int minLength = 0;
		while (!queue.isEmpty()) {
			Location cur = queue.poll();
			
			if (findFlag && cur.length > minLength) {
				break;
			}

			
			for (User user : users) {
				if (user.sr == cur.r && user.sc == cur.c) {
					findFlag = true;
					minLength = cur.length;
					selectedUser.add(new User(user.index, user.sr, user.sc, user.er, user.ec));
					break;
				}
			}
			
			for (int dir = 0; dir < 4; dir++) {
				int nr = cur.r + dr[dir];
				int nc = cur.c + dc[dir];
				
				if (nr < 0 || nr >= N || nc < 0 || nc >= N || visited[nr][nc] || board[nr][nc] == 1)
					continue;
				
				queue.add(new Location(nr, nc, cur.length + 1));
				visited[nr][nc] = true;
			}
		}
		
		if (selectedUser.size() > 0) {
			Collections.sort(selectedUser); // 정렬
			int i = 0;
			for (User user : users) {
				if (user.index == selectedUser.get(0).index) {
					users.remove(i); // 전체 승객에서 삭제
					break;
				}
				i += 1;
			}
			taxi_to_User = minLength;
		}
	}
	
	static void printTaxi() {
		if (!printFlag) 
			return ;
		System.out.println("printTaxi");
		System.out.println("taxi.r=" + taxi.r + " taxi.c=" + taxi.c);
	}
	static void printSelectedUser() {
		if (!printFlag) 
			return ;
		
		System.out.println("printSelectedUser");
		if (selectedUser.size() == 1) {			
			User user = selectedUser.get(0);
			System.out.println("user_r=" + user.sr + " user.sc=" + user.sc);
		}
		System.out.println();
		
		
	}
	static void printTaxiFuel() {
		if (!printFlag) 
			return ;
		
		System.out.println("printTaxiFuel");
		System.out.println("taxi_save_fuel=" + taxi.save + " taxi_used_fuel=" + taxi.used);
		System.out.println("taxi_to_User=" + taxi_to_User + " user_to_end=" + user_to_end);
		System.out.println();
	}
}
