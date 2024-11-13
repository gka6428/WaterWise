// 데이터 입력
#ifndef _INPUT_DATA_H // 이 헤더 파일을 불러오는데 정의가 안되어 있으면,
#define _INPUT_DATA_H // 아래 내용을 복붙해서 정의하시오.

# include <stdio.h>
#define YEAR_SIZE 100               //
#define ROUND_SIZE 15               // 9 + 2 * 3 byte
#define INDICATORS_SIZE 9           //
#define THE_MEASURE_OF_REFERENCES 1 //
#define THE_NUMBER_OF_REGION 10     // 수계 10곳
#define NAME_SIZE 15                // 받을 지역명의 길이에 따라 조정해야함.

// 사용자가 입력한 데이터를 받아올 구조체 정의
typedef struct indicators {
    char name_of_region[NAME_SIZE]; // 지역(수계)명
	short year[YEAR_SIZE];          // 측정연월, int 대신 short로
	char round[ROUND_SIZE];         // 회차, 10회차 안넘어가니 char로 선언
	float indicators[INDICATORS_SIZE][THE_MEASURE_OF_REFERENCES]; // 지표[지표개수][각지표의단위]
    // **주의) 수치를 매우 정확히 비교하여야 한다면 자료형을 다시 고려하자
} INDICATORS;
INDICATORS indicators_list[THE_NUMBER_OF_REGION]; // 지표구조체[측정지역수] 일단 선언

// 각각의 지표구조체에 수계명 넣어주기
void insert_name_of_region_to_nameList(INDICATORS* indicators_lst);
/*
{
    // 각 측정지역의 영문명은 다음과 같다.
    // 가양 - Gayang
    // 노량진 - Noryangjin
    // 도림천 - Dorimcheon
    // 안양천10 - Anyangcheon 10
    // 안양천9 - Anyangcheon 9
    // 중랑천5 - Jungnangcheon 5
    // 중랑천6 - Jungnangcheon 6
    // 청계천3 - Cheonggyecheon 3
    // 홍제천 - Hongjecheon
    // 보광 - Bogwang
}
*/

// 지표구조체 내 각각의 지표들에 대해 단위 삽입
void insert_measure_of_references_to_indicators(INDICATORS* indicators_lst);
/*
{
    pH단위일 경우 pH = 0
    mg/L단위일 경우 mgL = 1
    mL단위일경우 mL = 2
}
*/

// 엑셀 지표정보 받아오기
void load_data_to_indicators();
// 2) 입력을 어떻게 받을까?


#endif // _INPUT_DATA_H