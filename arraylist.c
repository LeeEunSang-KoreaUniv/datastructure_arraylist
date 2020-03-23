#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraylist.h"
// <�������>�� ���´� c/c++���� �����ϴ� ǥ�� ���̺귯���� ����Ǿ��ִ� ��������� ������ ��
// "�������"�� ���´� ������ ���� �ۼ��� ��������� ������ ��

// ������Ͽ��� ���������� �����Ͽ��� �Լ����� ��ü���� ���Ǹ� �����Ѵ�. 

// 1. createArrayList -> �迭����Ʈ ���� �Լ�
ArrayList* createArrayList(int maxElementCount) { 
	ArrayList* pReturn = NULL;
	int i = 0;

	if (maxElementCount > 0) {
		pReturn = (ArrayList*)malloc(sizeof(ArrayList)); // �⺻������ �����Ҵ��� �̿��Ͽ� �޸𸮸� �Ҵ�����, �迭���� X

		if (pReturn != NULL) { // �����Ҵ翡�� �̰� ������ �ʼ�!! �Ҵ��� �� ������ �̹� �Ҵ��� �޸� ������ ������ ������ �׻� �˻��ϰ� ��� �۾��� ������ ��!
			pReturn->maxElementCount = maxElementCount;
			pReturn->currentElementCount = 0;
			pReturn->pElement = NULL;
		}
		else {
			printf("����, �޸��Ҵ� ����! \n");
			return NULL;
		}
	}
	else {
		printf("����, �ִ� ���� ������ 0�̻��̾�� �մϴ�! \n");
		return NULL;
	}
	
	pReturn->pElement = (ArrayListNode*)malloc(sizeof(ArrayListNode)*maxElementCount); // �⺻������ �����Ҵ��� �̿��Ͽ� �޸𸮸� �Ҵ�����, �迭���� X

	if (pReturn->pElement == NULL) {
		printf("����, 2��° �޸��Ҵ� ����! \n");
		free(pReturn);
		return NULL;
	}
	memset(pReturn->pElement, 0, sizeof(ArrayListNode) * maxElementCount); // pElement�� ����Ű�� �޸𸮷� ã�ư� (�ִ� ���� ���� * 4����Ʈ) ��ŭ�� �޸𸮸� ��� 0���� �ʱ�ȭ -> 'memset �Լ�' 

	return pReturn;
}

// 2. deleteArrayList -> �迭����Ʈ ���� �Լ�
void deleteArrayList(ArrayList* pList) {
	if (pList != NULL) {                 
		if (pList->pElement != NULL) {    // �迭����Ʈ�� ����� ���޵ƴ���, ����Ʈ �� ��������� ����� ���޵ƴ��� Ȯ��
			free(pList->pElement);
			free(pList);
		}
		else {
			printf("����, ��Ȯ�� �迭����Ʈ�� ���޵��� �ʾҽ��ϴ�! Ȯ�����ּ���. \n");
		}
	}
	else {
		printf("����, ��Ȯ�� �迭����Ʈ�� ���޵��� �ʾҽ��ϴ�! Ȯ�����ּ���. \n");
	}
}

// 3. isArrayListFull -> �迭����Ʈ�� ��������� �����ִ��� Ȯ�����ִ� �Լ�
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
		printf("����, ��Ȯ�� �迭����Ʈ�� ���޵��� �ʾҽ��ϴ�! Ȯ�����ּ���. \n");
		return FALSE;
	}
}

// 4. addALElement -> �迭����Ʈ�� ���ϴ� ��ġ�� ���Ҹ� �������ִ� �Լ�
int addALElement(ArrayList* pList, int position, ArrayListNode element) {
	if (pList != NULL) {
		if (position >= 0 && position <= pList->maxElementCount - 1) {
			for (int i = (pList->currentElementCount) - 1; i >= position; i--) {
				pList->pElement[i + 1] = pList->pElement[i]; // pElement�� ���������� ���Ҹ� �����ϰ� �ִ� �迭�̴�(�����δ� ����ü ������). �迭ó�� ����Ͽ� �ڵ带 ¥�� ���ؿ� ���ϹǷ� �迭�ν� �����ϰڴ�.
			}
			*((pList->pElement) + position) = element; // ������ �ϰ����� ���� pList->pElement[position]�̶� ���°� �ո��������� ó�� ���� ������ ���¸� ���ܵΰ��� �� �κ��� ������ �����ʴ´�. �̷��Ե� �����ص� ��������� ����Ѵ�. pElement[] ���� ArrayListNode ����ü ��ü�� ����Ű��, pElement+i�� �� ����ü�� �ּҰ��� ����Ų��. 
			pList->currentElementCount ++; // += 1 �� �ᵵ ����, ������ �ð����⵵�� ����. ���� ���� ���� ������ ��������.
			return TRUE;
		}
		else{
			printf("����, ������ �� �ִ� �޸𸮿����� ������ϴ�! Ȯ�����ּ���. \n");
			return FALSE;
	    }
    }
	else {
		printf("����, ��Ȯ�� �迭����Ʈ�� ���޵��� �ʾҽ��ϴ�! Ȯ�����ּ���. \n");
		return FALSE;
	}
} 

