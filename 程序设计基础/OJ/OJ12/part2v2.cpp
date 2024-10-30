#include <iostream>
#include <vector>
using namespace std;
 
int N, M, minimum = 20000;
vector<int> a, b;
vector<int> maxPower;
 
void findmax(int pos){
 
    int max = 0;
 
    for (int i = 0; i < N ; i ++){
        if (pos == a[i]){
            if (b[i]> max){
                max = b[i];
            }
        }
    }
 
    for(int i = minimum; i < pos; i++){
        int j = pos - i;
        
        if (j < minimum){
            continue;
        }
 
        int val;
        if (j == i){
            val = maxPower[i]*2 + 233;
        }
        else{
            val = maxPower[i] + maxPower[j];
        }
        if (val > max){
            max = val;
        }
    }
 
    maxPower[pos] = max;
 
    if (pos == M){
        return;
    }
    else{
        findmax(pos+1);
    }
}
 
int main() {
    cin >> N >> M;
 
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        if (x < minimum){
            minimum = x;
        }
        a.push_back(x);
    }
    for (int i = 0; i < N; ++i){
        int x;
        cin >> x;
        b.push_back(x);
    }
    
    // for (int i = 0; i < N ; i ++){
    //     cout << a[i] << ' ';
    // }
    // cout << endl;
 
    // for (int i = 0; i < N ; i ++){
    //     cout << b[i] << ' ';
    // }
    // cout << endl;
 
    for (int i = 0; i<=M ; i ++){
        maxPower.push_back(0);
    }
 
    findmax(minimum);
 
    // for (int i = 0 ; i <= M ; i ++){
    //     cout << maxPower[i] << endl;
    // }
 
    cout << maxPower[M] << endl;
    return 0;
}