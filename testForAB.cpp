#include <iostream>
#include <time.h>

using namespace std;
int main(int argc, char** argv) {

int i,j,a=0,b=0;
int peGuess[4],pcAnswer[4];
pcAnswer[0]=rand()%9+1;   //1-9
for(i=1;i<4;i++){
    pcAnswer[i]=rand()%10;   //0-9
    for(j=i-1;j>=0;j++){
        while(pcAnswer[i]==pcAnswer[j]){ //代表需要重做的時候是與前元素（j）數字相同時
            pcAnswer[i]=rand()%10;
        }//end of while
    }//end of for inside
    cout<<pcAnswer[i]<<"\t";
}//end of for in order to produce four different entries
return 0;
}