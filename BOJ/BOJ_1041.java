import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		long N = Integer.parseInt(br.readLine()); // N이 int형으로 포함되면 형을 낮춰서 들어감
		
		StringTokenizer stk = new StringTokenizer(br.readLine());
		long[] dice = new long[] {
				Integer.parseInt(stk.nextToken()),
				Integer.parseInt(stk.nextToken()),
				Integer.parseInt(stk.nextToken()),
				Integer.parseInt(stk.nextToken()),
				Integer.parseInt(stk.nextToken()),
				Integer.parseInt(stk.nextToken())};
		
		
		long one = (N-2)*(5*N-6)*minOne(dice);
		long two = 4*(2*N-3)*minTwo(dice);
		long three = 4*minThree(dice);
		
		// 한 면만 보이는 경우 4*(N-1)*(N-2)+(N-2)*(N-2)개 -> (N-2)(5N-6)개
		// 두 면이 보이는 경우 4*(N-1)+4*(N-2)개 -> 4(2N-3)개
		// 세 면이 보이는 경우 4개
		if(N == 1) {
			System.out.println(diceOne(dice));
		} else {
			System.out.println(one + two + three);
		}
	}

	private static long diceOne(long[] dice) {
		long sum = 0;
		long max = 0;
		for (int i = 0; i < 6; i++) {
			sum += dice[i];
			max = Math.max(max, dice[i]);
		}
		return sum - max; 
	}

	private static long minThree(long[] dice) {
		long min = Long.MAX_VALUE;
		for (int i = 0; i < 4; i++) {
			for (int j = i+1; j < 5; j++) {
				if(i + j != 5) // 선택된 두 면이 마주보는 경우
				for (int k = j+1; k < 6; k++) {
					if(j + k != 5 && k + i != 5) // 나머지도 마주보지 않는 경우
						min = Math.min(min, dice[i]+dice[j]+dice[k]); 
				}
			}
		}
		return min;
	}

	private static long minTwo(long[] dice) {
		long min = Long.MAX_VALUE;
		for (int i = 0; i < 5; i++) {
			for (int j = i+1; j < 6; j++) {
				if(i + j != 5) // 선택된 두 면이 마주보는 경우
					min = Math.min(min, dice[i]+dice[j]); 
			}
		}
		return min;
	}

	private static long minOne(long[] dice) {
		long min = Long.MAX_VALUE;
		for (int i = 0; i < 6; i++) {
			min = Math.min(min, dice[i]);
		}
		return min;
	}
	
	
}