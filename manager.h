#pragma once
#include<iostream>
#include<string>
#include"worker.h"
using namespace std;

class Manager:public Worker
{
public:
	//���캯��
	Manager(int id, string name, int did);
	//��ʾ������Ϣ
	virtual void ShowInfo();
	//��ȡ��λ����
	virtual string getDeptName();


};