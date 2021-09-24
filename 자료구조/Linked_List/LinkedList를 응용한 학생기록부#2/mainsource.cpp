#include "Header.h"

//아무표시없는건 2중포인터 #2가 붙은건 포인터 

//학생구조체
struct Student
{
	string m_str_Name;
	int m_i_Age;
	string m_str_Address;
	int m_i_Korea;
	int m_i_English;
	int m_i_Math;
	int m_i_ScoreSum;
	float m_f_Avg;
	string m_str_Grade;
	Student *NextStudent; //link역할
};

//시작메뉴
void Menu(int StudentNumber)
{
	system("cls");
	cout << "< < < = = = = 메뉴 = = = = > > >" << endl << endl;
	cout << "현재 총 학생수 : " << StudentNumber << endl;
	cout << "1.학생 등록" << endl;
	cout << "2.학생 검색" << endl;
	cout << "3.학생 목록" << endl;
	cout << "4.학생 수정" << endl;
	cout << "5.학생 정보 선택 삭제" << endl;
	cout << "6.학생 전체 정보 삭제" << endl;
	cout << "7.종료" << endl;
	cout << "선택 : ";
}

//학생 국영수점수받아서 성적합계평균등급 구하기기능 함수
void CalculateGrade(Student* St)
{
	St->m_i_ScoreSum = St->m_i_Korea + St->m_i_English + St->m_i_Math;
	St->m_f_Avg = St->m_i_ScoreSum / (float)3;

	if (St->m_f_Avg >= 90)
		St->m_str_Grade = "A 등급";
	else if (St->m_f_Avg >= 80)
		St->m_str_Grade = "B 등급";
	else if (St->m_f_Avg >= 70)
		St->m_str_Grade = "C 등급";
	else  if (St->m_f_Avg >= 60)
		St->m_str_Grade = "D 등급";
	else
		St->m_str_Grade = "F 등급";
}

//학생정보를 입력받는 기능함수
void InputStudentData(Student* St)
{
	system("cls");

	cout << "학생 이름 입력 : ";
	cin >> St->m_str_Name;
	cout << St->m_str_Name << " 학생 나이 입력 : ";
	cin >> St->m_i_Age;
	cout << St->m_str_Name << " 학생 주소 입력 : ";
	cin >> St->m_str_Address;
	cout << St->m_str_Name << " 학생 국어 점수 : ";
	cin >> St->m_i_Korea;
	cout << St->m_str_Name << " 학생 영어 점수 : ";
	cin >> St->m_i_English;
	cout << St->m_str_Name << " 학생 수학 점수 : ";
	cin >> St->m_i_Math;

	CalculateGrade(St);

	cout << "학생 정보 입력 완료!" << endl;
}


//학생정밀정보 보여주는 기능함수
void ShowStudentData(Student* St)
{
	cout << "< < < = = = = Information = = = = > > >" << endl;
	cout << "학생 이름 : " << St->m_str_Name << endl;
	cout << "학생 나이 : " << St->m_i_Age << " 세" << endl;
	cout << "학생 주소 : " << St->m_str_Address << endl;
	cout << "국어 점수 : " << St->m_i_Korea << " 점" << endl;
	cout << "영어 점수 : " << St->m_i_English << " 점" << endl;
	cout << "수학 점수 : " << St->m_i_Math << " 점" << endl;
	cout << "합계 점수 : " << St->m_i_ScoreSum << " 점" << endl;
	cout.precision(4); //인터넷에 c++의 플롯형 소수점아랫자리 출력하는방법 검색
	cout << "평균 점수 : " << St->m_f_Avg << " 점" << endl;
	cout << "학생 등급 : " << St->m_str_Grade << endl;
}

//모든학생정보지우는 함수(전체동적할당해제)
void DeleteAll(Student** St)
{
	if (*St == NULL)
	{
		//cout << "저장된 정보없음";
		return;
	}

	Student *Dummy;
	Dummy = *St;
	*St = Dummy->NextStudent;
	delete Dummy;

	DeleteAll(St);
}

//그다음링크를 찾는 재귀함수
Student **SearchNextLink(Student **St)
{
	Student *Dummy;
	Dummy = *St;


	if (Dummy->NextStudent == NULL)
		return &Dummy->NextStudent;
	else
	{
		return SearchNextLink(&Dummy->NextStudent);
	}
}

