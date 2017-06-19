#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//primitives fichiers
FILE* mycreat(char *nom, char* mode);
FILE* myopen(char *nom, char* mode);
int myclose(FILE* inode);
char* myread(FILE* inode, char *buffer, int nbOctets);
int mywrite(FILE* inode,char *buffer, int nbOctets); 
int removeFile(char *nom);

//autres primitives 
int exec_shell(char** argv);

int main(void)
{
	//
	return 0;
}

FILE* mycreat(char *nom, char* mode)
{
	FILE* file=NULL;
	//
	return file;
}

FILE* myopen(char *nom, char *mode)
{
	FILE* file = NULL;
	
	file = fopen(nom, mode);
	if(file==NULL)
		printf("Impossible d'ouvrir le fichier.\n");
	
	return file;
}

int myclose(FILE* inode)
{
	if(inode==NULL)
		printf("Impossible de fermer le fichier.\n");
	else
		fclose(inode);
		
	return 0;
}

char* myread(FILE* inode, char *buffer, int nbOctets)
{
	if(inode!=NULL)
	{
		 fgets(buffer, nbOctets, inode);
	}
	else
		printf("Impossible d'ecrire dans ce fichier.\n");
	
	return buffer;
}

int mywrite(FILE* inode, char *buffer, int nbOctets)
{
	int i=0;
	char buf=' ';
	
	if(inode!=NULL)
	{
		while(i<nbOctets && buffer[i]!=EOF)
		{
			buf=buffer[i];
			fputc(buf, inode);
			i++;
		}
	}
	else
		printf("Impossible d'ecrire dans ce fichier.\n");
	
	return 0;
}

int removeFile(char *nom)
{
	char choix=' ';
	
	printf("Voulez vous vraiment supprimer ce fichier ?\n");
	scanf("%c",&choix);
	if(choix=='o' || choix=='O')
		remove(nom);
	
	return 0;
}


