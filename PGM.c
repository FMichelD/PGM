#include <PGM.h>

//Private
static bool isImageFormatValid(const char *buffer)
{
    if(buffer[0] == 'P' && buffer[1] == '2')
    {
        return 1;
    }

    return 0;    
}

static PGMPixel *createPixeis(PGMImage *img)
{
    //Memory allocation for "rows x cols" PGMPixels
    img->pixels = (PGMPixel*)malloc(img->rows * img->cols * sizeof(PGMPixel));
}

//==============================================================================
//Public
PGMImage* createPGMImage()
{
        //Memory allocation for PGMImage
    PGMImage *img = (PGMImage*)malloc(sizeof(PGMImage));
    if(!img)
    {
        printf("Unable to allocate memory\n");
        exit(1);
    }

    return img;
}

void deletePGM(PGMImage *img)
{
    free(img->pixels);
    img->pixels = NULL;

    free(img);
    img = NULL;
}

PGMImage* readPGMFromFile(FILE *imgFile)
{
    char buffer[16];

    //Read 1st line with file format
    fgets(buffer, sizeof(buffer), imgFile);
    if(!isImageFormatValid((const char *)&buffer))
    {
        printf("Invalid image format (must be 'P2')\n");
        exit(1);
    }

    PGMImage *img = createPGMImage();

    //Get image size
    fscanf(imgFile, "%d %d", &img->cols, &img->rows);
    createPixeis(img);

    //Get max value for white color
    fscanf(imgFile, "%d", &img->whiteDepth);

    //Read pixels
    int value;    
    int i;
    for(i = 0; i < img->rows * img->cols; i++)
    {        
        fscanf(imgFile, "%d", &value);
        img->pixels[i].grayValue = value;    
    }    
    return img;
}

void savePGM(const char *fileName, const PGMImage *img)
{
    FILE *ImgToSave;

    ImgToSave = fopen(fileName, "w");
    if(!ImgToSave)
    {
        printf("Nao foi possivel abri a imagem: %s\n", fileName);
        exit(1);
    }

    fprintf(ImgToSave, "P2\n");
    fprintf(ImgToSave, "%d %d\n", img->cols, img->rows);
    fprintf(ImgToSave, "%d\n", img->whiteDepth);
    for(int i = 0; i < img->rows; i++) 
    {
        for(int j = 0; j < img->cols; j++)
        {
           fprintf(ImgToSave, "%d ", img->pixels[i * img->cols + j].grayValue);
        }
        fprintf(ImgToSave, "\n");
    }
}

PGMImage *invertColor(const PGMImage *img)
{
    PGMImage *invertedColor = (PGMImage*)malloc(sizeof(PGMImage));
    invertedColor->cols = img->cols;
    invertedColor->rows = img->rows;
    invertedColor->whiteDepth = img->whiteDepth;
    createPixeis(invertedColor);

    for(int i = 0; i < (img->cols * img->rows); i++)
    {
        invertedColor->pixels[i].grayValue = img->whiteDepth - img->pixels[i].grayValue;
    }

    return invertedColor;
}



// PGMImage* readPGMFromInput()
// {
//     char buffer[16];

//     //Read 1st line with file format
//     fgets(buffer, sizeof(buffer), stdin);
//     if(!isImageFormatValid((const char *)&buffer))
//     {
//         printf("Invalid image format (must be 'P2')\n");
//         exit(1);
//     }

//     PGMImage *img = createPGMImage();

//     //Get image size
//     scanf("%d %d", &img->cols, &img->rows);
//     printf("rows = %d\ncols = %d\n", img->rows, img->cols);

//     //Memory allocation for "rows x cols" PGMPixels
//     img->pixels = (PGMPixel*)malloc(img->rows * img->cols * sizeof(PGMPixel));

//     //Get max value for white color
//     scanf("%d", &img->whiteDepth);
//     printf("white = %d\n", img->whiteDepth);

//     //Read pixels
//     int value;
    
//     int i;
//     for(i = 0; i < img->rows * img->cols; i++)
//     {        
//         scanf("%d", &value);
//         img->pixels[i].grayValue = value;    
//     }    



//     return img;
// }


