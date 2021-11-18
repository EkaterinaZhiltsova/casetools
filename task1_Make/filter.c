/**
 * @file
 * filter.c -- программа для наложения фильтров на 
 * изображение в формате BMP
 *
 * @copyright Copyright (c) 2019, 
 * @author Ekaterina Zhilcova <zhilcova@cs.petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */ 

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

/**
 * @brief Метод для наложения фильтров на 
 * изображение в формате BMP
 *
 * @param argc Число аргументов
 * @param argv Список аргументов
 *
 * @return Возвращает 0 при успехе
 */
int main(int argc, char *argv[])
{     
    bmp_image image;
    
    if (argc < 3) {
        fprintf(stderr, "Usage: %s sourcefile destfile\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    image = bmp_read(argv[1]);
 
    bmp_erode(image);
     
    bmp_write(argv[2], image);
    
    return 0;
}
