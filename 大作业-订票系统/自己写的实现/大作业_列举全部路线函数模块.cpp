
//��ѯ��·����·�ߣ���ѯȫ��·�ߺͲ�ѯ����·�߷ֱ�����������ȥ����

#include<iostream>
using namespace std;
//�о�ȫ����·��

class TrainNode
{
public:
	char Begin[20];						//���վ��
	char Terminus[20];                //�յ�վ��
	int Lines;                     //����       
	int Num;						//�г���
	int Time;                          //��ʱ
	int Maxnum;                     //��Ա����
	int Left;                       //��Ʊ��
	TrainNode(char B[20] = "", char T[20] = "", const int LINE = 0, const int NUM = 0, const int TIME = 0, const int MAX = 0, const int LEFT = 0);
};

TrainNode::TrainNode(char B[20], char T[20], const int LINE, const int NUM, const int TIME, const int MAX, const int LEFT)
{
	for (int i = 0; i <= 5; i++)
	{
		Begin[i] = B[i];					//���վ��
		Terminus[i] = T[i];					//�յ�վ��
	}
	Lines = LINE; Num = NUM; Time = TIME; Maxnum = MAX; Left = LEFT;
}






void ShowAllLines(TrainNode *TR)				//ShowAllFlight--->ShowAllLines   flightnode--->trainnode
{
	cout << "=============================================" << endl;
	cout << "����·��ʱ���   " << endl;
	cout << "=============================================" << endl;
	cout << "����" << "\t" << "����վ" << "\t" << "�յ�վ" << "\t" << "��ʱ(Сʱ)" << endl;

	for (int i = 0; i<5; i++)
	{
		cout << TR[i].Lines << "\t" << TR[i].Begin << "\t" << TR[i].Terminus << "\t" << TR[i].Time << endl;
	}

	cout << "---------------------------------------------" << endl;
	cout << "����Խ������²�����\n1.�鿴����·�ߣ�\n"
		<< "2.������һ��.\n"
		<< "��ѡ��";

	int chioce;
top:	cin >> chioce;

	if (chioce == 1)
	{
		cout << "���õ���·�߲�ѯ����������һ��ģ�飬�˴����о�" << endl;
		//ShowOneLine(TR);
	}
	else if (chioce == 2)
	{
		return;
	}
	else
	{
		cout << "�������������ѡ��";
		goto top;
	}
}

void main(void) {
	TrainNode TR[20];
	TR[0] = TrainNode("����", "�人", 1015, 102, 9, 100, 100);
	TR[1] = TrainNode("����", "�人", 1015, 102, 8, 100, 100);
	TR[2] = TrainNode("����", "�人", 1015, 102, 7, 100, 100);
	TR[3] = TrainNode("���", "�人", 1020, 103, 6, 100, 100);
	TR[4] = TrainNode("�Ϸ�", "�人", 1020, 103, 5, 100, 100);

	ShowAllLines(TR);
}