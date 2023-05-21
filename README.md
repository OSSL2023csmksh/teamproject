
# mini project 주제
 - 야구선수 스탯 레퍼런스 만들기

# mini project에 대한 소개
 - 선수별 능력치(타율,타점,홈런)을 입력 받고 알아보기 쉽게 코드를 만들어서 선수별 스탯 확인도 가능하게 하고 스탯 별로 선수의 순위도 보여준다. 추가적으로 모든 선수들의 경기결과에 대한 영향력을 알아내서 예상 mvp 순위를 보여준다.
 
![baseball-1091211__480](https://user-images.githubusercontent.com/89427936/236815171-739ea18f-690a-4912-9a82-8f3cbb37da19.jpg)

# project에 포함시킬 대략적인 기능 설명
 - CRUD : CRUD 기능으로 야구선수의 성적(타율,홈런,타점,포지션)을 입력 받고 갱신하고 삭제한다.
 - SAVE : 입력 받은 야구선수의 성적을 stat.txt 파일에 저장한다.
 - LOAD : stat.txt 파일을 불러온다
 - sorting : 타율순위, 홈런순위, 타점 순위를 볼 수 있게 선수들을 타율/홈런/타점 순위로 나열 한다.
 - 예상 MVP 순위 : 선수의 타율과 홈런과 타점 포지션을 가지고 실제 야구에서 쓰이는 승리기여도와 비
   슷한 방식으로 스탯별 가중치를 두어 계산을 해서 나온 값을 가지고 예상 MVP 순위를 나열한다.

# 코드 및 기능

    typedef struct {
      char name[20];
      float AVG;
      int RBI;
      int HR;
      int prmvp;// 예상 mvp 순위를 위한 세이버 매트릭스 값
    } Stat;// 구조체

    int selectMenu();
    int addStat(Stat *s);// 선수의 스탯을 추가하는 함수
    void readStat(Stat s);// 선수의 스탯 출력하는 함수
    void rankreadStat(Stat s, int rank);특정 순위의 선수의 스탯 출력하는 함수
    int updateStat(Stat *s);// 선수의 스탯 수정하는 함수
    void listStat(Stat *s[], int count);// 전체 등록된 선수 스탯 출력
    int selectDataNo(Stat *s[], int count);// 선수 번호 불러오는 함수
    int deleteStat(Stat *s);// 등록된 선수 삭제하는 함수
    void saveData(Stat *s[], int count);// 데이터를 파일에 저장하는 함수
    void searchName(Stat *s[], int count);// 선수 이름검색
    void listStatByHR(Stat *s[], int count);// 선수 홈런순위 sorting 함수
    void listStatByAVG(Stat *s[], int count);// 선수 타율순위 sorting 함수
    void listStatByRBI(Stat *s[], int count);// 선수 타점순위 sorting 함수
    int selctDataStat(Stat *s[], int count);// 타율,홈런, 타점 중 순위를 보기 원하는 스탯 고르게 하는 함수
    void listprMVP(Stat *s[], int count);// 예상 MVP 순위 나열하는 함수
    int loadData(Stat *s[]);// 저장된 데이터 불러오는 함수

# 개발환경 및 언어
 - 개발환경 : 리눅스
 - 언어 : C언어

# 팀소개
 - 반도체 공정쪽으로 취업하려는 전자심화 4학년과 전산심화이지만 전공 새내기인 2학년의 쉽지 않지만 열정을 가진 팀입니다!

# 팀원이 맡은 역할
 - 김승혁 :  Read.me파일 및 Wiki 작성  
 - 최승문 : CRUD,SAVE,LOAD,main 함수와 나머지 함수 구현 

