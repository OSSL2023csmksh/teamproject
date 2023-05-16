#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stat.h"

int selectMenu() {
  int menu;
  printf("\n*** 선수 성적 정보 ***\n");
  printf("1. 조회\n");
  printf("2. 추가\n");
  printf("3. 수정\n");
  printf("4. 삭제\n");
  printf("5. 저장\n");
  printf("6. 이름검색\n");
  printf("7. 홈런순위\n");
  printf("0. 종료\n\n");
  printf("=> 원하는 메뉴는? ");
  scanf("%d", &menu);
  return menu;
}

int addStat(Stat *s) {
  printf("이름은? ");
  scanf("%s", s->name);
  printf("년도는? ");
  scanf("%d", &s->Year);
  printf("타율은? ");
  scanf("%f", &s->AVG);
  printf("타점은? ");
  scanf("%d", &s->RBI);
  printf("홈런개수는? ");
  scanf("%d", &s->HR);
  printf("승리기여도는? ");
  scanf("%f", &s->WAR);
  printf("=> 추가됨!\n\n");
  return 1;
}

void readStat(Stat s) {
  printf(" Name    Year    AVG    RBI   HR   WAR\n");
  printf("==============================================\n");
  printf("%8s   %2d   %2.3f   %2d   %2d   %2.1f\n ", s.name, s.Year, s.AVG, s.RBI, s.HR, s.WAR);
}

int updateStat(Stat *s) {
  printf("이름은? ");
  scanf("%s", s->name);
  printf("년도는? ");
  scanf("%d", &s->Year);
  printf("타율은? ");
  scanf("%f", &s->AVG);
  printf("타점은? ");
  scanf("%d", &s->RBI);
  printf("홈런개수는? ");
  scanf("%d", &s->HR);
  printf("승리기여도는? ");
  scanf("%f", &s->WAR);
  printf("=> 수정됨!\n");
  return 1;
}

void listStat(Stat *s[], int count) {
  for (int i = 0; i < count; i++) {
    if (s[i] == NULL) continue;
    readStat(*s[i]);
  }
  printf("\n");
}

int selectDataNo(Stat *s[], int count) {
  int no;
  listStat(s, count);
  printf("번호는 (취소 :0)? ");
  scanf("%d", &no);
  return no;
}

int deleteStat(Stat *s) {
  s->Year = -1;
  s->RBI = -1;
  s->HR = -1;
  return 1;
}

void saveData(Stat *s[], int count)
{
  FILE *fp;
  fp = fopen("Stat.txt", "wt");
  for(int i = 0; i < count; i++){
    if(s[i] == NULL) continue;
    fprintf(fp, "%s %d %f %d %d %f\n",s[i]->name,s[i]->Year,s[i]->AVG,s[i]->RBI,s[i]->HR,s[i]->WAR);      
  fclose(fp);
  printf("=> 저장됨! ");
}

void searchName(Stat *s[], int count){
  int scnt = 0;
  char search[100];

  printf("검색할 이름? ");
  scanf("%s", search);

  printf("\nName  Year  AVG  RBI  HR  WAR\n");
  printf("================================\n");

  for(int i =0; i <count ; i++){
    if(s[i] == NULL) continue;
    if(strstr(s[i]->name, search)){
      printf("%2d ", i+1);
      readStat(*s[i]);
      scnt++;
    }
  }
  if(scnt == 0) printf("=> 검색된 데이터 없음!");
  printf("\n");
}

void listStatByHR(Stat *s[], int count) {
  Stat *sorted[100];
  int i, j;
  for (i = 0; i < count; i++) {
    sorted[i] = s[i];
  }
  for (i = 0; i < count - 1; i++) {
    for (j = i + 1; j < count; j++) {
      if (sorted[i]->HR < sorted[j]->HR) {
        Stat *temp = sorted[i];
        sorted[i] = sorted[j];
        sorted[j] = temp;
      }
    }
  }
  for (i = 0; i < count; i++) {
    if (sorted[i] == NULL) continue;
    readStat(*sorted[i]);
  }
  printf("\n");
}


int loadData(Stat *s[]){
  int count = 0, i = 0;
  FILE *fp;
  fp = fopen("Stat.txt", "rt");
  for(; i < 100; i++){
    s[i] =(Stat *)malloc(sizeof(Stat));
    fscanf(fp, "%s", s[i]->name);
    if(feof(fp)) break;
    fscanf(fp, "%d", &s[i]->Year);
    fscanf(fp, "%f", &s[i]->AVG);
    fscanf(fp, "%d", &s[i]->RBI);
    fscanf(fp, "%d", &s[i]->HR);
    fscanf(fp, "%f", &s[i]->WAR);
  }
  fclose(fp);
  printf("=> 로딩 성공!\n");
  return i;

}




