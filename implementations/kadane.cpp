ll kadane(ll a[],int n){
	ll maxsum = -1e18,currsum = 0;
	for(int i = 0; i < n; i++){
		currsum += a[i];
		maxsum = max(maxsum,currsum);
		currsum = max(currsum,0);
	}
	return maxsum;
}
