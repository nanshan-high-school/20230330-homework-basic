#include <iostream>
#include <ctime>
using namespace std;
int main () {

    int array[25];
    int check[25];
    int num, count = 0;
    
    srand(time(0));
    for (int i = 0; i < 25; i++) {
        check[i] = 0;
    }
    while (count < 25) {
        num = rand() % (25) + 0;
        if (check[num] == 0) {
            check[num] = 1;
            array[count] = num;
            count ++;
        } else {
            continue;
        }
    }
    for (int i = 0; i < 25; i++) {
        cout << array[i] + 1 << endl;
    }
    cout << endl;
    for (int i = 0; i < 25; i++) {
        cout << "-" << "\t";
        if ((i + 1) % 5 == 0) {
            cout << endl;
        }
    }
    cout << endl;
 
    for (int i = 0; i < 25; i++) {
        cout << array[i] + 1 << "\t";
        if ((i + 1) % 5 == 0) {
            cout << endl;
        }
    }
    cout << endl << "BINGO!!" << endl;
}