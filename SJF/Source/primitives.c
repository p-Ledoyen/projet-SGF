#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//primitives fichiers
int mycreat(char *nom, mode_t mode);
int myclose(int inode);
ssize_t myread(int inode, char *buffer, size_t nbChar);
ssize_t mywrite(int inode,char *buffer, size_t nbChar); 


//autres primitives 
int exec_shell(char** argv);

int main(void)
{
	//
	return 0;
}

int mycreat(char *nom, mode_t mode)
{
	return open(nom, O_WRONLY|O_CREAT|O_TRUNC, mode);//retourne l'inode, crée le fichier s'il n'existe pas, overwrite si le fichier existe
}


int myclose(int inode)
{
	int status=0;
	status=close(inode);
	if(status!=0)
		{
			printf("an error occured.\n");
			return -1;
		}
	else
		return 0;
}

ssize_t myread(int inode, char *buffer, size_t nbOctets)
{
	return read(inode, buffer, nbOctets);
}

ssize_t mywrite(int inode, char *buffer, size_t nbOctets)
{
	return write(inode, buffer, nbOctets);
}

int exec_shell(char ** argv)
{
        
	pid_t   pid=fork();

	if (pid==0) 
	{
		if (execve(argv[0], (char **)argv , NULL)==-1) //si exec retourne une erreur
		{
				printf("Commande invalide : %s\n", argv[0]);
				fflush(stdout);//vide le buffer
				exit(0);
				return -1;
		}
		//sinon le nouveau programme est lancé
	}
	return 0;
}


