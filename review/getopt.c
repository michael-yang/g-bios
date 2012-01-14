#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
	int opt;

	while ((opt = getopt(argc, argv, "nla:d:")) != -1) {
		switch(opt){
			case 'n':
				printf("%s\n", "opt is n");
				break;
			case 'l':
				printf("%s\n", "opt is l");
				break;
			case 'a':
				printf("%s\n", "opt is a");
				break;
			case 'd':
				printf("%s\n", "opt is d");
				break;
			default:
				break;
		}
	}
	return 0;
}
