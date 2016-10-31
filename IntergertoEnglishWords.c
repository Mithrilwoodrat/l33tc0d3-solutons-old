/*
  Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

For example,
123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
*/

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#define MAXLEN 200
#define CHUNKSIZE 50
#define WORDSIZE 10
#define ONEMILLION 1000000
#define ONEBILLION 1000000000

static char* Unit[] = {"Hundred", "Thousand", "Million","Billion"};
static char* below_20[] =  {"One", "Two", "Three", "Four","Five","Six","Seven","Eight","Nine","Ten", "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
static char* below_100[] = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

char* handred_chunk(int num) {
  if (num == 0)
    return "";
  char * chunk = (char *) malloc(sizeof(char)*CHUNKSIZE*WORDSIZE);
  bzero(chunk,sizeof(char)*CHUNKSIZE*WORDSIZE);
  int digits[3] = {0,0,0}, n = num;
  digits[0] = num / 100;
  num %= 100;
  digits[1] = num /10;
  num %= 10;
  digits[2] = num;
  if (n >= 100) {
    sprintf(chunk,"%s %s",below_20[digits[0]-1],Unit[0]);
    if (digits[1] >= 2) {
      sprintf(chunk,"%s %s",chunk, below_100[digits[1]-2]);
      if (digits[2] != 0)
        sprintf(chunk,"%s %s",chunk, below_20[digits[2]-1]);
    }
    else {
      int index = digits[1] * 10 + digits[2];
      if (index != 0)
        sprintf(chunk,"%s %s",chunk, below_20[index-1]);
    }
  }
  else if(n >= 20) {
    sprintf(chunk,"%s", below_100[digits[1]-2]);
    if (digits[2] != 0)
      sprintf(chunk,"%s %s",chunk, below_20[digits[2]-1]);
  }
  else {
    int index = digits[1] * 10 + digits[2];
    sprintf(chunk,"%s", below_20[index-1]);
  }
  return chunk;
}

char* numberToWords(int num) {
  if (num == 0) 
    return "Zero";
  char * words = (char *) malloc(sizeof(char)*MAXLEN*WORDSIZE);
  int below_thousand, below_million,over_million;
  if (num >= ONEBILLION) {
    int over_billion = num / ONEBILLION;
    sprintf(words,"%s %s",handred_chunk(over_billion),Unit[3]);
    int below_billion = num % ONEBILLION;
    if (below_billion !=0) {
        over_million = below_billion/ONEMILLION;
        if (over_million !=0)
            sprintf(words,"%s %s %s",words,handred_chunk(over_million),Unit[2]);
        below_million = num % ONEMILLION;
        if (below_million >= 1000) {
        sprintf(words,"%s %s %s",words,handred_chunk(below_million/1000), Unit[1]);
        }
        below_thousand = num % 1000;
        if (below_thousand !=0)
            sprintf(words,"%s %s",words,handred_chunk(below_thousand));
    }
  }   
  else if (num >= ONEMILLION) {
    over_million = num/ONEMILLION;
    sprintf(words,"%s %s",handred_chunk(over_million),Unit[2]);
    below_million = num % ONEMILLION;
    if (below_million >= 1000) {
      sprintf(words,"%s %s %s",words,handred_chunk(below_million/1000), Unit[1]);
    }
    below_thousand = num % 1000;
    if (below_thousand !=0)
     sprintf(words,"%s %s",words,handred_chunk(below_thousand));
  }
  else if (num >= 1000) {
    sprintf(words,"%s %s",handred_chunk(num/1000), Unit[1]);
    below_thousand = num % 1000;
    if (below_thousand !=0)
        sprintf(words,"%s %s",words,handred_chunk(below_thousand));
  }
  else {
    sprintf(words,"%s",handred_chunk(num));
  }
  return words; 
}
