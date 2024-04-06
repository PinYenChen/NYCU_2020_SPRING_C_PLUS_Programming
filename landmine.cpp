#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(int argc, char** argv) {

int m,n,p;
int **plate;
int **show;
int i,j,x,y;
bool winning=false; //winning=true---人贏了
int p1; //is another p

cout<<"Please input the m and n (mxn): ";
cin>>m>>n;
cout<<"Please input the number of landmines: ";
cin>>p;

p1=p;
plate=new int *[m+2];
for(i=0;i<m+2;i++){
    plate[i]=new int [n+2];
    for(j=0;j<n+2;j++){
        plate[i][j]=0;
    }
}//declaration of 2 dimension static array and initialization
show=new int *[m+2];
for(i=0;i<m+2;i++){
    show[i]=new int [n+2];
     for(j=0;j<n+2;j++){
         show[i][j]=-1;
     }
}

    for(y=1;y<=m;y++){
        for(x=1;x<=n;x++){
            plate[y][x]=9;
            p--;
            if(p==0)break;
        }
        if(p==0)break;
    }//放地雷(九)


for(y=1;y<=m;y++){
    for(x=1;x<=n;x++){
        int selectx,selecty,t;
        selectx=rand()%n+1; //0-n-1-----1-n
        selecty=rand()%m+1; //0-m-1-----1-m

        t=plate[selecty][selectx];
        plate[selecty][selectx]=plate[y][x];
        plate[y][x]=t;
    }
}//交換原本的地雷位置
cout<<"\t";
for(i=1;i<=n;i++){
    cout<<i<<"\t";
}
cout<<endl;
for(i=0;i<=n;i++){
    cout<<"--------";
}
cout<<endl;

for(y=1;y<=m;y++){
    cout<<y<<"|"<<"\t";
    for(x=1;x<=n;x++){
        cout<<plate[y][x]<<"\t";
    }
    cout<<endl;
}

cout<<endl<<"the game starts!!!\n\t";
for(i=1;i<=n;i++){
    cout<<i<<"\t";
}
cout<<endl;
for(i=0;i<=n;i++){
    cout<<"--------";
}
cout<<endl;

for(y=1;y<=m;y++){
    cout<<y<<"|"<<"\t";
    for(x=1;x<=n;x++){
        if(show[y][x]==-1)cout<<" \t";
        if(show[y][x]!=-1)cout<<show[y][x]<<"\t";
    }
    cout<<endl;
}


int x1,y1; //人踩的位置
int numberBomb=0; //附近的炸彈數
bool land=true; //true successfully hidden false didn't
int data[1000][2]; //為當回合要存進去用來在下回合檢查的資料們
int fact=0,fact1=0,u; //fact代表data中跑到的位置 fact1為當期存入的數目 
int already[1000][2],k=0; //already為已經檢查過的數據 //k為已經存進去already的數目
bool same=false; //same=true-----當前欲存入資料已經在資料庫了，代表不用存入
int mal=0; //mal代表已被翻開的格子

int flag=true; //如果有標誌時的狀況

