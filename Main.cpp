#include <stdio.h>
#include <string>

int main() {
	
	//Now, what do I do...
	
	/*
	 * Pomysly na program
	 * - szyfr jakiegos rodzaju popatrz stare zadania
	 * 
	 * */
	
/*int i;

scanf("%d", &i);
printf("LOL: %d\n",i* 1000);
printf("Wow\n");
*/

//Szyfr Viegenera

//Tablica z alfabetem
char alftab[26][26];
std::string alfabet= "abcdefghijklmnopqrstuvwxyz";

for(int i= 0; i<26; i++){
	for(int j= 0; j<26; j++){
		alftab[i][j]=alfabet[j];
	}
}

for(int i= 0; i<26; i++){
	printf("Rzad %d: ", i);
	for(int j= 0; j<26; j++){
		printf("%s", alftab[i][j]);
	}
	printf("\n");
}

return 0;
}
