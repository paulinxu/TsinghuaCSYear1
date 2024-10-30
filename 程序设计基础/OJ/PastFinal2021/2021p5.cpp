#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> times(1,0);

    int n, k;
    cin >> n >> k;
    
    for (int i = 0 ; i < n ; i ++){
        int val;
        cin >> val;
        times.push_back(val);
    }

    int min = times[1] + times[2] + times[3] + times[4];
    int sat = 1;
    int sun = 3;
 
    for (int i = 1 ; i <= n-k-1 ; i ++){
        for (int j = i + 2 ; j <= n-1; j++){
            
            int current = times[i] + times[i+1] + times[j] + times[j+1];

            if (current < min){
                min = current;
                sat = i;
                sun = j;
            }

        }
    }
    cout << sat << ' ' << sun;
}