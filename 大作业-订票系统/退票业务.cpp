//�а���Ʊҵ��

#include"FlightInfo.h"
#include<iostream>
using namespace std;


void ReturnTicket(FlightNode *F,POList *B,PWList *R)
{
	int Ftemp;									//��ʱ��ź����
	char Ntemp[20];									//��ʱ��ſͻ�����
	int BoNum;                               //��ʱ��ſͻ��Ķ�Ʊ��
	int flag=0;
	int flag1=0;
	int temp;
	int choice;
	bool flag2;

		flag=1;
		int Length;                             //�Ѷ�Ʊ�ͻ�������
		int LengthR;							//�򲹿ͻ�������
		cout<<"������Ҫ��Ʊ�ĺ���ţ�";
		cin>>Ftemp;
		cout<<"������������֣�";
		cin>>Ntemp;
		for(int i=0;i<=20;i++)
			{
				if(Ftemp==B[i].Fli){temp=i;flag1=1;}
			}
		if(flag1==0){cout<<"�޴˺���\n";return;}
		B[temp].setEnd();
		Length=B[temp].leftLength();
		cout<<Length<<endl;
		B[temp].setStart();
		//������û�д��ˣ�����еĻ���ɾ��
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
				cout<<"��Ʊ�ɹ���\n";
				R[temp].setEnd();
				LengthR=R[temp].leftLength();
				for(int k=0;k<=LengthR;k++)
					{
						if(flag2==false)break;
						if((BoNum>=R[temp].fence->Need)&&(R[temp].fence->Need!=0))
						{
							cout<<R[temp].fence->Name<<"��ã����ں����п�λ�ˣ���ȷ��Ҫ��Ʊ��(Y/N)��\n";
							cin>>choice;
							if(choice=='y'||choice=='Y')
								{
									B[temp].insert(Ntemp,R[temp].fence->Need,1);
									cout<<"��Ʊ�ɹ���"<<endl;
									flag2=R[temp].next();
								}
							else cout<<"ллʹ��!";
						}
					}
			}
			else cout<<"�Բ���û���㶩Ʊ�ļ�¼��\n";
			cout<<"��ѡ����һ��������1��������Ʊ 2����Ʊ 3�������ϼ��˵�\n";
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
				cout<<"�������������ѡ��";
				goto top5;
			}

}

