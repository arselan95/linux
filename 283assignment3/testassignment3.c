/*
 * Assignment 3 test driver
 */

#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>

static inline void
__cpuid(unsigned int *eax, unsigned int *ecx)
{
      asm volatile("cpuid" : "=a" (*eax) ,"=b" (*ecx) : "0" (*eax), "1" (*ecx));
}

int
main(int argc, char *argv[])
{
	unsigned int eax, ecx;

	eax=atoi(argv[1]);
	__cpuid(&eax, &ecx);
	printf("CPUID(0x4FFFFFFE) EXITS = %d\n",(eax));
	printf("GIVEN EXIT NUMBER = %d\n",atoi(argv[1]));

}
