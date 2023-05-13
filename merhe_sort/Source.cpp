#include <iostream>
using namespace std;
class Arr 
{
	int* arr;
	int size;
	void sort(int,int,int);
	void merge(int,int);
	friend istream& operator>>(istream&,Arr&);
	friend ostream& operator<<(ostream&,Arr&);
public:
	int& operator[](int);
	Arr(int*, int);
	void merge_sort(){merge(0, size - 1);}
};
int& Arr::operator[](int index)
{
	return this->arr[index];
}
ostream& operator<<(ostream& os, Arr& a)
{
	if (a.size == 0)
		return os;

	for (int i = 0; i < a.size; i++)
	{
		os << "array member  "<<i+1<<"  is`  " << a[i] << ' '<<endl;
	}
	return os;
}
istream& operator>>(istream& is, Arr& a)
{
	cout << "input array length`  ";
	is >> a.size;
	a.arr = new int[a.size];
	for (int i = 0; i < a.size; i++)
	{
		cout << "input array member  " << i+1<<"`  ";
		is >> a.arr[i];
	}
	return is;
}
Arr::Arr(int* arr=nullptr, int size=0)
{
	if (size > 0)
	{
		this->size = size;
		this->arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			this->arr[i] = arr[i];
		}
	}
	else
	{
		this->arr = nullptr;
		this->size = 0;
	}

}
void Arr:: sort(int low, int mid, int high)
{
	int size_1 = mid - low + 1;
	int size_2 = high - mid;

	int* a = new int[size_1];
	int* b = new int[size_2];

	for (int i = 0; i < size_1; i++)
	{
		a[i] = arr[low + i];
	}
	for (int i = 0; i < size_2; i++)
	{
		b[i] = arr[mid + i + 1];
	}
	int i = 0; int j = 0; int k = low;
	while (i < size_1 && j < size_2)
	{
		if (a[i] < b[j])
		{
			arr[k] = a[i]; k++; i++;
		}
		else
		{
			arr[k] = b[j]; k++; j++;
		}
	}
	while (i < size_1)
	{
		arr[k] = a[i]; k++, i++;
	}
	while (j < size_2)
	{
		arr[k] = b[j]; k++, j++;
	}
}
void Arr::merge(int low, int high)
{
	if (low < high) {

		int mid = (high + low) / 2;
		merge(mid + 1, high);
		merge(low, mid);

		sort(low, mid, high);
	}
}
int main()
{
	Arr a;
	cin >> a;
	a.merge_sort();
	cout << a;
	return 0;
}