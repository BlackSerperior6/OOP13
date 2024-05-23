#include "Comparable.h"
#include "PriorityQueue.h"

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

	cout << "Введите две пары, элементы из диапозона которых будут удалены!" << endl;

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