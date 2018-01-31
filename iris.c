#include <stdio.h>

#include "word.h"
#include "sentence.h"
#include "history.h"
#include "voc.h"

void drawLine(){
	printf("\n_______________ \n");
}
int main(){
	drawLine();
	printf("WordTest\n");
	word w1 = "hallo";
	word w2 = "hollo";
	word w3 = "halloo";
	word w4 = "h";
	printf("%f   -   %f   -   %f\n",compare_word(w1,w2),compare_word(w1,w3),compare_word(w1,w4));
	drawLine();
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
	drawLine();
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
	drawLine();
	printf("HistoryTest\n");
	history h;
	create_history(&h);
	sentence h1;
	create_sentence(&h1, "Ich bin 10 jahre alt");
	add_to_history(&h, &h1);
	sentence h2;
	create_sentence(&h2, "Ich mag schnulle auto");
	add_to_history(&h, &h2);
	sentence h3;
	create_sentence(&h3, "Hi");
	add_to_history(&h, &h3);
	sentence h4;
	create_sentence(&h4, "Wie geht es dir?");
	add_to_history(&h, &h4);
	sentence h5;
	create_sentence(&h5, "Ich habe Hunger");
	add_to_history(&h, &h5);
	sentence h6;
	create_sentence(&h6, "Ich mag katzen");
	add_to_history(&h, &h6);
	sentence h7;
	create_sentence(&h7, "asdfghjk");
	add_to_history(&h, &h7);
	sentence h8;
	create_sentence(&h8, "wie geht es dir");
	add_to_history(&h, &h8);
	sentence h9;
	create_sentence(&h9, "asdfghjk");
	add_to_history(&h, &h9);
	
	sentence a1 = search_for(&h, to_word("katzen"));
	sentence a2 = search_for(&h, to_word("alter"));
	sentence a3 = search_for(&h, to_word("schnelle"));
	printf("%s\n", to_string(&a1));
	printf("%s\n", to_string(&a2));
	printf("%s\n", to_string(&a3));
	drawLine();
	printf("VocabularyTest\n");
	vocabulary vocab;
	create_vocabulary(&vocab);
	word v1 = "wie";
	word v2 = "Hi";
	word v3 = "Hallo";
	word v4 = "mag";
	add_voc(&vocab, "question", &v1);
	add_voc(&vocab, "hello", &v2);
	add_voc(&vocab, "hello", &v3);
	add_voc(&vocab, "do", &v4);
	
	asentence av1 = analyse_sentence(&vocab, &h3);
	asentence av2 = analyse_sentence(&vocab, &h2);
	asentence av3 = analyse_sentence(&vocab, &h9);
	
	printf("%s - %s\n",to_string(&h3),av1.category);
	printf("%s - %s\n",to_string(&h2),av2.category);
	printf("%s - %s\n",to_string(&h9),av3.category);



	
	
	/*while(1){
		char input[20*20] = "";
		
		printf("User: ");
		fgets (input, 20*20, stdin);
		scanf("%s\n", &input);
		sentence s;
		create_sentence(&s, input);
		add_to_history(&h, &s);
		if(compare_sentence_with_string(&s, "search for") > 0.5){
			//sentence sa = search_for(&h, s.content[2]);
			//printf("%s\n", to_string(&sa));
		}
		
	}*/
	return 0;
}
