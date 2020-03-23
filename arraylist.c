#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraylist.h"
// <헤더파일>의 형태는 c/c++에서 제공하는 표준 라이브러리에 저장되어있는 헤더파일을 참조할 때
// "헤더파일"의 형태는 개인이 직접 작성한 헤더파일을 참조할 때

// 헤더파일에서 전반적으로 선언하였던 함수들의 구체적인 정의를 선언한다. 

// 1. createArrayList -> 배열리스트 생성 함수
ArrayList* createArrayList(int maxElementCount) { 
	ArrayList* pReturn = NULL;
	int i = 0;

	if (maxElementCount > 0) {
		pReturn = (ArrayList*)malloc(sizeof(ArrayList)); // 기본적으로 동적할당을 이용하여 메모리를 할당해줌, 배열선언 X

		if (pReturn != NULL) { // 동적할당에서 이건 언제나 필수!! 할당을 할 때에도 이미 할당한 메모리 공간에 접근할 때에도 항상 검사하고 모든 작업을 시작할 것!
			pReturn->maxElementCount = maxElementCount;
			pReturn->currentElementCount = 0;
			pReturn->pElement = NULL;
		}
		else {
			printf("오류, 메모리할당 실패! \n");
			return NULL;
		}
	}
	else {
		printf("오류, 최대 원소 개수는 0이상이어야 합니다! \n");
		return NULL;
	}
	
	pReturn->pElement = (ArrayListNode*)malloc(sizeof(ArrayListNode)*maxElementCount); // 기본적으로 동적할당을 이용하여 메모리를 할당해줌, 배열선언 X

	if (pReturn->pElement == NULL) {
		printf("오류, 2번째 메모리할당 실패! \n");
		free(pReturn);
		return NULL;
	}
	memset(pReturn->pElement, 0, sizeof(ArrayListNode) * maxElementCount); // pElement가 가르키는 메모리로 찾아가 (최대 원소 개수 * 4바이트) 만큼의 메모리를 모두 0으로 초기화 -> 'memset 함수' 

	return pReturn;
}

// 2. deleteArrayList -> 배열리스트 삭제 함수
void deleteArrayList(ArrayList* pList) {
	if (pList != NULL) {                 
		if (pList->pElement != NULL) {    // 배열리스트가 제대로 전달됐는지, 리스트 속 저장공간은 제대로 전달됐는지 확인
			free(pList->pElement);
			free(pList);
		}
		else {
			printf("오류, 정확한 배열리스트가 전달되지 않았습니다! 확인해주세요. \n");
		}
	}
	else {
		printf("오류, 정확한 배열리스트가 전달되지 않았습니다! 확인해주세요. \n");
	}
}

// 3. isArrayListFull -> 배열리스트에 저장공간이 남아있는지 확인해주는 함수
int isArrayListFull(ArrayList* pList) {
	if (pList != NULL) {
		if ((pList->maxElementCount) > (pList->currentElementCount)) {
			return FALSE;
		}
		else {
			return TRUE;
		}
	}
	else {
		printf("오류, 정확한 배열리스트가 전달되지 않았습니다! 확인해주세요. \n");
		return FALSE;
	}
}

// 4. addALElement -> 배열리스트에 원하는 위치에 원소를 저장해주는 함수
int addALElement(ArrayList* pList, int position, ArrayListNode element) {
	if (pList != NULL) {
		if (position >= 0 && position <= pList->maxElementCount - 1) {
			for (int i = (pList->currentElementCount) - 1; i >= position; i--) {
				pList->pElement[i + 1] = pList->pElement[i]; // pElement는 실질적으로 원소를 저장하고 있는 배열이다(실제로는 구조체 포인터). 배열처럼 취급하여 코드를 짜면 이해에 편리하므로 배열로써 접근하겠다.
			}
			*((pList->pElement) + position) = element; // 위와의 일관성을 위해 pList->pElement[position]이라 쓰는게 합리적이지만 처음 내가 구현한 형태를 남겨두고자 이 부분은 수정을 하지않는다. 이렇게도 접근해도 상관없음을 명시한다. pElement[] 꼴은 ArrayListNode 구조체 자체를 가리키고, pElement+i는 그 구조체의 주소값을 가리킨다. 
			pList->currentElementCount ++; // += 1 을 써도 무관, 동일한 시간복잡도를 가짐. 현재 저장 원소 개수를 갱신해줌.
			return TRUE;
		}
		else{
			printf("오류, 접근할 수 있는 메모리영역을 벗어났습니다! 확인해주세요. \n");
			return FALSE;
	    }
    }
	else {
		printf("오류, 정확한 배열리스트가 전달되지 않았습니다! 확인해주세요. \n");
		return FALSE;
	}
} 

