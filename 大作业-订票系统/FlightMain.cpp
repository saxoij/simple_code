//�������������������

#include"FlightInfo.h"
#include<iostream>
using namespace std;

void main()
{	
	
	FlightNode F[20];
	POList B[20];
	PWList R[20];

	//����������ߵ���ϸ��Ϣ
	F[0]=FlightNode("NULL",1000,1,1,0,0);               //��һ���޺���                                                     
	B[0]=100;                                         
	F[1]=FlightNode("����",1005,100,4,100,100);
	B[1].Fli=1005;
	F[2]=FlightNode("������",1010,101,5,100,100);
	B[2].Fli=1010;
	F[3]=FlightNode("����",1015,102,4,100,100);
	B[3].Fli=1015;
	F[4]=FlightNode("���",1020,103,2,100,100);
	B[4].Fli =1020;
	F[5]=FlightNode("����",1025,104,1,100,100);
	B[5].Fli =1025;
	F[6]=FlightNode("����",1030,105,6,100,100);
	B[6].Fli =1030;
	F[7]=FlightNode("����",1035,106,7,100,100);
	B[7].Fli =1035;
	F[8]=FlightNode("����",1040,107,1,100,100);
	B[8].Fli =1040;
	F[9]=FlightNode("̨��",1045,108,2,100,100);
	B[9].Fli =1045;
	F[10]=FlightNode("����",1050,109,3,100,100);
	B[10].Fli =1050;
	F[11]=FlightNode("�׶�",1055,110,4,100,100);
	B[11].Fli =1055;
	F[12]=FlightNode("ŦԼ",1060,111,5,100,100);
	B[12].Fli =1060;
	F[13]=FlightNode("����",1060,112,6,100,100);
	B[13].Fli =1060;
	F[14]=FlightNode("Ϥ��",1065,113,7,100,100);
	B[14].Fli =1065;
	F[15]=FlightNode("�¸绪",1070,114,1,100,100);
	B[15].Fli =1070;
	F[16]=FlightNode("��ʢ��",1075,115,2,100,100);
	B[16].Fli =1075;
	F[17]=FlightNode("�¼���",1080,116,3,100,100);
	B[17].Fli =1080;
	F[18]=FlightNode("ƽ��",1085,117,4,100,100);
	B[18].Fli =1085;
	F[19]=FlightNode("����",1090,118,5,100,100);
	B[19].Fli =1090;

	int choice;
	while(1)
	{
		cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
		cout<<"       ***  ��ӭʹ�ú��տ��˶�Ʊϵͳ����***       "<<endl;
		cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
		cout<<"����Խ������µĲ�����\n"
			<<"1==>��ѯȫ������\n"
			<<"2==>��ѯ��������\n"
			<<"3==>��Ʊ\n"
			<<"4==>��Ʊ\n"
			<<"5==>�˳�.\n"
			<<"----------------------------------------"<<endl;
		
		cout<<"��ѡ��";
top:		cin>>choice;
		switch(choice)
		{
		    case 1 :  ShowAllFlight(F);break;
			case 2 :  ShowOneFlight(F);break;
			case 3 :  BookTicket(F,B,R)  ;break;
			case 4 :  ReturnTicket(F,B,R)  ;break;
			case 5 : cout<<"�˳�ϵͳ����лʹ�ã�";return;
			default : cout<<"�����������������:\n";goto top;
		}
	}

}