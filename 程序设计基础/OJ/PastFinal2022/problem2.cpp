#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct meet{
    int startTime;
    int endTime;
};

int convert(string data){

    string string_hour = data.substr(0,2);
    string string_minute = data.substr(3,2);

    int sum = 0;

    sum += (int(string_hour[0] - '0')*600 + int(string_hour[1] - '0')*60 
    + int(string_minute[0] - '0')*10 + int(string_minute[1] - '0'));

    return sum;
}

int main(){

    meet meet1;
    meet meet2;

    string a, b, c, d;
    cin >> a >> b >> c >> d;

    meet1.startTime = convert(a);
    meet1.endTime = convert(b);
    meet2.startTime = convert(c);
    meet2.endTime = convert(d);

    if (meet1.endTime > meet2.startTime){
        cout << meet1.endTime - meet2.startTime << endl;
    }
    else {
        cout << -1 << endl;
    }

}