#pragma once
#include <iostream>
using namespace std;

#include <string.h>
#include <windows.h>

//ͨѶ¼�������
#define MAX 1000

struct Person	//��ϵ��
{
	string m_Name;	//����
	int m_Sex;	//�Ա�
	int m_Age;	//����
	string m_Phone;	//�绰
	string m_Addr;	//סַ
};

struct Addressbooks	//ͨѶ¼
{
	struct Person personArray[MAX];	//��ϵ��
	int m_Size;//��ϵ������
};

//�˵�����
void showMenu(void);

//�����ϵ��
void addPerson(Addressbooks* abs);

//��ʾ��ϵ��
void showPerson(struct Addressbooks abs);

//�����ϵ���Ƿ���ڣ����ڷ����������о���λ�ã������ڷ���-1
int isExist(Addressbooks* abs, string name);

//ɾ����ϵ��
void deletPersom(Addressbooks* abs);

//������ϵ��
void findPerson(Addressbooks* abs);

//�޸���ϵ��
void modifiPerson(Addressbooks* abs);

//�����ϵ��
void cleanPerson(Addressbooks* abs);

