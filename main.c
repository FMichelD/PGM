#include "PGM.h"

void menuInvertImage(const PGMImage *img)
{
    char newImg[128];

    printf("Digite o caminho e o nome da nova imagem: ");        
    scanf("%s", &newImg);

    PGMImage *inverted = invertColor(img);
    savePGM(newImg, inverted);
    deletePGM(inverted);
}

void menuClareiaImagem(const PGMImage *img)
{
    char newImg[128];
    
    printf("Digite um valor para clareamento entre 0 e 255\n");
    int brighter;
    scanf("%d", &brighter);
    printf("Digite o caminho e o nome da nova imagem: ");
    scanf("%s", &newImg);

    PGMImage *brightest = brightenImage(img, brighter);
    savePGM(newImg, brightest);
    deletePGM(brightest);
}

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

    int option;
    printf("Selecione: \n");
    printf("1: Inverter Cores\n");
    printf("2: Clarear imagem\n: ");

    scanf("%d", &option);
    switch (option)
    {
    case 1:
        menuInvertImage(pgmImage);
        break;
    case 2:
        menuClareiaImagem(pgmImage);
    default:
        break;
    }

    deletePGM(pgmImage);
    pgmImage = NULL;    

    printf("\nOK\n");
    return 0;
}
