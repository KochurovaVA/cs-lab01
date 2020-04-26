#include <limits>
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main()
{
	size_t number_count;
	cerr << "Enter number count: ";
	cin >> number_count;
	vector <double> numbers(number_count);

	cerr << "Enter values: " << endl;
	for (size_t i = 0; i < number_count; i++)
	{
		cout << i + 1 << ": ";
		cin >> numbers[i];
	}

	size_t bin_count;
	cerr << "Enter bin count: ";
	cin >> bin_count;
	vector <size_t> bins(bin_count, 0);

	double min = numbers[0];
	double max = numbers[0];
	for (double number : numbers)
	{
		if (number < min)
		{
			min = number;
		}

		if (number > max)
		{
			max = number;
		}
	}

	size_t bin_index;

	for (double number : numbers)
	{

		if (number != max)
		{
			bin_index = (size_t)((number - min) * bin_count / (max - min));

		}
		else
		{
			bin_index = (bin_count - 1);

		}
		bins[bin_index]++;
	}
	const size_t max_ast = 76;
	const size_t max_wight = 80;
	double koef = 1;
	size_t max_count = 0;

	for (size_t bin : bins)
	{
		if (bin > max_count)
		{
			max_count = bin;
		}
	}

	if (max_count > max_ast)
	{
		koef = static_cast <double> (max_ast) / max_count;
	}

	char pad, symbol, axis;

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cerr << "Enter padding symbol: ";
	pad = cin.get();
	if (pad == '\t' || pad == '\n')
	{
		cout << "INPUT ERROR!";
		return 1;
	}

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cerr << "Enter symbol: ";
	cin.get(symbol);
	if (symbol == '\t' || symbol == '\n')
	{
		cout << "INPUT ERROR!";
		return 1;
	}

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	cerr << "Enter axis symbol: ";
	cin.get(axis);
	if (axis == '\t' || axis == '\n')
	{
		cout << "INPUT ERROR!";
		return 1;
	}



	for (size_t bin : bins)
	{
		cout << setfill(pad) << setw(3) << bin;
		/*if (bin < 10)
		{

		//cout << "    " << bin << "|";
		}
		else if ((bin > 10) && (bin < 100)||(bin==10))
		{
		//cout << "  " << bin << "|";
		}
		else if ((bin>100) && (bin<1000)||(bin==100))
		{
		//cout << bin << "|";
		}
		else if (bin>1000)
		{
		cout << "anomalni nomer korzini";
		}*/
		cout << axis;
		size_t height = bin * koef;
		for (size_t i = 0; i < height; i++)
		{
			cout << symbol;
		}
		cout << '\n';
	}
	system("pause");
	return 0;
}
