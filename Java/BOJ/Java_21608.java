import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

class Student implements Comparable<Student> {
	int r, c, like, blank;
	
	Student(int r, int c, int like, int blank) {
		this.r = r;
		this.c = c;
		this.like = like;
		this.blank = blank;
	}

	@Override
	public int compareTo(Student o) {
		if (this.like == o.like) {
			if (this.blank == o.blank) {
				if (this.r == o.r) {
					return Integer.compare(this.c, o.c);
				} else {
					return Integer.compare(this.r, o.r);
				}
			} else {
				return Integer.compare(this.blank, o.blank) * -1;
			}
		} else {
			return Integer.compare(this.like, o.like) * -1;
		}
	}
	
	
}
public class Java_21608 {
	static boolean printFlag = false;
	static int N;
	static int maxPoint = 0;
	static int [] dr = {-1, 0, 1, 0};
	static int [] dc = {0, -1, 0, 1};
	static ArrayList<Integer> arr[];
	static ArrayList<Integer> student;
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		student = new ArrayList<>();
		N = Integer.parseInt(br.readLine());
		arr = new ArrayList[N * N + 1];
		// 1 ~ 9 
		for (int i = 0; i <= N * N; i++) {
			arr[i] = new ArrayList<>();
		}
		
		for (int i = 0; i < N * N; i++) {
			String [] tokens = br.readLine().split(" ");
			int num = Integer.parseInt(tokens[0]);
			int a = Integer.parseInt(tokens[1]);
			int b = Integer.parseInt(tokens[2]);
			int c = Integer.parseInt(tokens[3]);
			int d = Integer.parseInt(tokens[4]);
			student.add(num);
			arr[num].add(a);
			arr[num].add(b);
			arr[num].add(c);
			arr[num].add(d);
		}
		
		int [][] board = new int [N][N];
		dfs(0, board);
		
		System.out.println(maxPoint);
	}
	
	// 인덱스
	static void dfs(int index, int [][] board) {
		if (index == N * N) {
			int point = calculate(board);
			if (point > maxPoint) {
				maxPoint = point;
			}
			
			return ;
		}
		
		// 비어있는 칸중에서 좋아하는 학생이 인접한 칸
		int stuNum = student.get(index);
		ArrayList<Student> locations = new ArrayList<>();
		ArrayList<Integer> likeList = arr[stuNum];
		// 1번
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				if (board[r][c] == 0) {
					int like = 0;
					int blank = 0;
					for (int dir = 0; dir < 4; dir++) {
						int nr = r + dr[dir];
						int nc = c + dc[dir];
						
						if (nr < 0 || nr >= N || nc < 0 || nc >= N) 
							continue;
						
						if (board[nr][nc] != 0) {
							// 좋ㅇ하하는 학생 체크
							for (int st : likeList) {
								if (board[nr][nc] == st) {
									like += 1;
									break;
								}
							}
						} else {
							blank += 1;
						}
					}
					locations.add(new Student(r, c, like, blank));
				}
			}
		}
		
		Collections.sort(locations);
		Student now = locations.get(0);
		board[now.r][now.c] = stuNum;
		
		dfs(index + 1, board);
	}
	static int calculate(int [][] board) {
		printBoard(board);
		int point = 0;
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				int stuNum = board[r][c];
				ArrayList<Integer> likeList = arr[stuNum];
				
				int like = 0;
				
				for (int dir = 0; dir < 4; dir++) {
					int nr = r + dr[dir];
					int nc = c + dc[dir];
					
					if (nr < 0 || nr >= N || nc < 0 || nc >= N) {
						continue;
					}
					
					for (int student : likeList) {
						if (student == board[nr][nc]) {
							like += 1;
							break;
						}
					}
				}
				
				if (like == 1) {
					point += 1;
				} else if (like == 2) {
					point += 10;
				} else if (like == 3) {
					point += 100;
				} else if (like == 4) {
					point += 1000;
				}
			}
		}
		
		return point;
	}
	
	static void printBoard(int [][] src) {
		if (!printFlag)
			return ;
		
		System.out.println();
		for (int r = 0; r < N; r++) {
			for (int c = 0; c < N; c++) {
				System.out.print(src[r][c] + " ");
			}
			System.out.println();
		}
	}
	
	static void printLocations(ArrayList<Student> locations) {
		if (!printFlag)
			return ;
		
		for (Student stu : locations) {
			System.out.println("like=" + stu.like + " blank=" + stu.blank + " r=" + stu.r  + " c=" + stu.c);
		}
	}
}
