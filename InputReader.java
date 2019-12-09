class InputReader{
    private BufferedReader br;
    private StringTokenizer zer;

    public InputReader(){
        br = new BufferedReader(new InputStreamReader(System.in));
        zer = null;
    }

    public String n(){
        try{
            while(zer == null || !zer.hasMoreTokens())zer = new StringTokenizer(br.readLine());
            return zer.nextToken();
        }catch(IOException e){
            throw new RuntimeException(e);
        }
    }
    
    public String nL(){
		try{
			return br.readLine();
		}catch(IOException e){
			throw new RuntimeException(e);
		}
	}

    public int ni(){
        return Integer.parseInt(n());
    }
    
    public long nl(){
		return Long.parseLong(n());
	}
	
	public float nf(){
		return Float.parseFloat(n());
	}
	
	public double nd(){
		return Double.parseDouble(n());
	}
}
