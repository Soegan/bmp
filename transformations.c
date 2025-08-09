#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "bmp.h"
#include "transformations.h"

struct bmp_image* flip_horizontally(const struct bmp_image* image) {
    struct bmp_header* header = malloc(sizeof(struct bmp_header));
    if (header == NULL) {
        free(header);
        printf("Error: This is not a BMP file.\n");
        return NULL;
    }

    size_t size = image->header->width * image->header->height;
    struct pixel* data = malloc(size * sizeof(struct pixel));
    if (data == NULL) {
        free(header);
        free(data);
        printf("Error: Corrupted BMP file.\n");
        return NULL;
    }

    struct bmp_image* result = malloc(sizeof(struct bmp_image));
    if (result == NULL) {
        printf("Error during opening file!\n");
        free(header);
        free(data);
        return NULL;
    }

    result->header = image->header;

    result->data = data;

    for (int x = 0; x < image->header->height; x++) {
        for (int y = 0; y < image->header->width; y++) {
            result->data[x * image->header->width + (image->header->width - y)] = image->data[x * image->header->width + y];
        }
    }

    return result;
}

struct bmp_image* flip_vertically(const struct bmp_image* image) {
    struct bmp_header* header = malloc(sizeof(struct bmp_header));
    if (header == NULL) {
        free(header);
        printf("Error: This is not a BMP file.\n");
        return NULL;
    }

    size_t size = image->header->width * image->header->height;
    struct pixel* data = malloc(size * sizeof(struct pixel));
    if (data == NULL) {
        free(header);
        free(data);
        printf("Error: Corrupted BMP file.\n");
        return NULL;
    }

    struct bmp_image* result = malloc(sizeof(struct bmp_image));
    if (result == NULL) {
        printf("Error during opening file!\n");
        free(result);
        free(header);
        free(data);
        return NULL;
    }

    result->header = image->header;

    result->data = data;

    for (int x = 0; x < image->header->height; x++) {
        for (int y = 0; y < image->header->width; y++) {
            result->data[(image->header->height - x - 1) * image->header->width + y] = image->data[x * image->header->width + y];
        }
    }

    return result;
}

struct bmp_image* rotate_left(const struct bmp_image* image) {
    struct bmp_header* header = malloc(sizeof(struct bmp_header));
    if (header == NULL) {
        free(header);
        printf("Error: This is not a BMP file.\n");
        return NULL;
    }

    size_t size = image->header->width * image->header->height;
    struct pixel* data = malloc(size * sizeof(struct pixel));
    if (data == NULL) {
        free(header);
        free(data);
        printf("Error: Corrupted BMP file.\n");
        return NULL;
    }

    struct bmp_image* result = malloc(sizeof(struct bmp_image));
    if (result == NULL) {
        printf("Error during opening file!\n");
        free(result);
        free(header);
        free(data);
        return NULL;
    }

    result->header = image->header;

    result->data = data;

    for (int x = 0; x < image->header->height; x++) {
        for (int y = 0; y < image->header->width; y++) {
            result->data[(image->header->height * y) + (image->header->height - x - 1)] = image->data[x * image->header->width + y];
        }
    }

    int tmp;

    tmp = result->header->width;
    result->header->width = result->header->height;
    result->header->height = tmp;

    return result;
}

struct bmp_image* rotate_right(const struct bmp_image* image) {
    struct bmp_header* header = malloc(sizeof(struct bmp_header));
    if (header == NULL) {
        free(header);
        printf("Error: This is not a BMP file.\n");
        return NULL;
    }

    size_t size = image->header->width * image->header->height;
    struct pixel* data = malloc(size * sizeof(struct pixel));
    if (data == NULL) {
        free(header);
        free(data);
        printf("Error: Corrupted BMP file.\n");
        return NULL;
    }

    struct bmp_image* result = malloc(sizeof(struct bmp_image));
    if (result == NULL) {
        printf("Error during opening file!\n");
        free(result);
        free(header);
        free(data);
        return NULL;
    }

    result->header = image->header;

    result->data = data;

    for (int x = 0; x < image->header->height; x++) {
        for (int y = 0; y < image->header->width; y++) {
            result->data[(image->header->height * y) + (image->header->height - x - 1)] = image->data[x * image->header->width + y];
        }
    }

    int tmp;

    tmp = result->header->width;
    result->header->width = result->header->height;
    result->header->height = tmp;

    return result;
}