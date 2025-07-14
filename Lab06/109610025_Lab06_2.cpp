#include <iostream>
#include <conio.h>
using namespace std;
int main(int argc, char** argv) {

	char ch,ch1;
	int sum=0,sum1=0;
	//ch = getch();
	//cout << (int)ch << endl;
	
	cout<<"2-1\n"<<"Input a string: ";
	do{
		ch=getche();
		sum++;	
	}while(ch!=27); //with inputting esc, it has to stop
		
	cout<<"\nanswer = "<<sum<<endl;
	
	cout<<"2-2\nInput a string: ";
	do{
		ch1=getche();
		if(ch1==-32||ch1==0){   //f1-f12,home,end,pgdn,pgup,up down,left,right
			sum1--;
		}
		sum1++;
		
	}while(ch1!=27); //with inputting esc, it has to stop
		
	cout<<"\nanswer = "<<sum1;
	
	return 0;
}
