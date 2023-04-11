#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;
int nums[5][5] = {0};
int count = 0;
bool bingo = true;
int row;
int col;
int r;
int line;

//檢查是否獲勝
bool check() {
  line=0;
  bingo = true; // 新增 bingo 變量並初始化為 true
  for (int i = 0; i < 5; i++) {
    bingo = true;                 // 每次迭代都重置 bingo 為 true
    for (int k = 0; k < 5; k++) { // 添加 k 的初始值
      if (nums[i][k] != 0) {
        bingo = false;
      }
    }
    if (bingo) {
      line++;
    }
  }

  for (int i = 0; i < 5; i++) {
    bingo = true;                 // 每次迭代都重置 bingo 為 true
    for (int k = 0; k < 5; k++) { // 添加 k 的初始值
      if (nums[k][i] != 0) {
        bingo = false;
      }
    }
    if (bingo) {
      line++;
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
    line++;
  }

  bingo = true;
  for (int i = 0; i < 5; i++) {
    if (nums[i][4 - i] != 0) {
      bingo = false;
      break;
    }
  }
  if (bingo) {
    line++;
  }
  if(line>=3){
    return true;
  }else{
    return false;
  }
  
}

int main() {
  srand(time(0));
  char player;
  while (count < 25) {
    row = rand() % 5;
    col = rand() % 5;
    if (nums[row][col] == 0) {
      nums[row][col] = count + 1;
      count++;
    }
  }
  //顯示
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cout << nums[i][j] << "\t";
    }
    cout << endl;
  }

  while (true) {
    //抽隨機數字
    row = rand() % 5;
    col = rand() % 5;
    while (nums[row][col] == 0) {
      row = rand() % 5;
      col = rand() % 5;
    }
    r = nums[row][col];
    nums[row][col] = 0;
    cout << "抽出" << r << endl;

    //顯示
    for (int i = 0; i < 5; i++) {
      for (int j = 0; j < 5; j++) {
        cout << nums[i][j] << "\t";
      }
      cout << endl;
    }

    //檢查
    cout << "你bingo了嗎(Y/N))";
    cin >> player;
    if (player == 'y') {
      player = 'Y';
    }
    if (check() && player == 'Y') {
      cout << "平手";
      break;
    } else if (check()) {
      cout << "bingo，電腦贏了";
      break;
    } else if (player == 'Y') {
      cout << "你贏了";
      break;
    }
  }
}
