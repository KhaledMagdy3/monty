#include "monty.h"

/**
 * get_filename - get_filename
 * @filename: file name
 * Return: void
*/

void get_filename(char *filename)
{
	FILE *nu;

	nu = fopen(filename, "r");
	if (nu == NULL)
	{
		get_filename_failed(filename);
	}

	argument->file = fopen(filename, "r");
	if (argument->file == NULL)
	{
		fclose(nu);
		get_filename_failed(filename);
	}
}
