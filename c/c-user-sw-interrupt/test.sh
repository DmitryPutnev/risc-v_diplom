#!/bin/bash

# Сборка программы
make > /dev/null 2>&1

# Запуск программы
spike ecall_sw-interrupt > /dev/null 2>&1

# Сохранение кода завершения
exit_code=$?

# Код ожидания
expected_code=0

# Цвета
GREEN="\033[0;32m"
RED="\033[0;31m"
NC="\033[0m"

# Проверка кода завершения
if [ $exit_code -eq $expected_code ]; then
	echo -e "${GREEN}Test passed. Exit code: $exit_code${NC}"
else
	echo -e "${RED}Test failed/ Expected: $expected_code, Got: $exit_code${NC}"
fi

# Очистка файлов
make clean > /dev/null 2>&1
