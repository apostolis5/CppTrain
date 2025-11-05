#include "dangling_pointer.h"

int main() 
{
	int *num_ptr0 = new int(5);
	int *num_ptr1 = num_ptr0;

	//more code
	delete num_ptr1;

	//more code num_ptr0 tries to use the memory


	return 0;
}