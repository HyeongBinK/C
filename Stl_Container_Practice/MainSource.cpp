#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<list> //Linked_List �� ����Ʈ : ó������ �ڿ����� ����ؼ� ����
#include<vector> // Array �� ����Ʈ : ��� �޸� �ּҰ� ���������� ����(�迭�� Ư¡), 
#include<map> //Tree �� ���⿡ �ش�

//Stack Qeueu List Vector �� ���� std ������ �Ƿ� ���� std:: �����°� �´�.
using namespace std;

//C++ stl Container (Stack, Queue, List, Vector, Map) // Vector == List�� �����ϳ� �迭�� ������ , Map �ȿ� Tree������

//vector
//����
//1. Ư����ġ�� ������ ������ ������.
//2. ��������ġ�� ������ �߰��ϴµ� ������ ������.
//����
//1.�迭 Ư����ġ�� ������ �ִµ� ������ ���� �ҿ�ȴ�.()
//vector ������ �ִµ� ������� ������ �ַ� ����Ѵ�.

//List : Vector�� ������� �ݴ�
//����
//1.Ư����ġ�� ������ �ִµ� ������ ������
//����
//1.��ü����Ž���̿����ɸ���.
//2.�������� ������ �ִ� ������ �����ɸ���.(����1���� �Ȱ��� ����)

//map
//1,�ʿ� ����� ������ ����������.
//2,Ư�� ������ �������� key�� �������� value�� ã�´�.

void StartMenu()
{
	cout << "===== ������� �ڷᱸ��(int��) =====" << endl;
	cout << "1. ����(Stack)" << endl;
	cout << "2. ť(Queue)" << endl;
	cout << "3. ����(Vector)" << endl;
	cout << "4. ����Ʈ(List)" << endl;
	cout << "5. ��(Map)" << endl;
	cout << "6. ����" << endl;
	cout << "�Է� : ";
}

void ShowVector(vector<int> iVector)
{
	cout << "====================================" << endl;
	for (int i = 0; i < iVector.size(); i++)
	{
		cout << "iVector[" << i << "]:" << iVector[i] << endl;
		//���� : cout << "iVector[" << i << "]:" << iVector.at(i) << endl;
	}
	cout << "====================================" << endl;
}

void ShowVector2(vector<int> iVector) // �̹���� �� ��ȣ��
{
	cout << "====================================" << endl;
	//auto : �ʱⰪ�� �־����� �ʱⰪ�� ������� �ڵ����� �ڷ����� ���� ���⼱ auto == vector<int>::iterator
	for (auto iter = iVector.begin(); iter != iVector.end(); iter++) //vector<int>::iterator �ּҸ� �����Ҽ��ִ� �Լ� iVector.begin() : �����ּ� iVector.end() : ���������� �ּ�(NULL�κ�) 
	{
		cout << "iter : " << *iter << endl;
	}
	cout << "====================================" << endl;
}

void ShowList(list<int> iList)
{
	//List�� �迭�� �ƴϱ⿡ at()�� ���Ұ�
	cout << "====================================" << endl;
	for (auto iter = iList.begin(); iter != iList.end(); iter++)
		cout << "iter : " << *iter << endl;
	cout << "====================================" << endl;
}

struct Student
{
	string m_strName;
	int m_iClass;
	string m_strAddress;
	int m_iAge;

	Student()
	{
		cout << "�̸� �Է� : ";
		cin >> m_strName;
		cout << "�г� �Է� : ";
		cin >> m_iClass;
		cout << "�ּ� �Է� : ";
		cin >> m_strAddress;
		cout << "���� �Է� : ";
		cin >> m_iAge;
	}
	void ShowStudent()
	{
		cout << "�̸� : " << m_strName << "\t �г� :" << m_iClass << "\t �ּ� :" << m_strAddress << "\t ���� :" << m_iAge << endl;
	}
};

void ShowMap(map<int , Student*> StudentMap)
{
	cout << "====================================" << endl;
	for (auto iter = StudentMap.begin(); iter != StudentMap.end(); iter++)
	{
		cout << "Key : " << iter->first << "\tValue" << endl;
		iter->second->ShowStudent();
		cout << endl;
	}
	cout << "====================================" << endl;
}

void CallStack(int Data)
{
	stack<int> iStack;
	cout << "====================================" << endl;
	cout << "Push!" << endl;
	for (int i = 1; i <= Data; i++)
	{
		iStack.push(i);
		cout << "Top : " << iStack.top() << endl; //top == �������� �� Data�� ����Ű�� ����Ʈ �Լ�
	}
	cout << "====================================" << endl;
	cout << "Pop!" << endl;
	
	//��ü ���� �ϰ������ case 1. ����� ���ؼ� �ݺ���������
	//int size = iStack.size(); //size() == Data�� ������ �����ִ� �Լ�
	//for (int i = 0; i < size; i++)
	//{
	//	cout << "Top :" << iStack.top() << endl;
	//	iStack.pop();
	//}
	
	//��ü ���� �ϰ������ case 2. ����ִ���Ȯ���ؼ� Ʈ�簡�ɋ�����
	while (!iStack.empty()) //empty() == ����ִ��� Ȯ���ϴ� �Լ� ��������� true �ƴϸ� false ��ȯ
	{
		cout << "Top :" << iStack.top() << endl;
		iStack.pop();
	}
	system("pause");
}

