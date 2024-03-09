#!/bin/bash

if [[ "$1" == "?" ]]; then
	echo "1 parametr - suffix(rashirenie file\n 2 parametr - long(ves file)\n";
	echo "ukazivaya razmer vi zadaete dlinu dlya dopolneniya"
fi;

reference_file=~/Документы/test/file_1
target_directory=~/Документы/test

# Получаем хэш указанного файла
reference_hash=$(md5sum "$reference_file" | awk '{print $1}')

# Обходим все файлы в указанной директории
#for file in "$target_directory"/*; do
find "$target_directory" -type f | while read file; do
    # Проверяем, является ли текущий файл обрабатываемым файлом
    if [ -f "$file" ]; then
        # Получаем хэш текущего файла
        file_hash=$(md5sum "$file" | awk '{print $1}')
        #echo $file_hash
        # Сравниваем хэши
        if [ "$file_hash" = "$reference_hash" ]; then
            if [ -f "$file" ] && [ "$file" != "$reference_file" ]; then
            	#echo "$file"
            	#echo "$reference_file"
            	echo "Deleting $file"
            	rm "$file"
            fi
        fi
    fi
done

