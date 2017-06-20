#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define invite "Shell@CKLS>> "

char *liste_commandes[] = {
  "cat",
  "cd",
  "cp",
  "ln",
  "ls",
  "mkdir",
  "pwd",
  "rm"
};

int nombre_commandes() {
  return sizeof(liste_commandes) / sizeof(char *);
}

char* lire_saisie()
{
	char  c;
	char* saisie = malloc(sizeof(char)*1024); //1024 caractères max
	int   indice = 0;
	
	while((c=getchar())!='\n')
	{
		if(!(c==' ' && indice>0 && saisie[indice-1]==' '))
		{
			saisie[indice++]=c;
		}		
	}
	saisie[indice]='\0';
	return saisie;
}

char** separer_saisie(char* saisie)
{
	char   separateur[2] = " ";
	char*  token         = NULL;
	char** arguments     = malloc(sizeof(char*)*64); //64 arguments max
	int    indice        = 0;
	
	token=strtok(saisie, separateur);
	while(token!=NULL)
	{
		arguments[indice++]=token;
		token=strtok(NULL, separateur);
	}
	arguments[indice]=NULL;
	return arguments;
}

int executer(char** args)
{
	if(args[0]==NULL)
	{
		return 1;
	}
	else if(strcmp(args[0],"exit")==0)
	{
		return 0;
	}
	else
	{
		for (int i = 0; i < nombre_commandes(); i++)
		{
			if (strcmp(args[0], liste_commandes[i]) == 0) //si la commmande existe
			{
				printf("%i %s\n", nombre_commandes(), liste_commandes[i]);
				return 1;
				//return (*liste_commandes[i])(args);
			}
		}
		printf("La commande '%s' n'existe pas\n",args[0]);
		return 1;
	}
}

int shell()
{
	int    continuer = 1;
	char*  saisie;
	char** arguments;
	while(continuer)
	{
		printf(invite);
		saisie    = lire_saisie();
		arguments = separer_saisie(saisie);
		continuer = executer(arguments);
	}
	return 0;
}


int main(int argc, char* argv[])
{
	printf("    Bienvenue dans le Shell CherKhaLeSy\n\n");    
	shell();
	return 0;
}

