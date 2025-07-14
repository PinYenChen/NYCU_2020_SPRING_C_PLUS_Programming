#include <iostream>

using namespace std;

int main(int argc, char** argv) {

bool msign=false;
bool nsign=false;

int m,n,N[20]={0},X[20][25]={0},t2,x=0,t1,y=0,digit=0,A,d[25]={0},b,digitOfN=0; 

/*
安砞Nぃ禬筁计
N盢ㄤい计だ瞒计┮ㄏノ痻皚
X繦N计硅τ∕﹚痻皚
*/

cout<<"Please input two integer m and n: "<<endl;
cin>>m>>n;

//耞m n 琌タ临琌璽 
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
    }//end of first while in order to 耞计

while((n/10)>0 || (n%10)!=0){
        t2=n%10; //秈琌计
        N[x++]=t2;
        n=n/10;
    }//end of while in order to だ瞒计(n)

//for(int j=digitOfN-1;j>=0;j--){ //ㄓ琌蔼计
//    cout<<N[j]<<endl;
//}

for(int i=0;i<=digitOfN-1;i++){
    A=N[i]*m;
    int z=i;
    while(A){
        t1=A%10; //秈琌计
        X[i][z]=t1;
        A=A/10;
        digit=z+1;
        z++;
    }//end of while in order to calculate the 计of answer and 痻皚い
}//end of for

for(int u=0;u<=digit;u++){  
    for(int j=0;j<=digit;j++){
        d[u]+=X[j][u];
        if(d[u]>=10){
            X[0][u+1]+=d[u]/10;
            d[u]=d[u]%10;
        }// end of if in order to deal with 秈
    }//end of inner for
}//end of outer for

cout<<"the answer is ";
if(msign&&!nsign||nsign&&!msign){
    cout<<"-";
}

for(int w=digit-1;w>=0;w--){ //ㄓ琌蔼计ゑ耕边痻皚
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
        俱for琌ノㄓ耞家狾のㄓ方琌狦ㄤじぃ碞穦眖ず伴for 
        铬铬for癹伴 ㄏㄆン计2r
        */
       if(r==0){
           break;
           /*
           r==0柑じぃ惠盢ゑ耕传の︽
           (狦Τじぃ才r穦跑Θ2
           铬北︽癹伴北z
           */
        }//end of if
    }//end of for loop controlling z
    if(r==0){
        cout<<u<<","<<z<<endl;
        break;//r==0柑じぃ惠盢ゑ耕传の︽铬北︽癹伴北u
    }//end of if
}//end of for loop controlling u

return 0;
}




