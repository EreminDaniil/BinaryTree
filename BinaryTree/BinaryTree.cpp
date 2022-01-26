#include <iostream>
#include <algorithm>

int main() 
{
	const int Count = 7;
	int Array[Count];
	int Key;

	std::cout << "Enter "<< Count << " numbers " << std::endl;

	for (int i = 0; i < Count; i++) {
		std::cin >> Array[i];
	}

	std::sort(Array, Array + Count);

	std::cout << "Enter key: " << std::endl;

	std::cin >> Key;

	bool Flag = false;
	int LeftBorder = 0;
	int RightBorder = Count - 1; //index
	int Middle;

	while ((LeftBorder <= RightBorder) && (Flag != true)) {
		Middle = (LeftBorder + RightBorder) / 2; 

		if (Array[Middle] == Key) Flag = true; 
		if (Array[Middle] > Key) RightBorder = Middle - 1;
		else LeftBorder = Middle + 1;
	}
	if (Flag) 
	{
		std::cout << "Index elem " << Key << " in array = " << Middle;
	}	
	else 
	{
		std::cout << "Sorry. No this elem";
	}
	return 0;
}