#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge
{
    int weight;
    int start;
    int end;
};

int **grid;
int n;
vector<edge> edges;
bool finish = false;

class pclass 
{
    public:
    vector<int> pointers;
    int n;
    int m;
    int sumlim = n*m-(n-1)*n/2;

    //int minWeight = 10000000;

    pclass(int n, int m) : n(n), m(m)
    {
        for (int i = 1 ; i <= n ; i ++)
        {
        pointers.push_back(i);
        }
    }
    void add()
    {
        
        int sum = 0;
        for (int i = 0 ; i < n ; i++)
        {
            sum += pointers[i];
        }
        if (sum >= sumlim)
        {
            finish = true;
            return;
        }
        
        int pos = n-1;
        while (pos >= 0)
        {   
            pointers[pos] += 1;

            if (pointers[pos] > m - (n-1 - pos) && pos == 0)
            {
                pointers[pos] --;
                break;
            }
            else if (pointers[pos] > m - (n-1 - pos))
            {
                pointers[pos] = pointers[pos-1] + 2;
                pos --;
            }
            else
            {
                break;
            }
        }
    }
    void printpointers()
    {
        for (int i = 0 ; i < n ; i ++)
        {
            cout << pointers[i] << ' ';
        }
        cout << endl;
    }
    bool isValid()
    {
        edge left = edges[pointers[0]];
        edge right = edges[pointers[0]];
        bool valid = true;
        for (int i = 1 ; i < n ; i ++)
        {
            edge current = edges[pointers[i]];
            if (current.end == left.start)
            {
                left = current;
            }
            else if (current.start == left.end)
            {
                right = current;
            }
            else
            {
                valid = false;
                break;
            }
        }
        return valid;
    }
};

bool lesser(edge a, edge b)
{
    if (a.weight <= b.weight)
    {
        return true;
    }
    return false;
}

int main()
{

    cin >> n;
    grid = new int*[n];
    for (int i = 0 ; i < n ; i ++)
    {
        grid[i] = new int[n];
        for (int j = 0 ; j < n ; j++)
        {
            int w;
            cin >> w;
            if (i != j)
            {
                edge temp;
                temp.weight = w;
                temp.start = i+1;
                temp.end = j+1;
                edges.push_back(temp);
            }
        }
    }
    
    sort(edges.begin(), edges.end(), lesser);

    pclass p(n, edges.size());
    cout << p.sumlim << endl;
    int c = 0;
    while (!finish)
    {
        p.printpointers();
        p.add();
        c++;
    }
    

}