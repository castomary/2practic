#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;
using namespace chrono;

void MakeArray(int *array, int size) {
	srand(time(NULL));
	for (int i = 0; i < size; i++) {
		array[i] = rand() % 199 - 99;
	}
}
void PrintArray(int array[], int size) {
	for (int i = 0; i < size; i++) {
		cout << array[i] << " ";
	}
	cout << "\n";

}
void SaveValues(int *array, int *constArray, int size) {
	for (int i = 0; i < size; i++) {
		array[i] = constArray[i];
	}
}
void BubbleSort(int array[], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (array[j] > array[j + 1]) {
				swap(array[j], array[j + 1]);
			}
		}
	}
}
void ShakerSort(int array[], int size) {
	int low = 0, up = size - 1, last;
	while (low < up) {
		last = -1;
		for (int i = 0; i < up; i++) {
			if (array[i] > array[i + 1]) {
				swap(array[i], array[i + 1]);
				last = i;
			}
		}
		up = last;
		if (last == -1) {
			break;
		}
		last = size;
		for (int i = up; i >= low; i--) {
			if (array[i] > array[i + 1]) {
				swap(array[i], array[i + 1]);
				last = i;
			}
		}
		low = last + 1;
	}
}
void InsertionSort(int array[], int size) {
	for (int step = 1; step < size; step++) {
		int key = array[step];
		int j = step - 1;
		while (key < array[j] && j >= 0) {
			array[j + 1] = array[j];
			--j;
		}
		array[j + 1] = key;
	}
}
void CombSort(int array[], int size) {
	float k = 1.247, S = size - 1;
	int count = 0;
	while (S >= 1)
	{
		for (int i = 0; i + S < size; i++)
		{
			if (array[i] > array[int(i + S)])
			{
				swap(array[i], array[int(i + S)]);
			}
		}
		S /= k;
	}

	while (true)
	{
		for (int i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap(array[i], array[i + 1]);
			}
			else count++;
		}
		if (count == size - 1)
			break;
		else
			count = 0;
	}

}

