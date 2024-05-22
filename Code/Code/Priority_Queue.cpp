#include <iostream>
#include <queue>

#include "Pair.h"

using namespace std;

class Comparable
{
public:

	bool operator()(Pair& one, Pair& two) { return one < two; }
};


template<typename T1, typename T2>
class PriorityQueue
{
public:

	PriorityQueue() {};
	~PriorityQueue() {};

	void Add(T1 element)
	{
		queue.push(element);
	}

	void ClearByRange(T1& min, T1& max)
	{
		priority_queue<T1, vector<T1>, T2> filteredQueue;

		while (!queue.empty())
		{
			T1 current = queue.top();

			if (current > min && current < max)
			{
				queue.pop();
				continue;
			}	

			filteredQueue.push(current);

			queue.pop();
		}

		queue = filteredQueue;
	}

	T1 GetMax()
	{
		return queue.top();
	}

	T1 GetMin()
	{
		priority_queue<T1, vector<T1>, T2> buffer = queue;

		T1 result;

		while (!buffer.empty())
		{
			result = buffer.top();

			buffer.pop();
		}

		return result;
	}

	T1 Sum() 
	{
		T1 result;

		priority_queue<T1, vector<T1>, T2> buffer = queue;

		while (!buffer.empty())
		{
			T1 current = buffer.top();

			result += current;

			buffer.pop();
		}

		return result;
	}

	void AddToAll(T1 element)
	{
		priority_queue<T1, vector<T1>, T2> updatedQueue;

		while (!queue.empty())
		{
			T1 current = queue.top();

			updatedQueue.push(current + element);

			queue.pop();
		}

		queue = updatedQueue;
	}

	bool Exist(T1 element)
	{
		priority_queue<T1, vector<T1>, T2> buffer = queue;

		bool flag = false;

		while (!buffer.empty() && !flag)
		{
			T1 current = buffer.top();

			if (current == element)
				flag = true;

			buffer.pop();
		}

		return flag;
	}

	int GetSize()
	{
		return queue.size();
	}

	bool IsEmpty() 
	{
		return queue.empty();
	}

private:
	priority_queue<T1, vector<T1>, T2> queue;

	template<typename T1, typename T2>
	friend ostream& operator<<(ostream& stream, PriorityQueue<T1, T2>& to_print);
};

template<typename T1, typename T2>
ostream& operator<<(ostream& stream, PriorityQueue<T1, T2>& to_print)
{
	priority_queue<T1, vector<T1>, T2> buffer = to_print.queue;

	if (buffer.empty())
		stream << "Очередь пуста" << endl;
	else
	{
		Pair current = buffer.top();

		stream << current;

		buffer.pop();

		while (!buffer.empty())
		{
			Pair current = buffer.top();

			stream << " " << current;

			buffer.pop();
		}
	}

	return stream;
}

int main()
{
	setlocale(LC_ALL, "RUS");

	PriorityQueue<Pair, Comparable> mainQueue;

	int n;

	do
	{
		cout << "Введите кол-во элементов очереди" << endl;
		cin >> n;
	} 
	while (n <= 0);

	for (int i = 0; i < n; i++)
	{
		Pair value;

		cin >> value;

		mainQueue.Add(value);
	}

	cout << endl << mainQueue << endl << endl;

	Pair sum = mainQueue.Sum();

	Pair arif = (sum / mainQueue.GetSize());

	cout << "Среднее арифметическое = " << arif << endl;

	mainQueue.Add(arif);

	cout << "Добавляем в очередь: " << endl << mainQueue << endl;

	cout << "Введите две пары, элементы из диапозона которых будут удалены все элементы" << endl;

	Pair One;
	Pair Two;

	cin >> One >> Two;

	if (One > Two)
		swap(One, Two);

	cout << "Ваш диапозон: (" << One << " - " << Two << ")" << endl;

	mainQueue.ClearByRange(One, Two);

	cout << endl << "Очередь после чистки по диапозону:" << endl << mainQueue;

	if (mainQueue.IsEmpty())
		return 0;

	Pair max = mainQueue.GetMax();
	Pair min = mainQueue.GetMin();

	cout << endl << "Минимальный элемента очереди: " << min
		<< endl << "Максимальный элемента списка: " << max;

	sum = max + min;

	cout << endl << "Сумма минимума и максимума: " << sum << endl;

	mainQueue.AddToAll(sum);

	cout << endl << "Очередь, когда ко всем элементам добавили сумму максимума и минимума: " <<
		endl << mainQueue << endl;

	cout << "Введите пару. Проверим, есть ли она в очереди:"
		<< endl;

	Pair to_check;

	cin >> to_check;

	if (mainQueue.Exist(to_check))
		cout << "Элемент есть в очереди" << endl;
	else
		cout << "Элемента нет в очереди" << endl;
}