#include <iostream>
#include <functional>
#include <algorithm>
#include <map>

#include <vector>
#include <string>

#include "Pair.h"

const string arifKey = "Arifmetic";

ostream& operator<<(ostream& stream, map<string, Pair>& print)
{
	if (print.empty())
		stream << "Словарь пуст" << endl;
	else
	{
		for (pair<const string, Pair> keyValuePair : print)
		{
			string key = keyValuePair.first;

			Pair value = keyValuePair.second;

			stream << key << ":" << endl << value << endl << endl;
		}
	}

	return stream;
}

bool operator<(pair<const string, Pair>& value1, pair<const string, Pair>& value2)
{
	return value1.second < value2.second;
}

bool operator>(pair<const string, Pair>& value1, pair<const string, Pair>& value2)
{
	return value1.second > value2.second;
}

template<typename T1, typename T2>
void sortMapByValues(map<T1, T2>& m, bool byDecending = true)
{
	vector<T2> buffer;

	for (auto& p : m)
		buffer.push_back(p.second);

	sort(buffer.begin(), buffer.end(), [&byDecending](T2& value1, T2& value2)
		{return byDecending ? value1 > value2 : value1 < value2;});

	int counter = 0;

	for (auto& p : m)
		m[p.first] = buffer[counter++];
}

int main()
{
	map<string, Pair> mainMap;

	setlocale(LC_ALL, "RUS");

	int n;
	
	do
	{
		cout << "Введите кол-во элементов словаря!" << endl;
		cin >> n;
	} 
	while (n <= 0);

	bool flag = true;

	for (int i = 0; i < n; i++)
	{
		string key = "";
		Pair value;

		if (flag)
			cin.ignore();

		do
		{
			cout << endl << "Введиет ключ" << endl;
			getline(cin, key);
		} 
		while (key.empty());

		if (key == arifKey || mainMap.find(key) != mainMap.end())
		{
			cout << "Недопустимый ключ! Для него уже есть значение!" << endl;
			i--;

			flag = false;

			continue;
		}
		
		cout << "Введите значение" << endl;

		cin >> value;

		mainMap[key] = value;

		flag = true;
	}

	cout << endl << mainMap << endl << endl;

	Pair sum;

	for_each(mainMap.begin(), mainMap.end(), [&sum](pair<const string, Pair>& current) 
		{sum += current.second;});

	Pair arif = sum / mainMap.size();

	cout << "Среднее арифметическое: " << arif << endl << endl;

	mainMap[arifKey] = arif;

	cout << "Добавляем в словарь!" << endl << endl << mainMap;

	auto MinMax = minmax_element(mainMap.begin(), mainMap.end());

	cout << "Минимальный элемент: " << (*MinMax.first).second << ", максимальный элемент: " 
		<< (*MinMax.second).second << endl << endl;

	sum = (*MinMax.first).second + (*MinMax.second).second;

	cout << "Сумма максимума и минимума: " << sum << endl;

	cout << "Добавляем сумму ко всем элементам словаря!" << endl << endl;

	for_each(mainMap.begin(), mainMap.end(), [&sum](pair<const string, Pair>& current) 
		{current.second += sum;});

	cout << mainMap;

	Pair one;
	Pair two;

	cout <<
		"Введите 2 значения. Все элементы словаря, входящие в диапозон, будут удалены!"
		<< endl;

	cin >> one >> two;

	if (one > two)
		swap(one, two);

	cout << "Ваш диапозон: (" << one << " - " << two << ")" << endl;

	map<string, Pair> buffer;

	for (auto &current : mainMap)
	{
		Pair curValue = current.second;

		if (curValue > one && curValue < two)
			continue;

		buffer[current.first] = current.second;
	}

	mainMap = buffer;

	cout << "Словарь после чистки!" << endl << endl << mainMap;

	if (mainMap.empty())
		return 0;

	cin.ignore();

	cout << "Введите ключ, по которому надо получить значение" << endl;

	string k;

	getline(cin, k);

	auto it = mainMap.find(k);

	if (it == mainMap.end())
		cout << "Значение не найдено!" << endl;
	else
		cout << (*it).second << endl;

	cout << "Список отсортирован по убыванию:" << endl;

	sortMapByValues(mainMap);

	cout << mainMap;

	cout << "Список отсортирован по возростанию:" << endl;

	sortMapByValues(mainMap, false);

	cout << mainMap;
}