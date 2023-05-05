import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int X = Integer.parseInt(br.readLine());
		
		int ans = 0;
		int stick = 64;
		int cur = 0;
		while(cur != X) {
			if(stick == X) { ans++; break; }
			stick /= 2;
			// 절반을 잘라서 X보다 크면 붙인다. 붙인 막대 개수만 센다
			if(stick + cur <= X) {
				cur += stick;
				ans++;
			} 
		}
		System.out.println(ans);
	}
}
