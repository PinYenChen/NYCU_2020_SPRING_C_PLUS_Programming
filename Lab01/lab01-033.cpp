#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	cout<<"Hello World!~";
	cout<<"交大奈米讚喔哈!哈!哈!"<<endl; 
	cout<<"integer:"<<sizeof(int)<<"Bytes, largest integer="
	    <<INT_MAX<<endl;
	    char myname [20];//儲存字元(半形字) 
	    int tall, weight;
	    cout<<"嗨!請問大名:"; cin>>myname;
	    cout <<myname<<"你好 請問多高?";cin>>tall;
	    weight= tall-110;
	    cout<<"過年吃多動少 標準體重只能介於"<<weight*1.1<<"~"<<weight*0.9<<"Kg\n" ;
	    system("PAUSE") ;
	    
	     float ctem,ftem;
	  cout<<"Please input Celsius temperature"; cin>>ctem;
	  ftem= ctem*(9./5)+32;
	  cout<<"temperature in Fahrenheit="<<ftem<<endl;
	    
		return 0;
}  
 

