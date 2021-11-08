//NOT TESTED

// Kadane's algorithm for maximum sum subarray.

long long kadane(vector<long long>& a) {
    long long maxsum = -1e18;
    long long currsum = 0;
    for (int i = 0; i < n; i++) {
        currsum += a[i];
        maxsum = max(maxsum, currsum);
        currsum = max(currsum, 0LL);
    }
    return maxsum;
}
