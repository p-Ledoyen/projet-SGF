#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
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
int redirectionTHEN(char **argv1, char **argv2);

int main(void)
{
	char *argv1[]={"pwd",NULL};
	char *argv2[]={"ps",NULL};
	char *argv[]={"ls","-l",NULL};
	exec_shell(argv);
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
		printf("Impossible de lire dans ce fichier.\n");
	
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

int exec_shell(char **argv) //
{
	int i=0, argc;
	char path[128] = "/bin/";
	
    strcat(path, argv[0]);

	/*for(i=0;i<10;i++)
	{
		if(strcmp( argv[i], "|") == 0)
		{
			//erreur de segmentation
			//printf("string #%d: %s\n", i, argv[i]);
			//redirectionTHEN(argv1,argv2);
		}
		i++;
	}*/

	
	if (execve(path, argv , NULL)==-1) //si exec retourne une erreur
	{
			perror("execve failed");
			fflush(stderr);//vide le buffer
			exit(0);
			return -1;
	}
	
	return 0;
}

int redirectionTHEN(char **argv1, char **argv2)
{
        int tube[2];
        if(pipe(tube) == -1) {
          perror("Pipe failed");
          exit(1);
        }

        if(fork() == 0)            //first fork
        {
            close(STDOUT_FILENO);  //on ferme la sortie std
            dup(tube[1]);         //on remplace stdout avec pipe write
            close(tube[0]);       //on ferme pipe read
            close(tube[1]);

            execve(argv1[0], argv1,NULL);
            perror("execvp failed");
            exit(1);
        }

        if(fork() == 0)            //second fork
        {
            close(STDIN_FILENO);   //on ferme stdin
            dup(tube[0]);         //on remplace stdin avec pipe read
            close(tube[1]);       //on ferme pipe write
            close(tube[0]);

            execve(argv2[0], argv2,NULL);
            perror("execvp 2 failed");
            exit(1);
        }
        
		close(tube[0]);
        close(tube[1]);
        wait();
        wait();
        return 0;
}
