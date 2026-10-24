#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

enum word{
	NA,
	WA,
	WB,
	WC
};

enum word wordType(char* text, int *loc);

int main(){
	srand(time(NULL));
	unsigned char vals[4][4] = {0};
	unsigned char inpt[10240] = {0};
	puts("Enter some text:");
	scanf("%10239[^\n]%*c", inpt);
	printf("%s\n", inpt);
	int loc = 0;
	enum word cwd = NA;
	enum word pwd = NA;
	while (inpt[loc]!='\0'){
		pwd = cwd;
		cwd = wordType(inpt, &loc);
		vals[pwd][cwd]++;
		printf("%d\n", loc);
		loc++;
	}
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			printf("%d ", vals[i][j]);
		}
		puts("");
	}
	char tmp;
	scanf("%c", &tmp);
	int mx;
	cwd = tmp % 4;
	int randy = 0;
	int rande = 0;
	while (1){
		pwd = cwd;
		mx = 0;
		for (int i = 0; i < 4; i++){
			if (vals[pwd][i] > mx){
				mx = vals[pwd][i];
				loc = i;
			}
		}
		cwd = loc;
		randy++;
		if (cwd==pwd){
			cwd = (cwd + pwd + rand()) % 4; 
			randy=0;
		}
		rande += abs(cwd - pwd);
		if (rande>=21){
			cwd = (cwd + pwd + rand()) % 4;
			rande = 0;
		}
		if (cwd==WA) printf("WA ");
		else if (cwd==WB) printf("WB ");
		else if (cwd==WC) printf("WC ");
		else printf("NA ");
		fflush(stdout);
		usleep(10000);
	}
	return 0;
}

enum word wordType(char* text, int *loc){
	enum word ret;
	if (text[*loc]=='w' && text[*loc+1]=='a') ret = WA;
	else if (text[*loc]=='w' && text[*loc+1]=='b') ret = WB;
	else if (text[*loc]=='w' && text[*loc+1]=='c') ret = WC;
	else ret = NA;
	while (text[*loc]!=' ' && text[*loc]!='\n' && text[*loc]!='\0'){
		(*loc)++;
	}
	printf("%d ", ret);
	if (ret==WA) puts("WA");
	else if (ret==WB) puts("WB");
	else if (ret==WC) puts("WC");
	else puts("NA");
	return ret;
}
