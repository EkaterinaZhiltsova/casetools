filter: filter.o bmp_io.o bmp_erode.o	# компиляция проекта
	gcc -o filter filter.o bmp_io.o bmp_erode.o

.PHONY: filter start clean distclean install dist help wc document

.DEFAULT: 
	@echo "Заданной цели не существует"
	@make help
	
.SILENT: help wc .DEFAULT

filter.o: filter.c bmp.h	# сборка объектного файла filter.o
	gcc -c -Wall -Wextra filter.c

bmp_erode.o: bmp_erode.c bmp.h	# сборка объектного файла bmp_erode.o
	gcc -c -Wall -Wextra bmp_erode.c

bmp_io.o: bmp_io.c bmp.h	# сборка объектного файла bmp_io.o
	gcc -c -Wall -Wextra bmp_io.c

start: filter	# тестовый запуск проекта
	./filter images/cat.bmp cat_result.bmp

clean:	# очистка проекта (без удаления некоторых файлов)
	rm -rf *.o filter

distclean: clean	# полная очистка проекта
	rm -f TAGS config.status *.bmp *# Doxyfile

install: filter	# установка скомпилированного проекта
	cp filter /home/02/zhilcova/casetools/Program/
	cp -r images /home/02/zhilcova/casetools/Program/

dist: filter	# создание дистрибутива проекта
	zip -r erode_filter.zip images bmp.h bmp_erode.c bmp_gray.c bmp_io.c filter.c Makefile

help:	# справка об использовании файла сборки
	@./script

wc:	# запуск внешней утилиты wc (выведет три числа, обозначающих количество строк, слов и байт информации в Makefile)
	wc Makefile

document:	# создание документации
	doxygen Doxyfile


