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
//2.�ڽĳ�尡 �Ѵپ��°��, �����ʸ��ִ°��, ���ʸ� �ִ°��, �Ѵ��ִ°�� �� 4���� ���� �������.

//�����ҳ���� �ּҸ� ã���Լ�
Tree** SearchDeleteNode_Point(Tree **T, int Data)
{
	if ((*T)->m_iData == Data)
		return T;

	else if ((*T)->m_iData > Data)
		return SearchDeleteNode_Point(&(*T)->Left, Data);
	else
		return SearchDeleteNode_Point(&(*T)->Right, Data);
}

//���ΰ����ó���� �ּҸ� ã���Լ�
Tree** SearchUpGradeNode_Point(Tree **T)
{
	//�������� Right ��带 ������ Right����� �ڽ��� �ֿ��� Leaf ��带 �������ڴ�.
	if ((*T)->Left == NULL)
		return T;
	else
		return SearchUpGradeNode_Point(&(*T)->Left);
}

//�����ͼ��û���1
void DeleteData(Tree **T, int Data)
{
	if (*T == NULL)
	{
		cout << "����� ��������" << endl;
		return;
	}
	Tree **DeleteNode_Point = SearchDeleteNode_Point(T, Data);
	Tree *DeleteNode = (*DeleteNode_Point);
	
	//�����忡 �ڽĳ�尡 ���°��
	if (DeleteNode->Left == NULL && DeleteNode->Right == NULL)
	{
		(*DeleteNode_Point) = NULL;
	}
	//�������� �����ڽĳ�常 �ִ� ���
	else if (DeleteNode->Left == NULL && DeleteNode->Right != NULL)
	{
		(*DeleteNode_Point) = DeleteNode->Right;
	}
	//�������� ���� �ڽĳ�常 �ִ� ���
	else if (DeleteNode->Left != NULL && DeleteNode->Right == NULL)
	{
		(*DeleteNode_Point) = DeleteNode->Left;
	}
	//�������� �¿��� �Ѵ� �ڽĳ�尡 �ִ� ���
	else
	{
		Tree **UpGradeNode_Point = SearchUpGradeNode_Point(&(DeleteNode)->Right);
		Tree *UpGradeNode = (*UpGradeNode_Point);

		if (UpGradeNode->Right == NULL)
		{
			(*UpGradeNode_Point) = NULL;
		}
		else
		{
			(*UpGradeNode_Point) = UpGradeNode->Right;
		}
		(*DeleteNode_Point) = UpGradeNode;
		(*DeleteNode_Point)->Left = DeleteNode->Left;
		(*DeleteNode_Point)->Right = DeleteNode->Right;

	}
	delete DeleteNode;
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
			DeleteData(&pPractice, iData);
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