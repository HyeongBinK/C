#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<list> //Linked_List 형 리스트 : 처음꺼랑 뒤에꺼랑 계속해서 연결
#include<vector> // Array 형 리스트 : 모든 메모리 주소가 연속적으로 나열(배열의 특징), 
#include<map> //Tree 가 여기에 해당

//Stack Qeueu List Vector 등 전부 std 영역이 므로 원랜 std:: 가들어가는게 맞다.
using namespace std;

//C++ stl Container (Stack, Queue, List, Vector, Map) // Vector == List와 유사하나 배열로 관리함 , Map 안에 Tree가있음

//vector
//장점
//1. 특정위치의 정보에 접근이 빠르다.
//2. 마지막위치에 정보를 추가하는데 연산이 빠르다.
//단점
//1.배열 특정위치에 정보를 넣는데 연산이 많이 소요된다.()
//vector 정보를 넣는데 순서대로 넣을떄 주로 사용한다.

//List : Vector와 장단점이 반대
//장점
//1.특정위치에 정보를 넣는데 연산이 빠르다
//단점
//1.전체정보탐색이오래걸린다.
//2.마지막에 정보를 넣는 동작이 오래걸린다.(단점1번과 똑같은 이유)

//map
//1,맵에 저장된 정보는 순서가없다.
//2,특정 정보의 고유값인 key를 기준으로 value를 찾는다.

void StartMenu()
{
	cout << "===== 보고싶은 자료구조(int형) =====" << endl;
	cout << "1. 스택(Stack)" << endl;
	cout << "2. 큐(Queue)" << endl;
	cout << "3. 백터(Vector)" << endl;
	cout << "4. 리스트(List)" << endl;
	cout << "5. 맵(Map)" << endl;
	cout << "6. 종료" << endl;
	cout << "입력 : ";
}

void ShowVector(vector<int> iVector)
{
	cout << "====================================" << endl;
	for (int i = 0; i < iVector.size(); i++)
	{
		cout << "iVector[" << i << "]:" << iVector[i] << endl;
		//원형 : cout << "iVector[" << i << "]:" << iVector.at(i) << endl;
	}
	cout << "====================================" << endl;
}

void ShowVector2(vector<int> iVector) // 이방법이 더 선호됨
{
	cout << "====================================" << endl;
	//auto : 초기값을 넣었을떄 초기값을 기반으로 자동으로 자료형을 지정 여기선 auto == vector<int>::iterator
	for (auto iter = iVector.begin(); iter != iVector.end(); iter++) //vector<int>::iterator 주소를 저장할수있는 함수 iVector.begin() : 시작주소 iVector.end() : 마지막다음 주소(NULL부분) 
	{
		cout << "iter : " << *iter << endl;
	}
	cout << "====================================" << endl;
}

void ShowList(list<int> iList)
{
	//List는 배열이 아니기에 at()형 사용불가
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
		cout << "이름 입럭 : ";
		cin >> m_strName;
		cout << "학년 입력 : ";
		cin >> m_iClass;
		cout << "주소 입력 : ";
		cin >> m_strAddress;
		cout << "나이 입력 : ";
		cin >> m_iAge;
	}
	void ShowStudent()
	{
		cout << "이름 : " << m_strName << "\t 학년 :" << m_iClass << "\t 주소 :" << m_strAddress << "\t 나이 :" << m_iAge << endl;
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
		cout << "Top : " << iStack.top() << endl; //top == 마지막에 들어간 Data를 가르키는 포인트 함수
	}
	cout << "====================================" << endl;
	cout << "Pop!" << endl;
	
	//전체 팝을 하고싶을떄 case 1. 사이즈를 구해서 반복문돌리기
	//int size = iStack.size(); //size() == Data의 개수를 구해주는 함수
	//for (int i = 0; i < size; i++)
	//{
	//	cout << "Top :" << iStack.top() << endl;
	//	iStack.pop();
	//}
	
	//전체 팝을 하고싶을떄 case 2. 비어있는지확인해서 트루가될떄까지
	while (!iStack.empty()) //empty() == 비어있는지 확인하는 함수 비어있으면 true 아니면 false 반환
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
		iQueue.push(i); //enqueue 를 여기선Stack처럼 push 로씀
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
		iQueue.pop(); //DeQueue 를 여기선 Stack 처럼 Pop으로 씀
	}
	system("pause");
}

