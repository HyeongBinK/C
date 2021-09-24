#include "Çì´õ.h";

#define MAXSERIALNUMBER 100000

struct TAILGOMTANG
{
	// int m_i_ExpirationDate; //À¯Åë±âÇÑ
	int m_i_SerialNumber; //°íÀ¯¹øÈ£
	int m_i_InputNumber; //µé¾î¿Â¼ø¼­;
	TAILGOMTANG* NEXT;
};

void Menu(int TailGomTang)
{
	system("cls");

	cout << "====STARTMENU====" << endl;
	cout << "²¿¸®°õÅÁº¸À¯ÇöÈ² : " << TailGomTang << "ÀÏÄ¡" << endl;
	cout << "1.²¿¸®°õÅÁÇÏ·çÄ¡ÁÖ¹®" << endl;
	cout << "2.²¿¸®°õÅÁÇÏ·çÄ¡¼Ò¸ð" << endl;
	cout << "3.²¿¸®°õÅÁ°üÂû" << endl; //²¿¸®°õÅÁ ½Ã¸®¾óÄÚµåÈ®ÀÎ°¡´É
	cout << "4.²¿¸®°õÅÁÀü·®¼Ò¸ð" << endl;
	cout << "5.Á¾·á" << endl;
	cout << "ÀÔ·Â : ";
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

	cout << "µé¾î¿Â ¼ø¼­ : " << tmp->m_i_InputNumber << " °íÀ¯¹øÈ£ : " << tmp->m_i_SerialNumber << endl;
	
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
	int i_TailGomTang = 0; // ²¿¸®°õÅÁ º¸À¯¼ýÀÚ
	int i_TailGomTangNUM = 0; //²¿¸®°õÅÁ µé¾î¿Â¼ýÀÚ 
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
			cout << "²¿¸®°õÅÁº¸À¯ÇöÈ² : " << i_TailGomTang << "ÀÏÄ¡" << endl;
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
