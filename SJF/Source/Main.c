#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>


#define NB_Blocs 2048
#define Taille_Bloc 512


typedef struct Bloc Bloc ;

struct Bloc
{
    int id;
    Bloc * suivant ; //pointeur sur le bloc suivant

};

typedef struct Liste_Blocs  Liste_Blocs;
struct Liste_Blocs

{

    Bloc *premier;

};

void CreationDisque()
	{
	// Creation d'un fichier de Stockage d'une taille de 1 MO.
    int fd ;

    fd = open("./DISQUE", O_WRONLY |O_RDONLY| O_CREAT , 0666);
    if (fd < 0) {
    	 exit(EXIT_FAILURE);

    }

    lseek(fd, NB_Blocs * Taille_Bloc, SEEK_CUR);
    write(fd, "/0", 2);
    close(fd);

	}

//Création de la structure de controle + premier élement de la liste
Liste_Blocs *initialisation()

{

    Liste_Blocs *liste = malloc(sizeof(*liste));

    Bloc *bloc = malloc(sizeof(*bloc));


    if (liste == NULL || bloc == NULL)

    {

    	  exit(EXIT_FAILURE);

    }


    bloc->id = 0;

    bloc->suivant = NULL;

    liste->premier = bloc;


    return liste;

}
Liste_Blocs* AjouterFin(Liste_Blocs* liste,int nv)
{
	/* On crée un nouveau Bloc */

    Bloc* blocnv = malloc(sizeof(Bloc));



    /* On assigne la valeur au nouvel élément */

    blocnv->id = nv;



    /* On ajoute en fin, donc aucun élément ne va suivre */

    blocnv->suivant = NULL;



    if(liste == NULL)

    {

        /* Si la liste est videé il suffit de renvoyer le nv bloc */

        return  blocnv;

    }

    else

    {

        /* Sinon, on parcourt la liste à l'aide d'un pointeur temporaire et on

        indique que le dernier élément de la liste est relié au nouvel élément */

        Bloc* temp=liste->premier;

        while(temp->suivant != NULL)

        {

            temp = temp->suivant;

        }

        temp->suivant = blocnv;

        return liste;

    }

}


//Affichage liste pour vérifier

Liste_Blocs AfficherListe(Liste_Blocs *liste)

{
    if (liste == NULL)
    {
    	exit(EXIT_FAILURE);
    }

    Bloc *actuel = liste->premier;


    while (actuel != NULL)

    {
        printf("%d -> ", actuel->id);
        actuel = actuel->suivant;
    }

    printf("NULL\n");
}

int main(int argc, const char *argv[])
{
	int i =0;

	// CreationDisque();
	 Liste_Blocs *maListe = initialisation() ;

	 //chainage de tous les blocs du fichier de stockage
	 for(i=1; i<2048; i++)
	 {
		 AjouterFin(maListe,i);
	 }
	 AfficherListe(maListe);

    return 0;
}
