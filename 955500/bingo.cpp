#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
  int bingo[5][5];
  int number[25];
  srand(time(0));
  for (int i = 0; i < 25; i++) {
    int pick = rand() % 25 + 1;
    number[i] = pick;
    for (int j = 0; j < i; j++) {
      if (number[j] == pick){
        i--;
        break;
      }
    }
  }
for (int i = 0; i < 25; i++){
      cout << number[i] << "\n";   
    }
int x = 0;
for (int i = 0; i < 5; i++){
    for (int j = 0; j < 5; j++){
      bingo[i][j] = number[x];
      x += 1;
      cout << bingo[i][j] << " ";    
    }
cout << "\n";
  }

  
      
      
   
  
  
}
