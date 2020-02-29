#include <iostream>
#include <iostream>
using namespace std;

void Printer (int* val,string seperator = "\n")
{
	cout << val << seperator;
}

int main(void) 
{	
	const int consatant = 20;
	//Printer(consatant);//Error: invalid conversion from 'int' to 'int*'
	Printer(const_cast<int *>(&consatant));
	
	return 0;
}

