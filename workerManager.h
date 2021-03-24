#pragma once   //��ֹͷ�ļ��ظ�����
#include<iostream>  //�������������ͷ�ļ�
using namespace std;   //ʹ�ñ�׼�����ռ�
#include"worker.h"
#include<fstream>
#define FILENAME "empFile.txt"


class WorkerManager
{
public:
	//���캯��
	WorkerManager();
	//չʾ�˵�
	void Show_Menu();
	//�˳�ϵͳ
	void ExitSystem();
	//��������
	~WorkerManager();

	//���ӳ�Ա
	void Add_Emp();

	//��ʾ��Ա
	void Show_Emp();

	//�����ļ�
	void save();

	//��¼�ļ��е�����
	int m_EmpNum;

	//Ա�������ָ��
	Worker ** m_EmpArray;

	//�ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;

	//ͳ���ļ��е�ְ������
	int  get_EmpNum();

	//��ʼ��ְ��
	void init_Emp();

	//ɾ��ְ��
	void Del_Emp();
	//�ж�ְ���Ƿ���ڣ������ڣ��򷵻�����λ��,��֮����-1
	int IsExist(int id);

	//�޸�ְ��
	void Mod_Emp();

	//����ְ��
	void Find_Emp();

	//�����㷨
	void Sort_Emp();

	//����ļ�
	void Clean_File();

};