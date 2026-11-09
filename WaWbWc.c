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

int main(){
	srand(time(NULL));
	unsigned long long vals[4][4] = {0};
	puts("Enter some text:");
	int curchar = 0;
	int prevchar = 0;
	int let = 0;
	int sps = 0;
	enum word cwd = NA;
	enum word pwd = NA;
	curchar = getchar();
	while (curchar!=EOF && curchar!='\n'){
		pwd = cwd;
		let = 0;
		sps = 0;
		cwd = NA;
		while (let!=1){
			if (sps==1 && prevchar=='w'){
				if (curchar=='a') cwd = WA;
				else if (curchar=='b') cwd = WB;
				else if (curchar=='c') cwd = WC;
				else cwd = NA;
			}
			if (curchar==EOF || curchar==' ' || curchar=='\n') let = 1;
			prevchar = curchar;
			curchar = getchar();
			sps++;
		}
		vals[pwd][cwd]++;
	}
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			printf("%llu ", vals[i][j]);
		}
		puts("");
	}
	char tmp;
	curchar=getchar();
	while (curchar!=EOF) curchar=getchar(); 
	scanf("%c", &tmp);
	int mx;
	cwd = tmp % 4;
	int randy = 0;
	int rande = 0;
	int loc = 0;
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
		rande += cwd - pwd;
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
