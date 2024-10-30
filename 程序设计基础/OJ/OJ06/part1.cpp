#include <iostream>
using namespace std;
 
int *arr;
 
int sort(int n, int start){
    int min = arr[start];
    int minpos = start;
 
    for (int j = start+1; j<n ; j++){
        if (arr[j] < min){
            min = arr[j];
            minpos = j;
        }
    }
 
    int temp = arr[start];
    arr[start] = min;
    arr[minpos] = temp;
 
    cout << "swap(a[" << start << "], a[" << minpos << "]):";
    for (int x = 0 ; x < n ; x ++){
        cout << arr[x] << ' ';
    }
    cout << endl;
 
    if (start == n-1){
        return 0;
    }
    else{
        return sort(n, start+1);
    }
}
 
int main(){
 
    int n;
 
    cin >> n;
    arr = new int[n];
    for (int i = 0 ; i < n ; i ++){
        cin >> arr[i];
    }
 
    sort(n, 0);
}