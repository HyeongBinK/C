#include "Header.h"

//�ƹ�ǥ�þ��°� 2�������� #2�� ������ ������ 

//�л�����ü
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
	Student *NextStudent; //link����
};

//���۸޴�
void Menu(int StudentNumber)
{
	system("cls");
	cout << "< < < = = = = �޴� = = = = > > >" << endl << endl;
	cout << "���� �� �л��� : " << StudentNumber << endl;
	cout << "1.�л� ���" << endl;
	cout << "2.�л� �˻�" << endl;
	cout << "3.�л� ���" << endl;
	cout << "4.�л� ����" << endl;
	cout << "5.�л� ���� ���� ����" << endl;
	cout << "6.�л� ��ü ���� ����" << endl;
	cout << "7.����" << endl;
	cout << "���� : ";
}

//�л� �����������޾Ƽ� �����հ���յ�� ���ϱ��� �Լ�
void CalculateGrade(Student* St)
{
	St->m_i_ScoreSum = St->m_i_Korea + St->m_i_English + St->m_i_Math;
	St->m_f_Avg = St->m_i_ScoreSum / (float)3;

	if (St->m_f_Avg >= 90)
		St->m_str_Grade = "A ���";
	else if (St->m_f_Avg >= 80)
		St->m_str_Grade = "B ���";
	else if (St->m_f_Avg >= 70)
		St->m_str_Grade = "C ���";
	else  if (St->m_f_Avg >= 60)
		St->m_str_Grade = "D ���";
	else
		St->m_str_Grade = "F ���";
}

//�л������� �Է¹޴� ����Լ�
void InputStudentData(Student* St)
{
	system("cls");

	cout << "�л� �̸� �Է� : ";
	cin >> St->m_str_Name;
	cout << St->m_str_Name << " �л� ���� �Է� : ";
	cin >> St->m_i_Age;
	cout << St->m_str_Name << " �л� �ּ� �Է� : ";
	cin >> St->m_str_Address;
	cout << St->m_str_Name << " �л� ���� ���� : ";
	cin >> St->m_i_Korea;
	cout << St->m_str_Name << " �л� ���� ���� : ";
	cin >> St->m_i_English;
	cout << St->m_str_Name << " �л� ���� ���� : ";
	cin >> St->m_i_Math;

	CalculateGrade(St);

	cout << "�л� ���� �Է� �Ϸ�!" << endl;
}


//�л��������� �����ִ� ����Լ�
void ShowStudentData(Student* St)
{
	cout << "< < < = = = = Information = = = = > > >" << endl;
	cout << "�л� �̸� : " << St->m_str_Name << endl;
	cout << "�л� ���� : " << St->m_i_Age << " ��" << endl;
	cout << "�л� �ּ� : " << St->m_str_Address << endl;
	cout << "���� ���� : " << St->m_i_Korea << " ��" << endl;
	cout << "���� ���� : " << St->m_i_English << " ��" << endl;
	cout << "���� ���� : " << St->m_i_Math << " ��" << endl;
	cout << "�հ� ���� : " << St->m_i_ScoreSum << " ��" << endl;
	cout.precision(4); //���ͳݿ� c++�� �÷��� �Ҽ����Ʒ��ڸ� ����ϴ¹�� �˻�
	cout << "��� ���� : " << St->m_f_Avg << " ��" << endl;
	cout << "�л� ��� : " << St->m_str_Grade << endl;
}

//����л���������� �Լ�(��ü�����Ҵ�����)
void DeleteAll(Student** St)
{
	if (*St == NULL)
	{
		//cout << "����� ��������";
		return;
	}

	Student *Dummy;
	Dummy = *St;
	*St = Dummy->NextStudent;
	delete Dummy;

	DeleteAll(St);
}

//�״�����ũ�� ã�� ����Լ�
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

//1�����
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

//1�����#2
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

//2�����
void SearchAndShowOneStudent(Student** St, string Name)
{
	if (*St == NULL)
	{
		cout << "����� ��������";
		return;
	}

	Student *Dummy;
	Dummy = *St;


	if (Dummy->m_str_Name == Name)
	{
		cout << "�л����� �˻��Ϸ�" << endl;
		ShowStudentData(Dummy);
		return;
	}
	else if (Dummy->NextStudent == NULL)
	{
		cout << "�˻��ϰ��� �ϴ� �л��� �������� �ʽ��ϴ�" << endl;
		return;
	}
	else
		return SearchAndShowOneStudent(&Dummy->NextStudent, Name);
}

//2�����#2
void SearchAndShowOneStudent2(Student* St, string Name)
{
	if (St == NULL)
	{
		cout << "����� ��������";
		return;
	}

	if (St->m_str_Name == Name)
	{
		cout << "�л����� �˻��Ϸ�" << endl;
		ShowStudentData(St);
		return;
	}
	else if (St->NextStudent == NULL)
	{
		cout << "�˻��ϰ��� �ϴ� �л��� �������� �ʽ��ϴ�" << endl;
		return;
	}
	else
		return SearchAndShowOneStudent(&St->NextStudent, Name);
}

