#include <iostream>
#include <map>
#include <functional>
#include <algorithm>

#include "Pair.h"

ostream& operator<<(ostream& stream, map<Pair, Pair>& print)
{
	if (print.empty())
		stream << "Словарь пуст";
	else
	{
		for (pair<const Pair, Pair> keyValuePair : print)
		{
			Pair key = keyValuePair.first;
			Pair value = keyValuePair.second;

			stream << key << " - " << value << endl;
		}
	}

	return stream;
}

int main()
{
	map<Pair, Pair> mainMap;

	setlocale(LC_ALL, "RUS");

	int n;

	do
	{
		cout << "Введите кол-во элементов словаря" << endl;
		cin >> n;
	} 
	while (n <= 0);

	for (int i = 0; i < n; i++)
	{
		Pair key;
		Pair value;

		cin >> key;
		cin >> value;

		mainMap[key] = value;
	}

	cout << endl << mainMap << endl << endl;

	Pair sumofKeys, sumOfValues;

	for_each(mainMap.begin(), mainMap.end(), [&sumofKeys, &sumOfValues](pair<const Pair, Pair>& current) 
		{
			Pair key = current.first;
			
			sumofKeys += key;

			sumOfValues += current.second;
		});

	Pair arifKeys = sumofKeys / mainMap.size();
	Pair arifValues = sumofKeys / mainMap.size();

	cout << "Среднее арифметическое ключей = " << 
		arifKeys << endl << "Значений: " << arifValues << endl;

	mainMap[arifKeys] = arifValues;

	cout << "Добавляем словарь: " << endl << mainMap << endl;

	cout << "Введите две пары, элементы с ключами из диапозона которых будут удалены!" << endl;

	Pair One;
	Pair Two;

	cin >> One >> Two;

	if (One > Two)
		swap(One, Two);

	cout << "Ваш диапозон: (" << One << " - " << Two << ")" << endl;

	mainMap.erase(remove_if(mainMap.begin(), mainMap.end(), [&One, &Two](pair<const Pair, Pair>& current)
		{
			Pair key = current.first;

			return key > One && key < Two;
		}

	), mainMap.end());

	cout << endl << "Словарь после чистки по диапозону:" << endl << mainMap;

	if (mainMap.empty())
		return 0;

	auto MinMax = minmax_element(mainMap.begin(), mainMap.end());

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