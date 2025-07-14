#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(int argc, char** argv) {

int n,m1=0,m2=0,g,up=1,down=99,deter,j=2,b=50; 
/*m1/m2 is the time pc/people guessing
deter 是人判斷電腦猜的數有無符合人想的數所表示的行動
n 是電腦產生的隨機數後給人猜
g 是人猜電腦所想的數
b 是電腦每次猜人想的數*/
srand(time(NULL));

n=(rand()%99)+1;    //(0-98)---(1-99);

do{   //先看哪方先猜對
    cout<<"---Your turn---\n Guess a number between 1-99: ";
    cin>>g; //g is the number that people guessed.
    m2++;
    if(g>n) {  //the case that people guess too big
        cout<<"Your guess is too big"<<endl;
    }//end of if
    if(g<n){
        cout<<"Your guess is too small"<<endl;
    }//end of if
    if(g==n){
        cout<<" right \n People has guessed "<<m2<<" times"<<endl;
    }//end of if

    cout<<"---PC's turn---\n PC's Guess: "<<b; //b  is the number that people guessed.
    m1++;
    cout<<"\n People answer(0:too big, 1:too small, otherwise:bingo): ";
    cin>>deter;

    

    if (deter==0){ // the case pc guess too big
        down=b-1;
        b=(up+down)/2;
    }//end of if
    if (deter==1){ // the case pc guess too small
        up=b+1;
        b=(up+down)/2;
    }//end of if
    if (deter!=0&&deter!=1){ //the case pc guess right
        cout<<"PC is right! \n PC has guessed "<<m1<<" times!"<<endl;
        j=0; //j represents the case that PC guess right
    }//end of if
}//end of do 
while(j!=0&&g!=n); //在人跟電腦都沒猜對時繼續迴圈

if(g==n&&j!=0){   //人先猜中, pc do not
    do{
        cout<<"---PC's turn---\n PC's Guess: "<<b; //b  is the number that people guessed.
        m1++;
        cout<<"\n People answer(0:too big, 1:too small, otherwise:bingo): ";
        cin>>deter;

        if (deter==0){ // the case pc guess too big
            down=b-1;
            b=(up+down)/2;
         }//end of if
        if (deter==1){ // the case pc guess too small
            up=b+1;
            b=(up+down)/2;
            }//end of if
        if (deter!=0&&deter!=1){ //the case pc guess right
            cout<<" PC is right! \n PC has guessed "<<m1<<" times!"<<endl;
            j=0; //j represents the case that PC guess right
        }//end of if
    }//end of do
    while(j!=0);  //the do end when PCguessed the correct answer
}//end of if


if (j==0&&g!=n) {  //PC 先猜中,people do not
    do{
        cout<<"---Your turn---\n Guess a number between 1-99: ";
        cin>>g; //g is the number that people guessed.
        m2++;
        if(g>n) {  //the case that people guess too big
            cout<<"Your guess is too big"<<endl;
        }//end of if
        if(g<n){
            cout<<"Your guess is too small"<<endl;
        }//end of if
        if(g==n){
            cout<<"right \n People has guessed "<<m2<<" times"<<endl;
        }//end of if
    }//end of do
    while(g!=n);//this do end when people guessed the answer
}//end of if


if (m2<m1){
    cout<<"People has won the game\n People has guessed "<<m2<<" times";
}
if (m2>m1){
    cout<<"PC has won the game\n PC has guessed "<<m1<<" times";
}
if (m2==m1){
    cout<<"Both won the game\n Both have guessed "<<m2<<" times";
}

    return 0;
}


