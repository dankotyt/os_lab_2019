#include "revert_string.h"

void RevertString(char *str)
{
	if (str == 0) return;

	int left = 0;
	int right = strlen(str) - 1;

	while(left < right) {
		char temp = str[left];
		str[left] = str[right];
		str[right] = temp;

		left++;
		right--;
	}
}