do{
    flag=true;
    cout<<"Please input the site of people(0<y1<"<<m+1<<",0<x1<"<<n+1<<"): ";
    cin>>y1>>x1;
    while(show[y1][x1]!=-1&&y1>0&&x1>0){
        cout<<"Wrong"<<endl;
        cout<<"Please input the site of people(0<y1<"<<m+1<<",0<x1<"<<n+1<<"): ";
        cin>>y1>>x1;
    }
    if(y1<0&&x1<0){
        y1=y1*-1;
        x1=x1*-1;
        show[y1][x1]=-5;
        flag=false;
        cout<<"\t";
        for(i=1;i<=n;i++){
            cout<<i<<"\t";
        }
        cout<<endl;
        for(i=0;i<=n;i++){
            cout<<"--------";
        }
        cout<<endl;

        for(y=1;y<=m;y++){
            cout<<y<<"|"<<"\t";
            for(x=1;x<=n;x++){
                if(show[y][x]==-1)cout<<" \t";
                if(show[y][x]!=-1)cout<<show[y][x]<<"\t";
            }
            cout<<endl;
        }
    }

    numberBomb=0;

    if(plate[y1][x1]!=9&&flag){ //本身不是地雷以及當標示時不能進入迴圈

        for(y=y1-1;y<=y1+1;y++){
            for(x=x1-1;x<=x1+1;x++){
                if(plate[y][x]==9){
                    numberBomb++;
                }//end of if checking bomb
            }//end of for controlling x
        }//end of for controlling y
        //check the sorrounding landmines

        if(numberBomb!=0){
            show[y1][x1]=numberBomb;
            mal++;
            cout<<"\t";
            for(i=1;i<=n;i++){
                cout<<i<<"\t";
            }
            cout<<endl;
            for(i=0;i<=n;i++){
                cout<<"--------";
            }
            cout<<endl;

            for(y=1;y<=m;y++){
                cout<<y<<"|"<<"\t";
                for(x=1;x<=n;x++){
                    if(show[y][x]==-1)cout<<" \t";
                    if(show[y][x]!=-1)cout<<show[y][x]<<"\t";
                }
                cout<<endl;
            }
        }//end of if

        else if (numberBomb==0){
            show[y1][x1]=0;
            mal++;
            for(y=y1-1;y<=y1+1;y++){
                for(x=x1-1;x<=x1+1;x++){ //先存x再存y
                    if(x>0&&y>0&&x<=n&&y<=m){ //邊邊不可以存進去
                        if(x==x1&&y==y1||show[y][x]!=-1)continue; //踩到的那格不用存
                        data[fact][0]=x;
                        data[fact][1]=y;
                        already[k][0]=x;
                        already[k][1]=y;
                        k++;
                        fact++;
                        mal++;
                    }//end of if for the casex>0&&y>0

                }//end of if controlling x
            }//end of if controlling y
            //cout<<"this is fact "<<fact<<endl;
            //cout<<"this is k"<<k<<endl;
                //     for(i=0;i<k;i++){
                //     cout<<"already["<<i<<"]=";
                //         for(j=0;j<2;j++){
                //             cout<<already[i][j]<<",";
                //         }
                //     cout<<"\t";
                // }
                // cout<<endl;

            do{
                for(u=0;u<fact;u++){
                    numberBomb=0;
                    y1=data[u][1];
                    x1=data[u][0];
                    if(plate[y1][x1]==9)continue;
                    for(y=y1-1;y<=y1+1;y++){
                        for(x=x1-1;x<=x1+1;x++){
                            if(plate[y][x]==9){
                                numberBomb++;
                            }//end of if checking bomb
                        }//end of for controlling x
                    }//end of for controlling y
                    //把存起來的格子拿出來並檢查landmine number

                    if(numberBomb!=0){ 
                        show[y1][x1]=numberBomb;
                    }
                    if(numberBomb==0){ 
                        show[y1][x1]=0;
                        
                        // cout<<"show("<<y1<<")("<<x1<<"\t";

                        for(y=y1-1;y<=y1+1;y++){
                            for(x=x1-1;x<=x1+1;x++){ //先存x再存y
                                if(x>0&&y>0&&x<=n&&y<=m){ //邊邊不可以存進去
                                    if(x==x1&&y==y1)continue; //踩到的那格不用存

                                    same=false;
                                    for(int g=0;g<k;g++){  //已經存過的資料不用再存
                                        if(already[g][0]==x && already[g][1]==y){
                                            same=true;
                                            break;//break for of g
                                        }//end of if
                                    }//end of for controlling g
                                    if(same||show[y][x]!=-1)continue;

                                    data[fact][0]=x;
                                    data[fact++][1]=y;
                                    already[k][0]=x;
                                    already[k][1]=y;
                                    k++;                                    
                                    fact1++;
                                    mal++;
                                }//end of if for the case x>0&&y>0

                            }//end of if controlling x
                        }//end of if controlling y

                        //cout<<"this is fact 1 "<<fact1<<endl;
                    }//end of if presenting the case the numberBomb==0

                }//end of for controlling 存的每一筆資料

                fact=fact1;
                fact1=0;
                
            } while (fact!=0); //當要再檢查的資料沒有時，就不用重複
            
            cout<<"\t";
            for(i=1;i<=n;i++){
                cout<<i<<"\t";
            }
            cout<<endl;
            for(i=0;i<=n;i++){
                cout<<"--------";
            }
            cout<<endl;

            for(y=1;y<=m;y++){
                cout<<y<<"|"<<"\t";
                for(x=1;x<=n;x++){
                    if(show[y][x]==-1)cout<<" \t";
                    if(show[y][x]!=-1)cout<<show[y][x]<<"\t";
                }
                cout<<endl;
            }

            


        }//end of else if

    }//end of if for the case !=9
    else if (plate[y1][x1]==9&&flag){
        for(y=1;y<=m;y++){
            for(x=1;x<=n;x++){
                if(plate[y][x]==9){
                    show[y][x]=9; //show all landmines
                }
            }
        }
        land=false;
    }//end of if ==9

    //cout<<"this is mal "<<mal<<endl;
    // cout<<m*n-p1<<endl;
    if(mal==m*n-p1)winning=true; //已經列入already的個數為全部剪去地雷數

} while (land&&!winning); //重複為還沒踩到地雷及還沒贏

if(!land){
    cout<<"BOMBBBBBBBBBBBB!!!\nPlayer lost the game!!!"<<endl;


    cout<<"\t";
    for(i=1;i<=n;i++){
        cout<<i<<"\t";
    }
    cout<<endl;
    for(i=0;i<=n;i++){
        cout<<"--------";
    }
    cout<<endl;

    for(y=1;y<=m;y++){
        cout<<y<<"|"<<"\t";
        for(x=1;x<=n;x++){
            if(show[y][x]==-1)cout<<" \t";
            if(show[y][x]!=-1)cout<<show[y][x]<<"\t";
        }
        cout<<endl;
    }
}//end of if for the case that players lose the game

if(winning){
    cout<<"People win the game!!!Congratulations!!!"<<endl;
}



for(i=0;i<m+2;i++){
    delete[] plate[i];
} 
delete[] plate;

for(i=0;i<m+2;i++){
    delete[] show[i];
} 
delete[] show;

return 0;
}