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
		cout << "입력하신 " << Data << " 존재 합니다" << endl;
		return;
	}
}

//지적사항 
//1.기능분리
//2.자식노드가 둘다없는경우, 오른쪽만있는경우, 왼쪽만 있는경우, 둘다있는경우 총 4개의 경우로 나누어라.

//삭제할노드의 주소를 찾는함수
Tree** SearchDeleteNode_Point(Tree **T, int Data)
{
	if ((*T)->m_iData == Data)
		return T;

	else if ((*T)->m_iData > Data)
		return SearchDeleteNode_Point(&(*T)->Left, Data);
	else
		return SearchDeleteNode_Point(&(*T)->Right, Data);
}

//새로가져올노드의 주소를 찾는함수
Tree** SearchUpGradeNode_Point(Tree **T)
{
	//본문에서 Right 노드를 보내어 Right노드의 자식중 최우측 Leaf 노드를 가져오겠다.
	if ((*T)->Left == NULL)
		return T;
	else
		return SearchUpGradeNode_Point(&(*T)->Left);
}

//데이터선택삭제1
void DeleteData(Tree **T, int Data)
{
	if (*T == NULL)
	{
		cout << "저장된 정보없음" << endl;
		return;
	}
	Tree **DeleteNode_Point = SearchDeleteNode_Point(T, Data);
	Tree *DeleteNode = (*DeleteNode_Point);
	
	//지울노드에 자식노드가 없는경우
	if (DeleteNode->Left == NULL && DeleteNode->Right == NULL)
	{
		(*DeleteNode_Point) = NULL;
	}
	//지울노드의 좌측자식노드만 있는 경우
	else if (DeleteNode->Left == NULL && DeleteNode->Right != NULL)
	{
		(*DeleteNode_Point) = DeleteNode->Right;
	}
	//지울노드의 우측 자식노드만 있는 경우
	else if (DeleteNode->Left != NULL && DeleteNode->Right == NULL)
	{
		(*DeleteNode_Point) = DeleteNode->Left;
	}
	//지울노드의 좌우측 둘다 자식노드가 있는 경우
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

//동적할당전체해제 후위순회 응용
void DeleteAll(Tree **T)
{
	if (*T == NULL)
	{
		cout << "저장된 정보없음" << endl;
		return;
	}

	if ((*T)->Left != NULL)
		DeleteAll(&(*T)->Left);
	if ((*T)->Right != NULL)
		DeleteAll(&(*T)->Right);

	delete (*T);
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

//데이터의 존재유무
void SearchDataOX(Tree *T, int Data)
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
		SearchDataOX(T->Left, Data);
	else
		SearchDataOX(T->Right, Data);
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
			cout << "삭제할 데이터 입력 : " << endl;
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
			cout << "검색할 Data 입력 : ";
			cin >> iData;
			SearchDataOX(pPractice, iData);
			system("pause");
			break;
		case 7: //한꺼번에 데이터 지우는기능(임의로 만듬)
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