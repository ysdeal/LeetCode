/*
Implement strStr().

Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack. 
*/

#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
// O(M*N)
char *strStrSen(char *haystack, char *needle){
   if(!*needle) return haystack;
   char *p1 = (char *) haystack;
   while(*p1){
   	char *p1Begin = p1, *p2 = (char *)needle;
   	while(*p1 && *p2 && *p1 == *p2){
   		p1 ++;
   		p2 ++;
   	}
   	if (!*p2)
   		return p1Begin;
   	p1 = p1Begin + 1;
   }
   return NULL;
}

//O((N-M+1)*M)
char *strStr(char *haystack, char *needle){
   if(!*needle) return haystack;
   char *p1 = (char *) haystack;
   char *pad = (char *) haystack;
   char *p2 = (char *)needle;
   while(*++p2) pad++;
   while(*pad){
   	char *p1Begin = p1, *p2 = (char *)needle;
   	while(*p1 && *p2 && *p1 == *p2){
   		p1 ++;
   		p2 ++;
   	}
   	if (!*p2)
   		return p1Begin;
   	p1 = p1Begin + 1;
   	pad ++;
   }
   return NULL;
}




int main(int argc, char const *argv[])
{
	char s1[] = "asdfasdfa";
	char s2[] = "a";
    cout << strStrSen(s1,s2) <<endl;
    cout << strStr(s1,s2) <<endl;
    cout << strstr(s1,s2) << endl;
	return 0;
}