#pragma once
#include <iostream>
using namespace std;

#include <string.h>
#include <windows.h>

//通讯录最大人数
#define MAX 1000

struct Person	//联系人
{
	string m_Name;	//姓名
	int m_Sex;	//性别
	int m_Age;	//年龄
	string m_Phone;	//电话
	string m_Addr;	//住址
};

struct Addressbooks	//通讯录
{
	struct Person personArray[MAX];	//联系人
	int m_Size;//联系人人数
};

//菜单界面
void showMenu(void);

//添加联系人
void addPerson(Addressbooks* abs);

//显示联系人
void showPerson(struct Addressbooks abs);

//检测联系人是否存在，存在返回在数组中具体位置，不存在返回-1
int isExist(Addressbooks* abs, string name);

//删除联系人
void deletPersom(Addressbooks* abs);

//查找联系人
void findPerson(Addressbooks* abs);

//修改联系人
void modifiPerson(Addressbooks* abs);

//清空联系人
void cleanPerson(Addressbooks* abs);

