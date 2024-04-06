#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(int argc, char** argv) {

int i,j;
int peGuess[4],pcAnswer[4]; //peGuess人的猜測 pcAnswer電腦的答案

int a=0,b=0; //電腦給人的hint
int already[50][4]; //人所書過的不重複數們
bool info=true;
int a6=0,fact=0; //fact輸入不重複數放入already的次數

int data[4600][4]; //所有可能
int n=0; //data的樣本數
int z,k;

int pcTime=0,peTime=0;

int a3=0,b3=0; //a3 and b3 are the number that 判斷data 中的數字是否跟猜的數字(data[initialGuSite][i)同Ａ同Ｂ
int q;
int n1=0; //符合數值時所放入次數
bool compare1=false;//if(a3==a1&&b3==b1) compare1=true;與電腦所猜的數同AB的狀況
bool compare2=false;//if(a1!=4&&n==0) compare2=true;false為人沒騙 true為人騙了
bool compare3=false;//true猜中時 false沒猜中
int initialGuSite; //電腦隨機取的樣本位子
int a1,b1;//hint to the computer in order to 判斷電腦猜測
int selectNum[4]; //怕被符合資料蓋過的電腦猜測


int rank[20]={0};//this is the ranking
int sort=0,st; //玩家總共玩的次數
int ask=1;//whether the player wants to play again (ask==1 repeat ask==0 reject)
int contem; //排名暫存的地方
srand(time(NULL));



