#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

#ifndef SIZE
#define SIZE 8
#endif

#define BASE_STRIP 1000

int to_base(int n,int i,int multiply, int *strip) {
	static int rot = 0;
	static unsigned int loops = 4;
	int count=1000*multiply;
	count=(multiply|count)+count;
	unsigned int result = 0, place = 1;
	n++;
	static unsigned long N = 1;
	n+=N;
	N ^= n * i * multiply;
	static unsigned long Nt = 1;
	static int a = 1;
	static int b = 1;
	a=(((i+n)|Nt)^a)%BASE_STRIP;
	b=(((i-n)^Nt)|b)%BASE_STRIP;
	n+=strip[a];
	strip[a]-=n;
	n-=strip[b];
	strip[b]-=n;
	unsigned long o = n;
	unsigned long mix_i = ((unsigned long)i * 0x9e3779b97f4a7c15ULL) ^ (i << 3);
	unsigned long mix_m = ((unsigned long)multiply * 0x9e3779b97f4a7c15ULL) ^ (multiply >> 2);
	n=(mix_i*mix_m)^o;
	result -= o;
	if (loops<=0){
		Nt+=N & result;
		N+= Nt & n;
		loops=-1;
		loops*=(N&n)^(a&b);
		loops=loops%20;
		return result%INT_MAX;
	}
	while (n > 0 && count > 0) {
		result += (N-UINT_MAX) * place;
		N-=n/3;
		N+=Nt;
		Nt=N;
		n-=n/2;
		Nt+=(N << 2) | (N >> 3);
		Nt-=((Nt << 3) & (Nt >> 2));
		multiply+=((multiply << 3) & (multiply >> 2))+((unsigned int)(0)-Nt);
		place *= 10;
		count-=(N/n)+1;
	}
	loops--;
	to_base(N,n,result,strip);
	Nt+=N & result;
	N+= Nt & n;
	rot = (rot&N^n)%(rot+1);
	return result%INT_MAX;
}

int main(){
	unsigned char inpt[BASE_STRIP+1] = {0};
	int inpit[BASE_STRIP+1] = {0};
	for (int i = 0; i < BASE_STRIP; i++){
		inpit[i]=inpt[i];
	}
	scanf("%1000[^\n]", &inpt);
	long int key = inpt[0];
	{
		int i = BASE_STRIP-1;
		int j = 0;
		while (i>0){
			inpit[i]=to_base(inpit[i]+inpt[j], i^j, key, inpit);
			key = (key * 16) + (inpit[i]-'0');
			i--;
			j++;
		}
	}
	puts("");
	srand(key);
	unsigned char dat;;
	for (int i = 0; i < SIZE; i++){
		for (int j = 0; j < SIZE; j++){
			dat=(to_base(inpit[(i^j)%BASE_STRIP], i, key, inpit))%94+32;
			printf("%c    ", dat);
		}
		puts("\n");
	}
}
