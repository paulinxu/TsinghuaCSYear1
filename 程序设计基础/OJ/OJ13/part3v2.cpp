#include <iostream>
#include <vector>
using namespace std;

int n, m;

int shortest = 1000000;

struct position{int x, y;};

vector<position> dxy;

position start_pos, goal_pos = {0,0}; // problem here 

position path[1000];

int num;

int pos_cnt[2][100][100] = {{{0}}};

bool IsEq(position pos1, position pos2){
    return (pos1.x == pos2.x) && (pos1.y == pos2.y);
}

bool IsDone(position pos){
    return IsEq(pos, goal_pos);
}

bool IsValid(position pos, int step){
    bool v, s, r;
    int dir = step %2;

    v = (pos.x >= 0) && (pos.x <= n) && (pos.y >= 0) && (pos.y <= n);

    s = (pos.x==pos.y || pos.x == 0 || pos.x == n);

    r = pos_cnt[dir][pos.x][pos.y] == 0;

    return (v && s && r);

}

void SetCount(position pos, int step, int cnt){
    int dir = step%2;
    pos_cnt[dir][pos.x][pos.y] = cnt;
}

position GetNewPos(position pos, int k, int step){
    int dir = (step%2 ==0) ? -1:1;
    position next_pos = {pos.x + dir * dxy[k].x, pos.y + dir * dxy[k].y};
    return next_pos;
}

void LogStep(position pos, int step){
    path[step] = pos;
}

void OutStep(position pos){
    cout << "(" << pos.x << ", " << pos.y << ") ";
}
void OutAll(int step){
    for (int i=0; i<=step; i++){
        OutStep(path[i]);
    }
    cout << endl;
}

void Jump(position pos, int step){
    if (IsDone(pos)){
        num++;
        //cout << num << ": ";
        if (step < shortest){
            shortest = step;
        }
        //OutAll(step);
        return;
    }
    for (int k=1; k < dxy.size(); k++){
        position next_pos = GetNewPos(pos, k, step);
        if (!IsValid(next_pos, step+1)){
            continue;
        }
        SetCount(next_pos, step+1, 1);
        LogStep(next_pos, step+1);
        Jump(next_pos, step+1);
        SetCount(next_pos, step+1, 0);
    }
}

int main(){

    cin >> n >> m;
    for (int i = 0; i<=m; i++){
        for (int j = 0 ; j<=m ; j ++){
            if (i+j <= m){
                dxy.push_back({i, j});
            }
        }
    }
    
    // for (int i = 0;  i < dxy.size() ; i ++){
    //     cout << dxy[i].x << ' ' << dxy[i].y << endl;
    // }

    start_pos = {n, n};
    num = 0;

    SetCount(start_pos, 0, 1);
    LogStep(start_pos, 0);
    Jump(start_pos, 0);
    if (shortest == 1000000){
        cout << -1 << endl;
    }
    else{
        cout << shortest << endl;
    }

    return 0;
}