void CallVector(int Data)
{
	vector<int> iVector;
	for (int i = 1; i <= 10; i++)
		iVector.push_back(i);//Stack의 push 정보의 젤뒤에 정보를 넣음
	//ShowVector(iVector);
	ShowVector2(iVector);
	iVector.pop_back(); //Stack 의 pop 과 마찬가지로 젤마지막에 들어온 정보를 삭제
	ShowVector2(iVector);
	cout << "Front : " << iVector.front() << "\tBack : " << iVector.back() << endl; //iVector.front() : 첫값과 iVector.back() : 마지막값을 출력
	
	//데이터 선택삭제1 반복문이용해서 위치찾아서 삭제
	for (auto iter = iVector.begin(); iter != iVector.end(); iter++) 
	{
		//erase 삭제 시 인자값은 삭제할 대상의 주소를 보내면 반환값은 삭제한 값의 다음 주소를 리턴
		//리턴된 다음주소를 iter에 다시 넣는다.
		if (*iter == 5)
			iter = iVector.erase(iter); //데이터 선택삭제
	}
	ShowVector2(iVector);

	//데이터 선택삭제2 
	auto iter = find(iVector.begin(), iVector.end(), 16); //find 도 std::형, 찾는값이 없을시 NULL반환
	if(iter != iVector.end())
	iter = iVector.erase(iter);
	ShowVector2(iVector);

	//원하는위치에 정보넣기, 넣고싶은위치의 뒤에값을 찾아서 그 뒤의값의 앞에연결
	iter = find(iVector.begin(), iVector.end(), 6);
	if (iter != iVector.end())
		iter = iVector.insert(iter, 5);
	ShowVector2(iVector);
	
	// 전체삭제
	iVector.clear(); 
	
	//iVector.pop.back() //마지막 정보삭제
	system("pause");
}

void CallList(int Data)
{
	list<int> iList;
	for (int i = 1; i <= 10; i++)
		iList.push_back(i);//Stack의 push 정보의 제일 뒤에 정보를 넣음
						   //iList.push_front() //정보의 제일 앞에 정보를넣음
	ShowList(iList);

	//맨앞에 정보넣기
	iList.push_front(11);
	ShowList(iList);

	//맨뒤의 정보삭제
	iList.pop_back();
	ShowList(iList);

	//맨앞의 정보삭제
	iList.pop_front();
	ShowList(iList);

	//선택삭제
	auto iter = find(iList.begin(), iList.end(), 5);
	if (iter != iList.end())
		iter = iList.erase(iter);
	ShowList(iList);

	//원하는위치에 정보넣기
	iter = find(iList.begin(), iList.end(), 6);
	if (iter != iList.end())
		iter = iList.insert(iter, 5);
	ShowList(iList);

	//전체삭제
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
	//위를 줄이면 아래와 같은 방법이 된다.
	StudentMap[20201238] = new Student;
	//키값은 중복 안된다. 알아서 중복제어함 

	ShowMap(StudentMap);
	//전체삭제이지만 Key값은 남고 동적할당된거만 해제된다.
	for (auto iter = StudentMap.begin(); iter != StudentMap.end(); iter++)
	{
		delete iter->second;
	}

	//StudentMap.at(20201234);
	//위를 줄이면 아래와 같은 표현이된다.
	//StudentMap[20201234]; //여기에 포인터형식으로 ->ShowStudent와 같이 응용가능하단 
	
	//StudentMap.erase(20201234); //데이터선택삭제
	//완벽한 전체삭제(반복문돌려서 delete 한거랑다르게 키값도 동적할당한것도 같이 해제)
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
