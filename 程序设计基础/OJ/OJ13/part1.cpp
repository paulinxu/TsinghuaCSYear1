#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int main() {
    string a, b;
    cin >> a >> b;
 
    vector< vector<int> > dp(2, vector<int>(b.length() + 1, 0));
 
    for (int i = 1; i <= a.length(); i++) {
        for (int j = 1; j <= b.length(); j++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i % 2][j] = dp[(i - 1) % 2][j - 1] + 1;
            } else {
                dp[i % 2][j] = max(dp[(i - 1) % 2][j], dp[i % 2][j - 1]);
            }
        }
    }
 
    cout << dp[a.length() % 2][b.length()] << endl;
    return 0;
}