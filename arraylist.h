
// ifndef 선언은 메인함수 안에서 동일한 헤더파일이나 함수선언이 중복되어 선언되는 것을 방지하기 위해 이용된다. 만약 _ARRAYLIST_가 한번이라도 선언이 되었다면 '#ifndef~#endif' 사이 내용은 모두 생략된다.
// 허나 처음에 한번도 선언이 안된 상태라면 '#define _ARRAYLIST_' 라는 문장이 바로 뒤이어 등장하여 _ARRAYLIST_ 를 선언한다. 즉, 이 문장의 등장여부가 '#ifndef~#endif' 사이 내용의 생략여부를 결정한다.
#ifndef _ARRAYLIST_
#define _ARRAYLIST_

// 소스파일에서 이용할 기본적인 구조체들과 함수들을 미리 선언해둔다.
// 함수들에 대한 구체적인 설명은 소스파일에서 정의될 것
typedef struct ArraylistNodeType {
	int data;
} ArrayListNode;

typedef struct ArrayListType {
	int maxElementCount; // 최대 원소 개수 
	int currentElementCount; // 현재 원소 개수
	ArrayListNode* pElement; // 원소 저장을 위한 1차원 배열
} ArrayList;
 
ArrayList* createArrayList (int maxElementCount); // 최대 원소 개수를 입력받아 배열리스트를 생성 -> 동적할당을 활용, 배열리스트는 구조체의 형태로 한개의 구조체가 필요하다. 하지만 필요할 때마다 만들고 지우고 접근하기에 적합하도록 구조체 포인터 형태로 선언하여 사용한다.
void deleteArrayList (ArrayList* pList); // 배열리스트의 주소값을 입력받아 배열리스트를 삭제
int isArrayListFull (ArrayList* pList); // 배열리스트의 주소값을 입력받아 해당 배열리스트에 원소가 꽉차있는지를 Y/N로 반환
int addALElement (ArrayList* pList, int position, ArrayListNode element); // 배열리스트의 주소값, 위치값, 원소값을 입력받아 해당 배열리스트의 해당 위치값에 해당 원소값을 입력하고 성공했다면 TRUE, 실패했다면 FALSE를 출력 (이 때 위치값은 0을 시작으로 센다.)
int removeALElement (ArrayList* pList, int position); // 배열리스트의 주소값, 위치값을 입력받아 해당 배열리스트의 해당 위치값에 해당하는 원소값을 지우고 성공했다면 TRUE, 실패했다면 FALSE를 출력
ArrayListNode* getALElement(ArrayList* pList, int position); // 배열리스트의 주소값, 위치값을 입력받아 해당 배열리시트의 해당 위치값에 해당하는 원소값을 반환
void displayArrayList (ArrayList* pList); // 배열리시트의 주소값을 입력받아 해당 배열리스트의 최대 원소 개수를 출력하고, 저장되어있는 원소의 개수와  그 원소값들을 출력
void clearArrayList (ArrayList* pList); // 배열리스트의 주소값을 입력받아 해당 배열리스트의 모든 원소를 0으로 초기화하고 새로운 배열리스트의 주소값 반환
int getArrayListLength (ArrayList* pList); // 배열리스트의 주소값을 입력받아 해당 배열리스트에 저장되어있는 원소의 개수를 반환

#endif

// 동적으로 할당받은 배열리스트 크기(최대 원소 개수)는 처음에 이미 정해지는 상수이므로 알아내기 쉽지만 저장되어있는 원소의 개수를 알아내는 것은 쉽지 않다. 어디까지가 저장한 원소이고 어디서부터 비어있는 자리인지 파악할 때
// 해당 원소의 값으로 판단하는 것은 매우 부정확. 왜냐하면 기본적으로 무엇으로 초기화되어있을지 모르기 때문. 그렇기 때문에 현재 원소 개수를 계속 갱신해주며 이를 이용해 배열리스트에 효과적으로 접근할 수 있도록한다.

// 맨 위에서 설명한 내용이므로 자세한 설명은 생략
// 소스파일에서 사용할 T/F 상수를 미리 선언해둠
#ifndef _COMMON_LIST_DEF_
#define _COMMON_LIST_DEF_

#define TRUE 1
#define FALSE 0

#endif

// 위의 내용을 보아 헤더파일을 디자인할 땐 대략 어느 정도의 내용을 담아야할지 예상해볼 수 있다.
// 1. 매우 전반적인 개요에 사용될 툴들을 선언해둔다.
//   -> 주로 사용될 상수, 구조체, 함수 등등
// 2. '#ifndef~#endif' 을 이용한 중복선언 방지 코드는 필수!
// 이 헤더파일을 참조하여 소스파일에서 좀더 세세한 선언들과 정의들을 구사한다.