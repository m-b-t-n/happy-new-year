/*
 * Copyright 2020 m-b-t-n <mbtn_0xff@outlook.com>
 */

#include <stdio.h>
#include <time.h>

static const int hny_str[16] = {
	0x48,
	0x41,
	0x50,
	0x50,
	0x59,
	0x5F,
	0x4E,
	0x45,
	0x57,
	0x5F,
	0x59,
	0x45,
	0x41,
	0x52,
	0x0D,
	0x0A
};

static int get_year(char* const str)
{
	time_t timer;
	struct tm* date;
	size_t ret;

	timer = time(NULL);
	date = localtime(&timer);

	ret = snprintf(str, sizeof(str), "%4d", (date->tm_year + 1900));
	if (ret < 1) {
		return -1;
	}

	return (int)ret;
}

int main(void)
{
	int i;
	int ret;
	char year_str[5];

	ret = get_year(year_str);

	printf("%s ", year_str);
	for (i=0; i<16; ++i) {
		putchar(hny_str[i]);
	}
	printf("\n");

	return 0;
}

