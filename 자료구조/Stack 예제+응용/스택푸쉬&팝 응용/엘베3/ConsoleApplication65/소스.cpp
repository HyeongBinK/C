#include "소스.h"

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
	cout << "사람이 한명 탑승했다" << endl;
	People* newPeople = new People;
	newPeople->m_i_RideNumber = *RideNumber + 1;
	cout << "승객 이름입력: ";
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

	cout << "이름: " << tmp->m_str_Name << " KG : " << tmp->m_i_Weight << "내림" << endl;


	*NowKG -= tmp->m_i_Weight;
	*RideNumber -= 1;
	delete tmp;
}

void Menu()
{
	cout << "===엘리베이터===" << endl;
	cout << "1.엘리베이터운행" << endl;
	cout << "2.마지막에 탄승객 내리기" << endl;
	cout << "3.엘리베이터탑승인원 조회" << endl;
	cout << "4.엘리베이터 리셋" << endl;
	cout << "5.종료" << endl;
	cout << "입력 : ";

}

void GetName(People** P)
{
	People* tmp;
	tmp = *P;
	*P = tmp->NextPeople;

	cout << tmp->m_i_RideNumber << "번쨰 승객 이름 : " << tmp->m_str_Name << " 의 몸무게 :" << tmp->m_i_Weight << endl;
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
				cout << "엘리베이터 운행중[" << i_Floor << "층]" << endl;
				cout << "현재탑승인원 : " << i_Number << " 현재 승객 총합무게 :" << i_NowKG << endl;
				
				if (i_Floor == E1.m_i_MaxFloor)
				{
					cout << "최대층수에 도달하였습니다. 승객들은 내려주시길바랍니다" << endl;
					system("pause");
					break;
				}

				if (i_Number > E1.m_i_MaxPeople || i_NowKG >= E1.m_i_MaxKG)
				{
					if (i_NowKG >= E1.m_i_MaxKG)
						cout << "최대수용가능 무게 초과" << endl;
					else
					{
						cout << "엘리베이터내 공간이 부족하여 승객이 탈수없다" << endl;
						//RideOff(&P, &i_Number, &i_NowKG);
					}
					system("pause");
					break;
				}

				int RNum = (rand() % 2) + 1;
				if (RNum == 1)
					RideOn(&P, &i_Number, &i_NowKG);

				i_Floor++;
				//엘리베이터 운행속도
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
				cout << "현재탑승인원 :" << i_Number << " " << "현재탑승인원 무게 총합 :" << i_NowKG << endl;
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
