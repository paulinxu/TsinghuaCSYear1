#include <iostream>
#include <vector>
#include <climits>
using namespace std;
 
long long findMinCost(const vector<int>& nums, int n, long long L) {
    vector<long long> cumSum(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cumSum[i + 1] = cumSum[i] + nums[i];
    }
 
    vector<long long> dp(n + 1, LLONG_MAX);
    dp[0] = 0;
 
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            long long segmentSum = cumSum[i] - cumSum[j];
            long long cost = (segmentSum - L) * (segmentSum - L);
            dp[i] = min(dp[i], dp[j] + cost);
        }
    }
 
    return dp[n];
}
 
int main() {
    int n;
    long long L;
    cin >> n >> L;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
 
    cout << findMinCost(nums, n, L) << endl;
    return 0;
}