//1번기능
void InsertStudent(Student** St, int *StudentNumber)
{
	Student* NewStudent = new Student;
	if (*St == NULL)
	{
		*St = NewStudent;
	}
	else
	{
		*SearchNextLink(St) = NewStudent;
	}

	InputStudentData(NewStudent);
	
	NewStudent->NextStudent = NULL;
	
	(*StudentNumber)++;
}

//1번기능#2
Student* InsertStudent2(Student* St, int *StudentNumber)
{
	Student* NewStudent = new Student;

	if (St == NULL)
	{
		St = NewStudent;
	}
	else
	{
		*SearchNextLink(&St) = NewStudent;
	}

	InputStudentData(NewStudent);

	NewStudent->NextStudent = NULL;

	(*StudentNumber)++;
	
	return St;
}

//2번기능
void SearchAndShowOneStudent(Student** St, string Name)
{
	if (*St == NULL)
	{
		cout << "저장된 정보없음";
		return;
	}

	Student *Dummy;
	Dummy = *St;


	if (Dummy->m_str_Name == Name)
	{
		cout << "학생정보 검색완료" << endl;
		ShowStudentData(Dummy);
		return;
	}
	else if (Dummy->NextStudent == NULL)
	{
		cout << "검색하고자 하는 학생이 존재하지 않습니다" << endl;
		return;
	}
	else
		return SearchAndShowOneStudent(&Dummy->NextStudent, Name);
}

//2번기능#2
void SearchAndShowOneStudent2(Student* St, string Name)
{
	if (St == NULL)
	{
		cout << "저장된 정보없음";
		return;
	}

	if (St->m_str_Name == Name)
	{
		cout << "학생정보 검색완료" << endl;
		ShowStudentData(St);
		return;
	}
	else if (St->NextStudent == NULL)
	{
		cout << "검색하고자 하는 학생이 존재하지 않습니다" << endl;
		return;
	}
	else
		return SearchAndShowOneStudent(&St->NextStudent, Name);
}

//3번기능
void ShowAll(Student** St)
{
	if (*St == NULL)
	{
		cout << "저장된 정보없음";
		return;
	}

	//공간맞추는 방법 나중에 질문 : 추측은 gotoxy()문

	Student *Dummy;
	Dummy = *St;

	cout << Dummy->m_str_Name << "          " << Dummy->m_i_Age << "          " << Dummy->m_str_Address << endl;

	if (Dummy->NextStudent == NULL)
	{
		return;
	}
	else
		return ShowAll(&Dummy->NextStudent);
}

//3번기능#2
void ShowAll2(Student* St)
{
	if (St == NULL)
	{
		cout << "저장된 정보없음";
		return;
	}
	cout << St->m_str_Name << "          " << St->m_i_Age << "          " << St->m_str_Address << endl;

	if (St->NextStudent == NULL)
	{
		return;
	}
	else
		return ShowAll(&St->NextStudent);
}

//4번기능
void ModifyStudent(Student **St, string Name)
{
	if (*St == NULL)
	{
		cout << "저장된 정보없음";
		return;
	}

	Student *Dummy;
	Dummy = *St;


	if (Dummy->m_str_Name == Name)
	{
		int Select;
		string Name;
		int Age;
		string Address;

		while (1)
		{
			system("cls");
			ShowStudentData(Dummy);
			cout << endl << endl;
			cout << "수정할 항목을 선택하세요" << endl;
			cout << "1.이름  2.나이  3.주소  4.점수  5.수정종료" << endl;
			cout << "선택 : ";
			cin >> Select;
			switch (Select)
			{
			case 1:
				cout << "현재 이름 : " << Dummy->m_str_Name << endl;
				cout << "수정할 이름 : ";
				cin >> Name;
				Dummy->m_str_Name = Name;
				break;
			case 2:
				cout << "현재 나이 : " << Dummy->m_i_Age << endl;
				cout << "수정할 나이 : ";
				cin >> Age;
				Dummy->m_i_Age = Age;
				break;
			case 3:
				cout << "현재 주소 : " << Dummy->m_str_Address << endl;
				cout << "수정할 주소 : ";
				cin >> Address;
				Dummy->m_str_Address = Address;
				break;
			case 4:
				cout << "현재 점수" << endl;
				cout << "국어 : " << Dummy->m_i_Korea << " 영어 : " << Dummy->m_i_English << " 수학 : " << Dummy->m_i_Math << endl;
				cout << "수정할 국어점수 : ";
				cin >> Dummy->m_i_Korea;
				cout << "수정할 영어점수 : ";
				cin >> Dummy->m_i_English;
				cout << "수정할 수학점수 : ";
				cin >> Dummy->m_i_Math;

				CalculateGrade(Dummy);

				break;
			case 5:
				return;
			}

		}
		return;
	}
	else if (Dummy->NextStudent == NULL)
	{
		cout << "수정하고자 하는 학생이 존재하지 않습니다" << endl;
		return;
	}
	else
		return	ModifyStudent(&Dummy->NextStudent, Name);
}

