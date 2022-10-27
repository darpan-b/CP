// creating the pi table for pattern searching (here it is the prefix of the string itself)
vector<int> lps(n,-1);
int preidx = -1;
for(int i = 1; i < n; i++)
{
	while(preidx > -1 && s[i] != s[preidx+1])
		preidx = lps[preidx];
	if(s[preidx+1] == s[i])
	{
		preidx++;
		lps[i] = preidx;
	}
}
