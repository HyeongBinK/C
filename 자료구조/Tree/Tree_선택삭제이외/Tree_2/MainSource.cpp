#include "Header.h"

//트리구조체
struct Tree
{
	int m_iData;
	Tree* Left = NULL; //처음입력받은 데이터보다 작을떄
	Tree* Right = NULL; //처음입력받은 데이터보다 클떄

};

//시작메뉴
void Menu()
{
	cout << "1.Data 추가" << endl;
	cout << "2.Data 삭제" << endl;
	cout << "3.PreOrder(전위 순회)" << endl;
	cout << "4.InOrder(중위 순회)" << endl;
	cout << "5.PostOrder(후위 순회)" << endl;
	cout << "6.Data 검색" << endl;
	cout << "7.데이터전체삭제" << endl; //전체 동적할당해제후 다시 NULL로
	cout << "8.종료" << endl;
	cout << "입력 : ";
}

//데이터입력
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
		cout << "입력하신 " << Data << " 존재 합니다" << endl;
		return;
	}
}

//데이터선택삭제
void DeleteData()
{

}

//동적할당전체해제 후위순회 응용
void DeleteAll(Tree **T)
{
	if (*T == NULL)
	{
		cout << "저장된 정보없음" << endl;
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

//PreOrder(전위순회)
void ShowPreOrder(Tree *T)
{
	if (T == NULL)
	{
		cout << "저장된 Data가 없습니다" << endl;
		return;
	}

	cout << T->m_iData << " ";

	if (T->Left != NULL)
		ShowPreOrder(T->Left);
	
	if (T->Right != NULL)
		ShowPreOrder(T->Right);

}

//InOrder(중위순회)
void ShowInOrder(Tree *T)
{
	if (T == NULL)
	{
		cout << "저장된 Data가 없습니다" << endl;
		return;
	}

	if (T->Left != NULL)
	ShowInOrder(T->Left);
	
	cout << T->m_iData << " ";
	
	if (T->Right != NULL)
		ShowInOrder(T->Right);
}

//PostOrder(후위순회)
void ShowPostOrder(Tree *T)
{
	if (T == NULL)
	{
		cout << "저장된 Data가 없습니다" << endl;
		return;
	}

	if (T->Left != NULL)
		ShowPostOrder(T->Left);
	if (T->Right != NULL)
		ShowPostOrder(T->Right);
	
	cout << T->m_iData << " ";
}

//데이터검색
void SearchData(Tree *T, int Data)
{
	if (T == NULL)
	{
		cout << "저장된 Data가 없습니다" << endl;
		return;
	}

	if (T->m_iData == Data)
	{
		cout << Data << "는 존재합니다!" << endl;
		return;
	}
	else if (T->m_iData > Data)
		SearchData(T->Left, Data);
	else
		SearchData(T->Right, Data);
}

//메인함수
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
			cout << "Data 입력 : ";
			cin >> iData;
			InsertData(&pPractice, iData);
			break;
		case 2:
			cout << "현재 미구현된 기능(함수)입니다" << endl;
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
			cout << "검색할 Data 입력 : ";
			cin >> iData;
			SearchData(pPractice, iData);
			system("pause");
			break;
		case 7: //전체동적할당해제 되는과정을 직접보기위해 일부러만듬.
			DeleteAll(&pPractice);
			pPractice = NULL;
			cout << "전체 정보 삭제 완료" << endl;
			system("pause");
			break;
		case 8:
			DeleteAll(&pPractice);
			return;
		}
	}
}