#include <stdio.h>
#include "palavrasFuncs.h"


int scanearPalavra(char * palavra){
	char c;
	int i=0;
	c = getchar();
	while(c!='\0' && c!=' ' && c!='\t' && c!='\n' && c!=':' && c!=';' && c!=',' && c!='.' && c!='-' && c!='!'){
		if (c == EOF){
			return -1;
		}
		palavra[i] = c;

		i++;
		c = getchar();
	}
	if (i==0){
		return 0;
	}
	palavra[i]='\0';
	return 1;
}