void CallQueue(int Data)
{
	queue<int> iQueue;
	cout << "====================================" << endl;
	cout << "EnQueue!" << endl;
	for (int i = 1; i <= Data; i++)
	{
		iQueue.push(i); //enqueue �� ���⼱Stackó�� push �ξ�
		//back() == Rear front() == Front 
		cout << "Front : " << iQueue.front() << "\t";
		cout << "Rear : " << iQueue.back() << endl;
	}
	cout << "====================================" << endl;
	cout << "DeQueue!" << endl;
	while (iQueue.empty() == false)
	{
		cout << "Front : " << iQueue.front() << "\t";
		cout << "Rear : " << iQueue.back() << endl;
		iQueue.pop(); //DeQueue �� ���⼱ Stack ó�� Pop���� ��
	}
	system("pause");
}

void CallVector(int Data)
{
	vector<int> iVector;
	for (int i = 1; i <= 10; i++)
		iVector.push_back(i);//Stack�� push ������ ���ڿ� ������ ����
	//ShowVector(iVector);
	ShowVector2(iVector);
	iVector.pop_back(); //Stack �� pop �� ���������� ���������� ���� ������ ����
	ShowVector2(iVector);
	cout << "Front : " << iVector.front() << "\tBack : " << iVector.back() << endl; //iVector.front() : ù���� iVector.back() : ���������� ���
	
	//������ ���û���1 �ݺ����̿��ؼ� ��ġã�Ƽ� ����
	for (auto iter = iVector.begin(); iter != iVector.end(); iter++) 
	{
		//erase ���� �� ���ڰ��� ������ ����� �ּҸ� ������ ��ȯ���� ������ ���� ���� �ּҸ� ����
		//���ϵ� �����ּҸ� iter�� �ٽ� �ִ´�.
		if (*iter == 5)
			iter = iVector.erase(iter); //������ ���û���
	}
	ShowVector2(iVector);

	//������ ���û���2 
	auto iter = find(iVector.begin(), iVector.end(), 16); //find �� std::��, ã�°��� ������ NULL��ȯ
	if(iter != iVector.end())
	iter = iVector.erase(iter);
	ShowVector2(iVector);

	//���ϴ���ġ�� �����ֱ�, �ְ������ġ�� �ڿ����� ã�Ƽ� �� ���ǰ��� �տ�����
	iter = find(iVector.begin(), iVector.end(), 6);
	if (iter != iVector.end())
		iter = iVector.insert(iter, 5);
	ShowVector2(iVector);
	
	// ��ü����
	iVector.clear(); 
	
	//iVector.pop.back() //������ ��������
	system("pause");
}

void CallList(int Data)
{
	list<int> iList;
	for (int i = 1; i <= 10; i++)
		iList.push_back(i);//Stack�� push ������ ���� �ڿ� ������ ����
						   //iList.push_front() //������ ���� �տ� ����������
	ShowList(iList);

	//�Ǿտ� �����ֱ�
	iList.push_front(11);
	ShowList(iList);

	//�ǵ��� ��������
	iList.pop_back();
	ShowList(iList);

	//�Ǿ��� ��������
	iList.pop_front();
	ShowList(iList);

	//���û���
	auto iter = find(iList.begin(), iList.end(), 5);
	if (iter != iList.end())
		iter = iList.erase(iter);
	ShowList(iList);

	//���ϴ���ġ�� �����ֱ�
	iter = find(iList.begin(), iList.end(), 6);
	if (iter != iList.end())
		iter = iList.insert(iter, 5);
	ShowList(iList);

	//��ü����
	iList.clear();

	system("pause");
}

void CallMap()
{
	map<int, Student*> StudentMap;
	StudentMap.insert(make_pair(20201234, new Student));
	/*StudentMap.insert(make_pair(20201235, new Student));
	StudentMap.insert(make_pair(20201236, new Student));
	StudentMap.insert(make_pair(20201237, new Student));*/
	//���� ���̸� �Ʒ��� ���� ����� �ȴ�.
	StudentMap[20201238] = new Student;
	//Ű���� �ߺ� �ȵȴ�. �˾Ƽ� �ߺ������� 

	ShowMap(StudentMap);
	//��ü���������� Key���� ���� �����Ҵ�ȰŸ� �����ȴ�.
	for (auto iter = StudentMap.begin(); iter != StudentMap.end(); iter++)
	{
		delete iter->second;
	}

	//StudentMap.at(20201234);
	//���� ���̸� �Ʒ��� ���� ǥ���̵ȴ�.
	//StudentMap[20201234]; //���⿡ �������������� ->ShowStudent�� ���� ���밡���ϴ� 
	
	//StudentMap.erase(20201234); //�����ͼ��û���
	//�Ϻ��� ��ü����(�ݺ��������� delete �ѰŶ��ٸ��� Ű���� �����Ҵ��Ѱ͵� ���� ����)
	StudentMap.clear();
	system("pause");
}

void main()
{
	int iData = 10;
	int iSelect;
	

	while (1)
	{
		system("cls");
		StartMenu();
		cin >> iSelect;
		switch (iSelect)
		{
		case 1:
			CallStack(iData); 
			break;
		case 2:
			CallQueue(iData); 
			break;
		case 3:
			CallVector(iData); 
			break;
		case 4:
			CallList(iData);
			break;
		case 5:
			CallMap();
			break;
		case 6:
			return;
		}
	}
}
