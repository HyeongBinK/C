#include "소스.h"
using namespace std;

//struct Point
//{
//	int Data;
//	Point* link;
//};
//
//void push(Point** top, int Data)
//{
//	Point* newNode = new Point;
//
//	newNode->link = *top;
//	newNode->Data = Data;
//	*top = newNode;
//
//	cout << newNode->link << endl;
//	cout << newNode << endl << endl;
//}
//
//void pop(Point** top)
//{
//	Point *tmp;
//	tmp = *top;
//	*top = tmp->link;
//
//	cout << tmp->Data << endl << endl;
//	delete tmp;
//}
//
//void main()
//{
//	Point *point = NULL, *tmp;
//	
//	cout << point << endl << endl;
//	
//	push(&point, 10);
//	push(&point, 7);
//	push(&point, 23);
//
//	pop(&point);
//	pop(&point);
//	pop(&point);
//}

//class로 변환
class Point
{
private:
	int m_iData;
	Point* link;
public:
	void push(Point** top, int Data)
	{
		Point* newNode = new Point;

		newNode->link = *top;
		newNode->m_iData = Data;
		*top = newNode;

		cout << newNode->link << endl;
		cout << newNode << endl << endl;
	}
	void pop(Point** top);
};

void Point::pop(Point** top)
{
	Point *tmp;
	tmp = *top;
	*top = tmp->link;

	cout << tmp->m_iData << endl << endl;
	delete tmp;
}

void main()
{
	Point *point = NULL, *tmp;

	cout << point << endl << endl;

	point->push(&point, 10);
	point->push(&point, 7);
	point->push(&point, 23);

	point->pop(&point);
	point->pop(&point);
	point->pop(&point);
}