//3�����
void ShowAll(Student** St)
{
	if (*St == NULL)
	{
		cout << "����� ��������";
		return;
	}

	//�������ߴ� ��� ���߿� ���� : ������ gotoxy()��

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

//3�����#2
void ShowAll2(Student* St)
{
	if (St == NULL)
	{
		cout << "����� ��������";
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

//4�����
void ModifyStudent(Student **St, string Name)
{
	if (*St == NULL)
	{
		cout << "����� ��������";
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
			cout << "������ �׸��� �����ϼ���" << endl;
			cout << "1.�̸�  2.����  3.�ּ�  4.����  5.��������" << endl;
			cout << "���� : ";
			cin >> Select;
			switch (Select)
			{
			case 1:
				cout << "���� �̸� : " << Dummy->m_str_Name << endl;
				cout << "������ �̸� : ";
				cin >> Name;
				Dummy->m_str_Name = Name;
				break;
			case 2:
				cout << "���� ���� : " << Dummy->m_i_Age << endl;
				cout << "������ ���� : ";
				cin >> Age;
				Dummy->m_i_Age = Age;
				break;
			case 3:
				cout << "���� �ּ� : " << Dummy->m_str_Address << endl;
				cout << "������ �ּ� : ";
				cin >> Address;
				Dummy->m_str_Address = Address;
				break;
			case 4:
				cout << "���� ����" << endl;
				cout << "���� : " << Dummy->m_i_Korea << " ���� : " << Dummy->m_i_English << " ���� : " << Dummy->m_i_Math << endl;
				cout << "������ �������� : ";
				cin >> Dummy->m_i_Korea;
				cout << "������ �������� : ";
				cin >> Dummy->m_i_English;
				cout << "������ �������� : ";
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
		cout << "�����ϰ��� �ϴ� �л��� �������� �ʽ��ϴ�" << endl;
		return;
	}
	else
		return	ModifyStudent(&Dummy->NextStudent, Name);
}

//4�����#2
void ModifyStudent2(Student *St, string Name)
{
	if (St == NULL)
	{
		cout << "����� ��������";
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
			cout << "������ �׸��� �����ϼ���" << endl;
			cout << "1.�̸�  2.����  3.�ּ�  4.����  5.��������" << endl;
			cout << "���� : ";
			cin >> Select;
			switch (Select)
			{
			case 1:
				cout << "���� �̸� : " << St->m_str_Name << endl;
				cout << "������ �̸� : ";
				cin >> Name;
				St->m_str_Name = Name;
				break;
			case 2:
				cout << "���� ���� : " << St->m_i_Age << endl;
				cout << "������ ���� : ";
				cin >> Age;
				St->m_i_Age = Age;
				break;
			case 3:
				cout << "���� �ּ� : " << St->m_str_Address << endl;
				cout << "������ �ּ� : ";
				cin >> Address;
				St->m_str_Address = Address;
				break;
			case 4:
				cout << "���� ����" << endl;
				cout << "���� : " << St->m_i_Korea << " ���� : " << St->m_i_English << " ���� : " << St->m_i_Math << endl;
				cout << "������ �������� : ";
				cin >> St->m_i_Korea;
				cout << "������ �������� : ";
				cin >> St->m_i_English;
				cout << "������ �������� : ";
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
		cout << "�����ϰ��� �ϴ� �л��� �������� �ʽ��ϴ�" << endl;
		return;
	}
	else
		return	ModifyStudent(&St->NextStudent, Name);
}

//5�����
void DeleteStudent(Student** St, string Name, int *StudentNumber)
{
	if (*St == NULL)
	{
		cout << "����� ��������";
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
		cout << "�����ϰ��� �ϴ� �л��� �������� �ʽ��ϴ�" << endl;
		return;
	}
	else
		return	DeleteStudent(&Dummy->NextStudent, Name, StudentNumber);
}

//����
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
			cout << "�˻��� �̸� �Է� : ";
			cin >> str_Name;
			//SearchAndShowOneStudent(&St, str_Name);
			SearchAndShowOneStudent2(St, str_Name);
			system("pause");
			break;
		case 3:
			system("cls");
			cout << "< < < = = = = Information = = = = > > >" << endl;
			cout << "�л��̸�     " << "�л�����     " << "�л��ּ�" << endl;
			//ShowAll(&St);
			ShowAll2(St);
			cout << "�л� �������� ������ �˻��� �̿��ϼ���" << endl;
			system("pause");
			break;
		case 4:
			system("cls");
			cout << "������ �л��� �̸���?" << endl;
			cin >> str_Name;
			//ModifyStudent(&St, str_Name);
			ModifyStudent2(St, str_Name);
			system("pause");
			break;
		case 5:
			system("cls");
			cout << "������ �л� �̸� : " << endl;
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
