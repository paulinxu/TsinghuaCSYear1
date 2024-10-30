#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int find(vector<int> times, int n){
    sort(times.begin(), times.end());
    
    if (n <= 2){
        return times.back();
    }

    int total = 0;

    while (n > 3){
        int option_1 = times[0] + times[n-1] + times[1] *2;
        int option_2 = times[n-1] + times[n-2] + times[0]*2;

        total += min(option_1, option_2);

        n = n-2;
    }

    if (n == 3){
        total += (times[0] + times[1] + times[2]);
    }
    else {
        total += (times[1]);
    }

    return total;
}

int main(){
    int n;
    cin >> n;
    vector<int> times(n);
    for (int i =0 ; i< n ; i++){
        cin >> times[i];
    }

    cout << find(times, n) << endl;

}