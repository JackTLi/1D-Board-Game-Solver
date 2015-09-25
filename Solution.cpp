#include <vector>
#include <iostream>

using namespace std;

#define SOLVABLE 0
#define DEADEND -1
#define VISITED -2

bool IsSolvable (vector<int> array, vector<int>& visitedLocations, int i) 
{
	visitedLocations.push_back(i);

	if (array[i] == SOLVABLE) {
		return true;
	}
	else if (array[i] == DEADEND || array[i] == VISITED) {
		return false;
	}
	else 
	{
		int value = array[i];
		int spaceOnLeft = i;
		int spaceOnRight = array.size() - 1 - i;

		array[i] = VISITED; // mark this array element as visited

		if (value <= spaceOnLeft && value <= spaceOnRight) 
		{
			return (IsSolvable(array, visitedLocations, i - value) || IsSolvable(array, visitedLocations, i + value));
		}
		else if (value <= spaceOnLeft && value > spaceOnRight ) 
		{
			return IsSolvable(array, visitedLocations, i - value);
		}
		else if (value > spaceOnLeft && value <= spaceOnRight)
		{
			return IsSolvable(array, visitedLocations, i + value);
		}
		else 
		{
			return false;
		}
	}
}

void markVisitedAs(vector<int>& array, vector<int> visitedLocations, vector<int>& solutions, int newValue) 
{
	for (vector<int>::iterator it = visitedLocations.begin(); it < visitedLocations.end(); it++) 
	{
		array[*it] == newValue;
	}
}

vector<int> findAllSolutions (vector<int> array) 
{
	vector<int> solutions;

	for (int i = 0; i < array.size(); i++) 
	{
		vector<int> visited;
		if (IsSolvable(array, visited, i)) 
		{
			markVisitedAs(array, visited, solutions, SOLVABLE);
			solutions.push_back(i);
		}
		else 
		{
			markVisitedAs(array, visited, solutions, DEADEND);
		}
	}

	return solutions;
}

int main () 
{
	int size;
	int temp;
	cin >> size;

	vector<int> array;

	for (int i = 0; i < size; i++) 
	{
		cin >> temp;
		array.push_back(temp);
	}

	cout << "Solutions:" << endl;
	vector<int> solutions = findAllSolutions(array);

	for (vector<int>::iterator it = solutions.begin(); it < solutions.end(); it++) {
		cout << *it << endl;
	}
}