//4번기능#2
void ModifyStudent2(Student *St, string Name)
{
	if (St == NULL)
	{
		cout << "저장된 정보없음";
		return;
	}

	if (St->m_str_Name == Name)
	{
		int Select;
		string Name;
		int Age;
		string Address;

		while (1)
		{
			system("cls");
			ShowStudentData(St);
			cout << endl << endl;
			cout << "수정할 항목을 선택하세요" << endl;
			cout << "1.이름  2.나이  3.주소  4.점수  5.수정종료" << endl;
			cout << "선택 : ";
			cin >> Select;
			switch (Select)
			{
			case 1:
				cout << "현재 이름 : " << St->m_str_Name << endl;
				cout << "수정할 이름 : ";
				cin >> Name;
				St->m_str_Name = Name;
				break;
			case 2:
				cout << "현재 나이 : " << St->m_i_Age << endl;
				cout << "수정할 나이 : ";
				cin >> Age;
				St->m_i_Age = Age;
				break;
			case 3:
				cout << "현재 주소 : " << St->m_str_Address << endl;
				cout << "수정할 주소 : ";
				cin >> Address;
				St->m_str_Address = Address;
				break;
			case 4:
				cout << "현재 점수" << endl;
				cout << "국어 : " << St->m_i_Korea << " 영어 : " << St->m_i_English << " 수학 : " << St->m_i_Math << endl;
				cout << "수정할 국어점수 : ";
				cin >> St->m_i_Korea;
				cout << "수정할 영어점수 : ";
				cin >> St->m_i_English;
				cout << "수정할 수학점수 : ";
				cin >> St->m_i_Math;

				CalculateGrade(St);

				break;
			case 5:
				return;
			}

		}
		return;
	}
	else if (St->NextStudent == NULL)
	{
		cout << "수정하고자 하는 학생이 존재하지 않습니다" << endl;
		return;
	}
	else
		return	ModifyStudent(&St->NextStudent, Name);
}

//5번기능
void DeleteStudent(Student** St, string Name, int *StudentNumber)
{
	if (*St == NULL)
	{
		cout << "저장된 정보없음";
		return;
	}

	Student *Dummy;
	Dummy = *St;
	
	if (Dummy->m_str_Name == Name)
	{
		*St = Dummy->NextStudent;
		delete Dummy;
		(*StudentNumber)--;
		return;
	}
	else if (Dummy->NextStudent == NULL)
	{
		cout << "삭제하고자 하는 학생이 존재하지 않습니다" << endl;
		return;
	}
	else
		return	DeleteStudent(&Dummy->NextStudent, Name, StudentNumber);
}

//메인
void main()
{
	Student *St = NULL;

	int i_Select;
	int i_StudentNumber = 0;
	string str_Name;

	while (1)
	{
		Menu(i_StudentNumber);
		cin >> i_Select;
		switch (i_Select)
		{
		case 1:
			InsertStudent(&St, &i_StudentNumber);
			//St = InsertStudent2(St, &i_StudentNumber);
			break;
		case 2:
			system("cls");
			cout << "검색할 이름 입력 : ";
			cin >> str_Name;
			//SearchAndShowOneStudent(&St, str_Name);
			SearchAndShowOneStudent2(St, str_Name);
			system("pause");
			break;
		case 3:
			system("cls");
			cout << "< < < = = = = Information = = = = > > >" << endl;
			cout << "학생이름     " << "학생나이     " << "학생주소" << endl;
			//ShowAll(&St);
			ShowAll2(St);
			cout << "학생 개개인의 점수는 검색을 이용하세요" << endl;
			system("pause");
			break;
		case 4:
			system("cls");
			cout << "수정할 학생의 이름은?" << endl;
			cin >> str_Name;
			//ModifyStudent(&St, str_Name);
			ModifyStudent2(St, str_Name);
			system("pause");
			break;
		case 5:
			system("cls");
			cout << "삭제할 학생 이름 : " << endl;
			cin >> str_Name;
			DeleteStudent(&St, str_Name, &i_StudentNumber);
			system("pause");
			break;
		case 6:
			DeleteAll(&St);
			i_StudentNumber = 0;
			break;
		case 7:
			DeleteAll(&St);
			return;
		}
	}
}
