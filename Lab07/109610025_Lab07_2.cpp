#include <iostream>

using namespace std;

int main(int argc, char** argv) {

bool msign=false;
bool nsign=false;

int m,n,N[20]={0},X[20][25]={0},t2,x=0,t1,y=0,digit=0,A,d[25]={0},b,digitOfN=0; 

/*
���]N���@���W�L�G�Q���
N���N�䤤�@�ӼƤ�����ƮɩҨϥΪ��x�}
X���HN����Ʀh��ӨM�w���x�}
*/

cout<<"Please input two integer m and n: "<<endl;
cin>>m>>n;

//�P�_m n �O���٬O�t 
    msign = m > 0 ? false : true;
    nsign = n > 0 ? false : true;

if(msign){
    m = -m;
}
if(nsign){
    n = -n;
}
b=n;

while(b>0){
        b=b/10;
        digitOfN=digitOfN+1;
    }//end of first while in order to �P�_���

while((n/10)>0 || (n%10)!=0){
        t2=n%10; //����i�h���O�Ӧ��
        N[x++]=t2;
        n=n/10;
    }//end of while in order to �������(n)

//for(int j=digitOfN-1;j>=0;j--){ //���L�X�Ӫ��O�����
//    cout<<N[j]<<endl;
//}

for(int i=0;i<=digitOfN-1;i++){
    A=N[i]*m;
    int z=i;
    while(A){
        t1=A%10; //����i�h���O�Ӧ��
        X[i][z]=t1;
        A=A/10;
        digit=z+1;
        z++;
    }//end of while in order to calculate the ���of answer and ��J�x�}��
}//end of for

for(int u=0;u<=digit;u++){  
    for(int j=0;j<=digit;j++){
        d[u]+=X[j][u];
        if(d[u]>=10){
            X[0][u+1]+=d[u]/10;
            d[u]=d[u]%10;
        }// end of if in order to deal with �i��
    }//end of inner for
}//end of outer for

cout<<"the answer is ";
if(msign&&!nsign||nsign&&!msign){
    cout<<"-";
}

for(int w=digit-1;w>=0;w--){ //���L�X�Ӫ��O����Ƥ���ߩ�J�x�}
    cout<<d[w];
}
cout<<endl;



int t[3][3],p[7][7];
int i=0,j=0,u=0,z=0,r=0;

//t[0][0]=1;t[0][1]=1;t[0][2]=1;t[1][0]=1;t[1][1]=0;t[1][2]=1;t[2][0]=1;t[2][1]=1;t[2][2]=0;

// p[0][0]=1;p[0][1]=1;p[0][2]=0;p[0][3]=0;p[0][4]=0;p[0][5]=0;p[0][6]=0;
// p[1][0]=0;p[1][1]=0;p[1][2]=0;p[1][3]=1;p[1][4]=1;p[1][5]=1;p[1][6]=0;
// p[2][0]=0;p[2][1]=0;p[2][2]=0;p[2][3]=1;p[2][4]=0;p[2][5]=1;p[2][6]=0;
// p[3][0]=1;p[3][1]=1;p[3][2]=0;p[3][3]=1;p[3][4]=1;p[3][5]=0;p[3][6]=0;
// p[4][0]=0;p[4][1]=0;p[4][2]=0;p[4][3]=0;p[4][4]=0;p[4][5]=0;p[4][6]=0;
// p[5][0]=0;p[5][1]=0;p[5][2]=0;p[5][3]=0;p[5][4]=0;p[5][5]=0;p[5][6]=0;
// p[6][0]=0;p[6][1]=0;p[6][2]=0;p[6][3]=0;p[6][4]=0;p[6][5]=0;p[6][6]=0;

//input the value of the 2-dimensions array
 cin>>t[0][0]>>t[0][1]>>t[0][2];cout<<endl;

 cin>>t[1][0]>>t[1][1]>>t[1][2];cout<<endl;

 cin>>t[2][0]>>t[2][1]>>t[2][2];cout<<endl;

 cin>>p[0][0]>>p[0][1]>>p[0][2]>>p[0][3]>>p[0][4]>>p[0][5]>>p[0][6];cout<<endl;

 cin>>p[1][0]>>p[1][1]>>p[1][2]>>p[1][3]>>p[1][4]>>p[1][5]>>p[1][6];cout<<endl;

 cin>>p[2][0]>>p[2][1]>>p[2][2]>>p[2][3]>>p[2][4]>>p[2][5]>>p[2][6];cout<<endl;

 cin>>p[3][0]>>p[3][1]>>p[3][2]>>p[3][3]>>p[3][4]>>p[3][5]>>p[3][6];cout<<endl;

 cin>>p[4][0]>>p[4][1]>>p[4][2]>>p[4][3]>>p[4][4]>>p[4][5]>>p[4][6];cout<<endl;

 cin>>p[5][0]>>p[5][1]>>p[5][2]>>p[5][3]>>p[5][4]>>p[5][5]>>p[5][6];cout<<endl;

 cin>>p[6][0]>>p[6][1]>>p[6][2]>>p[6][3]>>p[6][4]>>p[6][5]>>p[6][6];cout<<endl;

for(u=0;u<5;u++){
    for(z=0;z<5;z++){
        r=0;
        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(t[i][j]!=p[u+i][z+j]){
                    r=2;
                    break;
                }//end of if
            }//end of for controlling j
            if(t[i][j-1]!=p[u+i][z+j-1]){
                r=2;
                break;
            }//end of if
        }/*
        end of for controlling i
        ���for�O�ΨӧP�_�ҪO�H�Ψӷ��O�_�ۦP�A�p�G��@�������ۦP�N�|���q����for 
        ���X�A���X�~����for�j�� �åB�Ϧ��ƥ󪺥N��Ʀr��2�]r�^
        */
       if(r==0){
           break;
           /*
           r==0�N��̭��������ҧk�X���ݦA�N������C�Φ�
           (�]���p�G���������۲ŦXr�|�ܦ�2�^
           �����X����檺�j��]����z�^
           */
        }//end of if
    }//end of for loop controlling z
    if(r==0){
        cout<<u<<","<<z<<endl;
        break;//r==0�N��̭��������ҧk�X���ݦA�N������C�Φ�A�A���X����檺�j��]����u�^
    }//end of if
}//end of for loop controlling u

return 0;
}




