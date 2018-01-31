#ifndef LIO_H
#define LIO_H

#include <stdio.h>
#include "sentence.h"

void out(sentence *s){
	printf("I.R.I.S.: %s\n", to_string(s));
}

void sout(char *str){
	printf("%s\n", str);
}

sentence in(){
	printf("User: ");
	char in[20*20];
	fgets(in, 20*20, stdin);
	in[strlen(in)-1] = 0;
	sentence s;
	create_sentence(&s, in);
	return s;
}

char *s_in(){
	char in[20*20];
	fgets(in, 20*20, stdin);
	in[strlen(in)-1] = 0;
	return in;
}


#endif	//LIO_H
