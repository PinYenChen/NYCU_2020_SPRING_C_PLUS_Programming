#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(int argc, char** argv) {

int i,j;
int peGuess[4],pcAnswer[4]; //peGuess�H���q�� pcAnswer�q��������

int a=0,b=0; //�q�����H��hint
int already[50][4]; //�H�ҮѹL�������Ƽƭ�
bool info=true;//�H�q�L�@�˪��P�_ TRUE:�q�L�@�˪��Ʀr 
int a6=0,fact=0; //fact��J�����ƼƩ�Jalready������

int data[4600][4]; //�Ҧ��i��
int n=0; //data���˥���
int z,k;

int pcTime=0,peTime=0;

int a3=0,b3=0; //a3 and b3 are the number that �P�_data �����Ʀr�O�_��q���Ʀr(data[initialGuSite][i)�P�ϦP��
int q;
int n1=0; //�ŦX�ƭȮɩҩ�J����
bool compare1=false;//if(a3==a1&&b3==b1) compare1=true;�P�q���Ҳq���ƦPAB�����p
bool compare2=false;//if(a1!=4&&n==0) compare2=true;false���H�S�F true���H�F�F
bool compare3=false;//true�q���� false�S�q��
int initialGuSite; //�q���H�������˥���l
int a1,b1;//hint to the computer in order to �P�_�q���q��
int selectNum[4]; //�ȳQ�ŦX��ƻ\�L���q���q��

int rank[20]={0};//this is the ranking
int sort=0,st; //���a�`�@��������
int ask=1;//whether the player wants to play again (ask==1 repeat ask==0 reject)
int contem; //�ƦW�Ȧs���a��
srand(time(NULL));


while(ask==1){
    peTime=0;pcTime=0;
    compare3=false;

for(i=0;i<fact;i++){
    for(j=0;j<4;j++){
        already[i][j]=0;
    }
}//����Ҧ�already info�k�s

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
                break; //���ۤv�N�����~��U�h�A�]�����U�Ӥ]���|����
            }else if(pcAnswer[i]==pcAnswer[j]){
                compare=false;
            }//end of else if
        }//end of for inside
    }//end of do
    while(!compare); //repeat the loop when compare is falsch
    cout<<pcAnswer[i]<<" "<<"\t";
}   //in order to ���͹q��������
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
    while(info&&peTime>=1){ //���i��|���ƪ��ɭԵo�ͦb�@������
        a6=0;
        cout<<"Please guess the computer answer: ";
        cin>>peGuess[0]>>peGuess[1]>>peGuess[2]>>peGuess[3];

        for(i=fact;i>=0;i--){
            a6=0; //�C���@�ӭn�k�s
            for(k=0;k<4;k++){
                
                if(already[i][k]==peGuess[k]){
                    a6++; //��m��Ʀr���@��
                }
                
            }//end of for controlling already
            if(a6==4){ //the case that �Ʀr�����@��
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
    }//����Ʈw��
    fact++;
    
    
    a=0;b=0;
    for(i=0;i<4;i++){ //in order to control the array of the computer answer
        for(j=0;j<4;j++){ //in order to control the array of the people's guess
            if(i==j && pcAnswer[i]==peGuess[j]){ //��m��Ʀr����
                a++;
            }//end of if presenting the case that it corresponds the condition of A
            if(i!=j && pcAnswer[i]==peGuess[j]){ //��m����Ʀr��
                b++;
            }//end of if presenting the case that it corresponds the condition of B
        }//end of for (j)
    }//end of for(i)
    cout<<a<<"A"<<b<<"B"<<endl;

    cout<<"------PC's turn------"<<endl;
    pcTime++;
    initialGuSite=rand()%n; //�qn���H���D�@�ӼƦr
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
        b3=0; //�s���Ƥ���n�k�s
        compare1=false;
    
        for(i=0;i<4;i++){ //in order to control the number of computer's guess
            for(j=0;j<4;j++){ //in order to control the number of the data
                if(i==j && selectNum[i]== data[q][j]){ //��m��Ʀr����
                    a3++;
                }//end of if presenting the case that it corresponds the condition of A
                if(i!=j && selectNum[i]== data[q][j]){ //��m����Ʀr��
                    b3++;
                }//end of if presenting the case that it corresponds the condition of B
            }
        }//end of for to check the AB
    
    if(a3==a1&&b3==b1)compare1=true;
    if(compare1&& a3!=4){ //represents the case that the selected data same AB with the data base.
        for(j=0;j<4;j++){ 
            data[n1][j]=data[q][j]; //n1 is from 0
            //cout<<data[n1][j];
        }//end of for in order to put the ��e��Ʃ�즹�x�}���Ĥ@�Ӧ�m���K�p��o�˪��Ҥl�|���X��
        n1++;
        //cout<<"\t";
    }//end of if
    if(a3==4&&compare1){ //�q����
        n1=0;
        compare3=true;
        //cout<<"this is a3 (final):"<<a3<<endl;
    }//end of if for �q����
    
    }//end of for of q
    n=n1;
    cout<<endl;
    //cout<<"this is final n: "<<n<<endl;

}//end of do 
while(a!=4 && n!=0); //�H�H�ιq�����٨S�q���ɥH�ιq���٨S�o�{�Q�F���~��

if(a1!=4&&n==0){ //the case that people lie and computer cannot find the right answer.
    compare2=true;
}

