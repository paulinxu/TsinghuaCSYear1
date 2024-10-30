#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, m;
    cin >> n;
    vector<vector<int>> points;
    for (int i = 0 ; i < n ; i ++){
        vector<int> p(2);
        cin >> p[0] >> p[1];
        points.push_back(p); 
    }
    vector<int> solutions;
    cin >> m;
    for (int i = 0 ; i < m ; i ++){

        int x, y, r;
        cin >> x >> y >>r;
        int count = 0 ;

        for (int j = 0 ; j < n ; j ++){
            int lhs = (points[j][0]-x)*(points[j][0]-x) + (points[j][1]-y)*(points[j][1]-y);
            int rhs = r*r;
            if (lhs <= rhs){
                count++;
            }
        }

        solutions.push_back(count);
    }

    for (int i = 0; i < m ; i ++){
        cout << solutions[i] << ' ';
    }

}