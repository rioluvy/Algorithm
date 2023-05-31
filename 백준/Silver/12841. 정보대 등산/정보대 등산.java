import java.util.*;
import java.io.*;

public class Main{
	// 12847 누적합을 해결해보자.
	
	public static void main(String[] args) throws IOException {
		//Scanner in = new Scanner(System.in);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		long[] cross = new long[n+1]; // 횡단 보도
		long[] left = new long[n]; // 왼쪽 길 거리
		long[] right = new long[n]; // 오른쪽 길 거리
		st = new StringTokenizer(br.readLine());
		for(int i=1; i<=n; i++)
			cross[i] =  (long)Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		for(int i=1; i<n; i++)
			left[i] = left[i-1] + (long)Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		for(int i=1; i<n; i++)
			right[i] = right[i-1] + (long)Integer.parseInt(st.nextToken());
		long min = 9223372036854775807L;
		int idx = 0;
		for(int i=1; i<=n; i++) {
			long max = cross[i] + right[n-1] - right[i-1] + left[i-1] - left[0];
			if(max < min) {
				min = max;
				idx = i;
			}
			else if(max == min) {
				min = max;
			}
		}
		System.out.print(idx+" ");
		System.out.print(min);
	}

}
