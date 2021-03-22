#ifndef PGM_H
#define PGM_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct PGMPixel{
    int grayValue;
}PGMPixel;

typedef struct PGMImage{
    int rows;
    int cols;
    int whiteDepth;
    PGMPixel *pixels;
}PGMImage;

PGMImage* createPGMImage();
void deletePGM(PGMImage *img);

PGMImage* readPGMFromFile(FILE *imgFile);
void savePGM(const char *fileName, const PGMImage *img);
PGMImage *invertColor(const PGMImage *img);
#endif