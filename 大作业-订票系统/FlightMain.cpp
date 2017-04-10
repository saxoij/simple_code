//主函数，程序的主界面

#include"FlightInfo.h"
#include<iostream>
using namespace std;

void main()
{	
	
	FlightNode F[20];
	POList B[20];
	PWList R[20];

	//定义各条航线的详细信息
	F[0]=FlightNode("NULL",1000,1,1,0,0);               //第一个无航班                                                     
	B[0]=100;                                         
	F[1]=FlightNode("北京",1005,100,4,100,100);
	B[1].Fli=1005;
	F[2]=FlightNode("哈尔滨",1010,101,5,100,100);
	B[2].Fli=1010;
	F[3]=FlightNode("长春",1015,102,4,100,100);
	B[3].Fli=1015;
	F[4]=FlightNode("天津",1020,103,2,100,100);
	B[4].Fli =1020;
	F[5]=FlightNode("西安",1025,104,1,100,100);
	B[5].Fli =1025;
	F[6]=FlightNode("拉萨",1030,105,6,100,100);
	B[6].Fli =1030;
	F[7]=FlightNode("杭州",1035,106,7,100,100);
	B[7].Fli =1035;
	F[8]=FlightNode("海口",1040,107,1,100,100);
	B[8].Fli =1040;
	F[9]=FlightNode("台北",1045,108,2,100,100);
	B[9].Fli =1045;
	F[10]=FlightNode("东京",1050,109,3,100,100);
	B[10].Fli =1050;
	F[11]=FlightNode("伦敦",1055,110,4,100,100);
	B[11].Fli =1055;
	F[12]=FlightNode("纽约",1060,111,5,100,100);
	B[12].Fli =1060;
	F[13]=FlightNode("巴黎",1060,112,6,100,100);
	B[13].Fli =1060;
	F[14]=FlightNode("悉尼",1065,113,7,100,100);
	B[14].Fli =1065;
	F[15]=FlightNode("温哥华",1070,114,1,100,100);
	B[15].Fli =1070;
	F[16]=FlightNode("华盛顿",1075,115,2,100,100);
	B[16].Fli =1075;
	F[17]=FlightNode("新加坡",1080,116,3,100,100);
	B[17].Fli =1080;
	F[18]=FlightNode("平壤",1085,117,4,100,100);
	B[18].Fli =1085;
	F[19]=FlightNode("汉城",1090,118,5,100,100);
	B[19].Fli =1090;

	int choice;
	while(1)
	{
		cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
		cout<<"       ***  欢迎使用航空客运订票系统！！***       "<<endl;
		cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
		cout<<"你可以进行以下的操作：\n"
			<<"1==>查询全部航线\n"
			<<"2==>查询单条航线\n"
			<<"3==>订票\n"
			<<"4==>退票\n"
			<<"5==>退出.\n"
			<<"----------------------------------------"<<endl;
		
		cout<<"请选择：";
top:		cin>>choice;
		switch(choice)
		{
		    case 1 :  ShowAllFlight(F);break;
			case 2 :  ShowOneFlight(F);break;
			case 3 :  BookTicket(F,B,R)  ;break;
			case 4 :  ReturnTicket(F,B,R)  ;break;
			case 5 : cout<<"退出系统！多谢使用！";return;
			default : cout<<"输入错误，请重新输入:\n";goto top;
		}
	}

}