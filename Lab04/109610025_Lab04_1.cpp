#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	cout<<"請輸入三個數字";
	
	int a=0, b=0,c=0;
	cin>>a>>b>>c;
	
	if (a>b&&a>c){ //a the biggest
		if (b>c){
		cout<<a<<">"<<b<<">"<<c;}
		else //b<c
		{
		cout<<a<<">"<<c<<">"<<b;}
		}
	if (b>a&&b>c){ //b the biggest
		if (a>c){
			cout<<b<<">"<<a<<">"<<c;
		}else {
			cout<<b<<">"<<c<<">"<<a;
		}
		}	
	if (c>a&&c>b){   //c the biggest
		if (b>a){
			 cout<<c<<">"<<b<<">"<<a;}
			 else{
			 cout<<c<<">"<<a<<">"<<b;
			 }
	
	}
	
	
	float Bmi, weight, height;
	
	cout<<"Input height and weight";
	cin>>height>>weight;
	
	Bmi=(float)weight/(height*height);
	
	if (Bmi<=24&&Bmi>=18.5)
	{cout<<"體重適中";
	cout<<Bmi;
	} 
	if (Bmi>24)
	{cout<<"體重過重";
	cout<<Bmi;
	} 
	if (Bmi<18.5)
	{cout<<"體重過輕";
	cout<<Bmi;
	} 
	
	
	return 0;
}
