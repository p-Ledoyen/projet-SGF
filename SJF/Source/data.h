#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  MAX_BLOC_USED 30


typedef struct inode
{
	char* name;
	char permission[8];
	int typeFile;
	int useBloc[MAX_BLOC_USED]
	int nbBlocUsed;

}Inode;


#define BLOC_SIZE 1024

typedef struct bloc
{
  int id;
	char data[BLOC_SIZE];
	int sizeData;

	int next_bloc;
	int previous_bloc;

}Bloc ;
