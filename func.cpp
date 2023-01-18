#include "header file.h"


//菜单界面
void showMenu()
{
	cout << "*-----------------------------*" << endl;
	cout << "*-----|  1、添加联系人  |-----*" << endl;
	cout << "*-----|  2、显示联系人  |-----*" << endl;
	cout << "*-----|  3、删除联系人  |-----*" << endl;
	cout << "*-----|  4、查找联系人  |-----*" << endl;
	cout << "*-----|  5、修改联系人  |-----*" << endl;
	cout << "*-----|  6、清空联系人  |-----*" << endl;
	cout << "*-----|  0，退出系统    |-----*" << endl;
	cout << "*-----------------------------*" << endl;
}



//添加联系人
void addPerson(Addressbooks* abs)
{
	//判断联系人是否已满，满了就不添加
	if (abs->m_Size == MAX)
	{
		cout << "不可添加，通讯录已满!" << endl;
		return;
	}
	else
	{
		//添加联系人

		//插入姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;

		abs->personArray[abs->m_Size].m_Name = name;

		//性别
		cout << "请输入性别：" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;

		int sex;

		while (true)
		{
			//输入的是1或2退出循环，错误继续执行循环
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入：" << endl;
		}

		//年龄
		cout << "请输入年龄：" << endl;

		int age;

		while (true)
		{

			cin >> age;
			if (age > 0 && age < 150)
			{
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			cout << "输入有误，请重新输入：" << endl;
		}

		//电话
		string phone;

		cout << "请输入联系电话;" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//家庭地址
		string addrese;

		cout << "请输入家庭住址：" << endl;
		cin >> addrese;
		abs->personArray[abs->m_Size].m_Addr = addrese;

		//更新通讯录人数
		abs->m_Size++;

		cout << "\n添加成功!" << endl;

		//按任意键继续（清屏）
		system("pause");
		system("cls");
	}
}


//显示联系人
void showPerson(struct Addressbooks abs)
{

	if (abs.m_Size == 0)
	{
		cout << "您的通讯录为空!" << endl;
	}
	else
	{

		string sex;

		cout << "共有" << abs.m_Size << "位联系人" << endl;
		for (int i = 0; i < abs.m_Size; i++)
		{
			//显示
			cout << i + 1 << "---->";
			cout << " 姓名:" << abs.personArray[i].m_Name <<
				"  性别:" << (abs.personArray[i].m_Sex == 1 ? "男" : "女") <<	//将性别数字改为汉字
				"  年龄:" << abs.personArray[i].m_Age <<
				"  电话:" << abs.personArray[i].m_Phone <<
				"  家庭住址:" << abs.personArray[i].m_Addr <<
				endl;
		}
	}
	system("pause");
	system("cls");
}

//检测联系人是否存在，存在返回在数组中具体位置，不存在返回-1
int isExist(Addressbooks* abs, string name)
{
	//遍历
	for (int i = 0; i < abs->m_Size; i++)
	{
		//找到用户输入的姓名
		if (abs->personArray[i].m_Name == name)
		{
			return i;	//存在 返回数组中的编号
		}
	}
	return -1;//不存在 返回-1
}

//删除联系人
void deletPersom(Addressbooks* abs)
{
	string name;
	cout << "请输入要删除的联系人姓名：" << endl;
	cin >> name;

	int flag = isExist(abs, name);

	if (flag == -1)
	{
		cout << "联系人不存在！" << endl;
	}
	else
	{
		//删除： 此联系人下标后所有元素前移
		for (int i = flag; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
			//将通讯录人数更正
			abs->m_Size--;
		}
		cout << "删除成功!" << endl;
	}
	system("pause");
	system("cls");
}

//查找联系人
void findPerson(Addressbooks* abs)
{
	string name;

	cout << "输入要查找的联系人" << endl;
	cin >> name;

	//判断指定的联系人是否存在
	int flag = isExist(abs, name);

	if (flag != -1)//找到联系人
	{
		cout << "查找结果:" << endl;

		cout << " 姓名:" << abs->personArray[flag].m_Name <<
			"  性别:" << (abs->personArray[flag].m_Sex == 1 ? "男" : "女") <<	//将性别数字改为汉字
			"  年龄:" << abs->personArray[flag].m_Age <<
			"  电话:" << abs->personArray[flag].m_Phone <<
			"  家庭住址:" << abs->personArray[flag].m_Addr <<
			endl;
	}
	else
	{
		cout << "未找到该联系人!" << endl;
	}

	system("pause");
	system("cls");
}

//修改联系人
void modifiPerson(Addressbooks* abs)
{
	string name;
	cout << "输入需要修改的联系人姓名：" << endl;

	cin >> name;

	//判断联系人是否存在
	int flag = isExist(abs, name);

	if (flag != -1)//找到联系人
	{
		cout << "查找结果:" << endl;

		cout << " 姓名:" << abs->personArray[flag].m_Name <<
			"  性别:" << (abs->personArray[flag].m_Sex == 1 ? "男" : "女") <<	//将性别数字改为汉字
			"  年龄:" << abs->personArray[flag].m_Age <<
			"  电话:" << abs->personArray[flag].m_Phone <<
			"  家庭住址:" << abs->personArray[flag].m_Addr <<
			endl;

		cout << "输入修改数据:" << endl;
		cout << " 姓名:" << endl;
		cin >> abs->personArray[flag].m_Name;

		cout << " 性别:" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		cin >> abs->personArray[flag].m_Sex;

		cout << " 年龄:" << endl;
		cin >> abs->personArray[flag].m_Age;

		cout << " 电话:" << endl;
		cin >> abs->personArray[flag].m_Phone;

		cout << " 家庭住址:" << endl;
		cin >> abs->personArray[flag].m_Addr;

		cout << "修改成功!";
	}
	else
	{
		cout << "未找到此联系人!" << endl;
	}

	system("pause");
	system("cls");
}

//清空联系人
void cleanPerson(Addressbooks* abs)
{
	//将人数清零即可
	abs->m_Size = 0;

	cout << "请输入下列数字确认清空" << endl;

	//生成随机数供用户输入
	srand((unsigned int)time(NULL));
	int flag, num = rand() % 100 + 1;

	cout << "验证:" << num << endl;
	cin >> flag;

	cout << (flag != num ? "清空失败！" : "清空成功！") << endl;

	system("pause");
	system("cls");
}
