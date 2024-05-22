#pragma once

#include <iostream>

using namespace std;

class Pair //����� ����
{
private:

	//������ � ������ �����
	int First;
	double Second;

public:

	//������������
	Pair()
	{
		First = 0;
		Second = 0;
	}

	Pair(int first, double second)
	{
		setFirst(first);
		setSecond(second);
	}

	//������� � �������
	void setFirst(int first) { First = first; }
	void setSecond(double second) { Second = second; }
	int getFirst() { return First; }
	double getSecond() { return Second; }

	Pair& operator=(Pair anotherPair)
	{
		First = anotherPair.First;
		Second = anotherPair.Second;

		return *this;
	}

	Pair& operator -= (Pair& anotherPair) //�������� ��������� ���� � ����
	{
		First -= anotherPair.First;
		Second -= anotherPair.Second;

		return *this;
	}

	Pair& operator/(int number)
	{
		First /= number;

		Second = (double)(Second / (double)number);

		return *this;
	}

	Pair& operator+=(Pair& anotherPair)
	{
		First += anotherPair.First;
		Second += anotherPair.Second;

		return *this;
	}

	Pair operator+(Pair& anotherPair)
	{
		Pair result;

		result.First = First + anotherPair.First;
		result.Second = Second + anotherPair.Second;

		return result;
	}

	Pair& operator += (double variable) //�������� ���������� ��������� � ����
	{
		int fullPart = variable;

		if (variable - fullPart == 0)
			First += variable;
		else
			Second += variable;

		return *this;
	}

	Pair& operator*=(Pair& anotherPair) //�������� ��������� ���� �� ���� 
	{
		First *= anotherPair.First;
		Second *= Second;

		return *this;
	}

	bool operator>(Pair& anotherPair)
	{
		if (First != anotherPair.First)
			return First > anotherPair.First;

		return Second > anotherPair.Second;
	}

	bool operator<(Pair& anotherPair)
	{
		if (First != anotherPair.First)
			return First < anotherPair.First;

		return Second < anotherPair.Second;
	}

	bool operator==(Pair& anotherPair)
	{
		return First == anotherPair.First && Second == anotherPair.Second;
	}

	//��������� ���������� ����� - ������
	friend istream& operator>>(istream& stream, Pair& pair);
	friend ostream& operator<<(ostream& stream, Pair& pair);
};

istream& operator>>(istream& stream, Pair& pair) //�������� �����
{
	cout << endl <<"����� ����?"; stream >> pair.First;
	cout << "����� ���?"; stream >> pair.Second;

	return stream;
}

ostream& operator<<(ostream& stream, Pair& pair) //�������� ������
{
	return { stream << pair.First << ":" << pair.Second };
}

