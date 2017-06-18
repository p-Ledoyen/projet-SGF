#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOC_SIZE 1024

typedef struct bloc
{
  int id;
	char data[BLOC_SIZE];
	int sizeData;

	Bloc* next_bloc;
	Bloc* previous_bloc;

} bloc ;