int main() {
	setlocale(0, "");
	auto start = steady_clock::now(); //таймер
	auto end = steady_clock::now();
	auto result = duration_cast <nanoseconds> (end - start);
	const int size = 100; //размер массива
	int array[size]; //массив
	int answer = 1; // для цикла


	int maxElement, minElement; //максимальный и минимальный элементы  массива для задания ..
	int number = 0; // для заданий с введенным числом пользователем
	int count = 0; // счетчик
	int low = 0, high = 0;  //верхняя и нижняя границы для бинарного поиска и шейкер сорта
	int last; // для шейкер сорта
	int average = 0; // среднее 
	int firstIndex, secondIndex; // хз что это 
	int isFound = 0; // флаг, который определяет найден ли элемент 1 - да 0 - нет

	float k = 1.247, S = size - 1; // дляя комб сорта
	int constArr[size];          //хранит в себе значение сделанного в пункте 1 массива.
	cout << "first task\n";
	MakeArray(array, size); // первое задание сделать массив и вывести его на экран
	PrintArray(array, size);
	for (int i = 0; i < size; i++) {
		constArr[i] = array[i];
	}
	do {
		int task;								// выбора задания
		cout << "choose task(2 - 8)\n";
		cin >> task;
		switch (task) {
		case 2:
			int variant;                  // для выбора варианта сортировки
			cout << "choose sort \n";
			cout << "1. bubble sort" << "\n" << "2. shaker sort" << "\n" << "3. comb sort" << "\n" << "4. insert sort" << "\n";
			cin >> variant;
			switch (variant) {
			case 1:     //бабл сорт
				srand(time(0));
				SaveValues(array, constArr, size);
				start = steady_clock::now();
				for (int i = 0; i < size; i++) {
					for (int j = 0; j < size - 1 - i; j++) {
						if (array[j] > array[j + 1]) {
							swap(array[j], array[j + 1]);
						}
					}
				}
				end = steady_clock::now();
				PrintArray(array, size);
				result = duration_cast <nanoseconds> (end - start);
				cout << "spent time = " << result.count() << endl;
				cout << "\n";
				break;
			case 2:            //шейкер сорт
				srand(time(0));
				low = 0;
				high = size - 1;
				SaveValues(array, constArr, size);
				start = steady_clock::now();
				while (low < high) {
					last = -1;
					for (int i = 0; i < high; i++) {
						if (array[i] > array[i + 1]) {
							swap(array[i], array[i + 1]);
							last = i;
						}
					}
					high = last;
					if (last == -1) {
						break;
					}
					last = size;
					for (int i = high; i >= low; i--) {
						if (array[i] > array[i + 1]) {
							swap(array[i], array[i + 1]);
							last = i;
						}
					}
					low = last + 1;
				}
				end = steady_clock::now();
				PrintArray(array, size);
				result = duration_cast <nanoseconds> (end - start);
				cout << "spent time = " << result.count() << endl;
				break;
			case 3:           //комб сорт
				srand(time(0));
				SaveValues(array, constArr, size);
				start = steady_clock::now();
				while (S >= 1)
				{
					for (int i = 0; i + S < size; i++)
					{
						if (array[i] > array[int(i + S)])
						{
							swap(array[i], array[int(i + S)]);
						}
					}
					S /= k;
				}
				while (true)
				{
					for (int i = 0; i < size - 1; i++)
					{
						if (array[i] > array[i + 1])
						{
							swap(array[i], array[i + 1]);
						}
						else count++;
					}
					if (count == size - 1)
						break;
					else
						count = 0;
				}
				end = steady_clock::now();
				PrintArray(array, size);
				result = duration_cast <nanoseconds> (end - start);
				cout << "spent time = " << result.count() << endl;
				break;
			case 4:     //инсерт сорт
				srand(time(0));
				SaveValues(array, constArr, size);
				start = steady_clock::now();
				for (int step = 1; step < size; step++) {
					int key = array[step];
					int j = step - 1;
					while (key < array[j] && j >= 0) {
						array[j + 1] = array[j];
						--j;
					}
					array[j + 1] = key;
				}
				end = steady_clock::now();
				PrintArray(array, size);
				result = duration_cast <nanoseconds> (end - start);
				cout << "spent time = " << result.count() << endl;
				break;
			default: break;
			}
			break;
		case 3:          //нахождение максимального и минимального элемента в массиве
			srand(time(0));
			SaveValues(array, constArr, size);
			maxElement = array[0], minElement = array[0];
			start = steady_clock::now();
			for (int i = 1; i < size - 1; i++) {
				if (array[i] > maxElement) {
					maxElement = array[i];
				}
				if (array[i] < minElement) {
					minElement = array[i];
				}
			}
			end = steady_clock::now();
			result = duration_cast <nanoseconds> (end - start);
			cout << "Max Element = " << maxElement << "\n";
			cout << "Min Element = " << minElement << "\n";
			cout << "time spent(in unsorted) = " << result.count() << endl;
			ShakerSort(array, size);
			srand(time(0));
			start = steady_clock::now();
			maxElement = array[0];
			minElement = array[size - 1];
			end = steady_clock::now();
			result = duration_cast <nanoseconds> (end - start); \
				cout << "time spent(in sorted) = " << result.count() << endl;
			break;

		case 4:                   //среднее значение максимального и мнимального эллементов и индексы элементов массива с таким значением и количество
			srand(time(0));
			count = 0;
			SaveValues(array, constArr, size);
			PrintArray(array, size);
			maxElement = array[0];
			minElement = array[0];
			start = steady_clock::now();
			for (int i = 1; i < size; i++) {
				if (array[i] > maxElement) {
					maxElement = array[i];
				}
				if (array[i] < minElement) {
					minElement = array[i];
				}
			}
			average = (maxElement + minElement) / 2;
			cout << "avegare indices: ";
			for (int i = 0; i < size; i++) {
				if (array[i] == average) {
					cout << i << " ";
					count++;
				}
			}
			cout << "\n";
			cout << "count = " << count << "\n"; // выводит количество элементов равных среднему максимального и минимального
			end = steady_clock::now();
			result = duration_cast <nanoseconds> (end - start);
			cout << "time spent(in unsorted) = " << result.count() << endl;
			count = 0;
			ShakerSort(array, size);
			PrintArray(array, size);
			start = steady_clock::now();
			minElement = array[0];
			maxElement = array[size - 1];
			average = (maxElement + minElement) / 2;
			cout << "average indices: ";
			//for (int i = 0; i < size; i++) {
			low = 0;
			high = size - 1;
			isFound = -1;
			while (low <= high) {
				int mid = low + (high - low) / 2;
				if (array[mid] == average) {
					isFound = mid;
				}
				if (array[mid] < average)
					low = mid + 1;
				else
					high = mid - 1;
			}
			if (isFound != -1) {
				for (int i = isFound - 1; i >= 0 && array[i] == average; i--) {
					count++;
					cout << " ";
				}
				for (int i = isFound; i < size && array[i] == average; i++) {
					count++;
					cout << i << " ";
				}

			}
			cout << "\n";
			cout << "count = " << count << "\n";
			end = steady_clock::now();
			result = duration_cast <nanoseconds> (end - start);
			cout << "time spent(in sorted) = " << result.count() << endl;
			break;
		case 5:          //количество элементов меньше введенного числа
			InsertionSort(array, size);
			PrintArray(array, size);
			cout << "Enter the number: (Выведется количество элементов массива, которые меньше этого числа)\n";
			cin >> number;
			for (int i = 0; i < size; i++) {
				if (number > array[i]) {
					count += 1;
				}
				else {
					break;
				}
			}
			cout << "count = ";
			cout << count << endl;
			break;
		case 6:           //количество элементов больше введенного числа
			count = size;
			InsertionSort(array, size);
			PrintArray(array, size);
			cout << "Enter the number: (Выведется количество элементов массива, которые больше этого числа)\n";
			cin >> number;
			for (int i = 0; i < size; i++) {
				if (number < array[i]) {
					break;
				}
				count -= 1;
			}
			cout << "count = ";
			cout << count << endl;
			break;
		case 7:              //бинарный поиск
			ShakerSort(array, size);
			PrintArray(array, size);
			cout << "Enter the number: (binary search)" << endl;
			cin >> number;
			start = steady_clock::now();
			low = 0;
			high = 99;
			isFound = 0;
			while (low <= high) {
				int mid = low + (high - low) / 2;
				if (array[mid] == number) {
					isFound = mid;
				}
				if (array[mid] < number)
					low = mid + 1;
				else
					high = mid - 1;

			}
			if (isFound) {
				cout << "index = " << isFound << endl;
			}
			else {
				cout << "not found" << endl;
			}
			end = steady_clock::now();
			result = duration_cast <nanoseconds> (end - start);
			cout << "time spent(with binary search) = " << result.count() << endl;
			start = steady_clock::now();
			count = 0;
			for (int i = 0; i < size; i++) {
				if (array[i] == number) {
					cout << "index = " << i << endl;
					count += 1;
					break;
				}
			}
			if (!count) {
				cout << "not found\n";
			}
			end = steady_clock::now();
			result = duration_cast <nanoseconds> (end - start);
			cout << "time spent(without binary search) = " << result.count() << endl;
			break;
		case 8:                   //меняет элементы массива, индексы которых вводит пользователь
			srand(time(0));
			InsertionSort(array, size);
			cout << "Array:\n";
			PrintArray(array, size);
			cout << "Select two element indices, that you want to swap\n";
			cin >> firstIndex >> secondIndex;
			start = steady_clock::now();
			swap(array[firstIndex], array[secondIndex]);
			end = steady_clock::now();
			result = duration_cast <nanoseconds> (end - start);
			cout << "Modified array:\n";
			PrintArray(array, size);
			cout << "time spent = " << result.count() << endl;
			break;
		}
		cout << "repeat? 0 - no, 1 - yes\n";
		cin >> answer;


	} while (answer);
}
