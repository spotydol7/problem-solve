#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int numbers[500001];
int frequency[8001];

int main()
{
	int n;
	
	int count = 0;
	double sum = 0;
	int max = -4001;
	int min = 4001;
	int fmax = 0;

	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
		sum += numbers[i];
		if (numbers[i] > max) {
			max = numbers[i];
		}
		if (numbers[i] < min) {
			min = numbers[i];
		}
		frequency[numbers[i] + 4000]++;
	}

	int flag = 0;
	for (int i = 0; i < 8001; i++) {
		if (frequency[i] > fmax) {
			fmax = frequency[i];
			flag = i;
		}
	}

	// flag부터 탐색 ***
	for (int i = flag + 1; i < 8001; i++) {
		if (frequency[i] == fmax) {
			flag = i;
			break;
		}
	}

	sort(numbers, numbers+n);

	double average = sum / n;
	average = round(average);
	if (average == -0) average = 0;

	cout << round(average) << endl << numbers[n / 2] << endl << flag - 4000 << endl << abs(max - min) << endl;

	return 0;
}