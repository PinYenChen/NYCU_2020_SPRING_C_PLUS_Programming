#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(int argc, char** argv) {

int m,n,p;
int **plate;
int **show;
int i,j,x,y;
bool winning=false; //winning=true---�HĹ�F
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
    }//��a�p(�E)

for(y=1;y<=m;y++){
    for(x=1;x<=n;x++){
        int selectx,selecty,t;
        selectx=rand()%n+1; //0-n-1-----1-n
        selecty=rand()%m+1; //0-m-1-----1-m

        t=plate[selecty][selectx];
        plate[selecty][selectx]=plate[y][x];
        plate[y][x]=t;
    }
}//�洫�쥻���a�p��m
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

int x1,y1; //�H�򪺦�m
int numberBomb=0; //���񪺬��u��
bool land=true; //true successfully hidden false didn't
int data[1000][2]; //����^�X�n�s�i�h�ΨӦb�U�^�X�ˬd����ƭ�
int fact=0,fact1=0,u; //fact�N��data���]�쪺��m fact1������s�J���ƥ� 
int already[1000][2],k=0; //already���w�g�ˬd�L���ƾ� //k���w�g�s�i�halready���ƥ�
bool same=false; //same=true-----��e���s�J��Ƥw�g�b��Ʈw�F�A�N���Φs�J
int mal=0; //mal�N��w�Q½�}����l

int flag=true; //�p�G���лx�ɪ����p

do{
    flag=true;
    cout<<"Please input the site of people(0<y1<"<<m+1<<",0<x1<"<<n+1<<"): ";
    cin>>y1>>x1;
    //cout<<y1<<x1<<endl;

    if(y1<0&&x1<0){
        y1=y1*(-1);
        x1=x1*(-1);
        //cout<<y1<<x1<<endl;
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

    if(plate[y1][x1]!=9&&flag){ //�������O�a�p�H�η�Хܮɤ���i�J�j��

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
                for(x=x1-1;x<=x1+1;x++){ //���sx�A�sy
                    if(x>0&&y>0&&x<=n&&y<=m){ //���䤣�i�H�s�i�h
                        if(x==x1&&y==y1||show[y][x]!=-1)continue; //��쪺���椣�Φs
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
                    //��s�_�Ӫ���l���X�Ө��ˬdlandmine number

                    if(numberBomb!=0){ 
                        show[y1][x1]=numberBomb;
                    }
                    if(numberBomb==0){ 
                        show[y1][x1]=0;
                        
                        // cout<<"show("<<y1<<")("<<x1<<"\t";

                        for(y=y1-1;y<=y1+1;y++){
                            for(x=x1-1;x<=x1+1;x++){ //���sx�A�sy
                                if(x>0&&y>0&&x<=n&&y<=m){ //���䤣�i�H�s�i�h
                                    if(x==x1&&y==y1)continue; //��쪺���椣�Φs

                                    same=false;
                                    for(int g=0;g<k;g++){  //�w�g�s�L����Ƥ��ΦA�s
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

                }//end of for controlling �s���C�@�����

                fact=fact1;
                fact1=0;
                
            } while (fact!=0); //��n�A�ˬd����ƨS���ɡA�N���έ���
            
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
    if(mal==m*n-p1)winning=true; //�w�g�C�Jalready���ӼƬ������ťh�a�p��

} while (land&&!winning); //���Ƭ��٨S���a�p���٨SĹ

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


