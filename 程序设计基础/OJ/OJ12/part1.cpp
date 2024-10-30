#include <iostream>
#include <vector>
#include <algorithm>

//memo
#include <map>
#include <tuple>
// CLOSE memo

using namespace std;

int *all, *important, n, m;

// memo

std::map<std::tuple<int, int, int, int>, int> memo;

// CLOSE memo

int findmax(int left, int right, int height, int interceptions){
    
    auto key = std::make_tuple(left, right, height, interceptions);
    if (memo.find(key) != memo.end()) {
        return memo[key];
    }
    
    int difference = all[right] - height;

    if (left == right){
        return interceptions;
    }
    
    if (height > all[right]){
        return 0;
    }

    int temp_max = 0;
    for (int d = 0; d <= difference ; d ++){

        int new_interceptions = 0;
        if (height+d == all[left]){
            new_interceptions += 1;
        }

        int x = findmax(left+1, right, height+d, interceptions + new_interceptions);
        if (x > temp_max){
            temp_max = x;
        }
    }

    memo[key] = temp_max;

    return temp_max;
}

int endfindmax(int n, const vector<int>& heights, int m, const vector<int>& mandatoryMissiles) {
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
 
    return *max_element(dp.begin(), dp.end());
}

int main(){

    cin >> n;
    all = new int[n]; 
    for (int i = 0 ; i < n; i++){
        cin >> all[i];
    }

    cin >> m;
    important = new int[m];
    for (int i = 0 ; i < m ; i++){
        int val;
        cin >> val;
        important[i] = val-1;
    }

    int sum = 0;

    for (int i = 0 ; i < m-1 ; i++){
        sum += findmax(important[i], important[i+1], all[important[i]], 0);
    }

    sum += findmax(0, important[0], 0, 0);

    // cout << "sum: " << sum << endl;
    
    int endspace = n-1 - important[m-1];

    if (endspace != 0){

        vector<int> heights(endspace+1);
        for (int i = 0 ; i < endspace+1; i++){
            heights[i] = all[i + important[m-1]];
            //cout << heights[i] << endl;
        }

        vector<int> mandatoryMissiles(n);

        sum += endfindmax(endspace+1, heights, 0, mandatoryMissiles);
    }    
    cout << sum << endl;
    
}