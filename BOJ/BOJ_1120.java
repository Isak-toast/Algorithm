import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stk = new StringTokenizer(br.readLine());
		
		String X = stk.nextToken();
		String Y = stk.nextToken();
		
		int ans = Integer.MAX_VALUE;
		for (int i = 0; i < Y.length() - X.length() + 1; i++) {
			int cnt = 0;
			for (int j = 0; j < X.length(); j++) {
				if(X.charAt(j) == Y.charAt(i+j))
					cnt++;
			}
			ans = Math.min(ans, X.length()-cnt);
		}
		System.out.println(ans);
	}
}

