#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  MAX_BLOC_USED 30

typedef struct inode
{
	char* name; //Nom du fichier
	char permission[8]; // Droit
	int typeFile; //Type du fichier
	int useBloc[MAX_BLOC_USED]

}Inode;


#define BLOC_SIZE 1024

typedef struct bloc
{
	int id; //Id bloc
	char data[BLOC_SIZE]; //Données
	int sizeData; //Taille utilisé

	int next_bloc;
	int previous_bloc;

}Bloc ;


#define MAX_INODE 15
#define MAX_BLOC (MAX_INODE*MAX_BLOC_USED)

typedef struct disk
{
  Bloc bloc[];
  Inode inode[];

}Disk;
