class Reader {
	private BufferedReader br;
	private StringTokenizer zer;
	public Reader() {
		br = new BufferedReader(new InputStreamReader(System.in));
		zer = null;
	}
	public String nextLine() throws IOException { return br.readLine(); }
	public String next() throws IOException {
		while(zer == null || !zer.hasMoreTokens()) {
			zer = new StringTokenizer(br.readLine());
		}
		return zer.nextToken();
	}
	public int nextInt() throws IOException { return Integer.parseInt(next()); }
	public long nextLong() throws IOException { return Long.parseLong(next()); }
	public float nextFloat() throws IOException { return Float.parseFloat(next()); }
	public double nextDouble() throws IOException { return Double.parseDouble(next()); }
}
