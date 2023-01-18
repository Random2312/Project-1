#include "header file.h"

int main()
{
	int select;
	//创建通讯录结构体变量
	Addressbooks abks;
	//初始化通讯录中人员个数
	abks.m_Size = 0;

	while (true)
	{
		showMenu();//显示菜单

		cin >> select;

		switch (select)
		{
		case 1://添加联系人
			addPerson(&abks);//地址传递
			break;

		case 2://显示联系人
			showPerson(abks);
			break;

		case 3://删除联系人
			deletPersom(&abks);
			break;

		case 4://查找联系人
			findPerson(&abks);
			break;

		case 5://修改联系人
			modifiPerson(&abks);
			break;

		case 6://清空联系人
			cleanPerson(&abks);
			break;

		case 0:	//退出
			cout << "欢迎下次使用!" << endl;
			system("pause");
			return 0;
			break;

		default:
			cout << "输入有误!" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	return 0;
}