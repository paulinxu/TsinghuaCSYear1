#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
 
using namespace std;
 
struct strct{
    string name;
    string score;
};
 
int getint(string n){
    int result = 0;
    int multiplier = 1;
    for (int i = n.length()-1; i>=0; i--){
        result += int(n[i]-48)*multiplier;
        multiplier *= 10;
    }
    return result;
}
 
string getfirst(string a, string b){
 
    if (a.length()<b.length()){
        for (int i = 0; i<a.length(); i++){
            if (int(a[i])<int(b[i])){
                return a;
            }
            else if (int(a[i])>int(b[i])){
                return b;
            }
        }
        return a;
    }
    else {
        for (int i = 0; i<b.length(); i++){
            if (int(b[i])<int(a[i])){
                return b;
            }
            else if (int(b[i])>int(a[i])){
                return a;
            }
        }
        return b;
    }
}
 
int main(){
    int n, x, y;
    cin >> n >> x >> y;
 
    vector<string> students(0);
    vector<int> scores(0);
 
    for (int i = 0; i<n ; i++){
        strct line;
        cin >> line.name >> line.score;
        students.push_back(line.name);
        scores.push_back(getint(line.score));
    }
    // LIKE
    for (int i = 0; i<x ; i++){
        strct line;
        cin >> line.name;
        for (int a = 0; a < students.size(); a++){
            if (line.name == students[a]){
                if (scores[a]<= 55){
                    scores[a] = 60;
                }
                else if (!(scores[a]>95)){
                    if (scores[a]<90){
                        scores[a] += 5;
                    }
                    else{
                        scores[a] = 95;
                    }
                }
            }
        }
    }
    //DISLIKE
    for (int i = 0; i<y ; i++){
        strct line;
        cin >> line.name;
        for (int a = 0; a < students.size(); a++){
            if (line.name == students[a]){
                if ((scores[a]>=60)){
                    if (scores[a]<=65){
                        scores[a] = 60;
                    }
                    else{
                        scores[a] -= 5;
                    }
                }
            }
        }
    }
 
    vector<string> students_sorted1(0);
    vector<int> scores_sorted1(0);
 
    for (int i = 0; i<n; i++){
        int max = 0;
        int maxpos = 0;
        for (int pos = 0; pos < scores.size(); pos++){
            if (scores[pos]>max){
                max = scores[pos];
                maxpos = pos;
            }
        }
        students_sorted1.push_back(students[maxpos]);
        scores_sorted1.push_back(scores[maxpos]);
 
        students.erase(students.begin() + maxpos);
        scores.erase(scores.begin() + maxpos);
    }
 
    for (int i=0; i<students_sorted1.size();i++){
        for (int a = 0 ; a<students_sorted1.size()-1; a++){
            if (scores_sorted1[a]==scores_sorted1[a+1]){
                if (students_sorted1[a+1] == getfirst(students_sorted1[a], students_sorted1[a+1])){
                    string students_temp = students_sorted1[a];
                    students_sorted1[a] = students_sorted1[a+1];
                    students_sorted1[a+1] = students_temp;
 
                    int scores_temp = scores_sorted1[a];
                    scores_sorted1[a] = scores_sorted1[a+1];
                    scores_sorted1[a+1] = scores_temp;
                }
            }
        }
    }
 
    for (int i = 0 ; i<n ; i++){
        cout << students_sorted1[i] << " " << scores_sorted1[i] << endl;
    }
}