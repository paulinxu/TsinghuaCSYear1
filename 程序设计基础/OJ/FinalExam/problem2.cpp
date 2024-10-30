#include <iostream>
#include <vector>
#include <string>


using namespace std;

string toLower(string a)
{
    for (int i = 0; i < a.length(); i++)
    {
        if (int(a[i]) >= 65 && int(a[i]) <= 90)
        {
            a[i] = a[i] + 32;
        }
    }
    return a;
}

string convertt(int num){
    vector<char> chars;
    chars.push_back('0' + (num/10));
    chars.push_back('0' + (num%10));
    string text = "";
    text += chars[0];
    text += chars[1];
    return text;
} 

string clean(string a){
    while (a[0] == '0'){
        a = a.substr(1, a.length()-1);
    }
    if (a.length() == 0){
        a = "0";
    }
    return a;
}

int main(){

    string convert[16] = {"zero", "one", "two", "three", " four", "five", "six", "seven", 
    "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen"};

    vector<int> nums;

    int n;
    cin >> n;

    for (int i = 0 ; i < n ; i ++){
        string text;
        cin >> text;
        text = toLower(text);
        for(int x = 0 ; x <=15 ; x++){
            if (text == convert[x]){
                nums.push_back(x);
            }
        }
    }

    // square + mod

    for (int i = 0 ; i < nums.size() ; i++){
        nums[i] = (nums[i]*nums[i]) % 100;
    }

    //sort 

    for (int i = 0 ; i < nums.size() ; i ++){

        int smallest = 10000;
        int pos = i;

        for (int j = i; j < nums.size() ; j ++){
            if (nums[j] < smallest){
                smallest = nums[j];
                pos = j;
            }
        }

        nums[pos] = nums[i];
        nums[i] = smallest; 
    }

    

    //concatenate

    string result = "";
    for (int i = 0 ; i < nums.size() ; i++){
        int x = nums[i];
        result += convertt(x);
    }

    cout << clean(result); 
    
}