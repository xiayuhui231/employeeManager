#pragma once
#include<iostream>
#include<string>
#include"worker.h"
using namespace std;

class Employee:public Worker
{
public:
	//���캯��
	Employee(int id,string name,int did);

	//��ʾ������Ϣ
	virtual void ShowInfo();

	//��ȡ��λ����
	virtual string getDeptName();
	
};