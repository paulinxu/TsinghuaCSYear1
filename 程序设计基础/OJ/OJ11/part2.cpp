#include <iostream>
using namespace std;

int* arr;
int n;

int sort(int start, int end){

    int lenght = end - start + 1;
    int midpoint = (start+end)/2;

    if(start == end){
        return 0;
    }

    sort(start, midpoint);
    sort(midpoint+1, end);

    int *a, *b;
    a = new int[lenght/2];
    b = new int[lenght/2];

    for (int i = 0; i<lenght/2; i++){
        a[i]=arr[start + i];
        b[i]=arr[midpoint + 1 + i];
    }
    
    int* temp;
    temp = new int[lenght];

    int i=0, j=0;
    for (int k = 0; k < lenght ; k++){
        if (i == lenght/2){
            temp[k] = b[j++];
        }
        else if (j == lenght/2){
            temp[k] = a[i++];
        }
        else if(a[i] < b[j]){
            temp[k] = a[i++];
        }
        else{
            temp[k] = b[j++];
        }
    }

    for (int i = start; i <= end ; i++){
        arr[i] = temp[i-start];
        cout << arr[i] << ' ';
    }

    cout << endl;

    delete[] a;
    delete[] b;
    delete[] temp;

    return 0;
}

int main(){
    cin >> n;
    arr = new int[n];

    for (int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    sort(0,n-1);

    delete[] arr;

}