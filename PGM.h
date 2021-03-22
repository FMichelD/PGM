#ifndef PGM_H
#define PGM_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct PGMImage PGMImage;

PGMImage* createPGMImage();
void deletePGM(PGMImage *img);
void savePGM(const char *fileName, const PGMImage *img);
PGMImage* readPGMFromFile(FILE *imgFile);
PGMImage* invertColor(const PGMImage *img);
PGMImage* brightenImage(const PGMImage *img, int brighten);

#endif