#include <iostream>
#include <cmath>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
    
    
    float a,b,c,L1,L2,L1real,L2real,L2complex,L1complex,newDeterminant, determinant;
    cout<<"�п�J�T�ӫY��"; 
    cin>>a>>b>>c;
    
    
    if ((b*b)-(4*a*c)>0&&a!=0){
        determinant=(b*b)-(4*a*c);
        L1=((-b)+sqrt(determinant))/(2*a);
        L2=((-b)-sqrt(determinant))/(2*a);
        cout<<"�Ѭ�"<<L1<<endl<<L2<<"(�G���)";
    }
    if  ((b*b)-(4*a*c)==0&&a!=0&&b!=0&&c!=0){
        
        L1=L2=(-b)/(2*a);
        cout<<"�Ѭ�"<<L1<<"(����)";
    
    }
    if  ((b*b)-(4*a*c)<0&&a!=0){
        L1real=(-b)/(2*a);
        L2real=(-b)/(2*a);
        
        newDeterminant=(-1)*((b*b)-(4*a*c));
        L1complex=(sqrt(newDeterminant)/(2*a));
        L2complex=(-1)*(sqrt(newDeterminant)/(2*a));
        
        
        cout<<"�Ѭ�"<<L1real<<"+"<<L1complex<<"i"<<endl<<L2real<<"+"<<L1complex<<"i"<<"(�G���)";
    }
    if (a==0&&b==0&&c==0){
        cout<<"�L���h�ո�";
    }   
    if (a==0&&b!=0&&c!=0){
        cout<<"�L�@���G����";
    }
    if (a==0&&b==0){
        cout<<"�L�@���G����";
		}
    
    return 0;
}

