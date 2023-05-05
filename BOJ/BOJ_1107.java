import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) {
		try {
//			version1();
			version2();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	static final int MAX_CHANNEL = 1000000;
	private static void version1() throws IOException {
		System.setIn(new FileInputStream("data2/1107.txt"));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stk = new StringTokenizer(br.readLine());
		int target = Integer.parseInt(stk.nextToken());
		int N = Integer.parseInt(br.readLine()); 
		boolean[] numbers = new boolean[10];
		Arrays.fill(numbers, true);
		if(N > 0) {
			stk = new StringTokenizer(br.readLine());
			// 망가진 리모컨 버튼
			for(int i = 0; i < N; i++) {
				int t = Integer.parseInt(stk.nextToken());
				numbers[t] = false; 
			}
		}
		if(target == 100) {
			System.out.println(0);
			return;
		}
		// 목표 채널 이동
		int ans = Integer.MAX_VALUE;
		for(int i = 0; i <= MAX_CHANNEL; i++) {
			boolean canNum = true;
			int cnt = 0;
			if(i != 100) {
				String it = String.valueOf(i);
				// 숫자가 버튼으로 표현이 되는지
				for(int j = 0; j < it.length(); j++) {
					int temp = (int)(it.charAt(j) -'0');
					if(!numbers[temp]) {
						canNum = false;
						break;
					}
					else {
						cnt++;
					}
				}
			}
			if(canNum) {
				cnt += Math.abs(i - target);
				ans = Math.min(ans, cnt);
			}
		}
		System.out.println(ans);
		br.close();
	}
	private static int N, M;
	private static boolean[] broken;	// 고장여부 확인 배열
	private static void version2() throws IOException {

		// 1. 이동하려고 하는 채널 N, 고장난 버튼의 개수 M, 고장난 버튼 배열에 저장
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		N = Integer.parseInt(st.nextToken());
		broken = new boolean[10];
		st = new StringTokenizer(br.readLine(), " ");
		M = Integer.parseInt(st.nextToken());
		if (M != 0) {
			st = new StringTokenizer(br.readLine(), " ");
		}
		for (int i = 0; i < M; i++) {
			broken[Integer.parseInt(st.nextToken())] = true; 
		}
		// 2. +, - 버튼으로만 채널 이동하는 횟수 변수 ans에 저장
		int ans = N - 100;
		if (ans < 0) {
			ans = -ans;
		}
		// 3. 0 ~ 100,000의 범위에서 각 자리의 숫자 고장 여부 확인하는 메서드 isPossible 생성(numbers[tmp%10] == true)
		for (int i = 0; i <= 1000000; i++) {
			int c = i;
			int len = isPossible(c);
			
			// 6.만약 return 값이 0보다 클 경우 len + Math.abs(N - i) 값이 정답이 됨
			if (len > 0) {
				int press = c - N;
				if (press < 0) {
					press = -press;
				}
				
				if (ans > len + press) {
					ans = len + press;
				}
			}
		}
			
		System.out.println(ans);
	}
	private static int isPossible(int c) {
		// 4. 고장여부 확인과 동시에 고장 버튼이면 return 0; 
		if (c == 0) {
			if (broken[0]) {
				return 0;
			} else {
				return 1;
			}
		}
		
		// 5. 고장 버튼이 아닐시에 해당 숫자 버튼을 누르는 길이를 세서 return len;
		int len = 0;
		while (c > 0) {
			if (broken[c%10]) {
				return 0;
			}
			
			len+=1;
			c /= 10;
		}
		return len;
	}
}