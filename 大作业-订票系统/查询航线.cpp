//查询航线，查询全部航线和查询单条航线分别用两个函数去处理
#include"FlightInfo.h"
#include<iostream>
using namespace std;
//列举全部航线
void ShowAllFlight(FlightNode *F)
{
    cout<<"+++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	cout<<"本公司尚处于起步阶段，暂时只开放以下航线：   "<<endl;
	cout<<"---------------------------------------------"<<endl;
	cout<<"航班号"<<"\t"<<"终点站"<<"\t"<<"飞行日"<<endl;

	for(int i=1;i<20;i++)
	{
		cout<<F[i].Flight <<"\t"<<F[i].Terminus <<"\t"<<F[i].Day <<endl;
	}

	cout<<"---------------------------------------------"<<endl;
	cout<<"你可以进行以下操作：1.查看单条航线；\n"
		<<"2.返回上一级.\n"
		<<"请选择：";
	
	int chioce;
top2:	cin>>chioce;

	if(chioce==1)
	{
		ShowOneFlight(F);
	}
	else if(chioce==2)
	{
		return;
	}
	else
	{
		cout<<"输入错误！请重新选择：";
		goto top2;
	}
}














//查询单条航线
void ShowOneFlight(FlightNode *F)               //查询航班的函数
{
		char T[20];
						
		int choice;						
			cout<<"请输入终点站名称:\n";
			cin>>T;
			FlightNode temp[20];
			int n=0;
			for(int i=0;i<=20;i++)
				{
					if(strcmp(T,F[i].Terminus)==0)
						{temp[n]=F[i];n++;}
					
				}
			if(n==0)cout<<"无此终点站"<<endl;
			else
			{
				FlightNode temp1=temp[0];                               //记录最近的航班
				cout<<"航班号："<<temp[0].Flight<<ends<<"飞机号："<<temp[0].Plane<<ends<<"飞行日："<<temp[0].Day<<ends<<"余票额："<<temp[0].Left<<endl;
				for(int j=1;j<n;j++)
					{
						if(temp[j].Day!=0)
						{
							cout<<"航班号："<<temp[j].Flight<<ends<<"飞机号："<<temp[j].Plane<<ends<<"飞行日："<<temp[j].Day<<ends<<"余票额："<<temp[j].Left<<endl;
							if((temp[j].Day>=3)&&(temp[j-1].Day>temp[j].Day))temp1=temp[j];
						}
					}
				cout<<"最近一天的航班：\n"
					<<"航班号："<<temp1.Flight<<ends<<"飞机号："<<temp1.Plane<<ends<<"飞行日："<<temp1.Day<<ends<<"余票额："<<temp1.Left<<endl;
			}
			cout<<"请选择所要的操作：1，继续查询 2.返回上一级\n";
top3:			cin>>choice;

			if(choice==1)
			{
				ShowOneFlight(F);
			}
			else if(choice==2)
			{
				return;
			}
			else
			{
				cout<<"输入错误！请重新选择：";
                 goto top3;
			}

}

