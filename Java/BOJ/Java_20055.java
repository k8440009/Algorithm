import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Belt {
	int d = 0;
	boolean robo = false;
	
	Belt (int d, boolean robo) {
		this.d = d;
		this.robo = robo;
	}
	
}

public class Java_20055 {
	static int N, K;
	// static int [] arr;
	// static ArrayList<Belt> arr = new ArrayList<>();
	static Belt [] arr;
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String [] tokens = br.readLine().split(" ");
		N = Integer.parseInt(tokens[0]);
		K = Integer.parseInt(tokens[1]);
		
		arr  = new Belt[N * 2];
		
		tokens = br.readLine().split(" ");
		for (int i = 0; i < 2 * N; i++) {
			arr[i] = new Belt(Integer.parseInt(tokens[i]), false);
		}
		// 0 ~ N - 1 : 올리는 위치 - N ~ 2N - 1 : 내리는 위치
		// 칸 : 내구도
		
		/**
		 * 로봇
		 * 벨트 : 내구도
		 *     : 로봇 여부
		 *     
		 * 1. 벨트 내구도 입력 받음
		 * 2. 로봇 : 큐에 넣음 (인덱스, 근데 벨트는 이동..)
		 * 
		 * 벨트에 로봇 체크
		 * 
		 * 이동 체크
		 */
		printBoard(arr);
		int step = 1;
		while (true) {
			// 1. moveBelt
			Belt tmp = arr[2 * N - 1];
			for (int i = 2 * N - 1; i >= 1; i--) {
				arr[i] = arr[i - 1];
			}
			arr[0] = tmp;
			// N 에 로봇이 있으면 삭제
			arr[N].robo = false;
			for (int i = N - 2; i >= 0; i--) {
				if (arr[i].robo) {
					if (arr[i+1].robo == false && arr[i].d > 0) {
						arr[i + 1].robo = true;
						arr[i + 1].d -= 1;
						arr[i].robo = false;
					}
				}				
			}
			// 3. 로봇 올림
			if (arr[0].d != 0) {
				arr[0].robo = true;
				arr[0].d -= 1;
			}
			
			// 4. 종료문
			int cnt = 0;
			for (Belt belt : arr) {
				if (belt.d == 0) {
					cnt += 1;
				}
			}
			printBoard(arr);
			if (cnt >= K) {
				break;
			}
			step += 1;
		}
		
		System.out.println(step);
	}
	
	static void printBoard(Belt [] arr) {
		for (int i = 0; i < arr.length; i++) {
			System.out.print(arr[i].d + " ");
		}
		System.out.println();
	}

}
