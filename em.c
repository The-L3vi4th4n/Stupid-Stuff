// this is a small C file written with uemacs from Linus Torvalds's repository for the funny
// it contains my opinion on it and what I like about it and is very informal and weirdly written
// note I personally don't like flashy features but like a convenient interface that is easy to work with
// that means I am not concidering fancy stuff like duplicating a line but more of like can I write code
// features that I find important are like being able to copy paste text and mass delete stuff and open multiple files at once
// other features can also be whatever the feature vim's swap files is(idk the name of it) as they are a life saver
// I don't think uemacs has that feature tho or maybe it does and I just never found out about it
// take this with a grain of salt as I am no experienced or good programmer in any regard

#include <stdio.h>

int main(){ 
	char input[2048] = {0};
	scanf("%2047[^\n]", input);
	printf("%s\n", input);
	printf("your input was captured\n");

	printf("\nthis program was written with uemacs from Linux Torvalds's fork of it\n");

	printf("I have like no prlbm with this like I barely use vims features at"
	" all an really don't use them other than some basic ones\n");

	printf("I can use this tho I still prefer vim for any actuall coding as"
	" of now but I have this weird feeling like what I had with vim where I"
	" wanted to use it over tools like sublime text just because I wanted to"
	" and now I love vim\n");
	
	printf("\nthx for listening and also note I will prbly use vim as"
	" it's more convenient and stuff. But I have reasons to try and use this"
	" even tho it can get hard at times(I accidentally deleted this line and"
	" idk how to undo and had to rewrite it from scratch like because I"
	" instincively tap escape after writing something)\n");

	printf("my reasons are as listed:\n");

	printf("1. it is so light weight and minimal which I love\n");

	printf("2. it feels cooler than vim because a non-programmer will look"
	" at this and go 'wow thats cool' and a programmer will go 'wow this"
	" person is hardcore' and that feels cool tho is a VERY stupid reason\n");

	printf("3. my fav person of all time, Linux Torvalds, uses it so like I"
	" want to too :3\n");

	printf(" note: he also actively says not to use it and that him using it"
	" is not a good thing but like I want to use it because I can and y"
	" not?\n");

	printf("4. it is made in C and I love C as it's also minimal\n");

	printf("5. it's has no autocorrent and suggest, which is actually why I"
	" use vim as it for me it works like a text editor but in the terminal and"
	" is more convenient than opening Sublime Text or that one text editing"
	" tool python comes along with that I used learn it. It's also why I hate"
	" VS Code like it's so cluttered at least for me\n");

	printf("6. escape + j is some sort of formatting tool which idk if is in"
	" vim but makes my text sooo much easier to read for me rather than one"
	" veerrry long line tho vim prbly has something like this\n");

	printf("\nbefore I go I will list some key things in uemacs I found:\n\n");

	printf("aborting any one of these(or if confused) -> ctrl+g\n");
	printf("help -> esc+?\n");
	printf("saving the file(anywhere) -> ctrl+x ctrl+w\n");
	printf("saving the file(current file, doesn't work in tty for me) -> ctrl+x ctrl+s\n");
	printf("exiting -> ctrl+x ctrl+c\n");
	printf("setting a mark(to copy or delete) -> esc .\n");
	printf("copying and deleting(from the mark to your current pos) -> ctrl+w\n");
	printf("copying and deleting till the end of your line -> ctrl+k\n");
	printf("copying(from the mark to your current pos) -> esc+w\n");
	printf("going to the start of the file -> esc+<\n");
	printf("going to the end of the file -> esc+>\n");
	printf("going to the start of your current line -> ctrl+a\n");
	printf("going to the end of your current line -> ctrl+e\n");
	printf("opening another file buffer to edit -> ctrl+x ctrl+f\n");
	printf("go to a line -> esc+g\n");

	printf("\nbuffers:\n");
	printf("buffers are like tabs in other editors\n");
	printf("listing all buffers(doens't work in tty for me either) -> ctrl+x ctrl+b\n");
	printf("opening a buffer -> ctrl+x b\n");
	printf("renaming a buffer -> esc ctrl+n\n");
	printf("deleting a buffer -> ctrl+x k\n");

	printf("\nwindows:\n");
	printf("deleting the current window -> ctrl+x 0\n");
	printf("deleting other windows -> ctrl+x 1");
	printf("spliting the current window -> ctrl+x 2\n");
	printf("using next window -> ctrl+x o\n");
	printf("using previous window -> ctrl+x p\n");
		

	printf("\nthats everthing I know so far and remembered to put down\n");	

	printf("I can now say I can use emacs lmfao, when I reality I use"
	" uemacs. tbf they are both emacs so I wouln't be wrong but they are"
	" pretty different at least from my knowledge\n");

	return 0;
}
