#include <iostream>

using namespace std;

int main( void )
{
	int num;
	while(1)
	{
		cin >> num;
		if( num == 42 )
			break;
		else
			cout << num << "\n";
	}
	
	return 0;
}

