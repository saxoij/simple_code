//��ѯ���ߣ���ѯȫ�����ߺͲ�ѯ�������߷ֱ�����������ȥ����
#include"FlightInfo.h"
#include<iostream>
using namespace std;
//�о�ȫ������
void ShowAllFlight(FlightNode *F)
{
    cout<<"+++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	cout<<"����˾�д����𲽽׶Σ���ʱֻ�������º��ߣ�   "<<endl;
	cout<<"---------------------------------------------"<<endl;
	cout<<"�����"<<"\t"<<"�յ�վ"<<"\t"<<"������"<<endl;

	for(int i=1;i<20;i++)
	{
		cout<<F[i].Flight <<"\t"<<F[i].Terminus <<"\t"<<F[i].Day <<endl;
	}

	cout<<"---------------------------------------------"<<endl;
	cout<<"����Խ������²�����1.�鿴�������ߣ�\n"
		<<"2.������һ��.\n"
		<<"��ѡ��";
	
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
		cout<<"�������������ѡ��";
		goto top2;
	}
}














//��ѯ��������
void ShowOneFlight(FlightNode *F)               //��ѯ����ĺ���
{
		char T[20];
						
		int choice;						
			cout<<"�������յ�վ����:\n";
			cin>>T;
			FlightNode temp[20];
			int n=0;
			for(int i=0;i<=20;i++)
				{
					if(strcmp(T,F[i].Terminus)==0)
						{temp[n]=F[i];n++;}
					
				}
			if(n==0)cout<<"�޴��յ�վ"<<endl;
			else
			{
				FlightNode temp1=temp[0];                               //��¼����ĺ���
				cout<<"����ţ�"<<temp[0].Flight<<ends<<"�ɻ��ţ�"<<temp[0].Plane<<ends<<"�����գ�"<<temp[0].Day<<ends<<"��Ʊ�"<<temp[0].Left<<endl;
				for(int j=1;j<n;j++)
					{
						if(temp[j].Day!=0)
						{
							cout<<"����ţ�"<<temp[j].Flight<<ends<<"�ɻ��ţ�"<<temp[j].Plane<<ends<<"�����գ�"<<temp[j].Day<<ends<<"��Ʊ�"<<temp[j].Left<<endl;
							if((temp[j].Day>=3)&&(temp[j-1].Day>temp[j].Day))temp1=temp[j];
						}
					}
				cout<<"���һ��ĺ��ࣺ\n"
					<<"����ţ�"<<temp1.Flight<<ends<<"�ɻ��ţ�"<<temp1.Plane<<ends<<"�����գ�"<<temp1.Day<<ends<<"��Ʊ�"<<temp1.Left<<endl;
			}
			cout<<"��ѡ����Ҫ�Ĳ�����1��������ѯ 2.������һ��\n";
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
				cout<<"�������������ѡ��";
                 goto top3;
			}

}

