// ��ǥ ��
#ifndef _EVALUATION_OF_DATA_H // �� ��� ������ �ҷ����µ� ���ǰ� �ȵǾ� ������,
#define _EVALUATION_OF_DATA_H // �Ʒ� ������ �����ؼ� �����Ͻÿ�.

# include "input_data.h" // ��ǥ ������ �Է��ϴ� ��� ���� �ҷ�����
# include "load_on_data.h"
# include <stdio.h>
#define REF_PH_SIZE 5
#define MGL_SIZE 6
#define REF_MGL_SIZE 5
#define COLIFORMS_SIZE 2
#define REF_COLIFORMS_SIZE 4

// 1) ����ġ �����͸� ���� ����ü�� ��� ������ �ϴ°�?
typedef struct references { // ����ġ ����ü�� Ÿ�� ����
	char revision_year[50]; // ����ġ�� ���� �⵵(�ֽ� ����ġ) 
	float pH_references[REF_PH_SIZE];
	float mgL_references[MGL_SIZE][REF_MGL_SIZE];
	int mL_references[COLIFORMS_SIZE][REF_COLIFORMS_SIZE];
} REF;

// 2) ����ġ �����Ϳ� ��ǥ �����Ͱ� �񱳸� ���� ���ǹ��� ��� �ۼ��ұ�?
// ��ǥ�� ����ġ�� �����Ͽ� ����ϴ� �Լ�
char* evaluate_indicators(INDICATORS* indicators_lst, REF* references_lst);
/*
{
	// ��ǥ�� ���� ����ġ ������ �ε����� ���߾��ٰ� �����Ѵ�.

	// �ʱ� ����
	(����) ��ǥ[] = ��ǥ����ü.indicators[]
	int i, j, temp;
	length = sizeof(��ǥ[])/sizeof((����)) // �迭�� ����, �̶� ��ǥ[]�� ����ġ[]���̴� ���ٰ� �����ص�

	// ��ǥ-����ġ ���� �ݺ���(�̿�)
	for (j=0, j<length)
		for (i=0; i<length; i++) { // i�� Ŀ������ �� ���� ���������� �а� �� (�ٵ� �̰� ���ϱ� ����)

			if (��ǥ[Ư���ε���] )
				if (��ǥ < ����ġ[i])
					{
						temp = i;
						break;
					}	
		}

}
*/

// �� ����� �������� �Բ� ����ϴ� �Լ�
void print_variance();


#endif // _EVALUATION_OF_DATA_H