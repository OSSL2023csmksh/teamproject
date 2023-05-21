#include <stdio.h>

typedef struct {
  char name[20];
  float AVG;
  int RBI;
  int HR;
  int prmvp;
} Stat;

int selectMenu();
int addStat(Stat *s);
void readStat(Stat s);
void rankreadStat(Stat s, int rank);
int updateStat(Stat *s);
void listStat(Stat *s[], int count);
int selectDataNo(Stat *s[], int count);
int deleteStat(Stat *s);
void saveData(Stat *s[], int count);
void searchName(Stat *s[], int count);
void listStatByHR(Stat *s[], int count);
void listStatByAVG(Stat *s[], int count);
void listStatByRBI(Stat *s[], int count);
int selctDataStat(Stat *s[], int count);
void listprMVP(Stat *s[], int count);
int loadData(Stat *s[]);

