import java.util.*;
import java.io.*;

public class Main {
	static int[] dx = {0,1,0,-1};
	static int[] dy = {1,0,-1,0};
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		char[][] board = new char[N][M];
		for (int i = 0; i < N; i++) {
			String s = br.readLine();
			for (int j = 0; j < M; j++) {
				board[i][j] = (s.charAt(j) == '.')?'@':'+';
			}
		}
		// 시작점, 도착점 찾기
		List<int[]> hole = new ArrayList<int[]>();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if(board[i][j] == '@' && (i == 0 || j == 0 || i == N-1 || j == M-1)) {
					hole.add(new int[] {i,j});
				}
			}
		}
		board[hole.get(0)[0]][hole.get(0)[1]] = '.';
		BackT(board,N,M,hole.get(0),hole.get(1));
	}
	
	public static void BackT(char[][] board, int N, int M,int[] now,int[] end) {
		if(now[0] == end[0] && now[1] == end[1]) {
			board[now[0]][now[1]] = '.';
			StringBuilder sb = new StringBuilder();
			
			for (int i = 0; i < N; i++) {
				sb.append(board[i]);
				sb.append("\n");
			}
			System.out.println(sb.toString());
			return;
		}
		for (int d = 0; d < 4; d++) {
			int nx = now[0]+dx[d];
			int ny = now[1]+dy[d];
			if(0 <= nx && nx < N && 0 <= ny && ny < M && board[nx][ny] == '@') {
				board[nx][ny] = '.';
				BackT(board,N,M,new int[] {nx,ny},end);
				board[nx][ny] = '@';
			}
		}
	}
}