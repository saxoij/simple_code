#ifndef FLIGHTINFO_H
#define FLIGHTINFO_H
#include<iostream>
#include<string>

//记录已订票的旅客及信息
class PsgOn
{
public:
	char Name[20];                  //客户姓名
	int Booknum;                     //订票量
	int Rank;						//舱位等级
	PsgOn *next;
	PsgOn(char N[20],const int B,const int R,PsgOn *Ne=NULL);
	PsgOn(PsgOn *Ne=NULL);
};

//记录替补的客户
class PsgWait
{
public:
	char Name[20];                      //客户姓名
	int Need;							//所需票量
	PsgWait *next;
	PsgWait(char N[20],const int D,PsgWait *Ne=NULL);
	PsgWait(PsgWait *Ne=NULL);
};

//记录，处理每条航线信息的类
class FlightNode
{
public:
	char Terminus[20];                //终点站名
	int Flight;                     //航班号       
	int Plane;                       //飞机号
	int Day;                          //飞行日
	int Maxnum;                     //乘员定额
	int Left;                       //余票量
	FlightNode(char T[20]="",const int F=0,const int P=0,const int D=0,const int M=0,const int L=0);

};

//对已订票的客户的信息的操作的类
class POList
{
private:
	void init();
public:
	PsgOn *head;
	PsgOn *tail;
	PsgOn *fence;
	int leftcnt;
	int rightcnt;
	int Fli;                                    //记录航班号
	POList(int size=10);
	void clear();
	bool insert(char N[20],const int B,const int R);
	bool append(char N[20],const int B,const int R);
	bool remove(char *N,int &B);
	void setStart();
	void setEnd();
	void prev();
	void next();
	int leftLength()const;
	int rightLength()const;
	bool gerValue(char *N,int &B,int &R)const;
};

//对替补客户的信息的操作的类
class PWList
{
private:
	void init();
public:
	PsgWait *head;
	PsgWait *tail;
	PsgWait *fence;
	int leftcnt;
	int rightcnt;
	int Fli;                                    //记录航班号
	PWList(int size=10);
	void clear();
	bool insert(char N[20],const int D);
	bool append(char N[20],const int D);
	bool remove(char *N);
	void setStart();
	void setEnd();
	void prev();
	bool next();
	int leftLength()const;
	int rightLength()const;
	bool gerValue(char *N,int &D)const;
};



void ShowAllFlight(FlightNode *F);
void ShowOneFlight(FlightNode *F);
void BookTicket(FlightNode *F,POList *B,PWList *R) ;
void ReturnTicket(FlightNode *F,POList *B,PWList *R);

#endif