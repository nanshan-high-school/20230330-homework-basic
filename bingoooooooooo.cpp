#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(NULL));
    int count = 1, n = 0, line = 0, num[25], array[5][5] = {0};
    bool finish=true;
    
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
    
    while(finish==true){
        n=rand()%25+1;
        array[n / 5][n%5]=0;
        cout << "{" << n / 5 << "," << n % 5 << "}"<< endl;
        
        for(int i=0;i<5;i++){
            if(array[0][i]==0){
                line=0;
                for(int j=0;j<5;j++){
                    if(array[i][j]==0){
                        line++;
                    }
                } 
                if (line==5){
                    cout<<"bingo!";
                    return(0);
                }
            }
        }
        
        for(int i=0;i<5;i++){
            if(array[i][0]==0){
                line=0;
                    for(int j=0;j<5;j++){
                        if(array[j][i]==0){
                            line++;
                        }
                    }
                    if (line==5){
                        cout<<"bingo!";
                        return(0);
                    }
            }
        }
        
        if(array[0][0]==0){
            line=0;
                for(int j=0;j<5;j++){
                    if(array[j][j]==0){
                        line++;
                    }
                }
                if (line==5){
                    cout<<"bingo!";
                    return(0);
                }
        }
        
        if(array[4][0]==0){
            line=0;
                for(int j=0;j<5;j++){
                    if(array[4-j][j]==0){
                        line++;
                    }
                }
                if (line==5){
                    cout<<"bingo!";
                    return(0);
                }
        }
    }
}
