//�а충Ʊҵ��

#include"FlightInfo.h"
#include<iostream>
using namespace std;

void BookTicket(FlightNode *F,POList *B,PWList *R)                          //��Ʊ����ĺ���
{

	int flag=0;
	int Fl;                                       //��ʱ��ź����
	int N;										 //��ʱ��Ŷ�Ʊ��
	char Na[20];                                 //��ʱ��ſͻ�����
                                      //����ֵ
	int choice;

		int temp;
		cout<<"������������ĺ���ţ�\n";
top6:		cin>>Fl;

			if(!(Fl%5==0))
			{
				cout<<"��������޴˺���ţ����������룺";
				goto top6;
			}

		cout<<"�����붩Ʊ�\n";
		cin>>N;
		cout<<"�������������֣�\n";
		cin>>Na;
		for(int i=0;i<=20;i++)
			{
				if(Fl==B[i].Fli){temp=i;flag=1;}
			}
		if(flag==0){cout<<"�޴˺���\n";return;}
		if(F[temp].Left>=N)
			{
				char choice1;
				cout<<"������Ʊ��"<<ends<<"�����գ�"<<F[temp].Day<<ends<<"�ɻ��ţ�"<<F[temp].Plane<<endl;
				cout<<"��Ҫ��"<<N<<"��Ʊ,ȷ����Ʊ����N/Y��"<<endl;
				cin>>choice1;
				switch(choice1)
					{
						case 'Y':
													//F[temp].Left=100-N����������Flightline��
						case 'y':B[temp].append(Na,N,1);F[temp].Left=100-N;cout<<"��Ʊ�ɹ���\n";break;
						default:return ;//re=0;
					}
			}
		else
			{
				char choice2;
				cout<<"��Ʊ���㣬��Ҫ�ŶӺ���(N/Y)"<<endl;
				cin>>choice2;
				switch(choice2)
					{
						case 'Y':
						case 'y':R[temp].append(Na,N);cout<<"�ѽ���������\n";R[temp].setEnd();cout<<R[temp].leftLength();break;
						default:return ;//re=0;
					}
			}
		cout<<"��ѡ����һ��������1��������Ʊ  2����Ʊ 3.������һ��\n";
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
			cout<<"�������������ѡ��";
			goto top4;
		}
}