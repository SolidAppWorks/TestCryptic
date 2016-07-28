#ifndef _HEADER_H_
#define _HEADER_H_

extern std::string alfabet;
extern char alftab[52][52];
 
//int checkPos(char k);
std::string szyfrowanie(std::string tekst, std::string klucz);
std::string deszyfrowanie(std::string encode, std::string klucz);
 
#endif