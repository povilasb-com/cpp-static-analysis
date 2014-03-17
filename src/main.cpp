#include <iostream>


using namespace std;


// #1 Bug
void
wrong_delete_operator(void)
{
	// Alocates a single element.
	char *symbol = new char;
	char *buff = symbol;

	// Deletes array.
	delete[] buff;
}


// #2 Bug
void
memleak(void) {
	int *number = new int;
	char *buff = (char *)malloc(10);
	int *number_array = new int[10];

	buff = buff;
	number = number;
	number_array = number_array;
}


// #3 Bug
void
static_array_out_of_bounds(void) {
	int array[10];
	int i = 11;
	int number = array[i];
	number = number;
}


// #4 Bug
void
dynamic_array_out_of_bounds(void) {
	int *array = new int[10];
	int i = 11;
	int number = array[i];

	number = number;
	delete[] array;
}


// #5 Bug
void
dereferencing_null_pointer()
{
	int *number = NULL;

	*number = 5;
}

struct object
{
	int value;
};

void
dereferencing_null_pointer_complex(struct object *obj)
{
	if (obj == NULL)
	{
		goto done;
	}

	obj->value = 1;

done:
	// Wait, what if obj was NULL?
	obj->value = 2;
}


// #6 Bug
void
bad_free(void)
{
	char *n = new char;
	char *m = (char *)malloc(1);

	free(n);
	delete m;
}


int
main(void)
{
	int retval = 0;

	return retval;
}
