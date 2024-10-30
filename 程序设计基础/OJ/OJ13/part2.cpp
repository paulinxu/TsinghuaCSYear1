#include <iostream>
#include <vector>
using namespace std;

struct plant{
    int time;
    int value;
    bool used = false;
};

int t, m;
plant *plants;
int *maximums;
vector<int> *maximums_plants_used;

int independend(vector<int> a, vector<int> b){
    for (int i = 0 ; i< a.size(); i ++){
        for (int j = 0; j<b.size(); j++){
            if (a[i] == b[j]){
                return false;
            }
        }
    }
    return true;
}

void findmax(int pos){
    if (pos > t){
        return;
    }
    
    bool found = false;
    for (int i = 0; i < m ; i++){
 
        if (plants[i].time <= pos && plants[i].used == false){

            bool foundgreater = false;
            for (int j = 0; j < m ; j++){
                if (plants[i].time == plants[j].time && plants[j].value > plants[i].value && plants[j].used == false){
                    foundgreater = true;
                    break;
                }
            }
            if (foundgreater){
                continue;
            }
 
            if (maximums[pos-1] >= plants[i].value + maximums[pos - plants[i].time]){
                maximums[pos] = maximums[pos-1];
                maximums_plants_used[pos] = maximums_plants_used[pos-1];
                found = true;
                break;
            }
            else{
                // cout << "---" << plants[i].value + plants[pos-i].value << endl;
                maximums[pos] = plants[i].value + maximums[pos - plants[i].time];

                maximums_plants_used[pos].push_back(i);
                for (int x = 0; x < maximums_plants_used[pos - plants[i].time].size(); x++){
                    maximums_plants_used[pos].push_back(maximums_plants_used[pos - plants[i].time][x]);
                }

                plants[i].used = true;
                found = true;
                break;
            }
 
        }
    }
    if (found == false){
        maximums[pos] = maximums[pos-1];
        maximums_plants_used[pos] = maximums_plants_used[pos-1];
    }

    for (int i = 0; i < pos/2; i ++){
        int j = pos-i;
        if (maximums[i]+maximums[j] > maximums[pos] && independend(maximums_plants_used[i], maximums_plants_used[j])){ // i, j must be independent
            maximums[pos] = maximums[i]+maximums[j];

            maximums_plants_used[pos].clear();

            for (int x = 0; x < maximums_plants_used[i].size(); x++){
                maximums_plants_used[pos].push_back(maximums_plants_used[i][x]);
            }
            
            for (int x = 0; x < maximums_plants_used[j].size(); x++){
                maximums_plants_used[pos].push_back(maximums_plants_used[j][x]);
            }
        }
    }
 
    findmax(pos+1);
}

int main(){
    
    cin >> t >> m;

    plants = new plant[m];

    for (int i = 0; i < m ; i++){
        cin >> plants[i].time >> plants[i].value;
    }

    // for (int i = 0; i < m ; i++){
    //     cout << plants[i].time << ' ' << plants[i].value << ' ' << plants[i].used << endl;
    // }

    maximums = new int[t+1];
    maximums_plants_used = new vector<int>[t+1];

    for (int i = 0 ; i < t+1 ; i++){
        maximums[i] = 0;;
    }

    findmax(1);

    
    // cout << "==============" << endl;
    // for (int i = 0; i < t+1; i++){
    //     cout << maximums[i] << ": ";

    //     for (int j =0 ; j < maximums_plants_used[i].size() ; j++){
    //         cout << maximums_plants_used[i][j] << ' ';
    //     }
        
    //     cout << endl;
    // }

    cout << maximums[t] <<endl;
    


}