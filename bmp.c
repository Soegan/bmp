#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "bmp.h"
#include "transformations.h"

struct bmp_header* read_bmp_header(FILE* stream) {

    if (stream == NULL) {
        printf("Error during opening file!\n");
        return NULL;
    }

    struct bmp_header* header = malloc(sizeof(struct bmp_header));

    if (header == NULL) {
        printf("Error during opening file!\n");
        return NULL;
    }

    size_t result = fread(header, sizeof(struct bmp_header), 1, stream);

    if (result == 0) {
        printf("Error during opening file!\n");
        free(header);
        return 0;
    }

    // if (header->type[0] != 0x42 || header->type[1] != 0x4D) {
    //     free(header);
    //     return NULL;
    // }

    // if (header->type != "BM") {
    //     printf("Error during opening file!\n");
    //     free(header);
    //     return 0;
    // }

    return header;
}

struct pixel* read_data(FILE* stream, const struct bmp_header* header) {
    if (stream == NULL || header == NULL) {
        printf("Error during opening file!\n");
        return NULL;
    }

    size_t size = header->width * header->height;

    struct pixel* data = malloc(size * sizeof(struct pixel));

    if (data == NULL) {
        free(data);
        return NULL;
    }
    
    fread(data, sizeof(struct pixel), size, stream);

    return data;
}

struct bmp_image* read_bmp(FILE* stream) {
    if (stream == NULL) {
        printf("Error during opening file!\n");
        return NULL;
    }
    
    struct bmp_header* header = read_bmp_header(stream);
    if (header == NULL) {
        free(header);
        printf("Error: This is not a BMP file.\n");
        return NULL;
    }

    struct pixel* data = read_data(stream, header);
    if (data == NULL) {
        free(header);
        free(data);
        printf("Error: Corrupted BMP file.\n");
        return NULL;
    }

    struct bmp_image* image = malloc(sizeof(struct bmp_image));
    if (image == NULL) {
        free(header);
        free(data);
        printf("Error during opening image!\n");
        return NULL;
    }

    image->header = header;
    image->data = data;

    return image;
}

bool write_bmp(FILE* stream, const struct bmp_image* image) {
    if (stream == NULL || image == NULL) {
        printf("Error during opening file!\n");
        return false;
    }

    fwrite(image->header, sizeof(struct bmp_header), 1, stream);

    fwrite(image->data, sizeof(struct pixel), image->header->width * image->header->height, stream);

    return true;
}

void free_bmp_image(struct bmp_image* image) {
    if (image) {
        free(image->header);
        free(image->data);
        free(image);
    }
}