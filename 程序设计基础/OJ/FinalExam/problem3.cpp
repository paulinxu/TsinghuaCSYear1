#include <iostream>
#include <vector>


using namespace std;

int m1, n1 , m2 , n2 , s ,p;

int **matrix;
int **kernel;

int convolutepixel(int x1, int y1){

    int sum = 0 ;

    for (int i = 0 ; i < m2 ; i++){
        for (int j = 0 ; j < n2 ; j ++){
            // cout << matrix[x1 + i][y1 + j] << ' ' <<  kernel[i][j] << endl;;
            sum += matrix[x1 + i][y1 + j] * kernel[i][j];
        }
    }

    // cout << x1 << ' '  << y1 << ' ' << sum << endl;
    
    return sum;

}

int main(){

    cin >> m1 >> n1 >> m2 >> n2 >> s >> p;

    if (p >= 1){

        matrix = new int*[m1+ (2*p)];
        for (int i = 0 ; i < m1+ (2*p) ; i ++){
            matrix[i] = new int[n1 + (2*p)];
        }

        for (int i = 0 ; i < m1+ (2*p) ; i ++){
            for (int j = 0 ; j < n1 + (2*p) ; j ++){
                matrix[i][j] = 0;
            }
        }

        for (int i = p ; i < p + m1 ; i ++){
            for (int j = p ; j < p + n1 ; j ++){
                int val;
                cin >> val;
                matrix[i][j] = val;
            }
        }

        m1 = m1+ (2*p);
        n1 = n1 + (2*p);

    }
    else {
        matrix = new int*[m1];
        for (int i = 0 ; i < m1 ; i ++){
            matrix[i] = new int[n1];
        }

        for (int i = 0 ; i < m1 ; i ++){
            for (int j = 0 ; j < n1 ; j ++){
                int val;
                cin >> val;
                matrix[i][j] = val;
            }
        }

    }


    kernel = new int*[m2];
    for (int i = 0 ; i < m2 ; i ++){
        kernel[i] = new int[n2];
    }

    for (int i = 0 ; i < m2 ; i ++){
        for (int j = 0 ; j < n2 ; j ++){
            int val;
            cin >> val;
            kernel[i][j] = val;
        }
    }

    // for (int i = 0 ; i < m1 ; i ++){
    //     for (int j = 0 ; j < n1 ; j ++){
    //         cout << matrix[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    // for (int i = 0 ; i < m2 ; i ++){
    //     for (int j = 0 ; j < n2 ; j ++){
    //         cout << kernel[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    // start 

    vector< vector<int> > result;

    
    int xpos = 0;
    int ypos = 0;

    if (s % 2 == 1){
        while(xpos + s < m1){

            int ypos = 0;

            vector<int> temp;

            while (ypos + s < n1){

                // cout << xpos << ' ' << ypos << endl;

                temp.push_back(convolutepixel(xpos, ypos));

                ypos += s;

            }

            result.push_back(temp);

            xpos += s;
        }

    }
    else{
        while(xpos + s <= m1){

            int ypos = 0;

            vector<int> temp;

            while (ypos + s <= n1){

                // cout << xpos << ' ' << ypos << endl;

                temp.push_back(convolutepixel(xpos, ypos));

                ypos += s;

            }

            result.push_back(temp);

            xpos += s;
        }

    }

    

    

    // printing


    for (int i = 0 ; i < result.size() ; i ++){
        for (int j = 0 ; j < result[i].size() ; j ++){
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }

}