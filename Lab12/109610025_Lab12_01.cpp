#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void bubblesorting(float rank[] ,int n){ 
    float t;
    int i,j;
    for(i=n-2;i>=0;i--){
        for(j=i;j<n-1;j++){
            if(rank[j]<rank[j+1]&&rank[j]>=0&&rank[j+1]>=0){
                t=rank[j+1];
                rank[j+1]=rank[j];
                rank[j]=t;
            }
        }
    }
}


int main(){
    srand(time(NULL));
    char **plate,i,j,k=0;
    char **show;
    int n;
    int input;
    char *alpha;
    bool produce=false;
    float u=0;
    float rank[10]={0};
    int s=0;
    int store;
    char filename[50];
    int open[100][2],p=0,p1=-1;
    bool flag1=false; //using to check select1
    bool flag2=false;
    
    int x1,y1; //first guess
    int x2,y2; //second guess
    int y3,x3; //before info

    fstream file;
        //first load the rank
    file.open("rank.txt",ios::in);
    if(!file){
        cout<<"There is no ranking record."<<endl;
    }
    file>>s;
    for(i=0;i<10;i++){
        file>>rank[i];
    }
    file.close();//read the rank

    do{
        cout<<"Please input the function you want: ";
        cin>>input;
        produce=false;


        if(input==1){

            cout<<"Please the n (even number): ";
            cin>>n;
            cout<<endl;
            plate=new char*[n+1];
            for(i=0;i<n+1;i++){
                plate[i]=new char [n+1];
            }
            //handling the alphabet to ensure there is no repeat alpha.

            int select;
            int select1; //1 for capital letter
            int select2;
            int data1[26];
            int data2[26];
            p=0;
            for(i=0;i<100;i++){
                for(j=0;j<2;j++){
                    open[i][j]=-1;
                }
            }//initialization of open[100][2]
            bool repeat=false;
            

            alpha=new char[n];
            select=(n*n)/2; //muss select
            do{
                select1=(rand()%26)+1; //0-25 -----1-26 at most 26 alphabets (unit ge)
                select2=select-select1;

                if(select1>0&&select1<26) flag1=true;
                if(select2>0&&select2<26) flag2=true;

            }while(!flag1||!flag2); //A and a do not surpass 26.
            
            //  cout<<"this is select 1 "<<select1<<endl;
            //  cout<<"this is select 2 "<<select2<<endl;

            for(i=0;i<select1;i++){

                if(i==0){
                    alpha[i]=char('A'+rand()%26); //0-26
                    data1[i]=alpha[i];
                }
                else if (i!=0){
                    do{
                        repeat=false;
                        alpha[i]=char('A'+rand()%26); //0-26
                        for(j=i-1;j>=0;j--){
                            if(alpha[i]==data1[j]){
                                repeat=true;
                                break;
                            }
                        }
                    } while (repeat);
                    data1[i]=alpha[i];
                }
                //cout<<alpha[i]<<"\t";
            }
            
            for(i=select1;i<select;i++){
                if(i==select1){
                    alpha[i]=char('a'+rand()%26); //0-26
                    data2[i]=alpha[i];
                }
                else if (i!=select1){
                    do{
                        repeat=false;
                        alpha[i]=char('a'+rand()%26); //0-26
                        for(j=i-1;j>=select1;j--){
                            if(alpha[i]==data2[j]){
                                repeat=true;
                                break;
                            }
                        }
                    } while (repeat);
                    data2[i]=alpha[i];
                }//end of if !=select1
                    
                //cout<<alpha[i]<<"\t";
            }
            // cout<<"this is the result!"<<endl;
            // for(i=0;i<select;i++){
            //     cout<<alpha[i]<<"\t";
            // }
            // cout<<endl;
            
            for(i=0;i<select;i++){
                alpha[i+select]=alpha[i];
            }

            // for(i=0;i<n*n;i++){
            //     cout<<alpha[i]<<"\t";
            // }
            //cout<<endl;
            k=0;
            cout<<"Original"<<endl;
            for(i=1;i<=n;i++){
                for(j=1;j<=n;j++){
                    plate[i][j]=alpha[k];
                    k++;
                    //cout<<plate[i][j]<<"\t";
                }
                //cout<<endl;
            }//填入字母
            
            for(k=0;k<100;k++){
                for(i=1;i<=n;i++){
                    for(j=1;j<=n;j++){
                        int t,x,y;
                        x=rand()%n+1; //0-n-1---1-n
                        y=rand()%n+1;
                        t=plate[i][j];
                        plate[i][j]=plate[y][x];
                        plate[y][x]=t; 
                    }
                }//打亂板子
            }
            for(i=1;i<=n;i++){
                for(j=1;j<=n;j++){
                    cout<<plate[i][j]<<"\t";
                }
                cout<<endl;
            }
            produce=true;
            u=0;
            delete[] alpha;
            
        }//end of if input ==1

        char readfile[50];
        if(input==2){
            cout<<"Please enter the filename: ";
            cin>>readfile;
            file.open(readfile,ios::in);
            if(!file){
                cout<<"Sorry. We couldn't open the file."<<endl;
                return 0;
            }
            
            file>>n; //read the n and the time alreagy guessed
            file>>u;
            
            plate = new char*[n+1];
            for(j=0;j<n+1;j++){
                plate[j]=new char[n+1];
            }
            //read the original plate
            for(i=1;i<=n;i++){
                for(j=1;j<=n;j++){
                    file>>plate[i][j];
                }
            }
            int w=0;
            //read the aktuelle situation
            while(file>>open[w][0]>>open[w][1]){
                w++;
            }
            file.close();

            produce=true;
        }
        //if(produce) start the game.
        bool win=false;
        bool inter=false;

        if(produce){
            bool repeat1=false;
            cout<<"------------Start------------"<<endl;
            
            do{
                cout<<"\t";
                for(int q=1;q<=n;q++){
                    cout<<q<<"\t";
                }
                cout<<endl;
                for(i=0;i<=10*n;i++){
                    cout<<"-";
                }
                cout<<endl;

                for(i=1;i<=n;i++){
                    cout<<i<<"|"<<"\t";
                    for(j=1;j<=n;j++){
                        flag1=false;
                        for(k=p1;k>=0;k--){
                            y3=open[k][0];
                            x3=open[k][1];
                            if(i==y3&&j==x3){
                                flag1=true;
                                break;
                            }//end of if
                        }//end of k
                        if(flag1){
                            cout<<plate[i][j]<<"\t";
                        }else{
                            cout<<" "<<"\t";
                        }    
                    }//end of j
                    cout<<endl;
                }//end of i
                do{
                    cout<<"Please input (y1,x1): ";
                    cin>>y1>>x1;
                    repeat1=false;
                    if(y1<0&&x1<0)inter=true;
                    if(y1>n||x1>n||y1==0||x1==0)repeat1=true;
                    for(int f=0;f<p;f++){
                        if(open[f][0]==y1&&open[f][1]==x1){
                            repeat1=true;
                        }
                    }
                }while(repeat1);//in order to avoid open twice


                cout<<endl;
                if(!inter){
                    u++;
                    //cout<<"this is u "<<u<<endl;

                    cout<<"\t";
                    for(int q=1;q<=n;q++){
                        cout<<q<<"\t";
                    }
                    cout<<endl;
                    for(i=1;i<=10*n;i++){
                        cout<<"-";
                    }
                    cout<<endl;

                    for(i=1;i<=n;i++){
                        cout<<i<<"|"<<"\t";
                        for(j=1;j<=n;j++){
                            
                            flag1=false;
                            flag2=false;
                            for(k=p1;k>=0;k--){

                                y3=open[k][0];
                                x3=open[k][1];
                                if(i==y3&&j==x3){
                                    flag1=true;
                                    break;
                                }
                            }//end of k
                            if(flag1){
                                cout<<plate[i][j]<<"\t";
                            }                 
                            if(y1==i&&x1==j&&!flag1){
                                cout<<plate[i][j]<<"\t";
                                flag2=true;
                            }else if(!flag2&&!flag1){ //left case
                                cout<<" "<<"\t";
                            }
                        }//end of j
                        cout<<endl;
                    }//end of i
                    do{
                    cout<<"Please input (y1,x1) again : ";
                    cin>>y2>>x2;
                    repeat1=false;
                    if(y2<0&&x2<0)inter=true;
                    if(y2==y1&&x2==x1)repeat1=true;
                    if(y2>n||x2>n||y2==0||x2==0)repeat1=true;
                    for(int f=0;f<p;f++){
                        if(open[f][0]==y2&&open[f][1]==x2){
                            repeat1=true;
                        }
                    }
                    }while(repeat1);

                    cout<<endl;
                    if(!inter){
                        u++;
                        //cout<<"this is u "<<u<<endl;
                        cout<<"\t";
                        for(int q=1;q<=n;q++){
                            cout<<q<<"\t";
                        }
                        cout<<endl;
                        for(i=1;i<=10*n;i++){
                            cout<<"-";
                        }
                        cout<<endl;
                        for(i=1;i<=n;i++){
                            cout<<i<<"|"<<"\t";
                            for(j=1;j<=n;j++){
                                
                                flag1=false;
                                flag2=false;
                                for(k=p1;k>=0;k--){
                                    y3=open[k][0];
                                    x3=open[k][1];
                                    if(i==y3&&j==x3){
                                        flag1=true;
                                        break;
                                    }
                                }//end of k 
                                if(flag1){
                                    cout<<plate[i][j]<<"\t";
                                }              
                                if(y2==i&&x2==j||i==y1&&j==x1&&!flag1){
                                    cout<<plate[i][j]<<"\t";
                                    flag2=true;
                                
                                }else if(!flag2&&!flag1){
                                    cout<<" "<<"\t";
                                }
                            }
                            cout<<endl;
                        }
                        if(plate[y2][x2]==plate[y1][x1]){
                            open[p][0]=y2;
                            open[p++][1]=x2;
                            
                            open[p][0]=y1;
                            open[p++][1]=x1;
                            
                        }
                        p1=p;
                        //cout<<p1<<"this is p1"<<endl;
                    }//if!inter
                }

                if(p1==n*n){
                    win=true;
                    for(j=0;j<n+1;j++) delete[] plate[j];
                    delete[] plate; //到時候載入資料進來要丟外面
                }
            }while(!win&&!inter); //before win or interruption repeat the loop
                    


        }//end of if produce


        if(win){
            cout<<"Congraltulation!You won the game!!! "<<endl<<"Scores: "<<(n*n)/u<<endl;
            cout<<u<<" this is the total times"<<endl;
            rank[s]=(n*n)/u;
            s++;
            bubblesorting(rank,s);
        }
        if(inter){
            cout<<"Do you want to store the game? (0---no,1---yes): ";
            cin>>store;
            cout<<endl;
            if(store){
                cout<<"Please input the name of file: ";
                cin>>filename;
                ofstream out (filename);

                out<<n<<endl; //in order to make a plate when read
                out<<u<<endl; //in order to record the u

                for(i=1;i<=n;i++){
                    for(j=1;j<=n;j++){
                        out<<plate[i][j]<<"\t";
                    }
                    out<<endl;
                }//original plate 

                out<<endl;

                if(y1<=0&&x1<=0||y2<=0&&x2<=0){
                    for(i=0;i<p;i++){
                        for(j=0;j<2;j++){
                            out<<open[i][j]<<"\t";
                        }
                        out<<endl;
                    }//store open
                out.close();
                }//end of if of the case y1<0&&x1<0 aktuelle situation
                for(j=0;j<n+1;j++) delete[] plate[j];
                delete[] plate; //到時候載入資料進來要丟外面
            }//end of if of the case if want store
        }


        if(input==3){
            for(i=0;i<10;i++){
                cout<<"The "<<i+1<<" place is : "<<rank[i];
                cout<<endl;
            }
        }
        cout<<endl;


    }while(input!=4);
    cout<<"Thanks for playing the game!"<<endl;

     ofstream out("rank.txt");
     out<<s<<endl; //length
     for(i=0;i<10;i++){
         out<<rank[i]<<"\t";
     }
    out.close();
    

    return 0;
}