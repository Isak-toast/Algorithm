import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.StringTokenizer;

/*
 * N명의 사람이 원을 이루면 앉음
 * K번째 사람을 제거 -> N명이 모두 제거될 때까지 계속
 * 
 * (N,K) 요세푸스 순열이라고 함
 * sol) 입력 자료구조를 순회하면서 값을 빼서 순열을 만든다.
 * 큐 자료구조를 활용
 * 앞에 있는 원소를 뒤로 위치 -> 연산 1번
 * K번 마다 순열 리스트에 저장
 */
public class Main {
	public static void main(String[] args) {
		try {
			version1();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	private static void version1() throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer stk = new StringTokenizer(br.readLine());
		StringBuilder sb = new StringBuilder();
		
		int N = Integer.parseInt(stk.nextToken());
		int K = Integer.parseInt(stk.nextToken());
		Queue<Integer> input = new LinkedList<>();
		for(int i = 1; i <= N; i++) input.offer(i);
		List<Integer> josephus = new ArrayList<>();
		
		int cur = 1;
		while(input.size() != 0) {
			if(cur == K) {
				cur = 1;
				josephus.add(input.poll());
			}
			else {
				cur++;
				input.offer(input.poll());
			}
		}
		sb.append("<" + josephus.get(0));
		for(int i = 1; i < N; i++) sb.append(", " + josephus.get(i));
		sb.append(">");
		System.out.println(sb);
		br.close();
	}
}
