// Kadane's algorithm for maximum sum subarray.
ll kadane(vector<ll>& a){
    ll maxsum = -1e18;
    ll currsum = 0;
    for(int i = 0; i < n; i++){
        currsum += a[i];
        maxsum = max(maxsum, currsum);
        currsum = max(currsum, 0LL);
    }
    return maxsum;
}
