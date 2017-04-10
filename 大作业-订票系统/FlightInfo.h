#ifndef FLIGHTINFO_H
#define FLIGHTINFO_H
#include<iostream>
#include<string>

//��¼�Ѷ�Ʊ���ÿͼ���Ϣ
class PsgOn
{
public:
	char Name[20];                  //�ͻ�����
	int Booknum;                     //��Ʊ��
	int Rank;						//��λ�ȼ�
	PsgOn *next;
	PsgOn(char N[20],const int B,const int R,PsgOn *Ne=NULL);
	PsgOn(PsgOn *Ne=NULL);
};

//��¼�油�Ŀͻ�
class PsgWait
{
public:
	char Name[20];                      //�ͻ�����
	int Need;							//����Ʊ��
	PsgWait *next;
	PsgWait(char N[20],const int D,PsgWait *Ne=NULL);
	PsgWait(PsgWait *Ne=NULL);
};

//��¼������ÿ��������Ϣ����
class FlightNode
{
public:
	char Terminus[20];                //�յ�վ��
	int Flight;                     //�����       
	int Plane;                       //�ɻ���
	int Day;                          //������
	int Maxnum;                     //��Ա����
	int Left;                       //��Ʊ��
	FlightNode(char T[20]="",const int F=0,const int P=0,const int D=0,const int M=0,const int L=0);

};

//���Ѷ�Ʊ�Ŀͻ�����Ϣ�Ĳ�������
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
	int Fli;                                    //��¼�����
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

//���油�ͻ�����Ϣ�Ĳ�������
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
	int Fli;                                    //��¼�����
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