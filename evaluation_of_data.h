// 지표 평가
#ifndef _EVALUATION_OF_DATA_H // 이 헤더 파일을 불러오는데 정의가 안되어 있으면,
#define _EVALUATION_OF_DATA_H // 아래 내용을 복붙해서 정의하시오.

# include "input_data.h" // 지표 데이터 입력하는 헤더 파일 불러오기
# include "load_on_data.h"
# include <stdio.h>
#define REF_PH_SIZE 5
#define MGL_SIZE 6
#define REF_MGL_SIZE 5
#define COLIFORMS_SIZE 2
#define REF_COLIFORMS_SIZE 4

// 1) 기준치 데이터를 담을 구조체는 어떻게 만들어야 하는가?
typedef struct references { // 기준치 구조체의 타입 설정
	char revision_year[50]; // 기준치의 개정 년도(최신 기준치) 
	float pH_references[REF_PH_SIZE];
	float mgL_references[MGL_SIZE][REF_MGL_SIZE];
	int mL_references[COLIFORMS_SIZE][REF_COLIFORMS_SIZE];
} REF;

// 2) 기준치 데이터와 지표 데이터간 비교를 위한 조건문을 어떻게 작성할까?
// 지표를 기준치와 비교하하여 출력하는 함수
char* evaluate_indicators(INDICATORS* indicators_lst, REF* references_lst);
/*
{
	// 지표에 대한 기준치 단위는 인덱스로 맞추었다고 가정한다.

	// 초기 선언
	(선언) 지표[] = 지표구조체.indicators[]
	int i, j, temp;
	length = sizeof(지표[])/sizeof((선언)) // 배열의 길이, 이때 지표[]와 기준치[]길이는 같다고 설정해둠

	// 지표-기준치 대조 반복문(미완)
	for (j=0, j<length)
		for (i=0; i<length; i++) { // i가 커질수록 더 높은 수질기준을 읽게 됨 (근데 이건 정하기 나름)

			if (지표[특정인덱스] )
				if (지표 < 기준치[i])
					{
						temp = i;
						break;
					}	
		}

}
*/

// 비교 결과를 증감률과 함께 출력하는 함수
void print_variance();


#endif // _EVALUATION_OF_DATA_H