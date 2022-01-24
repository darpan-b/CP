class InputReader {
    private BufferedReader bufferedReader;
    private StringTokenizer stringTokenizer;
    
    public InputReader() {
        bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        stringTokenizer = null;
    }
    
    public String nextLine() throws IOException {
        return bufferedReader.readLine();
    }
    
    public String next() throws IOException {
        while (stringTokenizer == null || !stringTokenizer.hasMoreTokens())
            stringTokenizer = new StringTokenizer(bufferedReader.readLine());
        return stringTokenizer.nextToken();
    }
    
    public int nextInt() throws IOException {
        return Integer.parseInt(next());
    }
    
    public long nextLong() throws IOException {
        return Long.parseLong(next());
    }
    
    public float nextFloat() throws IOException {
        return Float.parseFloat(next());
    }
    
    public double nextDouble() throws IOException {
        return Double.parseDouble(next());
    }
}
