#include <iostream>
#include <vector>

using namespace std;

int max(int a, int b){
    return a > b ? a:b;
}

int main(){
    int n;
    cin >> n;

    vector<int> nums(n+1, 0);
    nums[0] = -10001;

    for (int i = 1 ; i <= n ; i ++){
        int x; 
        cin >> x;
        nums[i] = x;
    }

    vector<int> dp(n+1, 0);

    
        
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i] >= nums[j]) {
                dp[i] = max(dp[i], dp[j] + nums[i]);
            }
        }
    }
    
    for (int i = 0 ; i <= n ; i ++){
        cout << nums[i] << ' ' << dp[i] << endl;
    }


}