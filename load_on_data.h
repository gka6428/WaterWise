// 데이터 불러오기
// 1) 엑셀에서 정보를 담아올 구조체를 어떻게 정의해야 할까?
// 2) 엑셀에서 정보 불러오기
//		1. 어떤 순서로 정보를 받아오는 걸 반복해야 할까? 
//			- 파일 입출력 후 구조체에 저장
//		2. 설계 외적인 문제) 엑셀을 어떻게 다듬어야 할까? 
#ifndef _LOAD_ON_DATA_H // 이 헤더 파일을 불러오는데 정의가 안되어 있으면,
#define _LOAD_ON_DATA_H // 아래 내용을 복붙해서 정의하시오.

# include <stdio.h>
#define YEAR_SIZE 100
#define MONTH_SIZE 15 // 9 + 2 * 3 byte
#define INDICATORS_SIZE 9


int main(void)
{
	// 1) 엑셀에서 정보를 담아올 구조체를 어떻게 정의해야 할까?
	const struct indicators {
		char location[1000];
		char year[YEAR_SIZE];
		char month[MONTH_SIZE];
		float indicators[INDICATORS_SIZE]; // **주의) 수치를 매우 정확히 비교하여야 한다면 자료형을 다시 고려하자
	};
	
	// list처럼 배열의 인덱스 늘리는 함수도 고려해보아야 함.

	// 2) 엑셀에서 정보 불러오기
	//		1. 어떤 순서로 정보를 받아오는 걸 반복해야 할까? 
	//			- 파일 입출력 후 구조체에 저장
	//		2. 설계 외적인 문제) 엑셀을 어떻게 다듬어야 할까? 
}

#endif // _LOAD_ON_DATA_H