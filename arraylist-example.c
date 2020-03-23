#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arraylist.h"


int main() {
	ArrayList* pList = createArrayList(10);
	ArrayListNode value;
	for (int i = 0; i < 10; i++) {
		value.data = i + 1;
		addALElement(pList, i, value);
	}
	displayArrayList(pList);
	removeALElement(pList, 4);
	removeALElement(pList, 1);
	displayArrayList(pList);
	if (isArrayListFull(pList) == 1) {
		printf("�� �迭����Ʈ�� ��� ���ֽ��ϴ�!");
	}
	else {
		printf("�� �迭����Ʈ�� ���� %d���� ������ �����ֽ��ϴ�!", (pList->maxElementCount) - (pList->currentElementCount));
	}
	return 0;
}