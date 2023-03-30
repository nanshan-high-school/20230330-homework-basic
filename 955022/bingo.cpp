#include <cstdlib>
#include <iostream>
using namespace std;
int main() {
  int bingo[5][5];
  int one_to_twentyfive[25] = {0};
  srand(time(0));

  for (int i = 0; i < 25; i++) {
    int pick;

    do {
      pick = rand() % 25 + 1;
    } while (one_to_twentyfive[pick - 1] > 0);
    
    one_to_twentyfive[pick - 1]++;
    
    cout << pick << '\n';
  }

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      bingo[i][j] = one_to_twentyfive[i * 5 + j];
    } // j
  } // i
  
    return 0;
}
