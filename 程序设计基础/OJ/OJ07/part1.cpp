#include <iostream>
using namespace std;
 
struct Node{
    int x, y;
} a, b;
 
Node mean(Node a, Node b)
{
    Node temp = {(a.x + b.x) / 2, (a.y + b.y) / 2};
    return temp;
}
 
int main() {
  
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    
    Node c = mean(a,b);
    cout<< c.x << " "<<c.y << endl;
    return 0;
}