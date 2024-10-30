#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int maxMissilesIntercepted(int n, const vector<int>& heights, int m, const vector<int>& mandatoryMissiles) {
    vector<int> dp(n, 1);
 
    vector<bool> isMandatory(n, false);
    for (int idx : mandatoryMissiles) {
        isMandatory[idx] = true;
    }
 
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (heights[i] >= heights[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
 
    return dp[n-1];
}
 
int main() {
    int n, m;
    cin >> n;
    vector<int> heights(n);
    for (int i = 0; i < n; ++i) {
        cin >> heights[i];
    }

    cin >> m;
    vector<int> mandatoryMissiles(m);
    for (int i = 0; i < m; ++i) {
        cin >> mandatoryMissiles[i];
    }
 
    cout << maxMissilesIntercepted(n, heights, m, mandatoryMissiles) << endl;
    return 0;
}