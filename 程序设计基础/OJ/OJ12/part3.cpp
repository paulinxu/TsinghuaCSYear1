#include <iostream>
using namespace std;

int n;
long long l;
int *nums;

long long find(int pos, long long sum){
    if (pos >= n){
        return sum;
    }
    
    long long minimum;
    for (int i = pos+1; i <= n; i++){
        long long s = 0;
        for (int x = pos; x < i; x++){
            s += nums[x];
        }
        long long val = (s-l) * (s-l);

        // returning minimum value
        if (i == pos+1){
            minimum = find(i, sum+val);
        }
        else{
            long long x = find(i, sum+val);
            if (x < minimum){
                minimum = x;
            }
        }
    }
    return minimum;
}

int main(){
    cin >> n >> l;
    nums = new int[n];
    for (int i = 0 ; i < n ; i ++){
        cin >> nums[i];
    }

    cout << find(0, 0);
}