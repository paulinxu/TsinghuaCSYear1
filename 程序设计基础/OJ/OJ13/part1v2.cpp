#include <iostream>
#include <string>
using namespace std;

string a, b;

int max(int a, int b){
    return (a>b ? a:b);
}

int find(int pos_a, int pos_b, int count){

    //cout << pos_a << ' ' << pos_b << ' ' << count << endl;

    if (pos_a >= a.length() - 1 || pos_b >= b.length() -1){
        return count+1;
    }

    int new_pos = -1;
    for (int i = pos_b; i< b.length() ; i ++){
        if (a[pos_a] == b[i]){
            //cout << a[pos_a] << endl;
            new_pos = i;
            break;
        }
    }

    if (new_pos >= 0){
        return max(find(pos_a+1, pos_b, count), find(pos_a+1, new_pos+1, count+1));
    }
    else{
        return find(pos_a+1, pos_b, count);
    }
}

int main(){
    
    cin >> a >> b;
    cout << find(0, 0, 0) << endl;

}