if(a==4&&!compare2&&compare3){ //�P�ɲq��
    cout<<"People and computer won. People's answer is ";
    for(i=0;i<4;i++){
        cout<<peGuess[i];
    }//end of for in order to print the answer guessed by people

    cout<<"\ncomputer got right answer!!!"<<"the answer is"<<endl;
    for(i=0;i<4;i++){
        cout<<selectNum[i];
    }

}
if(a==4&&!compare2&&!compare3){ //a==4�N��H���q�� compare2==0�N��H�S�F compare3==0�N��q���٨S�q��
    cout<<"people got right.\nThe answer is ";
    for(i=0;i<4;i++){
        cout<<peGuess[i];
    }//end of for in order to print the answer guessed by people
    do{
        cout<<"\n------PC's turn------"<<endl;
        pcTime++;
        initialGuSite=rand()%n; //�qn���H���D�@�ӼƦr
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
            b3=0; //�s���Ƥ���n�k�s
            compare1=false;
        
            for(i=0;i<4;i++){ //in order to control the number of computer's guess
                for(j=0;j<4;j++){ //in order to control the number of the data
                    if(i==j && selectNum[i]== data[q][j]){ //��m��Ʀr����
                        a3++;
                    }//end of if presenting the case that it corresponds the condition of A
                    if(i!=j && selectNum[i]== data[q][j]){ //��m����Ʀr��
                        b3++;
                    }//end of if presenting the case that it corresponds the condition of B
                }
            }//end of for to check the AB
        
        if(a3==a1&&b3==b1)compare1=true;
        if(compare1&& a3!=4){ //represents the case that the selected data same AB with the data base.
            for(j=0;j<4;j++){ 
                data[n1][j]=data[q][j]; //n1 is from 0
                //cout<<data[n1][j];
            }//end of for in order to put the ��e��Ʃ�즹�x�}���Ĥ@�Ӧ�m���K�p��o�˪��Ҥl�|���X��
            n1++;
            //cout<<"\t";
        }//end of if
        if(a3==4&&compare1){ //�q����
            n1=0;
            compare3=true;
            //cout<<"this is a3 (final):"<<a3<<endl;
        }//end of if for �q����
        
        }//end of for of q
        n=n1;
        cout<<endl;
        //cout<<"this is final n: "<<n<<endl;
    }while(n!=0); //�q��ɡA�Q�F�ɡ]n==0�^���X�j��
    
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

if(a!=4&&!compare2&&compare3){//a!=4�N��H�٨S�q�� compare2�N��H���F compare3==true�N��q�����q��
    cout<<"\ncomputer got right answer!!!"<<"the answer is"<<endl;
    for(i=0;i<4;i++){
        cout<<selectNum[i];
    }

    do
    {
        cout<<"\n------PEOPLE's turn------"<<endl;
        info=true;
        while(info&&peTime>=1){ //���i��|���ƪ��ɭԵo�ͦb�@������
            a6=0;
            cout<<"Please guess the computer answer: ";
            cin>>peGuess[0]>>peGuess[1]>>peGuess[2]>>peGuess[3];

            for(i=fact;i>=0;i--){
                a6=0; //�C���@�ӭn�k�s
                for(k=0;k<4;k++){
                    
                    if(already[i][k]==peGuess[k]){
                        a6++; //��m��Ʀr���@��
                    }
                    
                }//end of for controlling already
                if(a6==4){ //the case that �Ʀr�����@��
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
        }//����Ʈw��
        fact++;
        cout<<endl;

        peTime++;
        a=0;b=0;
        for(i=0;i<4;i++){ //in order to control the array of the computer answer
            for(j=0;j<4;j++){ //in order to control the array of the people's guess
                if(i==j && pcAnswer[i]==peGuess[j]){ //��m��Ʀr����
                    a++;
                }//end of if presenting the case that it corresponds the condition of A
                if(i!=j && pcAnswer[i]==peGuess[j]){ //��m����Ʀr��
                    b++;
                }//end of if presenting the case that it corresponds the condition of B
            }//end of for (j)
        }//end of for(i)
        cout<<a<<"A"<<b<<"B"<<endl;
    } while (a!=4); //a==4�N��H�q���Y���X�j�� 

    cout<<"People got right!\nthe answer is: ";
    for(i=0;i<4;i++){
        cout<<peGuess[i];
    }//end of for in order to print the answer guessed by people
    cout<<endl;

}//end of if for the case that computer won

if(compare2){ //compare2�N��H�F�F�q��
    cout<<"People lie!!!\n------End------"<<endl;

    cout<<"the first three guessed time of the game: "<<endl;
    for(i=0;i<3;i++){
        cout<<"the "<<i+1<<"th place is "<<rank[i]<<" time."<<endl;
    }//end of for

}else if (!compare2) //�H�����F�~�i�H�ƧǥH�ε��X���y
{
    cout<<"\n";
    if(peTime<=10)cout<<"���a�ӼF�`�F��"<<endl;
    if(peTime>10&&peTime<=30)cout<<"���a������"<<endl;
    if(peTime>30)cout<<"���a�n�A�[�o��>.<"<<endl;

    if(pcTime<=2)cout<<"�z�q���ӷ|�F��"<<endl;
    if(pcTime>2&&pcTime<=5)cout<<"�q��������"<<endl;
    if(pcTime>5)cout<<"�q���B��A�[�o"<<endl;

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

cout<<"�n�A���@���ܡH�]0=���n 1�׭n�^"<<endl;
cin>>ask;
}//end of while if want to play again

//ranking the time of people


cout<<"The game is finally end...\nThanks for your lovely participation"<<endl;
cout<<endl;
return 0;
}


