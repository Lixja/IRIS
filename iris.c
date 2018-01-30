#include <stdio.h>

#include "word.h"
#include "sentence.h"
#include "history.h"

int main(){
	printf("WordTest\n");
	word w1 = "hallo";
	word w2 = "hollo";
	word w3 = "halloo";
	word w4 = "h";
	printf("%f   -   %f   -   %f\n",compare_word(w1,w2),compare_word(w1,w3),compare_word(w1,w4));
	
	printf("SentenceTest\n");
	sentence s1;
	sentence s2;
	create_sentence(&s1, "hallo welt");
	for(int i=0; i< s1.size; i++){
		printf("word%d = %s\n", i, s1.content[i]);
	}
	create_sentence(&s1, "ich bin dein vater. muhahahahahahahaha");
	for(int i=0; i< s1.size; i++){
		printf("word%d = %s\n", i, s1.content[i]);
	}
	printf("CompareTest\n");
	create_sentence(&s1, "Alighatorenfallenschwanzgur welt");
	create_sentence(&s2, "Alighatorenfalkdiekdmcndjur wolt");
	printf("%f\n", compare_sentence(&s1, &s2));
	create_sentence(&s2, "Aighatorenfallenschwanzgur weet");
	printf("%f\n", compare_sentence(&s1, &s2));
	create_sentence(&s2, "Alighatorenfallenschwanzgur wo");
	printf("%f\n", compare_sentence(&s1, &s2));
	create_sentence(&s2, "Alighatorenfallenschwanzgur welt");
	printf("%f\n", compare_sentence(&s1, &s2));
	
	printf("HistoryTest\n");
	history h;
	create_history(&h);
	while(1){
		char input[20*20] = "";
		
		printf("User: ");
		fgets (input, 20*20, stdin);
		scanf("%s\n", &input);
		sentence s;
		create_sentence(&s, input);
		add_to_history(&h, &s);
		if(compare_sentence_with_string(&s, "search for") > 0.5){
			sentence sa = search_for(&h, s.content[2]);
			printf("%s\n", to_string(&sa));
		}
		
	}
	return 0;
}
