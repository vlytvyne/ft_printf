#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int *b;
	b = malloc(10);
	*b = 10;
	printf("1C:%-5c\n", 'a');
	printf("2S:%4.7s\n", "Miami Police");
	printf("3S:%4.7s\n", "KO");
	printf("4P:%20p\n", b);
	printf("5D:%010d\n", 11);
	printf("6D:%-10.4d\n", 12);
	printf("7D:%-.4d\n", 13);
	printf("8D:%-.4d\n", -14);
	printf("9D:%-.0d\n", 0);
	printf("10D:%.d\n", 0);
	printf("11I:% i\n", 15);
	//'o' works similar to 'd' except for '+' and ' '
	printf("12O:%#4o\n", 15);
	printf("13U:%.4u\n", 10);
	printf("14x:%#x\n", 122);
	printf("15X:%#X\n", 122);
	printf("16F:%# 010.f\n", 1234.2);
	printf("17F:%3.4f\n", 1234.2);
}
