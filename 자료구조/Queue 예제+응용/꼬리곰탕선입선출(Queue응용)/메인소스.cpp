#include "���.h";

#define MAXSERIALNUMBER 100000

struct TAILGOMTANG
{
	// int m_i_ExpirationDate; //�������
	int m_i_SerialNumber; //������ȣ
	int m_i_InputNumber; //���¼���;
	TAILGOMTANG* NEXT;
};

void Menu(int TailGomTang)
{
	system("cls");

	cout << "====STARTMENU====" << endl;
	cout << "��������������Ȳ : " << TailGomTang << "��ġ" << endl;
	cout << "1.���������Ϸ�ġ�ֹ�" << endl;
	cout << "2.���������Ϸ�ġ�Ҹ�" << endl;
	cout << "3.������������" << endl; //�������� �ø����ڵ�Ȯ�ΰ���
	cout << "4.�������������Ҹ�" << endl;
	cout << "5.����" << endl;
	cout << "�Է� : ";
}

void Input(TAILGOMTANG **Start, TAILGOMTANG ** Last, int *TailGomTang, int*TailGomTangNum)
{
	TAILGOMTANG* NewTailGomTang = new TAILGOMTANG;

	if (*Start == NULL)
	{
		*Start = NewTailGomTang;
		*Last = NewTailGomTang;
	}

	if (*Start != NULL)
	{
		TAILGOMTANG *tmp;
		tmp = *Last;
		*Last = NewTailGomTang;
		tmp->NEXT = NewTailGomTang;
	}

	int RNum = (rand() % MAXSERIALNUMBER);
	NewTailGomTang->m_i_InputNumber = *TailGomTangNum+1;
	NewTailGomTang->m_i_SerialNumber = RNum;
	(*TailGomTang)++;
	(*TailGomTangNum)++;
}

void output(TAILGOMTANG **Start, int *TailGomTang)
{
	if (*Start == NULL)
		return;
	TAILGOMTANG*tmp;
	tmp = *Start;

	cout << tmp->m_i_InputNumber << endl;
	cout << tmp->m_i_SerialNumber << endl;
	*Start = tmp->NEXT;
	delete tmp;
	(*TailGomTang)--;

	if (*TailGomTang == 0)
		*Start = NULL;
}

void ShowTailGomTang(TAILGOMTANG **Start, int *TailGomTang)
{
	if (*Start == NULL)
		return;

	TAILGOMTANG* tmp;
	tmp = *Start;
	*Start = tmp->NEXT;

	cout << "���� ���� : " << tmp->m_i_InputNumber << " ������ȣ : " << tmp->m_i_SerialNumber << endl;
	
	if (*TailGomTang == 1)
	{
		return;
	}
	else
	{
		(*TailGomTang)--;
		ShowTailGomTang(Start, TailGomTang);
	}
	//if (*Start != NULL)
	//delete tmp;
}

void main()
{
	TAILGOMTANG *Start = NULL, *Last = NULL;
	TAILGOMTANG *DummyStart;
	srand((unsigned)time(NULL));
	int i_TailGomTang = 0; // �������� ��������
	int i_TailGomTangNUM = 0; //�������� ���¼��� 
	int i_Select;
	int DummyTailGomTang;

	while (1)
	{
		Menu(i_TailGomTang);
		cin >> i_Select;
		switch (i_Select)
		{
		case 1:
			Input(&Start, &Last, &i_TailGomTang, &i_TailGomTangNUM);
			break;
		case 2:
			output(&Start, &i_TailGomTang);
			break;
		case 3:
			DummyStart = Start;
			DummyTailGomTang = i_TailGomTang;
			cout << "��������������Ȳ : " << i_TailGomTang << "��ġ" << endl;
			ShowTailGomTang(&DummyStart, &DummyTailGomTang);
			system("pause");
			break;
		case 4:
			while (1)
			{
				output(&Start, &i_TailGomTang);
				if (i_TailGomTang == 0)
					break;
			}
			break;
		case 5:
			while (1)
			{
				output(&Start, &i_TailGomTang);
				if (i_TailGomTang == 0)
					break;
			}
			return;

		}
	}
}
