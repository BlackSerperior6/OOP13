#include <iostream>
#include <algorithm>
#include <functional>
#include <list>

#include "Pair.h"

using namespace std;

ostream& operator<<(ostream& stream, list<Pair>& to_print)
{
	if (to_print.empty())
		stream << "Список пуст";
	else
	{
		stream << *to_print.begin();

		list<Pair>::iterator it = to_print.begin();
		it++;

		for (; it != to_print.end(); it++)
			stream << " " << *it;
	}

	return stream;
}

int main()
{
	setlocale(LC_ALL, "RUS");

	list<Pair> mainList;

	int n;

	do
	{
		cout << "Введите кол-во элементов списка" << endl;
		cin >> n;
	} while (n <= 0);

	for (int i = 0; i < n; i++)
	{
		Pair value;

		cin >> value;

		mainList.push_back(value);
	}

	cout << endl << mainList << endl << endl;

	Pair sum;

	for_each(mainList.begin(), mainList.end(), [&sum](Pair& current) {sum += current; });

	Pair arif = (sum / mainList.size());

	cout << "Среднее арифметическое = " << arif << endl;

	mainList.push_back(arif);

	cout << "Добавляем в конец списка: " << endl << mainList << endl;

	cout << "Введите две пары, элементы из диапозона которых будут удалены все элементы" << endl;

	Pair One;
	Pair Two;

	cin >> One >> Two;

	if (One > Two)
		swap(One, Two);

	cout << "Ваш диапозон: (" << One << " - " << Two << ")" << endl;

	mainList.erase(remove_if(mainList.begin(), mainList.end(), [&One, &Two](Pair& current)
		{return current > One && current < Two; }), mainList.end());

	cout << endl << "Список после чистки по диапозону:" << endl << mainList;

	if (mainList.empty())
		return 0;

	auto MinMax = minmax_element(mainList.begin(), mainList.end());

	cout << endl << "Минимальный элемента списка: " << *MinMax.first
		<< endl << "Максимальный элемента списка: " << *MinMax.second;

	sum = *MinMax.first + *MinMax.second;

	cout << endl << "Сумма минимума и максимума: " << sum << endl;

	for_each(mainList.begin(), mainList.end(), [&sum](Pair& current) {current += sum; });

	cout << endl << "Список, когда ко всем элементам добавили сумму максимума и минимума: " <<
		endl << mainList << endl;

	cout << "Введите число. Необходимо будет найти элемент, в котором первое число равно заданому:"
		<< endl;

	int number;

	cin >> number;

	if (find_if(mainList.begin(), mainList.end(),
		[&number](Pair& current) {return current.getFirst() == number; }) != end(mainList))
		cout << "Такой элемент есть в списке" << endl;
	else
		cout << "Такого элемента нет в списке" << endl;

	mainList.sort([](Pair& first, Pair& second) {return first < second; });

	cout << endl << "Список отсортирован по возрастанию:" << endl << mainList << endl;

	mainList.sort([](Pair& first, Pair& second) {return first > second; });

	cout << endl << "Список отсортирован по убыванию:" << endl << mainList << endl;
}