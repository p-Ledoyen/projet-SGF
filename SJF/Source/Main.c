#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <fcntl.h>

#define NB_Blocs 2048
#define Taille_Bloc 512


void CreationDisque()
	{
	// Creation d'un fichier de Stockage d'une taille de 1 MO.
    int fd ;

    fd = open("./DISQUE", O_WRONLY |O_RDONLY| O_CREAT , 0666);
    if (fd < 0) {
        perror("Erreur d'ouverture du fichier ");
        return 2;
    }

    lseek(fd, NB_Blocs * Taille_Bloc, SEEK_CUR);
    write(fd, "/0", 2);
    close(fd);

	}
int main(int argc, const char *argv[])
{
	CreationDisque();

    return 0;
}
