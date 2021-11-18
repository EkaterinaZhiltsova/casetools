/**
* @file
* Заголовочный файл для проекта filter
*/
#ifndef BMP_H
#define BMP_H

#include <stdint.h>

/* Структура заголовка BMP-файла */
typedef struct _bmp_header {
    
    /* Данные файлового заголовка */
    uint16_t signature;
    uint32_t file_size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t pixel_array_offset;
    
    /* Данные информационного заголовка */
    uint32_t header_size;
    int32_t width;
    int32_t height;
    uint16_t color_planes;
    uint16_t bits_per_pixel;
    uint32_t compression_method;
    uint32_t image_size;
    int32_t horizontal_resolution;
    int32_t vertical_resolution;
    uint32_t colors;
    uint32_t important_colors;    
} bmp_header;

typedef double *bmp_pixel_array;

typedef struct _bmp_image {
    bmp_header header;
    bmp_pixel_array pixel_array;
} bmp_image;

/**
 * @brief Метод для чтения файлов изображений в формате BMP
 *
 * @param bmp_file_path Путь до файла изображения в формате BMP
 *
 * @return Изображение в формате BMP
 */
bmp_image bmp_read(char *bmp_file_path);

/**
 * @brief Метод для записи файлов изображений в формате BMP
 *
 * @param bmp_file_path Путь до файла изображения в формате BMP
 * @param image Изображение в формате BMP
 *
 * @return void
 */
void bmp_write(char *bmp_file_path, bmp_image image);

/**
 * @brief Метод для наложения чёрно-белого фильтра на 
 * изображение в формате BMP
 *
 * Преобразует цвета пикселей в черно-белую гамму
 * (30% красного + 59% зеленого + 11% синего)
 *
 * @param image Изображение в формате BMP
 *
 * @return void
 */
void bmp_gray(bmp_image image);

/**
 * @brief Метод для наложения фильтра Эрозия на 
 * изображение в формате BMP
 *
 * @param image Изображение в формате BMP
 *
 * @return void
 */
void bmp_erode(bmp_image image);

#endif
