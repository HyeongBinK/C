#include "Header.h"

//Ʈ������ü
struct Tree
{
	int m_iData;
	Tree* Left = NULL; //ó���Է¹��� �����ͺ��� ������
	Tree* Right = NULL; //ó���Է¹��� �����ͺ��� Ŭ��

};

//���۸޴�
void Menu()
{
	cout << "1.Data �߰�" << endl;
	cout << "2.Data ����" << endl;
	cout << "3.PreOrder(���� ��ȸ)" << endl;
	cout << "4.InOrder(���� ��ȸ)" << endl;
	cout << "5.PostOrder(���� ��ȸ)" << endl;
	cout << "6.Data �˻�" << endl;
	cout << "7.��������ü����" << endl; //��ü �����Ҵ������� �ٽ� NULL��
	cout << "8.����" << endl;
	cout << "�Է� : ";
}

//�������Է�
void InsertData(Tree **T, int Data)
{
	Tree* NewTree = new Tree;
	NewTree->m_iData = Data;

	if (*T == NULL)
	{
		*T = NewTree;
		return;
	}
	if (NewTree->m_iData > (*T)->m_iData)
		InsertData(&(*T)->Right, Data);
	else if (NewTree->m_iData < (*T)->m_iData)
		InsertData(&(*T)->Left, Data);
	else
	{
		cout << "�Է��Ͻ� " << Data << " ���� �մϴ�" << endl;
		return;
	}
}

//�����ͼ��û���
void DeleteData()
{

}

//�����Ҵ���ü���� ������ȸ ����
void DeleteAll(Tree **T)
{
	if (*T == NULL)
	{
		cout << "����� ��������" << endl;
		return;
	}
	Tree *tmp;
	tmp = *T;

	if (tmp->Left != NULL)
		DeleteAll(&tmp->Left);
	if (tmp->Right != NULL)
		DeleteAll(&tmp->Right);

	delete tmp;
}

//PreOrder(������ȸ)
void ShowPreOrder(Tree *T)
{
	if (T == NULL)
	{
		cout << "����� Data�� �����ϴ�" << endl;
		return;
	}

	cout << T->m_iData << " ";

	if (T->Left != NULL)
		ShowPreOrder(T->Left);
	
	if (T->Right != NULL)
		ShowPreOrder(T->Right);

}

//InOrder(������ȸ)
void ShowInOrder(Tree *T)
{
	if (T == NULL)
	{
		cout << "����� Data�� �����ϴ�" << endl;
		return;
	}

	if (T->Left != NULL)
	ShowInOrder(T->Left);
	
	cout << T->m_iData << " ";
	
	if (T->Right != NULL)
		ShowInOrder(T->Right);
}

//PostOrder(������ȸ)
void ShowPostOrder(Tree *T)
{
	if (T == NULL)
	{
		cout << "����� Data�� �����ϴ�" << endl;
		return;
	}

	if (T->Left != NULL)
		ShowPostOrder(T->Left);
	if (T->Right != NULL)
		ShowPostOrder(T->Right);
	
	cout << T->m_iData << " ";
}

//�����Ͱ˻�
void SearchData(Tree *T, int Data)
{
	if (T == NULL)
	{
		cout << "����� Data�� �����ϴ�" << endl;
		return;
	}

	if (T->m_iData == Data)
	{
		cout << Data << "�� �����մϴ�!" << endl;
		return;
	}
	else if (T->m_iData > Data)
		SearchData(T->Left, Data);
	else
		SearchData(T->Right, Data);
}

//�����Լ�
void main()
{
	Tree *pPractice = NULL;
	int iSelect;
	int iData;

	while (1)
	{
		system("cls");
		Menu();
		cin >> iSelect;
		cout << ">>>>>>>>>>>>>>" << endl;
		switch (iSelect)
		{
		case 1:
			cout << "Data �Է� : ";
			cin >> iData;
			InsertData(&pPractice, iData);
			break;
		case 2:
			cout << "���� �̱����� ���(�Լ�)�Դϴ�" << endl;
			//DeleteData();
			break;
		case 3:
			ShowPreOrder(pPractice);
			system("pause");
			break;
		case 4:
			ShowInOrder(pPractice);
			system("pause");
			break;
		case 5:
			ShowPostOrder(pPractice);
			system("pause");
			break;
		case 6:
			cout << "�˻��� Data �Է� : ";
			cin >> iData;
			SearchData(pPractice, iData);
			system("pause");
			break;
		case 7: //��ü�����Ҵ����� �Ǵ°����� ������������ �Ϻη�����.
			DeleteAll(&pPractice);
			pPractice = NULL;
			cout << "��ü ���� ���� �Ϸ�" << endl;
			system("pause");
			break;
		case 8:
			DeleteAll(&pPractice);
			return;
		}
	}
}