import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class Main
{
	public static void main(String[] args) throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		int n=Integer.parseInt(br.readLine());
		char[][] grid=new char[n+1][n+1];
		for(int i=1;i<=n;i++)
		{
			String tempstr=br.readLine();
			for(int j=1;j<=n;j++)
				grid[i][j]=tempstr.charAt(j-1);
		}
		final long MOD=(long)1e9+7;
		long[][] dp=new long[n+1][n+1];
		for(int i=0;i<n+1;i++)
			Arrays.fill(dp[i],0);
		dp[1][1]=(grid[1][1]=='.'?1:0);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(grid[i][j]=='.')
				{
					dp[i][j]+=dp[i-1][j];
					dp[i][j]%=MOD;
					dp[i][j]+=dp[i][j-1];
					dp[i][j]%=MOD;
				}
			}
		}
		System.out.println(dp[n][n]);
	}
}
