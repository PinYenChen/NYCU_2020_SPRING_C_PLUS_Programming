#include <iostream>
using namespace std;

int main(int argc,char** argv){
	
	int value=0,a1=0,a2=0,a3=0,a4=0,a5=0,a6=0,a7=0,a8=0;
	cout<<" Input a number: ";
	cin>>value;
	
	a1=value%2; a2=(value%100)/10%2; a3=(value%1000)/100%2; a4=(value%10000)/1000%2;
	a5=(value%100000)/10000%2; a6=(value%1000000)/100000%2; a7=(value%10000000)/1000000%2; a8=(value%100000000)/10000000%2;
	
	(value>9999999&&value<100000000)?cout<<a1+a2+a3+a4+a5+a6+a7+a8://计 
		(value>999999&& value<10000000)?cout<<a1+a2+a3+a4+a5+a6+a7://计 
			(value>99999&&value<1000000)?cout<<a1+a2+a3+a4+a5+a6://せ计 
				(value>9999&&value<100000)?cout<<a1+a2+a3+a4+a5://き计 
					(value>999&&value<10000)?cout<<a1+a2+a3+a4://计 
						(value>99&&value<1000)?cout<<a1+a2+a3://计 
							(value>9&&value<100)?cout<<a1+a2://计 
								(value>0&&value<10)?cout<<a1://计 
									cout<<""; 
	
	return 0; 

}
