#include "swap.h"

void Swap(char *left, char *right)
{
	char temp = *left; // Сохраняем значение left во временной переменной
    *left = *right;    // Меняем значение left на значение right
    *right = temp;
}
