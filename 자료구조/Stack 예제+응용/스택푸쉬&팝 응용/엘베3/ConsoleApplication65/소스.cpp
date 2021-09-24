#include "�ҽ�.h"

#define MAXKG 1000
#define MAXFLOOR 63
#define MAXPEOPLE 10
#define MAXPEOPLEPLUSKG 100
#define MINPEOPLEKG 40

struct People
{
	string m_str_Name;
	int m_i_Weight;
	int m_i_RideNumber;
	People* NextPeople;
};

struct Elevator
{
	int m_i_MaxFloor = MAXFLOOR;
	int m_i_MaxKG = MAXKG;
	int m_i_MaxPeople = MAXPEOPLE;
};

void RideOn(People** P, int *RideNumber, int *NowKG)
{
	cout << "����� �Ѹ� ž���ߴ�" << endl;
	People* newPeople = new People;
	newPeople->m_i_RideNumber = *RideNumber + 1;
	cout << "�°� �̸��Է�: ";
	cin >> newPeople->m_str_Name;
	int RNum = (rand() % MAXPEOPLEPLUSKG) + MINPEOPLEKG;
	newPeople->m_i_Weight = RNum;
	*NowKG += newPeople->m_i_Weight;
	*RideNumber+=1;
	newPeople->NextPeople = *P;
	*P = newPeople;
}

void RideOff(People** P, int *RideNumber, int *NowKG)
{
	if (*P == NULL)
		return;

	People* tmp;
	tmp = *P;
	*P = tmp->NextPeople;

	cout << "�̸�: " << tmp->m_str_Name << " KG : " << tmp->m_i_Weight << "����" << endl;


	*NowKG -= tmp->m_i_Weight;
	*RideNumber -= 1;
	delete tmp;
}

void Menu()
{
	cout << "===����������===" << endl;
	cout << "1.���������Ϳ���" << endl;
	cout << "2.�������� ź�°� ������" << endl;
	cout << "3.����������ž���ο� ��ȸ" << endl;
	cout << "4.���������� ����" << endl;
	cout << "5.����" << endl;
	cout << "�Է� : ";

}

void GetName(People** P)
{
	People* tmp;
	tmp = *P;
	*P = tmp->NextPeople;

	cout << tmp->m_i_RideNumber << "���� �°� �̸� : " << tmp->m_str_Name << " �� ������ :" << tmp->m_i_Weight << endl;
	if (*P == NULL)
		return;
	else
	GetName(P);

	if(*P!= NULL)
	delete tmp;
}

void main()
{
	Elevator E1;
	People* P = NULL, *Dummy;
	int i_Number = 0;
	int i_NowKG = 0;
	int i_Floor = 1;
	int i_Select = 0;
	
	srand((unsigned)time(NULL));
	
	while (i_Select != 5)
	{
		system("cls");

		Menu();
		cin >> i_Select;

		switch (i_Select)
		{
		case 1:
			while (1)
			{
				system("cls");
				cout << "���������� ������[" << i_Floor << "��]" << endl;
				cout << "����ž���ο� : " << i_Number << " ���� �°� ���չ��� :" << i_NowKG << endl;
				
				if (i_Floor == E1.m_i_MaxFloor)
				{
					cout << "�ִ������� �����Ͽ����ϴ�. �°����� �����ֽñ�ٶ��ϴ�" << endl;
					system("pause");
					break;
				}

				if (i_Number > E1.m_i_MaxPeople || i_NowKG >= E1.m_i_MaxKG)
				{
					if (i_NowKG >= E1.m_i_MaxKG)
						cout << "�ִ���밡�� ���� �ʰ�" << endl;
					else
					{
						cout << "���������ͳ� ������ �����Ͽ� �°��� Ż������" << endl;
						//RideOff(&P, &i_Number, &i_NowKG);
					}
					system("pause");
					break;
				}

				int RNum = (rand() % 2) + 1;
				if (RNum == 1)
					RideOn(&P, &i_Number, &i_NowKG);

				i_Floor++;
				//���������� ����ӵ�
				//Sleep(1000);
			}
			break;

		case 2:
			RideOff(&P, &i_Number, &i_NowKG);
			break;

		case 3:
			if (i_Number != 0)
			{
				Dummy = P;
				cout << "����ž���ο� :" << i_Number << " " << "����ž���ο� ���� ���� :" << i_NowKG << endl;
				GetName(&Dummy);
				system("pause");
			}
			break;

		case 4:
			while (i_Number != 0)
			{
				RideOff(&P, &i_Number, &i_NowKG);
			}
		
			i_Floor = 1;
			//system("pause");

			break;
		case 5:
			while (i_Number != 0)
			{
				RideOff(&P, &i_Number, &i_NowKG);
			}
			return;
		}
	}

}
