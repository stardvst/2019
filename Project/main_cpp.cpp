#include <stdio.h>
#include <stdlib.h>
#include <cppabi.h>

int main()
{
	const char *mangled_name = "_ZNK3MapI10StringName#RefI8GDScriotE10ComparatorIS0_E16DefaultAllocatorE3hasERKS0_";
	int status = -1;

	char *demangled_name = abi::__cxa_demangle(mangled_name, NULL, NULL, &status);
	printf("Demangled: %s\n", demangled_name);

	free(demangled_name);
	return 0;
}
