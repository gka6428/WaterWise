// 데이터 입력에 대한 헤더 파일입니다.
/* 수질관리시스템의 기능 중 해당 파일은 아래와 같은 목적을 가집니다.

*/
#ifndef INPUT_DATA_H
#define INPUT_DATA_H

#define _CRT_SECURE_NO_WARNINGS // scanf_s는 문자열 입력이 불가능하여 scanf 사용을 위해 정의함
# include <stdio.h>
# include <string.h>
#define ARRAY_SIZE_OF_NAME_OF_REGION 30      // 측정지역명을 담을 배열의 길이 지정               
#define ARRAY_SIZE_OF_YEAR 20                // 측정년도를 담을 배열의 길이 지정  
#define ARRAY_SIZE_OF_THE_NUMBER_OF_ROUND 20 // 측정시기회차를 담을 배열의 길이 지정
#define THE_NUMBER_OF_INDICATORS 9           // 저장할 지표의 개수 지정
#define THE_NUMBER_OF_REGION 10              // 측정지역의 개수
#define THE_NUMBER_OF_MEASURE 3              // 지표 단위의 개수(pH, mg/L, mL)

// 사용자가 입력한 측정지역, 측정연도, 측정회차, 지표 정보 데이터에 대한 구조체 선언
typedef struct indicators {
    char name_of_region[ARRAY_SIZE_OF_NAME_OF_REGION];
    char year[ARRAY_SIZE_OF_YEAR];
    char round[ARRAY_SIZE_OF_THE_NUMBER_OF_ROUND];
    char indicators[THE_NUMBER_OF_INDICATORS][3][50]; 
} INDICATORS;

// 초기화하지 않은 지표구조체 정의
INDICATORS indi[THE_NUMBER_OF_REGION];

char nameOfRegion_list[THE_NUMBER_OF_REGION][25] = {
    // 각 측정지역의 영문명은 다음과 같다.
    // 0)가양
    "Gayang",
    // 1)노량진
    "Noryangjin",
    // 2)도림천
    "Dorimcheon",
    // 3)안양천10
    "Anyangcheon 10",
    // 4)안양천9
    "Anyangcheon 9",
    // 5)중랑천5
    "Jungnangcheon 5",
    // 6)중랑천6
    "Jungnangcheon 6",
    // 7)청계천3
    "Cheonggyecheon 3",
    // 8)홍제천
    "Hongjecheon",
    // 9)보광
    "Bogwang" 
};

const char indicators_list[THE_NUMBER_OF_INDICATORS][25] = {
    // THE_NUMBER_OF_INDICATORS만큼 {}추가
    "pH",           // pH
    "BOD",          // mg/L
    "COD",          // mg/L
    "TOC",          // mg/L
    "TSS",          // mg/L
    "DO",           // mg/L
    "T-P",          // mg/L
    "총대장균군",    // mL
    "분원성 대장균군"// mL
};

const char measure_list[THE_NUMBER_OF_MEASURE][10] = {
    "pH",
    "mg/L",
    "mL"
};


void insert_info_to_struct(void);
void insert_name_of_region_to_nameArr(INDICATORS* indicators, const int i);
void insert_year_infor_to_yearArr(INDICATORS* indicators, char* yearArr);
void insert_round_infor_to_roundArr(INDICATORS* indicators, char* roundArr);
void insert_indicators_infor_to_indiArr(INDICATORS* indicators);
void insert_measure_of_references_to_measureArr(INDICATORS* indicators);