// 5. removeALElement -> 배열리스트에 원하는 위치의 원소를 제거해주는 함수
int removeALElement(ArrayList* pList, int position) {
	if (pList != NULL) {
		if (position >= 0 && position <= pList->currentElementCount - 1) {
			for (int i = position + 1; i < pList->currentElementCount; i++) {
				pList->pElement[i - 1] = pList->pElement[i];
			}
			(pList->pElement[pList->currentElementCount - 1]).data = 0; // 맨 마지막 칸은 이제 비어있는 칸이 되므로 다시 0으로 초기화해준다.
			pList->currentElementCount--; // 현재 원소 저장 개수 갱신
			return TRUE;
		}
		else {
			printf("오류, 접근할 수 있는 메모리영역을 벗어났습니다! 확인해주세요. \n");
			return FALSE;
		}
	}
	else {
		printf("오류, 정확한 배열리스트가 전달되지 않았습니다! 확인해주세요. \n");
		return FALSE;
	}
}

// 6. getALElement -> 배열리스트에서 원하는 위치에 저장되어있는 원소 값을 불러오는 함수
ArrayListNode* getALElement(ArrayList* pList, int position) {
	if (pList != NULL) {
		if (position >= 0 && position <= pList->currentElementCount - 1) {
			return (pList->pElement + position);
		}
		else {
			printf("오류, 접근할 수 있는 메모리영역을 벗어났습니다! 확인해주세요. \n");
			return NULL;
		}
	}
	else {
		printf("오류, 정확한 배열리스트가 전달되지 않았습니다! 확인해주세요. \n");
		return NULL;
	}
}

// 7. displayArrayList -> 배열리스트의 최대 원소 개수, 현재 원소 저장 개수, 원소값들을 출력해주는 함수
void displayArrayList(ArrayList* pList) {
	if (pList != NULL) {
		printf("최대 원소 개수: %d개 \n", pList->maxElementCount);
		printf("현재 원소 저장 개수: %d개 \n", pList->currentElementCount);
		printf("<현재 저장 원소> \n");
		for (int i = 0; i < pList->currentElementCount; i++) {
			printf("%d ", pList->pElement[i].data);
		}
		for (int i = pList->currentElementCount; i < pList->maxElementCount; i++) {
			printf("[Empty]");
		}
		printf("\n");
	}
	else {
		printf("오류, 정확한 배열리스트가 전달되지 않았습니다! 확인해주세요. \n");
	}
}

// 8. clearArrayList -> 배열리스트의 모든 공간을 0으로 초기화 시키는 함수 (모두 비우는 함수) 
void clearArrayList(ArrayList* pList) {
	if (pList != NULL) {
		for (int i = 0; i < pList->maxElementCount; i++) {
			pList->pElement[i].data = 0;
		}
	}
	else {
		printf("오류, 정확한 배열리스트가 전달되지 않았습니다! 확인해주세요. \n");
	}
}

// 9.  getArrayListLength -> 배열리스트에 현재 저장되어있는 원소의 개수를 반환해주는 함수
int getArrayListLength(ArrayList* pList) {
	if (pList != NULL) {
		return pList->currentElementCount;
	}
	else {
		printf("오류, 정확한 배열리스트가 전달되지 않았습니다! 확인해주세요. \n");
		return FALSE;
	}
}