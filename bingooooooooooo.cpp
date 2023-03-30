#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(NULL));
    int array[5][5];
    int count = 1;
    int num[25];
    for (int i = 0; i < 25; i++) {
        num[i] = i + 1;
    }
    
    for (int i = 0; i < 25; i++) {
        int j = rand() % 25;
        int temp = num[i];
        num[i] = num[j];
        num[j] = temp;
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            array[i][j] = num[count - 1];
            cout << array[i][j] << " ";
            count++;
        }
        cout << endl;
    }

    return 0;
}
