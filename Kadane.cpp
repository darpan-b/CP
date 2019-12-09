// implementation of kadane's algorithm to find max sum continuous subarray

int kadane(int a[],int n){
	int maxsum = -INF,currsum = 0;
	for(int i = 0; i < n; i++){
		currsum += a[i];
		maxsum = max(maxsum,currsum);
		currsum = max(currsum,0);
	}
	return maxsum;
}
