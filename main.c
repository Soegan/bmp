#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "bmp.h"
#include "transformations.h"

int main () {

    FILE* f = fopen("./assets/adventurer.bmp", "rb");

    if (f == NULL) {
        printf("Error during opening file!\n");
        return 1;
    }

    struct bmp_image* image = read_bmp(f);

    if (image == NULL) {
        printf("Error while reading BMP file");
        return 1;
    }

    fclose(f);

    f = fopen("./adventurer2.bmp", "wb");

    struct bmp_image* image2 = flip_horizontally(image);

    bool written2 = write_bmp(f, image2);

    if (written2);

    fclose(f);

    f = fopen("./adventurer3.bmp", "wb");

    struct bmp_image* image3 = flip_vertically(image);

    bool written3 = write_bmp(f, image3);

    if (written3);

    fclose(f);

    f = fopen("./adventurer4.bmp", "wb");

    struct bmp_image* image4 = rotate_left(image);

    bool written4 = write_bmp(f, image4);

    if (written4);

    fclose(f);

    f = fopen("./adventurer5.bmp", "wb");

    struct bmp_image* image5 = rotate_right(image);

    bool written5 = write_bmp(f, image5);

    if (written5);

    free_bmp_image(image);

    return 0;
}