// 5. removeALElement -> �迭����Ʈ�� ���ϴ� ��ġ�� ���Ҹ� �������ִ� �Լ�
int removeALElement(ArrayList* pList, int position) {
	if (pList != NULL) {
		if (position >= 0 && position <= pList->currentElementCount - 1) {
			for (int i = position + 1; i < pList->currentElementCount; i++) {
				pList->pElement[i - 1] = pList->pElement[i];
			}
			(pList->pElement[pList->currentElementCount - 1]).data = 0; // �� ������ ĭ�� ���� ����ִ� ĭ�� �ǹǷ� �ٽ� 0���� �ʱ�ȭ���ش�.
			pList->currentElementCount--; // ���� ���� ���� ���� ����
			return TRUE;
		}
		else {
			printf("����, ������ �� �ִ� �޸𸮿����� ������ϴ�! Ȯ�����ּ���. \n");
			return FALSE;
		}
	}
	else {
		printf("����, ��Ȯ�� �迭����Ʈ�� ���޵��� �ʾҽ��ϴ�! Ȯ�����ּ���. \n");
		return FALSE;
	}
}

// 6. getALElement -> �迭����Ʈ���� ���ϴ� ��ġ�� ����Ǿ��ִ� ���� ���� �ҷ����� �Լ�
ArrayListNode* getALElement(ArrayList* pList, int position) {
	if (pList != NULL) {
		if (position >= 0 && position <= pList->currentElementCount - 1) {
			return (pList->pElement + position);
		}
		else {
			printf("����, ������ �� �ִ� �޸𸮿����� ������ϴ�! Ȯ�����ּ���. \n");
			return NULL;
		}
	}
	else {
		printf("����, ��Ȯ�� �迭����Ʈ�� ���޵��� �ʾҽ��ϴ�! Ȯ�����ּ���. \n");
		return NULL;
	}
}

// 7. displayArrayList -> �迭����Ʈ�� �ִ� ���� ����, ���� ���� ���� ����, ���Ұ����� ������ִ� �Լ�
void displayArrayList(ArrayList* pList) {
	if (pList != NULL) {
		printf("�ִ� ���� ����: %d�� \n", pList->maxElementCount);
		printf("���� ���� ���� ����: %d�� \n", pList->currentElementCount);
		printf("<���� ���� ����> \n");
		for (int i = 0; i < pList->currentElementCount; i++) {
			printf("%d ", pList->pElement[i].data);
		}
		for (int i = pList->currentElementCount; i < pList->maxElementCount; i++) {
			printf("[Empty]");
		}
		printf("\n");
	}
	else {
		printf("����, ��Ȯ�� �迭����Ʈ�� ���޵��� �ʾҽ��ϴ�! Ȯ�����ּ���. \n");
	}
}

// 8. clearArrayList -> �迭����Ʈ�� ��� ������ 0���� �ʱ�ȭ ��Ű�� �Լ� (��� ���� �Լ�) 
void clearArrayList(ArrayList* pList) {
	if (pList != NULL) {
		for (int i = 0; i < pList->maxElementCount; i++) {
			pList->pElement[i].data = 0;
		}
	}
	else {
		printf("����, ��Ȯ�� �迭����Ʈ�� ���޵��� �ʾҽ��ϴ�! Ȯ�����ּ���. \n");
	}
}

// 9.  getArrayListLength -> �迭����Ʈ�� ���� ����Ǿ��ִ� ������ ������ ��ȯ���ִ� �Լ�
int getArrayListLength(ArrayList* pList) {
	if (pList != NULL) {
		return pList->currentElementCount;
	}
	else {
		printf("����, ��Ȯ�� �迭����Ʈ�� ���޵��� �ʾҽ��ϴ�! Ȯ�����ּ���. \n");
		return FALSE;
	}
}