#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

struct state {int R, G;};

int n, m;

state s[1000];
int d[1000] = {0};
int k;

vector<state> op;

void display(){
    for (int i = 1; i <= k ; i++){
        cout << setw(2) << i;
        cout << ": (" << s[i].R << ',' << s[i].G << ")";
        cout << " choice = " << d[i];
        cout << " {" << op[d[i]].R << ',' << op[d[i]].G << "}";
        cout << endl;
    }

}

void transfer_state(){
    k = 1;
    s[1].R = n;
    s[1].G = n;
    int fx;

    do{
        if (k%2 == 1){fx = -1;}
        else {fx = 1;}

        int i;
        for (i = d[k]+1 ; i < op.size() ; i ++){

            int u = s[k].R + fx*op[i].R;
            int v = s[k].G + fx*op[i].G;

            if (u > n || v > n || u < 0 || v < 0){
                continue;
            }

            bool AQ = (u==n) || (u==0) || (u==v);
            if (!AQ){
                continue;
            }

            bool CHF = false;
            for (int j = k-1 ; j >=1 ; j -=2){
                if (s[j].R == u && s[j].G == v){
                    CHF = true;
                }
            }
            if (CHF) {
                continue;
            }


            d[k] = i;
            k++;
            s[k].R = u;
            s[k].G = v;

            break;

        }

        if (i > op.size()-1) {
            d[k--] = 0;
        }

    } while (!(s[k].R == 0 && s[k].G == 0));
}

int main(){

    cin >> n >> m;
    for (int i = 0; i<=m; i++){
        for (int j = 0 ; j<=m ; j ++){
            if (i+j <= m){
                op.push_back({i, j});
            }
        }
    }
    
    for (int i = 0;  i < op.size() ; i ++){
        cout << op[i].R << ' ' << op[i].G << endl;
    }

    transfer_state();
    display();


    cout << k-1 << endl;
    return 0;
}