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
	if (*T == NULL)
	{
		*T = new Tree;
		(*T)->m_iData = Data;
		return;
	}

	if (Data > (*T)->m_iData)
		InsertData(&(*T)->Right, Data);
	else if (Data < (*T)->m_iData)
		InsertData(&(*T)->Left, Data);
	else
	{
		cout << "�Է��Ͻ� " << Data << " ���� �մϴ�" << endl;
		return;
	}
}

//�������� 
//1.��ɺи�
//2.�ڽĳ�尡 �Ѵپ��°��, �����ʸ��ִ°��, ���ʸ� �ִ°��, �Ѵ��ִ°�� �� 4��.

//�����Ͱ��� ������ �����ҳ�带 ã���Լ�
Tree* SearchDeleteNode(Tree *T, int Data)
{
	if (T->m_iData == Data)
	{
		return T;
	}
	else if (T->m_iData > Data)
		 return SearchDeleteNode(T->Left, Data);
	else
		 return SearchDeleteNode(T->Right, Data);
}


//�����ҳ�忡 ������ �������ΰ��� �ֿ��� leaf���  or �������ΰ��� ������ leaf��� ã�� �Լ�

//�����ҳ���� �θ� ��带 ã���Լ�
Tree** SearchDeleteNode_Point(Tree **T1, int Data)
{
	if ((*T1)->m_iData == Data)
		return T1;

	else if ((*T1)->m_iData > Data)
		return SearchDeleteNode_Point(&(*T1)->Left, Data);
	else
		return SearchDeleteNode_Point(&(*T1)->Right, Data);
}

//�����ͼ��û���1
void DeleteData1(Tree **T, int Data)
{
	if (*T == NULL)
	{
		cout << "����� ��������" << endl;
		return;
	}
	Tree **DeleteNode_Parent = SearchDeleteNode_Point(T, Data);
	Tree *DeleteNode = (*DeleteNode_Parent);


	//�����忡 �ڽĳ�尡 ���°��
	if ((*DeleteNode_Parent)->Left == NULL && (*DeleteNode_Parent)->Right == NULL)
	{
		(*DeleteNode_Parent) = NULL;
	}
	//�������� �����ڽĳ�常 �ִ°��
	else if (DeleteNode->Left == NULL && DeleteNode->Right != NULL)
	{
		(*DeleteNode_Parent) = DeleteNode->Right;
	}
	//�������� �����ڽĳ�常 �ִ°��
	else if (DeleteNode->Left != NULL && DeleteNode->Right == NULL)
	{
		(*DeleteNode_Parent) = DeleteNode->Left;
	}
	//�������� �¿����Ѵ��ڽĳ�尡�ִ°��
	else
	{
		(*DeleteNode_Parent)
		return;
	}
}

//�����Ҵ���ü���� ������ȸ ����
void DeleteAll(Tree **T)
{
	if (*T == NULL)
	{
		cout << "����� ��������" << endl;
		return;
	}

	if ((*T)->Left != NULL)
		DeleteAll(&(*T)->Left);
	if ((*T)->Right != NULL)
		DeleteAll(&(*T)->Right);

	delete (*T);
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

//�������� ��������
void SearchDataOX(Tree *T, int Data)
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
		SearchDataOX(T->Left, Data);
	else
		SearchDataOX(T->Right, Data);
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
			cout << "������ ������ �Է� : " << endl;
			cin >> iData;
			DeleteData1(&pPractice, iData);
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
			SearchDataOX(pPractice, iData);
			system("pause");
			break;
		case 7: //�Ѳ����� ������ ����±��(���Ƿ� ����)
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