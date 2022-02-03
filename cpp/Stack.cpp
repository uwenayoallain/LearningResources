#include <iostream>

using namespace std;
const int size = 50;
int top = -1;
int stack[50];
int isFull()
{
	if (top == (size - 1))
	{
		cout << "Stack Overflow" << endl;
		return 1;
	}
	return 0;
}
int isEmpty()
{
	if (top == -1)
	{
		cout << "Stack Underflow" << endl;
		return 1;
	}
	return 0;
}
int Peek()
{
	if (!isEmpty())
	{
		return stack[top];
	}
	return isEmpty();
}

int Display()
{
	for (int i = top; i > -1; i--)
	{
		cout << stack[i] << endl;
	}
}

void Push(int data)
{
	if (!isFull())
	{
		top++;
		stack[top] = data;
	}
}

void Pop()
{
	if (!isEmpty())
	{
		top--;
	}
}

int main()
{
	system("color f0");
	system("title Stack");
	system("mode con cols=50 lines=20");
	system("cls");
	int choice;
	do
	{
		cout << "1. Push" << endl;
		cout << "2. Pop" << endl;
		cout << "3. Peek" << endl;
		cout << "4. Display" << endl;
		cout << "5. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			int data;
			cout << "Enter data: ";
			cin >> data;
			Push(data);
			break;
		case 2:
			Pop();
			break;
		case 3:
			cout << "Peek: " << Peek() << endl;
			break;
		case 4:
			Display();
			break;
		case 5:
			break;
		default:
			cout << "Invalid choice" << endl;
			break;
		}
	} while (choice != 5);
}