while(ask==1){
    peTime=0;pcTime=0;
    compare3=false;

for(i=0;i<fact;i++){
    for(j=0;j<4;j++){
        already[i][j]=0;
    }
}//先把所有already info歸零

fact=0;

pcAnswer[0]=rand()%9+1;   //1-9
cout<<pcAnswer[0]<<"\t";

bool compare=true;

 for(i=1;i<4;i++){
    do{
        pcAnswer[i]=rand()%10;
            compare=true;
        for(j=0;j<4;j++){
            if(i==j){
                break; //比到自己就不用繼續下去，因為接下來也不會重複
            }else if(pcAnswer[i]==pcAnswer[j]){
                compare=false;
            }//end of else if
        }//end of for inside
    }//end of do
    while(!compare); //repeat the loop when compare is falsch
    cout<<pcAnswer[i]<<" "<<"\t";
}   //in order to 產生電腦的答案
//cout<<endl;


n=0;
for(i=1;i <10;i ++){
       for(j=0;j<10;j++){
            if(i==j){
                continue;
            }
             for(k=0;k<10;k++){
                   if(k==j||k==i){
                      continue;
                      }
                   for(z=0;z<10;z++){
                        if(z==j||z==k||z==i){
                            continue;
                        }//end of if 
                         data[n][0]=i;
                         data[n][1]=j;
                         data[n][2]=k;
                         data[n][3]=z;
                         n++;
                     }// end of for controlling z
              }//end of for controlling k
        }//end of for controlling j
}////end of for controlling i
//all possibilities 
//cout<<"this is initial n: "<<n<<endl;



do{
    cout<<"\n------PEOPLE's turn------"<<endl;
    if(peTime<1){
        cout<<"Please guess the computer answer: ";
        cin>>peGuess[0]>>peGuess[1]>>peGuess[2]>>peGuess[3];
    }
    
    info=true;
    while(info&&peTime>=1){ //有可能會重複的時候發生在一次之後
        a6=0;
        cout<<"Please guess the computer answer: ";
        cin>>peGuess[0]>>peGuess[1]>>peGuess[2]>>peGuess[3];

        for(i=fact;i>=0;i--){
            a6=0; //每換一個要歸零
            for(k=0;k<4;k++){
                
                if(already[i][k]==peGuess[k]){
                    a6++; //位置跟數字都一樣
                }
                
            }//end of for controlling already
            if(a6==4){ //the case that 數字完全一樣
                info=true;
                break; //break for of i
            }
            if(a6!=4){
                info=false;
            }
        }//check every already ob die schon drin sind.
    }//end of while in order to ask people wieder neue Nummer anzugeben
    peTime++;
    //cout<<"this is the "<<peTime<<" th info and a6 "<<a6<<endl;
    //cout<<"this is fact "<<fact;
    for(i=0;i<4;i++){
        already[fact][i]=peGuess[i];
        //cout<<already[fact][i];
    }//放到資料庫裡
    fact++;
    
    
    a=0;b=0;
    for(i=0;i<4;i++){ //in order to control the array of the computer answer
        for(j=0;j<4;j++){ //in order to control the array of the people's guess
            if(i==j && pcAnswer[i]==peGuess[j]){ //位置跟數字都對
                a++;
            }//end of if presenting the case that it corresponds the condition of A
            if(i!=j && pcAnswer[i]==peGuess[j]){ //位置不對數字對
                b++;
            }//end of if presenting the case that it corresponds the condition of B
        }//end of for (j)
    }//end of for(i)
    cout<<a<<"A"<<b<<"B"<<endl;

    cout<<"------PC's turn------"<<endl;
    pcTime++;
    initialGuSite=rand()%n; //從n中隨機挑一個數字
    //cout<<initialGuSite<<endl;
    cout<<"computer's guess is : ";
    
    for(i=0;i<4;i++){
        selectNum[i]=data[initialGuSite][i];
        cout<<data[initialGuSite][i];
    }
    cout<<endl; //to print the answer of computer


    cout<<"People's answer is (a1)A (b1)B : ";
    cin>>a1>>b1;

    n1=0;
    for(q=0;q<n;q++){ //q is the variable to control the first, second, third...data
        a3=0;
        b3=0; //新的數比較要歸零
        compare1=false;
    
        for(i=0;i<4;i++){ //in order to control the number of computer's guess
            for(j=0;j<4;j++){ //in order to control the number of the data
                if(i==j && selectNum[i]== data[q][j]){ //位置跟數字都對
                    a3++;
                }//end of if presenting the case that it corresponds the condition of A
                if(i!=j && selectNum[i]== data[q][j]){ //位置不對數字對
                    b3++;
                }//end of if presenting the case that it corresponds the condition of B
            }
        }//end of for to check the AB
    
    if(a3==a1&&b3==b1)compare1=true;
    if(compare1&& a3!=4){ //represents the case that the selected data same AB with the data base.
        for(j=0;j<4;j++){ 
            data[n1][j]=data[q][j]; //n1 is from 0
            //cout<<data[n1][j];
        }//end of for in order to put the 當前資料放到此矩陣的第一個位置順便計算這樣的例子會有幾個
        n1++;
        //cout<<"\t";
    }//end of if
    if(a3==4&&compare1){ //猜中時
        n1=0;
        compare3=true;
        //cout<<"this is a3 (final):"<<a3<<endl;
    }//end of if for 猜中時
    
    }//end of for of q
    n=n1;
    cout<<endl;
    //cout<<"this is final n: "<<n<<endl;


}//end of do 
while(a!=4 && n!=0); //人以及電腦接還沒猜中時以及電腦還沒發現被騙時繼續

if(a1!=4&&n==0){ //the case that people lie and computer cannot find the right answer.
    compare2=true;
}

if(a==4&&!compare2&&compare3){ //同時猜中
    cout<<"People and computer won. People's answer is ";
    for(i=0;i<4;i++){
        cout<<peGuess[i];
    }//end of for in order to print the answer guessed by people

    cout<<"\ncomputer got right answer!!!"<<"the answer is"<<endl;
    for(i=0;i<4;i++){
        cout<<selectNum[i];
    }

}
if(a==4&&!compare2&&!compare3){ //a==4代表人先猜中 compare2==0代表人沒騙 compare3==0代表電腦還沒猜中
    cout<<"people got right.\nThe answer is ";
    for(i=0;i<4;i++){
        cout<<peGuess[i];
    }//end of for in order to print the answer guessed by people
    do{
        cout<<"\n------PC's turn------"<<endl;
        pcTime++;
        initialGuSite=rand()%n; //從n中隨機挑一個數字
        //cout<<initialGuSite<<endl;
        cout<<"computer's guess is : ";
        
        for(i=0;i<4;i++){
            selectNum[i]=data[initialGuSite][i];
            cout<<data[initialGuSite][i];
        }
        cout<<endl; //to print the answer of computer


        cout<<"People's answer is (a1)A (b1)B : ";
        cin>>a1>>b1;

        n1=0;
        for(q=0;q<n;q++){ //q is the variable to control the first, second, third...data
            a3=0;
            b3=0; //新的數比較要歸零
            compare1=false;
        
            for(i=0;i<4;i++){ //in order to control the number of computer's guess
                for(j=0;j<4;j++){ //in order to control the number of the data
                    if(i==j && selectNum[i]== data[q][j]){ //位置跟數字都對
                        a3++;
                    }//end of if presenting the case that it corresponds the condition of A
                    if(i!=j && selectNum[i]== data[q][j]){ //位置不對數字對
                        b3++;
                    }//end of if presenting the case that it corresponds the condition of B
                }
            }//end of for to check the AB
        
        if(a3==a1&&b3==b1)compare1=true;
        if(compare1&& a3!=4){ //represents the case that the selected data same AB with the data base.
            for(j=0;j<4;j++){ 
                data[n1][j]=data[q][j]; //n1 is from 0
                //cout<<data[n1][j];
            }//end of for in order to put the 當前資料放到此矩陣的第一個位置順便計算這樣的例子會有幾個
            n1++;
            //cout<<"\t";
        }//end of if
        if(a3==4&&compare1){ //猜中時
            n1=0;
            compare3=true;
            //cout<<"this is a3 (final):"<<a3<<endl;
        }//end of if for 猜中時
        
        }//end of for of q
        n=n1;
        cout<<endl;
        //cout<<"this is final n: "<<n<<endl;
    }while(n!=0); //猜對時，被騙時（n==0）跳出迴圈
    
    if(a1!=4&&n==0){ //the case that people lie and computer cannot find the right answer.
        compare2=true;
    }
    if(!compare2)cout<<"computer got right!";
        cout<<"the answer is:";
        for(i=0;i<4;i++){
            cout<<selectNum[i];
    }
        cout<<endl;
}//end of if for the case that people first win


if(a!=4&&!compare2&&compare3){//a!=4代表人還沒猜中 compare2代表人不騙 compare3==true代表電腦先猜中
    cout<<"\ncomputer got right answer!!!"<<"the answer is"<<endl;
    for(i=0;i<4;i++){
        cout<<selectNum[i];
    }


    do
    {
        cout<<"\n------PEOPLE's turn------"<<endl;
        info=true;
        while(info&&peTime>=1){ //有可能會重複的時候發生在一次之後
            a6=0;
            cout<<"Please guess the computer answer: ";
            cin>>peGuess[0]>>peGuess[1]>>peGuess[2]>>peGuess[3];

            for(i=fact;i>=0;i--){
                a6=0; //每換一個要歸零
                for(k=0;k<4;k++){
                    
                    if(already[i][k]==peGuess[k]){
                        a6++; //位置跟數字都一樣
                    }
                    
                }//end of for controlling already
                if(a6==4){ //the case that 數字完全一樣
                    info=true;
                    break; //break for of i
                }
                if(a6!=4){
                    info=false;
                }
            }//check every already ob die schon drin sind.
        }//end of while in order to ask people wieder neue Nummer anzugeben
        
        //cout<<"this is the "<<peTime<<" th info and a6 "<<a6<<endl;
        //cout<<"this is fact "<<fact;
        for(i=0;i<4;i++){
            already[fact][i]=peGuess[i];
            //cout<<already[fact][i];
        }//放到資料庫裡
        fact++;
        cout<<endl;

        peTime++;
        a=0;b=0;
        for(i=0;i<4;i++){ //in order to control the array of the computer answer
            for(j=0;j<4;j++){ //in order to control the array of the people's guess
                if(i==j && pcAnswer[i]==peGuess[j]){ //位置跟數字都對
                    a++;
                }//end of if presenting the case that it corresponds the condition of A
                if(i!=j && pcAnswer[i]==peGuess[j]){ //位置不對數字對
                    b++;
                }//end of if presenting the case that it corresponds the condition of B
            }//end of for (j)
        }//end of for(i)
        cout<<a<<"A"<<b<<"B"<<endl;
    } while (a!=4); //a==4代表人猜中即跳出迴圈 

    cout<<"People got right!\nthe answer is: ";
    for(i=0;i<4;i++){
        cout<<peGuess[i];
    }//end of for in order to print the answer guessed by people
    cout<<endl;

}//end of if for the case that computer won

if(compare2){ //compare2代表人騙了電腦
    cout<<"People lie!!!\n------End------"<<endl;

    cout<<"the first three guessed time of the game: "<<endl;
    for(i=0;i<3;i++){
        cout<<"the "<<i+1<<"th place is "<<rank[i]<<" time."<<endl;
    }//end of for

}else if (!compare2) //人不欺騙才可以排序以及給出評語
{
    cout<<"\n";
    if(peTime<=10)cout<<"玩家太厲害了啦"<<endl;
    if(peTime>10&&peTime<=30)cout<<"玩家不錯喔"<<endl;
    if(peTime>30)cout<<"玩家要再加油喔>.<"<<endl;

    if(pcTime<=2)cout<<"哇電腦太會了啦"<<endl;
    if(pcTime>2&&pcTime<=5)cout<<"電腦不錯喔"<<endl;
    if(pcTime>5)cout<<"電腦運氣再加油"<<endl;

    if(peTime>pcTime)cout<<"Pc won and guessed "<<pcTime<<" times.";
    if(pcTime>peTime)cout<<"People won and guessed "<<peTime<<" times.";
    if(pcTime==peTime)cout<<"Both won and guessed "<<peTime<<" times.";

    
    rank[sort]=peTime; //sort is the repeating time of the player
    st=sort;

    while(st>0&&rank[st]<rank[st-1]){
        contem=rank[st];
        rank[st]=rank[st-1];
        rank[st-1]=contem;
        st--;
    }//end of while controlling the ranking
    

    sort++;
    cout<<"\nThe first three guessed time of the game: "<<endl;
    for(i=0;i<3;i++){
        cout<<"the "<<i+1<<"th place is "<<rank[i]<<" time."<<endl;
    }//end of for

}//end of else if people didnt lie

cout<<"要再玩一次嗎？（0=不要 1＝要）"<<endl;
cin>>ask;
}//end of while if want to play again

//ranking the time of people



cout<<"The game is finally end...\nThanks for your lovely participation"<<endl;
cout<<endl;
return 0;
}