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
		printf("이 배열리스트는 모두 차있습니다!");
	}
	else {
		printf("이 배열리스트는 아직 %d개의 공간이 남아있습니다!", (pList->maxElementCount) - (pList->currentElementCount));
	}
	return 0;
}