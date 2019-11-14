#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int numOfVillages = 0;
	std::cin >> numOfVillages;

	std::vector<double> V(0);
	std::vector<double> distances(0);

	for (int i = 0; i < numOfVillages; i++) {
		int newVillage = 0;
		std::cin >> newVillage;
		V.push_back(newVillage);
	}

	std::sort(V.begin(), V.end());

	for (int j = 1; j < numOfVillages - 1; j++) {
		double distance = ((V[j + 1] - V[j]) / 2 + (V[j] - V[j - 1]) / 2);
		distances.push_back(distance);
	}

	std::sort(distances.begin(), distances.end());

	printf("%.1f", distances[0]);

	return 0;
}

