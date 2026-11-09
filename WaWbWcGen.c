#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
	char acter;
	srand(time(NULL));
	while (1){
		acter = rand()%3;
		if (acter == 0) printf("wa ");
		else if (acter == 1) printf("wb ");
		else printf("wc ");
	}
}
