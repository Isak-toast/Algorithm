import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int N;
	static int[][] R;
	static int[] guilty;
	static boolean[] killed;
	static int ans;
	static int eunjin;
	static int night;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stk = null;
		N = Integer.parseInt(br.readLine());
		guilty = new int[N];
		stk = new StringTokenizer(br.readLine());
		for (int i = 0; i < N; i++) {
			guilty[i] = Integer.parseInt(stk.nextToken()); 
		}
		R = new int[N][N];
		for (int i = 0; i < N; i++) {
			stk = new StringTokenizer(br.readLine());
			for (int j = 0; j < N; j++) {
				R[i][j] = Integer.parseInt(stk.nextToken()); 
			}
		}
		eunjin = Integer.parseInt(br.readLine());
		killed = new boolean[N];
		
		int total = N;
		int mafia = 1;
		int cityzen = N-1;
		
		night = 0;
		if(total != mafia) {
			game(0, total, mafia, cityzen);
		}
		System.out.println(night);
	}

	// 모든 최적해를 찾아본다.
	static boolean flag;
	private static void game(int cnt, int total, int mafia, int cityzen) {
		if(flag) return;
		if((total&1) == 0) {
			if(cityzen == 1) { // 시민이 1명이면 어차피 끝남
				night = Math.max(night, cnt+1);
				flag = true;
				return;
			}
			// 밤에는 유죄 지수를 낮춰주는 최적의 수로 진행
			for (int i = 0; i < N; i++) {
				// 은진을 제외한 산 사람 중에서 죽인다
				if(i == eunjin || killed[i]) continue;
				killed[i] = true; // 빵야 
				addGuilty(i);
				game(cnt + 1, total-1, mafia, cityzen-1);
				subGuilty(i);
				killed[i] = false; // 부활! 
			}
		} else {
			// 낮에는 모든 인원 중 유죄 지수가 가장 높은 한 명이 죽는다.
			int j = justice();
			if(j == eunjin) {
				night = Math.max(night, cnt);
				return; // 마피아가 죽어서 게임 끝
			}
			killed[j] = true; 
			game(cnt, total-1, mafia, cityzen-1);
			killed[j] = false;
		}		
	}

	
	private static int justice() {
		int max = 0;
		int j = 0;
		for (int i = N-1; i >= 0; i--) {
			if(killed[i]) continue; // 죽은 사람은 심판받지 않음
			if(max <= guilty[i]) {
				max = guilty[i];
				j = i;
			}
		}
		return j;
	}
	private static void subGuilty(int i) {
		for (int j = 0; j < N; j++) {
			if(killed[j]) continue;
			guilty[j] -= R[i][j]; 
		}
	}

	private static void addGuilty(int i) {
		for (int j = 0; j < N; j++) {
			if(killed[j]) continue;
			guilty[j] += R[i][j]; 
		}
	}
}