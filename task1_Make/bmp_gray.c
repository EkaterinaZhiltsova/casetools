/**
 * @file
 * bmp_grey.c -- программа для наложения чёрно-белого фильтра на 
 * изображение в формате BMP
 *
 * @copyright Copyright (c) 2019, 
 * @author Ekaterina Zhilcova <zhilcova@cs.petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */ 

#include "bmp.h"

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
void bmp_gray(bmp_image image)
{
    unsigned int i, j;
    
    /* Получаем линейные размеры изображения */
    unsigned int w = image.header.width;
    unsigned int h = image.header.height;

    /* Для всех строк пикселей */
    for (i = 0; i < h; i++) {
        /* Для каждого пикселя */
        for(j = 0; j < w; j++) {
            
            /* Получаем компоненты цвета текущего пикселя*/
            double blue = image.pixel_array[0 * h * w + i * w + j];
            double green = image.pixel_array[1 * h * w + i * w + j];
            double red = image.pixel_array[2 * h * w + i * w + j];
            
            /* Преобразуем в черно-белое */
            image.pixel_array[0 * h * w + i * w + j] =
            image.pixel_array[1 * h * w + i * w + j] =
            image.pixel_array[2 * h * w + i * w + j] =
                0.11 * blue + 0.59 * green + 0.30 * red;
        }
    }
}
