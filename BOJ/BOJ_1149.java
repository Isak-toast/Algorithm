import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	static int N;
	static int[][] colorMap;
	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(br.readLine());
		
		colorMap = new int[N+1][3];
		
		for (int i = 1; i <= N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int j = 0; j < 3; j++) {
				colorMap[i][j] = Integer.parseInt(st.nextToken()); 
			}
		}
		// 최소 비용 구하기 알고리즘
		/*
		 * colormap의 첫번째 컬러는 0인덱스  직전 컬러의 1,2중에서 최소 비용을 선택
		 * colormap의 두번째 컬러는 1인덱스  직전 컬러의 0,2중에서 최소 비용을 선택
		 * colormap의 세번째 컬러는 2인덱스  직전 컬러의 0,1중에서 최소 비용을 선택
		 * 
		 * 마지막 집에서 세가지 최적해 중에서 가장 최소인 값을 출력
		 */
		for(int i = 2; i <= N; i++) {
			colorMap[i][0] = colorMap[i][0] + Math.min(colorMap[i-1][1], colorMap[i-1][2]);
			colorMap[i][1] = colorMap[i][1] + Math.min(colorMap[i-1][0], colorMap[i-1][2]);
			colorMap[i][2] = colorMap[i][2] + Math.min(colorMap[i-1][0], colorMap[i-1][1]);
		}
		System.out.println(minThree(colorMap[N][0], colorMap[N][1], colorMap[N][2]));
	}
	private static int minThree(int x, int y, int z) {
		return Math.min(x, Math.min(y, z));
	}
}
