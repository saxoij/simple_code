#include<iostream>
using namespace std;

//��ѯ���̳���

class TrainNode							//���峵����Ϣ��
{
public:
	char Begin[20];						//���վ��
	char Terminus[20];                //�յ�վ��
	int Lines;                     //����       
	int Num;						//�г���
	int Time;                          //��ʱ
	int Maxnum;                     //��Ա����
	int Left;                       //��Ʊ��


};

void ShowOneLine(TrainNode *TR)
{
	char T[20];

	int choice;
	cout << "�������յ�վ����:\n";
	cin >> T;
	TrainNode temp[20];
	int n = 0;
	for (int i = 0; i <= 20; i++)
	{
		if (strcmp(T, TR[i].Terminus) == 0)
		{
			temp[n] = TR[i]; n++;
		}

	}
	if (n == 0)cout << "�޴��յ�վ" << endl;
	else
	{
		TrainNode temp1 = temp[0];                               //��¼�����·��
		cout << "���Σ�" << temp[0].Lines << "\t" << "�г��ţ�" << temp[0].Num << "\t" << "��ʱ��" << temp[0].Time << "\t" << "ʣ�೵Ʊ��" << temp[0].Left << endl;
		for (int j = 1; j<n; j++)
		{
			if (temp[j].Time != 0)
			{
				cout << "���Σ�" << temp[j].Lines << "\t" << "�г��ţ�" << temp[j].Num << "\t" << "��ʱ��" << temp[j].Time << "\t" << "ʣ�೵Ʊ��" << temp[j].Left << endl;
				if ((temp[j].Time >= 3) && (temp[j - 1].Time>temp[j].Time))temp1 = temp[j];
			}
		}
		cout << "���һ����г���\n"
			<< "���Σ�" << temp1.Lines << ends << "�г��ţ�" << temp1.Num << ends << "�գ�" << temp1.Time << ends << "��Ʊ�" << temp1.Left << endl;
	}
	cout << "��ѡ����Ҫ�Ĳ�����\n1��������ѯ 2.������һ��\n";
top:			cin >> choice;

	if (choice == 1)
	{
		ShowOneLine(TR);
	}
	else if (choice == 2)
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
	ShowOneLine(TR);
}