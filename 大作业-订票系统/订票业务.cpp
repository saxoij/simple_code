//承办订票业务

#include"FlightInfo.h"
#include<iostream>
using namespace std;

void BookTicket(FlightNode *F,POList *B,PWList *R)                          //订票服务的函数
{

	int flag=0;
	int Fl;                                       //临时存放航班号
	int N;										 //临时存放订票额
	char Na[20];                                 //临时存放客户名字
                                      //返回值
	int choice;

		int temp;
		cout<<"请输入需乘坐的航班号：\n";
top6:		cin>>Fl;

			if(!(Fl%5==0))
			{
				cout<<"输入错误！无此航班号，请重新输入：";
				goto top6;
			}

		cout<<"请输入订票额：\n";
		cin>>N;
		cout<<"请输入您的名字：\n";
		cin>>Na;
		for(int i=0;i<=20;i++)
			{
				if(Fl==B[i].Fli){temp=i;flag=1;}
			}
		if(flag==0){cout<<"无此航班\n";return;}
		if(F[temp].Left>=N)
			{
				char choice1;
				cout<<"尚有余票，"<<ends<<"飞行日："<<F[temp].Day<<ends<<"飞机号："<<F[temp].Plane<<endl;
				cout<<"你要订"<<N<<"张票,确定订票？（N/Y）"<<endl;
				cin>>choice1;
				switch(choice1)
					{
						case 'Y':
													//F[temp].Left=100-N将余量赋入Flightline中
						case 'y':B[temp].append(Na,N,1);F[temp].Left=100-N;cout<<"订票成功！\n";break;
						default:return ;//re=0;
					}
			}
		else
			{
				char choice2;
				cout<<"余票不足，需要排队候补吗？(N/Y)"<<endl;
				cin>>choice2;
				switch(choice2)
					{
						case 'Y':
						case 'y':R[temp].append(Na,N);cout<<"已进候补名单！\n";R[temp].setEnd();cout<<R[temp].leftLength();break;
						default:return ;//re=0;
					}
			}
		cout<<"请选择下一步操作：1，继续订票  2，退票 3.返回上一级\n";
top4:		cin>>choice;

        if(choice==1)
		{
			BookTicket(F,B,R);
		}
		else if(choice==2)
		{
			ReturnTicket(F,B,R);
		}
		else if(choice==3)
		{
			return;
		}
		else
		{
			cout<<"输入错误！请重新选择：";
			goto top4;
		}
}