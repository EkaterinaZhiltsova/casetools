/**
 * @file
 * bmp_erode.c -- программа для наложения фильтра Эрозия на 
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
 * @brief Метод для наложения фильтра Эрозия на 
 * изображение в формате BMP
 *
 * @param image Изображение в формате BMP
 *
 * @return void
 */
void bmp_erode(bmp_image image)
{
    unsigned int i, j, p, k, q;
    double *a;
    
    /* Получаем линейные размеры изображения */
    unsigned int w = image.header.width;
    unsigned int h = image.header.height;

    /*Создание массива - копии изображения, с добавлением крёв*/
    a = (double*)malloc((w + 4)*3*(h + 4)*sizeof(double));
    
    /*Для каждого слоя цветов*/
    for (p = 0; p < 3; p++)
     /* Для всех строк пикселей */
     for (i = 0; i < h; i++) 
        /* Для каждого пикселя */
        for(j = 0; j < w; j++)                   
	    a[p * (h + 4) * (w + 4) + (i + 2) * (w + 4) + (j + 2)] =
	     image.pixel_array[p * h * w + i * w + j];
           
/*Заполнение краёв*/    
    /*Низ*/
    /*Для каждого слоя цветов*/
    for (p = 0; p < 3; p++)
     /* Для всех строк пикселей */
     for (i = 0; i < 2; i++) 
        /* Для каждого пикселя */
        for(j = 2; j < w + 2; j++) 
	    a[p * (h + 4) * (w + 4) + i * (w + 4) + j] =
		image.pixel_array[p * h * w + (j - 2)];
    
    /*Верх*/
    /*Для каждого слоя цветов*/
    for (p = 0; p < 3; p++)
     /* Для всех строк пикселей */
     for (i = h + 2; i < h + 4; i++) 
        /* Для каждого пикселя */
        for(j = 2; j < w + 2; j++) 
	    a[p * (h + 4) * (w + 4) + i * (w + 4) + j] =
		image.pixel_array[p * h * w + (h - 1) * w + (j - 2)];	
         
    /*Левый край*/
    /*Для каждого слоя цветов*/
    for (p = 0; p < 3; p++)
     /* Для всех строк пикселей */
     for (i = 0; i < h + 4; i++)
        /* Для каждого пикселя */
        for(j = 0; j < 2; j++) 
	    a[p * (h + 4) * (w + 4) + i * (w + 4) + j] =
		image.pixel_array[p * h * w + i * w];
	     
    /*Правый край*/
    /*Для каждого слоя цветов*/
    for (p = 0; p < 3; p++)
     /* Для всех строк пикселей */
     for (i = 0; i < h + 4; i++) 
        /* Для каждого пикселя */
        for(j = w + 2; j < w + 4; j++) 
	    a[p * (h + 4) * (w + 4) + i * (w + 4) + j] =
		image.pixel_array[p * h * w + i * w + (w - 1)];
       
/*Фильтр*/
    /*Для каждого слоя цветов*/
    for (p = 0; p < 3; p++) 
     /* Для всех строк пикселей */
     for (i = 2; i < h + 2; i++) 
        /* Для каждого пикселя */
        for(j = 2; j < w + 2; j++) {
	    double max = 0;
	    /*Матрица 5*5*/
	    for (k = i - 2; k < i + 3; k++)
		for (q = j - 2; q < j + 3; q++){
		    if (a[p * (h + 4) * (w + 4) + k * (w + 4) + q] > max)
			max = a[p * (h + 4) * (w + 4) + k * (w + 4) + q];
		}
	 image.pixel_array[p * h * w + (i - 2) * w + (j - 2)] = max;
	}
    free(a);
}



    
