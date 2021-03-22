#include "PGM.h"

int main(int argc, char *argv[])
{
    FILE *file = NULL;    
    char imagePath[512];
    PGMImage *pgmImage;

    printf("Digite o caminho completo para a imagem: ");
    scanf("%s", &imagePath);

    file = fopen(imagePath, "r");
    if(!file)
    {
        printf("Nao foi possivel abri a imagem: %s\n", imagePath);
        exit(1);
    }

    pgmImage = readPGMFromFile(file);
    fclose(file);

    savePGM("new.pgm", pgmImage);

    PGMImage *inverted = invertColor(pgmImage);
    savePGM("inverted.pgm", inverted);
    deletePGM(inverted);

    deletePGM(pgmImage);
    pgmImage = NULL;    

    printf("\n Hello World!\n");
    return 0;
}
