//承办退票业务

#include"FlightInfo.h"
#include<iostream>
using namespace std;


void ReturnTicket(FlightNode *F,POList *B,PWList *R)
{
	int Ftemp;									//临时存放航班号
	char Ntemp[20];									//临时存放客户名字
	int BoNum;                               //临时存放客户的定票额
	int flag=0;
	int flag1=0;
	int temp;
	int choice;
	bool flag2;

		flag=1;
		int Length;                             //已订票客户的数量
		int LengthR;							//候补客户的数量
		cout<<"请输入要退票的航班号：";
		cin>>Ftemp;
		cout<<"请输入你的名字：";
		cin>>Ntemp;
		for(int i=0;i<=20;i++)
			{
				if(Ftemp==B[i].Fli){temp=i;flag1=1;}
			}
		if(flag1==0){cout<<"无此航班\n";return;}
		B[temp].setEnd();
		Length=B[temp].leftLength();
		cout<<Length<<endl;
		B[temp].setStart();
		//查找有没有此人，如果有的话就删除
		for(int j=0;j<=Length;j++)
			{
				if(strcmp(B[temp].fence->Name,Ntemp)==0)
					{
			
						B[temp].prev();
						B[temp].remove(Ntemp,BoNum);
						F[temp].Left+=BoNum;

					}
				B[temp].next();

			}
		if(flag==1)
			{
				cout<<"退票成功！\n";
				R[temp].setEnd();
				LengthR=R[temp].leftLength();
				for(int k=0;k<=LengthR;k++)
					{
						if(flag2==false)break;
						if((BoNum>=R[temp].fence->Need)&&(R[temp].fence->Need!=0))
						{
							cout<<R[temp].fence->Name<<"你好！现在航班有空位了，你确认要订票吗(Y/N)？\n";
							cin>>choice;
							if(choice=='y'||choice=='Y')
								{
									B[temp].insert(Ntemp,R[temp].fence->Need,1);
									cout<<"订票成功！"<<endl;
									flag2=R[temp].next();
								}
							else cout<<"谢谢使用!";
						}
					}
			}
			else cout<<"对不起，没有你订票的记录！\n";
			cout<<"请选择下一步操作：1，继续退票 2，订票 3，返回上级菜单\n";
top5:			cin>>choice;

			if(choice==1)
			{
				ReturnTicket(F,B,R);
			}
			else if(choice==2)
			{
				BookTicket(F,B,R);
			}
			else if(choice==3)
			{
				return;
			}
			else
			{
				cout<<"输入错误！请重新选择：";
				goto top5;
			}

}