// 정의된 지표구조체에 정보 넣어주기
void insert_info_to_struct(void)
{
    int i;
    memset(&indi, 0, sizeof(indi));
    // 절차 1) 각각의 지표구조체에 측정지역명 넣어주기(자동)
    printf("지역명은 자동 입력됩니다.\n");
    printf("입력 중입니다... 잠시만 기다려 주십시오.\n");
    for (i = 0; i < THE_NUMBER_OF_REGION; i++)
    {
        insert_name_of_region_to_nameArr(&indi[i], i);
    }
    printf("입력 완료. \n\n");
    
    // 절차 2) 각각의 지표구조체에 측정연도, 측정회차 입력(수동)
    for (i = 0; i < THE_NUMBER_OF_REGION; i++)
    {
        char yearArr[ARRAY_SIZE_OF_YEAR];
        char roundArr[ARRAY_SIZE_OF_THE_NUMBER_OF_ROUND];

        // 입력과 입력값을 구조체에 저장
        printf("지역 (%d)의 이번 측정년도와 회차를 (xxxx년 x회차)의 형식으로 입력하시오. :", i);
        scanf("%s %s", yearArr, roundArr);
        insert_year_infor_to_yearArr(&indi[i], yearArr);
        insert_round_infor_to_roundArr(&indi[i], roundArr);
        printf("\n");
    }
    printf("입력 완료. \n\n");

    // 절차 3) (미완)각각의 지표 구조체에 지표 입력(수동, 각 지표마다 단위 입력은 자동)
    for (i = 0; i < THE_NUMBER_OF_REGION; i++)
    {
        printf("(%d/10)\n", i);
        insert_indicators_infor_to_indiArr(&indi[i]); // 각 지표의 측정값과 단위 삽입
    }
}

// "정의된 지표구조체에 정보 넣어주기" 함수의 하위 함수들 
void insert_name_of_region_to_nameArr(INDICATORS* indicators, const int i)
{
    strcpy_s(indicators->name_of_region, sizeof(indicators->name_of_region), nameOfRegion_list[i]);
    printf("%s\n", nameOfRegion_list[i]);
}

void insert_year_infor_to_yearArr(INDICATORS* indicators, char* yearArr)
{   
    char *ptr = strtok(yearArr,"년");
    strcpy_s(indicators->year, sizeof(indicators->year), ptr);
    printf("%s가 연도에 저장됨.\n", indicators->year);
}

void insert_round_infor_to_roundArr(INDICATORS* indicators, char* roundArr)
{   
    char *ptr = strtok(roundArr,"회");
    strcpy_s(indicators->round, sizeof(indicators->round), ptr);
    printf("%s가 측정회차에 저장됨.\n", indicators->round);
}

void insert_indicators_infor_to_indiArr(INDICATORS* indicators)
{
    int i;
    printf("지표에 대해 입력하세요.\n");
    char answer[30];
    for (i = 0; i < THE_NUMBER_OF_INDICATORS; i++)
    {
        if (i == 0) {
            printf("%s 농도: ", indicators_list[i]);
            scanf("%s", answer);
            strcpy_s(indicators->indicators[i][2], sizeof(indicators->indicators[i][2]), "pH");
        }
        else if (i >= 1 || i <= 6) {
            printf("%s의 양: ", indicators_list[i]);
            scanf("%s", answer);
            strcpy_s(indicators->indicators[i][2], sizeof(indicators->indicators[i][2]), "mg/L");
        }
        else {
            printf("%s의 수: ", indicators_list[i]);
            scanf("%s", answer);
            strcpy_s(indicators->indicators[i][2], sizeof(indicators->indicators[i][2]), "mL");
        }
        strcpy_s(indicators->indicators[i][1], sizeof(indicators->indicators[i][1]), answer);
        printf("%s로 입력하셨습니다.\n", answer);
    } 
}

// 지역 리스트 변경(삭제 후 추가 기능/추가 기능)

#endif // INPUT_DATA_H

// 사용자가 입력한 데이터를 받아올 구조체 정의
    // 구조체
        // 측정지역명에 대한 배열 선언 
        // 측정년도에 대한 배열 선언   
        // 측정회차에 대한 배열 선언
        // 지표들 선언 -> 지표[지표의 개수][해당 지표에 담을 정보의 개수][문자열 입력을 위해 확보할 배열의 길이]

// 사용자의 데이터 입력 (1: 일일히 입력하는 경우) (오류가 있을 경우는 아직 고려안함)
    // 지표구조체의 포인터를 매개변수로 받는다.
    // 아래의 과정을 반복한다
        // 

// 각각의 지표구조체에 정보 넣어주기
    // 각각의 지표구조체에 측정지역명 순서대로 넣어주기
        //(미정) load_on_data.h애서 정의된 구조체를 가져와 정보를 그대로 복사하여 옮기기
    // 각각의 지표구조체에 측정년도 순서대로 넣어주기
    // 각각의 지표구조체에 측정회차 순서대로 넣어주기
    // 각각의 지표구조체에 지표들 순서대로 넣어주기
    // 지표구조체 내 각각의 지표들에 대해 단위 삽입
    