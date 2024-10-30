#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int n, m;
vector<int> lengths(0);
vector<int> strengths(0);

int find(int l, int s){

    if (l == m){
        return s;
    }
    if (l>m){
        return 0;
    }

    int maxs = 0;
    for (int i = 0; i < lengths.size(); i++){

        int news;

        if (s == strengths[i]){
            news = s*2 +233;        
        }
        else{
            news = s + strengths[i];
        }

        if (l + lengths[i] <= m){
            int x = find(l + lengths[i], news);
            if (x> maxs){
                maxs = x;
            }
        }
    }

    return maxs;
}

int main()
{   
    cin >> n >> m;

    for (int i = 0 ; i < n ; i++){
        int x;
        cin >> x;
        lengths.push_back(x);
    }
    for (int i = 0 ; i < n ; i++){
        int x;
        cin >> x;
        strengths.push_back(x);
    }
    cout << find(0, 0) << endl;

}
