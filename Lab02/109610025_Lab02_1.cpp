#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	cout<<"1-1\n";
	cout<<"块10秈俱计锣传秈r\n";
	
	
	
	int r=0, value=0;
	int rr1=0, rr2=0, rr3=0, rr4=0, rr5=0, rr6=0, rr7=0, rr8=0, rr9=0, rr10=0, rr11=0,rr12=0, rr13=0, rr14=0, rr15=0, rr16=0, rr17=0, rr18=0, rr19=0, rr20=0, rr21=0, rr22=0, rr23=0, rr24=0, rr25=0,rr26=0, rr27=0;
	
	cin>>value>>r;
	
	rr1=value%r;
	rr2=(value/r)%r;
	rr3=(value/r/r)%r;
	rr4=(value/r/r/r)%r;
	rr5=(value/r/r/r/r)%r;
	rr6=(value/r/r/r/r/r)%r;
	rr7=(value/r/r/r/r/r/r)%r;
	rr8=(value/r/r/r/r/r/r/r)%r;
	
	
	cout<<r<<"秈计"<<rr8<<rr7<<rr6<<rr5<<rr4<<rr3<<rr2<<rr1;
	
	cout<<"\n1-2\n";
	cout<<"块r秈俱计锣传秈r\n";
	
	
	
	
	
	int v9=0, r1=0, v1=0, v12=0, v123=0, v1234=0, v12345=0, v123456=0, v1234567=0, v12345678=0, v2=0, v3=0, v4=0, v5=0, v6=0, v7=0, v8=0, vtotal=0;
	cin>>v9>>r1;
	
	if(v9 > 9999999)   //8计 
	{
		v1=v9/10000000;
		v12=v9/1000000;
		v123=v9/100000;
		v1234=v9/10000;
		v12345=v9/1000;
		v123456=v9/100;
		v1234567=v9/10;
		v12345678=v9%10;
		
		/*だ瞒计*/
		 
		v2=v12-(v1*10);
		v3=v123-(v12*10);
		v4=v1234-(v123*10);
		v5=v12345-(v1234*10);
		v6=v123456-(v12345*10);
		v7=v1234567-(v123456*10);
		
		
		vtotal=(v12345678*1)+(v7*r1)+(v6*r1*r1)+(v5*r1*r1*r1)+(v4*r1*r1*r1*r1)+(v3*r1*r1*r1*r1*r1)+(v2*r1*r1*r1*r1*r1*r1)+(v1*r1*r1*r1*r1*r1*r1*r1);
		cout<<v9<<""<<r1<<"秈"<<vtotal;
	}
	
		if(v9>999999&&v9<10000000)   //7计 
	{
		v1=v9/1000000;
		v12=v9/100000;
		v123=v9/10000;
		v1234=v9/1000;
		v12345=v9/100;
		v123456=v9/10;
		v1234567=v9%10;
		
		
		/*だ瞒计*/
		 
		v2=v12-(v1*10);
		v3=v123-(v12*10);
		v4=v1234-(v123*10);
		v5=v12345-(v1234*10);
		v6=v123456-(v12345*10);
		
		
		
		vtotal=(v1234567*1)+(v6*r1)+(v5*r1*r1)+(v4*r1*r1*r1)+(v3*r1*r1*r1*r1)+(v2*r1*r1*r1*r1*r1)+(v1*r1*r1*r1*r1*r1*r1);
		cout<<v9<<""<<r1<<"秈"<<vtotal;
	}
		if(v9>99999&&v9<1000000)   //6计 
	{
		v1=v9/100000;
		v12=v9/10000;
		v123=v9/1000;
		v1234=v9/100;
		v12345=v9/10;
		v123456 = v9 % 10;
	
		/*だ瞒计*/
		 
		v2=v12-(v1*10);
		v3=v123-(v12*10);
		v4=v1234-(v123*10);
		v5=v12345-(v1234*10);
		
		
		vtotal=(v123456*1)+(v5*r1)+(v4*r1*r1)+(v3*r1*r1*r1)+(v2*r1*r1*r1*r1)+(v1*r1*r1*r1*r1*r1);
		cout<<v9<<""<<r1<<"秈"<<vtotal;
	}
		if(v9>9999&&v9<100000)   //5计 
	{
		v1=v9/10000;
		v12=v9/1000;
		v123=v9/100;
		v1234=v9/10;
		v12345=v9%10;
		
		/*だ瞒计*/
		 
		v2=v12-(v1*10);
		v3=v123-(v12*10);
		v4=v1234-(v123*10);
		
	
		
		vtotal=(v12345*1)+(v4*r1)+(v3*r1*r1)+(v2*r1*r1*r1)+(v1*r1*r1*r1*r1);
		cout<<v9<<""<<r<<"秈"<<vtotal;
	}
		if(v9>999&&v9<10000)   //4计 
	{
		v1=v9/1000;
		v12=v9/100;
		v123=v9/10;
		v1234=v9%10;
		
		/*だ瞒计*/
		 
		v2=v12-(v1*10);
		v3=v123-(v12*10);
		
		
	
		
		vtotal=(v1234*1)+(v3*r1)+(v2*r1*r1)+(v1*r1*r1*r1);
		cout<<v9<<""<<r<<"秈"<<vtotal;
	}
		if(v9>999&&v9<10000)   //3计 
	{
		v1=v9/100;
		v12=v9/10;
		v123=v9%10;
		
		/*だ瞒计*/
		 
		v2=v12-(v1*10);
		
	
	
		
		vtotal=(v123*1)+(v2*r1)+(v1*r1*r1);
		cout<<v9<<""<<r<<"秈"<<vtotal;
	}
		if(v9>99&&v9<1000)   //2计 
	{
		v1=v9/10;
		v12=v9%10;
		
	
		
		/*だ瞒计*/
		 
		
		
	
		
		vtotal=(v12*1)+(v1*r1);
		cout<<v9<<""<<r<<"秈"<<vtotal;
			if(v9>9&&v9<100)   //1计 
	{
	
	
		
		/*だ瞒计*/
		 
	
		
		vtotal=(v1*1);
		cout<<v9<<""<<r<<"秈"<<vtotal;
	}
	}
	return 0;
}
