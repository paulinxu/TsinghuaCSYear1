#include <iostream>
#include <vector>
using namespace std;
int n, m;
 
vector<int> heights, mandatoryMissiles(1000, 0), maximums;
 
int getmax(int a, int b){
    return (a>b ? a : b);
}
 
void findmax(int pos, vector<int> &maximums, int currMax){
    if (mandatoryMissiles[pos]){
        for (int i = 0; i < pos; i++){
            if (heights[i] > heights[pos]){
                maximums[i] = 0;
            }
        }
        currMax = heights[pos];
    }
 
    for (int i = 0; i < pos ; i++){
        if (heights[pos] >= heights[i]){
            maximums[pos] = getmax(maximums[pos], maximums[i]+1); 
        }
    }
 
    if (heights[pos] < currMax){
        maximums[pos] = 0;
    }
 
    if (pos == n-1){
        return;
    }
    else {
        findmax(pos+1, maximums, currMax);
    }
}
 
int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        heights.push_back(x);
    }
 
    vector<int> maximums(n,1);
    maximums[0] = 1;
 
    cin >> m;
    int lastMax = 0;
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        mandatoryMissiles[x] = 1;
        lastMax = getmax(lastMax, x);
    }
    
    findmax(0, maximums, 0);
    // for (int i = 0 ; i < n ; i ++){
    //     cout << maximums[i] << endl;
    // }
 
    int oput = 0;
    for (int i = lastMax; i < n; i++){
        oput = max(oput, maximums[i]);
    }
    cout << oput << endl;
 
}