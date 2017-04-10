#include<iostream>
using namespace std;

//查询单程车次

class TrainNode							//定义车次信息类
{
public:
	char Begin[20];						//起点站名
	char Terminus[20];                //终点站名
	int Lines;                     //车次       
	int Num;						//列车号
	int Time;                          //历时
	int Maxnum;                     //乘员定额
	int Left;                       //余票量


};

void ShowOneLine(TrainNode *TR)
{
	char T[20];

	int choice;
	cout << "请输入终点站名称:\n";
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
	if (n == 0)cout << "无此终点站" << endl;
	else
	{
		TrainNode temp1 = temp[0];                               //记录最近的路线
		cout << "车次：" << temp[0].Lines << "\t" << "列车号：" << temp[0].Num << "\t" << "历时：" << temp[0].Time << "\t" << "剩余车票：" << temp[0].Left << endl;
		for (int j = 1; j<n; j++)
		{
			if (temp[j].Time != 0)
			{
				cout << "车次：" << temp[j].Lines << "\t" << "列车号：" << temp[j].Num << "\t" << "历时：" << temp[j].Time << "\t" << "剩余车票：" << temp[j].Left << endl;
				if ((temp[j].Time >= 3) && (temp[j - 1].Time>temp[j].Time))temp1 = temp[j];
			}
		}
		cout << "最近一天的列车：\n"
			<< "车次：" << temp1.Lines << ends << "列车号：" << temp1.Num << ends << "日：" << temp1.Time << ends << "余票额：" << temp1.Left << endl;
	}
	cout << "请选择所要的操作：\n1，继续查询 2.返回上一级\n";
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
		cout << "输入错误！请重新选择：";
		goto top;
	}

}

void main(void) {
	TrainNode TR[20];
	ShowOneLine(TR);
}