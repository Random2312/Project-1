#include "header file.h"

int main()
{
	int select;
	//����ͨѶ¼�ṹ�����
	Addressbooks abks;
	//��ʼ��ͨѶ¼����Ա����
	abks.m_Size = 0;

	while (true)
	{
		showMenu();//��ʾ�˵�

		cin >> select;

		switch (select)
		{
		case 1://�����ϵ��
			addPerson(&abks);//��ַ����
			break;

		case 2://��ʾ��ϵ��
			showPerson(abks);
			break;

		case 3://ɾ����ϵ��
			deletPersom(&abks);
			break;

		case 4://������ϵ��
			findPerson(&abks);
			break;

		case 5://�޸���ϵ��
			modifiPerson(&abks);
			break;

		case 6://�����ϵ��
			cleanPerson(&abks);
			break;

		case 0:	//�˳�
			cout << "��ӭ�´�ʹ��!" << endl;
			system("pause");
			return 0;
			break;

		default:
			cout << "��������!" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	return 0;
}