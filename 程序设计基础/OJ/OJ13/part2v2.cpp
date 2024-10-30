#include <iostream>
#include <algorithm>
using namespace std;
 
struct plant {
    int time;
    int value;
};
 
int main() {
    int T, M;
    cin >> T >> M;
    plant *plants;
    plants = new plant[M];
 
    for (int i = 0; i < M; i++) {
        cin >> plants[i].time >> plants[i].value;
    }
 
    int dp[101][1001];
    for (int i = 0; i <= M; i++) {
        for (int j = 0; j <= T; j++) {
            dp[i][j] = 0;
        }
    }
 
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= T; j++) {
            if (plants[i - 1].time <= j) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - plants[i - 1].time] + plants[i - 1].value);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
 
    cout << dp[M][T] << endl;
 
    return 0;
}