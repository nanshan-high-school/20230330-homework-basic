#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;
int nums[5][5] = {0};
int count = 0;
int row;
int col;
int turn = 0;
int level[5][5] = {1};
int line = 0;
void check();   //檢查連線數量
void tryget();  //能連線就連線
void change();  //更改等級
void findmax(); //找最大等級
void out();     //顯示電腦的bingo格子

int main() {
  srand(time(0));
  cout << "五條線就贏了\n你要先(0)還是後(1)";
  while (true) {
    cin >> turn;
    if (turn == 0 || turn == 1) {
      break;
    } else {
      cout << "你要先(0)還是後(1)";
    }
  }

  //建立電腦的bingo格子
  while (count < 25) {
    row = rand() % 5;
    col = rand() % 5;
    if (nums[row][col] == 0) {
      nums[row][col] = count + 1;
      count++;
    }
  }
  //進行遊戲
  while (line < 5) {
    if (turn == 1) {
      turn = 0;
    } else {
      turn = 1;
    }
    if (turn == 0) {
      tryget(); //先連線
      if (row == -1 && col == -1) {
        findmax();
      }
      cout << "抽出" << nums[row][col] << endl;
      nums[row][col] = 0;
    } else { //讓使用著輸入
      int a;
      bool findit = false;
      do {
        cout << "輸入你要劃掉數字";
        cin >> a;
        for (row = 0; row < 5; row++) {
          for (col = 0; col < 5; col++) {
            if (a == nums[row][col]) {
              nums[row][col] = 0;
              findit = true;
              break;
            }
          }
          if (a == nums[row][col]) {
            nums[row][col] = 0;
            findit = true;
            break;
          }
        }
      } while (!findit || a == 0); //若輸入錯誤則重興輸入
    }
    level[row][col] = -1; //避免已選過的數被選到
    change();

    check();
    //檢查
    cout << "你bingo了嗎(Y/N)";
    char player;
    while (true) {
      cin >> player;
      if (player == 'Y' || player == 'y' || player == 'N' || player == 'n') {
        break;
      } else {
        cout << "你bingo了嗎(Y/N)";
      }
    }
    if (player == 'y') {
      player = 'Y';
    }
    if (line >= 5 && player == 'Y') {
      out();
      cout << "平手";
      break;
    } else if (line >= 5) {
      out();
      cout << "bingo，電腦贏了";
      break;
    } else if (player == 'Y') {
      out();
      cout << "你贏了";
      break;
    }
  }
}

void check() {
  line = 0;
  bool bingo = true;
  for (int i = 0; i < 5; i++) {
    bingo = true;                 // 每次迭代都重置 bingo
    for (int k = 0; k < 5; k++) { // 添加 k 的初始值
      if (nums[i][k] != 0) {
        bingo = false;
      }
    }
    if (bingo) {
      line += 1;
    }
  }

  for (int i = 0; i < 5; i++) {
    bingo = true;                 // 每次迭代都重置 bingo
    for (int k = 0; k < 5; k++) { // 添加 k 的初始值
      if (nums[k][i] != 0) {
        bingo = false;
      }
    }
    if (bingo) {
      line += 1;
    }
  }

  // 檢查斜線是否都為0
  bingo = true;
  for (int i = 0; i < 5; i++) {
    if (nums[i][i] != 0) {
      bingo = false;
      break;
    }
  }
  if (bingo) {
    line += 1;
  }

  bingo = true;
  for (int i = 0; i < 5; i++) {
    if (nums[i][4 - i] != 0) {
      bingo = false;
      break;
    }
  }
  if (bingo) {
    line += 1;
  }
  return;
}
void tryget() {

  int bingo = 0;
  for (int i = 0; i < 5; i++) {
    bingo = 0;                    // 每次迭代都重置 bingo
    for (int k = 0; k < 5; k++) { // 添加 k 的初始值
      if (nums[i][k] != 0) {
        row = i;
        col = k;
      } else {
        bingo++;
      }
    }
    if (bingo == 4) {
      return;
    }
  }

  for (int i = 0; i < 5; i++) {
    bingo = 0;                    // 每次迭代都重置 bingo
    for (int k = 0; k < 5; k++) { // 添加 k 的初始值
      if (nums[k][i] != 0) {
        row = k;
        col = i;
      } else {
        bingo++;
      }
    }
    if (bingo == 4) {
      return;
    }
  }

  // 檢查斜線是否能連線
  bingo = 0;
  for (int i = 0; i < 5; i++) {
    if (nums[i][i] != 0) {
      row = i;
      col = i;
    } else {
      bingo++;
    }
  }
  if (bingo == 4) {
    return;
  }

  bingo = 0;
  for (int i = 0; i < 5; i++) {
    if (nums[i][4 - i] != 0) {
      row = i;
      col = 4 - i;
    } else {
      bingo++;
    }
  }
  if (bingo == 4) {
    return;
  }
  row = -1;
  col = -1;
  return;
}
void change() {
  for (int i = 0; i < 5; i++) {
    if (level[i][col] != -1) {
      level[i][col] += 1;
    }
  }
  for (int i = 0; i < 5; i++) {
    if (level[row][i] != -1) {
      level[row][i] += 1;
    }
  }
  if (row == col) {
    for (int i = 0; i < 5; i++) {
      if (level[i][i] != -1) {
        level[i][i] += 1;
      }
    }
  }
  if (row == 4 - col) {
    for (int i = 0; i < 5; i++) {
      if (level[i][4 - i] != -1) {
        level[i][4 - i] += 1;
      }
    }
  }
  level[row][col] = -1;
}
void findmax() {
  int maxscore = 0;
  for (int i = 0; i < 5; i++) {
    for (int z = 0; z < 5; z++) {
      if (nums[i][z] != 0 && maxscore < level[i][z]) {
        maxscore = level[i][z];
        row = i;
        col = z;
      }
    }
  }
}
void out() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cout << nums[i][j] << "\t";
    }
    cout << endl;
  }
}
