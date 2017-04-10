//对FlightInfo.h所有类中函数的实现

#include"FlightInfo.h"
#include<iostream>
using namespace std;


//PsgOn中的函数的实现
PsgOn::PsgOn(char N[20],const int B,const int R,PsgOn *Ne)
{    for(int i=0;i<=20;i++)
		{
			Name[i]=N[i];
		}
	Booknum=B;Rank=R;next=Ne;   
 }

PsgOn::PsgOn(PsgOn *Ne)
{  next=Ne;   }

//POList中的函数的实现
void POList::init()
{
	fence=tail=head=new PsgOn;
	leftcnt=rightcnt=0;
}


POList::POList(int size){       init();       }

bool POList::insert(char N[20],const int B,const int R)
{
	fence->next=new PsgOn(N,B,R,fence->next);
		if(tail==fence)tail=fence->next;
		rightcnt++;                               
		return true;
}

bool POList::append(char N[20],const int B,const int R)
{
	tail=tail->next=new PsgOn(N,B,R,NULL);
	rightcnt++;
	return true;
}

bool POList::remove(char *N,int &B)
{
	if(fence->next==NULL)return false;
	N=fence->next->Name;B=fence->next->Booknum;
	PsgOn *ltemp=fence->next;
	fence->next=ltemp->next;
	if(tail==ltemp)tail=fence;
	delete ltemp;
	rightcnt--;                                    //减去此人的订票额
	return true;
}

void POList::setStart()
{     fence=head;rightcnt+=leftcnt;leftcnt=0;}

void POList::setEnd()
{    fence=tail;leftcnt+=rightcnt;rightcnt=0;}

void POList::prev()
{
	PsgOn *temp=head;
	if(fence==head)return;
	while(temp->next!=fence)temp=temp->next;
	fence=temp;
	leftcnt--;rightcnt++;
}

void POList::next()
{
	if(fence!=tail)
		{fence=fence->next;rightcnt--;leftcnt++;}
}

int POList::leftLength()const
{return leftcnt;}

int POList::rightLength()const
{return rightcnt;}

bool POList::gerValue(char *N,int &B,int &R)const
{
	if(rightLength()==0)return false;
	N=fence->next->Name;B=fence->next->Booknum;R=fence->next->Rank;
	return true;
}

//PsgWait中的函数的实现
PsgWait::PsgWait(char N[20],const int D,PsgWait *Ne)
{         for(int i=0;i<=20;i++)
			{
				Name[i]=N[i];
			}
		Need=D;next=Ne;   
}

PsgWait::PsgWait(PsgWait *Ne)
{    next=Ne;    }

//PWList中的函数的实现
void PWList::init()
{
	fence=tail=head=new PsgWait;
	leftcnt=rightcnt=0;
}


PWList::PWList(int size){       init();       }


bool PWList::insert(char N[20],const int D)
{
	fence->next=new PsgWait(N,D,fence->next);
	if(tail==fence)tail=fence->next;
	rightcnt++;
	return true;
}

bool PWList::append(char N[20],const int D)
{
	tail=tail->next=new PsgWait(N,D,NULL);
	rightcnt++;
	return true;
}

bool PWList::remove(char *N)
{
	if(fence->next ==NULL)return false;
	N=fence->next->Name;
	PsgWait *ltemp=fence->next;
	fence->next=ltemp->next;
	if(tail==ltemp)tail=fence;
	delete ltemp;
	rightcnt--;
	return true;
}

void PWList::setStart()
{     fence=head;rightcnt+=leftcnt;leftcnt=0;}

void PWList::setEnd()
{    fence=tail;leftcnt+=rightcnt;rightcnt=0;}

void PWList::prev()
{
	PsgWait *temp=head;
	if(fence==head)return;
	while(temp->next!=fence)temp=temp->next;
	fence=temp;
	leftcnt--;rightcnt++;
}

bool PWList::next()
{
	if(fence!=tail)
	{fence=fence->next;leftcnt++;rightcnt--;return true;}
	else return false;
}

int PWList::leftLength()const
{     return leftcnt;}

int PWList::rightLength()const
{     return rightcnt;}

bool PWList::gerValue(char *N,int &D)const
{
	if(rightLength()==0)return false;
	N=fence->next->Name;D=fence->next->Need;
	return true;
}

FlightNode::FlightNode(char T[20],const int F,const int P,const int D,const int M,const int L)
{    for(int i=0;i<=20;i++)
		{
			Terminus[i]=T[i];
		}
Flight=F;Plane=P;Day=D;Maxnum=M;Left=L;  
}



