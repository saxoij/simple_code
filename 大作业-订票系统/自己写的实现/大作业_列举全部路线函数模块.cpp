
//查询铁路客运路线，查询全部路线和查询单条路线分别用两个函数去处理

#include<iostream>
using namespace std;
//列举全部火车路线

class TrainNode
{
public:
	char Begin[20];						//起点站名
	char Terminus[20];                //终点站名
	int Lines;                     //车次       
	int Num;						//列车号
	int Time;                          //历时
	int Maxnum;                     //乘员定额
	int Left;                       //余票量
	TrainNode(char B[20] = "", char T[20] = "", const int LINE = 0, const int NUM = 0, const int TIME = 0, const int MAX = 0, const int LEFT = 0);
};

TrainNode::TrainNode(char B[20], char T[20], const int LINE, const int NUM, const int TIME, const int MAX, const int LEFT)
{
	for (int i = 0; i <= 5; i++)
	{
		Begin[i] = B[i];					//起点站名
		Terminus[i] = T[i];					//终点站名
	}
	Lines = LINE; Num = NUM; Time = TIME; Maxnum = MAX; Left = LEFT;
}






void ShowAllLines(TrainNode *TR)				//ShowAllFlight--->ShowAllLines   flightnode--->trainnode
{
	cout << "=============================================" << endl;
	cout << "开放路线时间表：   " << endl;
	cout << "=============================================" << endl;
	cout << "车次" << "\t" << "出发站" << "\t" << "终点站" << "\t" << "历时(小时)" << endl;

	for (int i = 0; i<5; i++)
	{
		cout << TR[i].Lines << "\t" << TR[i].Begin << "\t" << TR[i].Terminus << "\t" << TR[i].Time << endl;
	}

	cout << "---------------------------------------------" << endl;
	cout << "你可以进行以下操作：\n1.查看单程路线；\n"
		<< "2.返回上一级.\n"
		<< "请选择：";

	int chioce;
top:	cin >> chioce;

	if (chioce == 1)
	{
		cout << "调用单程路线查询函数，在另一个模块，此处不列举" << endl;
		//ShowOneLine(TR);
	}
	else if (chioce == 2)
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
	TR[0] = TrainNode("长春", "武汉", 1015, 102, 9, 100, 100);
	TR[1] = TrainNode("济南", "武汉", 1015, 102, 8, 100, 100);
	TR[2] = TrainNode("开封", "武汉", 1015, 102, 7, 100, 100);
	TR[3] = TrainNode("天津", "武汉", 1020, 103, 6, 100, 100);
	TR[4] = TrainNode("合肥", "武汉", 1020, 103, 5, 100, 100);

	ShowAllLines(TR);
}