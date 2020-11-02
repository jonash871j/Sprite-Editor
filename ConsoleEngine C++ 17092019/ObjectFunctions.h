
#pragma once

// Used to convert integer into a integer array
std::vector <int> integerToArray(int x)
{
	std::vector <int> resultArray;
	while (true)
	{
		resultArray.insert(resultArray.begin(), x % 10);
		x /= 10;
		if (x == 0)
			return resultArray;
	}
}