#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stat.h"

int main(void) {
  int count = 0, menu;
  int result = 0;
  Stat *sp[100];
  int index = 0;

  count = loadData(sp);
  index = count;

  while (1) {
    menu = selectMenu();
    if (menu == 0) break;
    else if (menu == 2) {
        sp[index] = (Stat *)malloc(sizeof(Stat));
        count += addStat(sp[index++]);
    }
    else if (menu == 1) {
        if(count > 0) listStat(sp, index);
        else printf("데이터가 없습니다.\n");
    }
    else if (menu == 3) {
      int no = selectDataNo(sp, index);
      if (no == 0) {
        printf("=> 취소됨!\n");
        continue;
      }
      updateStat(sp[no - 1]);
    }

    else if (menu == 4) {
      int no = selectDataNo(sp, index);
      if (no == 0) {
        printf("=> 취소됨!\n");
        continue;
      }
      int deleteok;
      printf("정말로 삭제하시겠습니까?(삭제 :1)");
      scanf("%d", &deleteok);
      if (deleteok == 1) {
        if (sp[no-1]) free(sp[no-1]);
        sp[no-1] = NULL;
        count--;
        printf("삭제됨\n");
      }
      else printf("취소됨\n");
      }
      else if(menu == 5){
          saveData(sp, index);
      }
      else if(menu == 6){
          searchName(sp, index);
      }
      else if (menu == 7) {
          if(count > 0) listStatByHR(sp, index);
          else printf("데이터가 없습니다.\n");
      }

    }
    printf("종료됨!\n");
    return 0;

}
