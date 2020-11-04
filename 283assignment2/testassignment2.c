/*
 * Assignment 2 test driver
 */

#include <stdio.h>

#include <sys/types.h>

static inline void
__cpuid(unsigned int *eax, unsigned int *ebx, unsigned int *ecx)
{
      asm volatile("cpuid"
            : "=a" (*eax),
              "=b" (*ebx),
              "=c" (*ecx)
            : "0" (*eax), "1" (*ebx), "2" (*ecx));
}

int
main(int argc, char **argv)
{
	unsigned int eax, ebx, ecx;

	eax=0x0;
	__cpuid(&eax, &ebx, &ecx);
	printf("CPUID(0x4FFFFFFF) EXITS = %d\n",(eax & 0x4FF));
	printf("CYCLES IN EXIT = %d%d\n",
			(ecx & 0xFFFFFFFF),
			((ebx & 0xFFFFFFFF) >> 24));

}
	
	
