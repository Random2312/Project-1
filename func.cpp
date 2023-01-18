#include "header file.h"


//�˵�����
void showMenu()
{
	cout << "*-----------------------------*" << endl;
	cout << "*-----|  1�������ϵ��  |-----*" << endl;
	cout << "*-----|  2����ʾ��ϵ��  |-----*" << endl;
	cout << "*-----|  3��ɾ����ϵ��  |-----*" << endl;
	cout << "*-----|  4��������ϵ��  |-----*" << endl;
	cout << "*-----|  5���޸���ϵ��  |-----*" << endl;
	cout << "*-----|  6�������ϵ��  |-----*" << endl;
	cout << "*-----|  0���˳�ϵͳ    |-----*" << endl;
	cout << "*-----------------------------*" << endl;
}



//�����ϵ��
void addPerson(Addressbooks* abs)
{
	//�ж���ϵ���Ƿ����������˾Ͳ����
	if (abs->m_Size == MAX)
	{
		cout << "������ӣ�ͨѶ¼����!" << endl;
		return;
	}
	else
	{
		//�����ϵ��

		//��������
		string name;
		cout << "������������" << endl;
		cin >> name;

		abs->personArray[abs->m_Size].m_Name = name;

		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;

		int sex;

		while (true)
		{
			//�������1��2�˳�ѭ�����������ִ��ѭ��
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "�����������������룺" << endl;
		}

		//����
		cout << "���������䣺" << endl;

		int age;

		while (true)
		{

			cin >> age;
			if (age > 0 && age < 150)
			{
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			cout << "�����������������룺" << endl;
		}

		//�绰
		string phone;

		cout << "��������ϵ�绰;" << endl;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//��ͥ��ַ
		string addrese;

		cout << "�������ͥסַ��" << endl;
		cin >> addrese;
		abs->personArray[abs->m_Size].m_Addr = addrese;

		//����ͨѶ¼����
		abs->m_Size++;

		cout << "\n��ӳɹ�!" << endl;

		//�������������������
		system("pause");
		system("cls");
	}
}


//��ʾ��ϵ��
void showPerson(struct Addressbooks abs)
{

	if (abs.m_Size == 0)
	{
		cout << "����ͨѶ¼Ϊ��!" << endl;
	}
	else
	{

		string sex;

		cout << "����" << abs.m_Size << "λ��ϵ��" << endl;
		for (int i = 0; i < abs.m_Size; i++)
		{
			//��ʾ
			cout << i + 1 << "---->";
			cout << " ����:" << abs.personArray[i].m_Name <<
				"  �Ա�:" << (abs.personArray[i].m_Sex == 1 ? "��" : "Ů") <<	//���Ա����ָ�Ϊ����
				"  ����:" << abs.personArray[i].m_Age <<
				"  �绰:" << abs.personArray[i].m_Phone <<
				"  ��ͥסַ:" << abs.personArray[i].m_Addr <<
				endl;
		}
	}
	system("pause");
	system("cls");
}

//�����ϵ���Ƿ���ڣ����ڷ����������о���λ�ã������ڷ���-1
int isExist(Addressbooks* abs, string name)
{
	//����
	for (int i = 0; i < abs->m_Size; i++)
	{
		//�ҵ��û����������
		if (abs->personArray[i].m_Name == name)
		{
			return i;	//���� ���������еı��
		}
	}
	return -1;//������ ����-1
}

//ɾ����ϵ��
void deletPersom(Addressbooks* abs)
{
	string name;
	cout << "������Ҫɾ������ϵ��������" << endl;
	cin >> name;

	int flag = isExist(abs, name);

	if (flag == -1)
	{
		cout << "��ϵ�˲����ڣ�" << endl;
	}
	else
	{
		//ɾ���� ����ϵ���±������Ԫ��ǰ��
		for (int i = flag; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
			//��ͨѶ¼��������
			abs->m_Size--;
		}
		cout << "ɾ���ɹ�!" << endl;
	}
	system("pause");
	system("cls");
}

//������ϵ��
void findPerson(Addressbooks* abs)
{
	string name;

	cout << "����Ҫ���ҵ���ϵ��" << endl;
	cin >> name;

	//�ж�ָ������ϵ���Ƿ����
	int flag = isExist(abs, name);

	if (flag != -1)//�ҵ���ϵ��
	{
		cout << "���ҽ��:" << endl;

		cout << " ����:" << abs->personArray[flag].m_Name <<
			"  �Ա�:" << (abs->personArray[flag].m_Sex == 1 ? "��" : "Ů") <<	//���Ա����ָ�Ϊ����
			"  ����:" << abs->personArray[flag].m_Age <<
			"  �绰:" << abs->personArray[flag].m_Phone <<
			"  ��ͥסַ:" << abs->personArray[flag].m_Addr <<
			endl;
	}
	else
	{
		cout << "δ�ҵ�����ϵ��!" << endl;
	}

	system("pause");
	system("cls");
}

//�޸���ϵ��
void modifiPerson(Addressbooks* abs)
{
	string name;
	cout << "������Ҫ�޸ĵ���ϵ��������" << endl;

	cin >> name;

	//�ж���ϵ���Ƿ����
	int flag = isExist(abs, name);

	if (flag != -1)//�ҵ���ϵ��
	{
		cout << "���ҽ��:" << endl;

		cout << " ����:" << abs->personArray[flag].m_Name <<
			"  �Ա�:" << (abs->personArray[flag].m_Sex == 1 ? "��" : "Ů") <<	//���Ա����ָ�Ϊ����
			"  ����:" << abs->personArray[flag].m_Age <<
			"  �绰:" << abs->personArray[flag].m_Phone <<
			"  ��ͥסַ:" << abs->personArray[flag].m_Addr <<
			endl;

		cout << "�����޸�����:" << endl;
		cout << " ����:" << endl;
		cin >> abs->personArray[flag].m_Name;

		cout << " �Ա�:" << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		cin >> abs->personArray[flag].m_Sex;

		cout << " ����:" << endl;
		cin >> abs->personArray[flag].m_Age;

		cout << " �绰:" << endl;
		cin >> abs->personArray[flag].m_Phone;

		cout << " ��ͥסַ:" << endl;
		cin >> abs->personArray[flag].m_Addr;

		cout << "�޸ĳɹ�!";
	}
	else
	{
		cout << "δ�ҵ�����ϵ��!" << endl;
	}

	system("pause");
	system("cls");
}

//�����ϵ��
void cleanPerson(Addressbooks* abs)
{
	//���������㼴��
	abs->m_Size = 0;

	cout << "��������������ȷ�����" << endl;

	//������������û�����
	srand((unsigned int)time(NULL));
	int flag, num = rand() % 100 + 1;

	cout << "��֤:" << num << endl;
	cin >> flag;

	cout << (flag != num ? "���ʧ�ܣ�" : "��ճɹ���") << endl;

	system("pause");
	system("cls");
}
