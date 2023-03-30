#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
  int count = 0;
  int bingo[5][5];
  int number[25] = {0};
  srand(time(0));
  for (int i = 0; i < 25; i++) {
    int pick;
    do {
      pick = rand() % 25 + 1;
    } while (number[pick - 1] > 0);

    number[pick - 1]++;

    cout << pick << "  ";
    count++;
    if (count == 5) {
      cout << '\n';
      count = 0;
    }
  }

  for (int i = 0; i < 25; i++) {
    int y = i / 5;
    int x = i % 5;
    bingo[y][x] = number[i];
  }

  // for (int i = 0; i < 5; i++) {
  //     for (int j = 0; j < 5; j++) {
  //         bingo[i][j] = number[5*i+j];
  //     } // j
  // } // i

  int number2[25] = {0};
  int question[25] = {0};
  for (int i = 0; i < 25; i++) {
    int pick;
    do {
      pick = rand() % 25 + 1;
    } while (number[pick] > 0);

    number[pick - 1]++;

    question[i] = pick + 1;

    // bingo[0][0~2]
    for (int j = 0; j <= i; j++) {
      if (bingo[0][0] == question[i]) {
      }
    }
  }
}
