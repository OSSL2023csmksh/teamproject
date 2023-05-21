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
  printf("8. 타율순위\n");
  printf("9. 타점순위\n");
  printf("10. 예상MVP순위\n");
  printf("0. 종료\n\n");
  printf("=> 원하는 메뉴는? ");
  scanf("%d", &menu);
  return menu;
}

int addStat(Stat *s) {
  printf("이름은? ");
  scanf("%s", s->name);
  printf("타율은? ");
  scanf("%f", &s->AVG);
  printf("타점은? ");
  scanf("%d", &s->RBI);
  printf("홈런개수는? ");
  scanf("%d", &s->HR);
  printf("=> 추가됨!\n\n");
  return 1;
}

void readStat(Stat s) {
  printf(" Name  AVG  RBI  HR  \n");
  printf("==============================================\n");
  printf("%8s    %2.3f   %2d   %2d \n ", s.name, s.AVG, s.RBI, s.HR);
}

void rankreadStat(Stat s, int rank) {
  printf(" RANK  Name  AVG  RBI  HR  \n");
  printf("==============================================\n");
  printf(" %4d  %8s  %2.3f   %2d   %2d \n ", rank, s.name, s.AVG, s.RBI, s.HR);
}

int updateStat(Stat *s) {
  printf("이름은? ");
  scanf("%s", s->name);
  printf("타율은? ");
  scanf("%f", &s->AVG);
  printf("타점은? ");
  scanf("%d", &s->RBI);
  printf("홈런개수는? ");
  scanf("%d", &s->HR);
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
    fprintf(fp, "%s %f %d %d \n",s[i]->name,s[i]->AVG,s[i]->RBI,s[i]->HR);      
  fclose(fp);
  printf("=> 저장됨! ");
  }
}

void searchName(Stat *s[], int count){
  int scnt = 0;
  char search[100];

  printf("검색할 이름? ");
  scanf("%s", search);

  printf("\nName  AVG  RBI  HR \n");
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
  printf("\n*** 홈런 순위 ***\n");
  printf(" Rank    Name    HR   AVG    RBI\n");
  printf("=================================\n");
  for (i = 0; i < count; i++) {
    if (sorted[i] == NULL) continue;
    rankreadStat(*sorted[i], i + 1);
  }
  printf("\n");
}

void listStatByAVG(Stat *s[], int count) {
  Stat *sorted[100];
  int i, j;
  for (i = 0; i < count; i++) {
    sorted[i] = s[i];
  }
  for (i = 0; i < count - 1; i++) {
    for (j = i + 1; j < count; j++) {
      if (sorted[i]->AVG < sorted[j]->AVG) {
        Stat *temp = sorted[i];
        sorted[i] = sorted[j];
        sorted[j] = temp;
      }
    }
  }
  printf("\n*** 타율 순위 ***\n");
  printf(" Rank    Name    HR   AVG    RBI\n");
  printf("=================================\n");
  for (i = 0; i < count; i++) {
    if (sorted[i] == NULL) continue;
    rankreadStat(*sorted[i], i + 1);
  }
  printf("\n");
}
  

void listStatByRBI(Stat *s[], int count) {
  Stat *sorted[100];
  int i, j;
  for (i = 0; i < count; i++) {
    sorted[i] = s[i];
  }
  for (i = 0; i < count - 1; i++) {
    for (j = i + 1; j < count; j++) {
      if (sorted[i]->RBI < sorted[j]->RBI) {
        Stat *temp = sorted[i];
        sorted[i] = sorted[j];
        sorted[j] = temp;
      }
    }
  }
  printf("\n*** 타점 순위 ***\n");
  printf(" Rank    Name    HR   AVG    RBI\n");
  printf("=================================\n");
  for (i = 0; i < count; i++) {
    if (sorted[i] == NULL) continue;
    rankreadStat(*sorted[i], i + 1);
  }
  printf("\n");
}

int selectDataStat(Stat *s[], int count) {
  int statOption;
  printf("\n*** 선수 성적 순위 ***\n");
  printf("1. 타율 순위\n");
  printf("2. 홈런 순위\n");
  printf("3. 타점 순위\n");
  printf("0. 취소\n\n");
  printf("=> 원하는 스탯은? ");
  scanf("%d", &statOption);
  return statOption;
}

void listprMVP(Stat *s[], int count) {
  Stat *sorted[100];
  int i, j;
  
  // Copying the array of pointers to a temporary array
  for (i = 0; i < count; i++) {
    sorted[i] = s[i];
  }
  
  // Sorting the array in descending order of MVP score
  for (i = 0; i < count - 1; i++) {
    for (j = i + 1; j < count; j++) {
      int score_i = sorted[i]->HR * 10 + sorted[i]->AVG * 100 + sorted[i]->RBI * 5;
      int score_j = sorted[j]->HR * 10 + sorted[j]->AVG * 100 + sorted[j]->RBI * 5;
      
      if (score_i < score_j) {
        Stat *temp = sorted[i];
        sorted[i] = sorted[j];
        sorted[j] = temp;
      }
    }
  }
  
  // Displaying the top 10 players
  printf("\n*** 예상 MVP 순위 ***\n");
  printf(" Rank    Name    HR   AVG    RBI   MVP Score\n");
  printf("==============================================\n");
  
  int limit = (count < 10) ? count : 10; // Limiting to the available count or 10, whichever is smaller
  
  for (i = 0; i < limit; i++) {
    if (sorted[i] == NULL) continue;
    int score = sorted[i]->HR * 10 + sorted[i]->AVG * 100 + sorted[i]->RBI * 5;
    printf("%4d %8s   %2d   %2.3f   %2d   %5d\n", i + 1, sorted[i]->name, sorted[i]->HR, sorted[i]->AVG, sorted[i]->RBI, score);
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
    fscanf(fp, "%f", &s[i]->AVG);
    fscanf(fp, "%d", &s[i]->RBI);
    fscanf(fp, "%d", &s[i]->HR);
  }
  fclose(fp);
  printf("=> 로딩 성공!\n");
  return i;
}
