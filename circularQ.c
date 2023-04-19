/* circularQ.c
 *
 *  Data Structures, Homework #5
 *  School of Computer Science at Chungbuk National University
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 4

typedef char element;
typedef struct { // 구조체 선언
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
}QueueType;


QueueType *createQueue();  // 함수 선언
int freeQueue(QueueType *cQ);
int isEmpty(QueueType *cQ);
int isFull(QueueType *cQ);
void enQueue(QueueType *cQ, element item);
void deQueue(QueueType *cQ, element* item);
void printQ(QueueType *cQ);
void debugQ(QueueType *cQ);
element getElement();

int main(void)

{
	QueueType *cQ = createQueue(); //QueueType 포인터 선언 후 createQueue함수 값 할당
	element data; //element 형 변수 data 선언
	char command; // char 형 변수 command 선언
	
	printf("----- ohjaesik ------ 2022040014-----");
	do{ // Queue 연산을 위한 반복문
		printf("\n-----------------------------------------------------\n");
		printf("                     Circular Q                   \n");
		printf("------------------------------------------------------\n");
		printf(" Insert=i,  Delete=d,   PrintQ=p,   Debug=b,   Quit=q \n");
		printf("------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'i': case 'I': //Queue에 값을 대입
			data = getElement();
			enQueue(cQ, data);
			break;
		case 'd': case 'D': // Queue에 front값 삭제
			deQueue(cQ, &data);
			break;
		case 'p': case 'P': // Queue print
			printQ(cQ);
			break;
		case 'b': case 'B': // Queue debug
			debugQ(cQ);
			break;
		case 'q': case 'Q': // Queue 메모리 해제
   	        freeQueue(cQ);
			break;
		default: // 잘못 입력된 값 처리
			printf("\n       >>>>>   Concentration!!   <<<<<     \n");
			break;
		}

	}while(command != 'q' && command != 'Q'); // 종료


	return 1;
}

QueueType *createQueue()
{
	QueueType *cQ; // QueueType 포인터 변수 선언
	cQ = (QueueType *)malloc(sizeof(QueueType)); // cQ가 가리키는 주소에 QueueType의 크기의 메모리 할당
	cQ->front = 0; // cQ가 가리키는 주소에 front의 값 할당
	cQ->rear = 0; // cQ가 가리키는 주소에 rear의 값 할당
	return cQ;
}

int freeQueue(QueueType *cQ)
{
    if(cQ == NULL) return 1; // cQ가 가르키는 주소에 할당된 메모리 해제
    free(cQ);
    return 1;
}

element getElement()
{
	element item; 
	printf("Input element = ");
	scanf(" %c", &item); // 입력받은 값을 item에 할당
	return item;
}


/* complete the function */
int isEmpty(QueueType *cQ)
{
    if(cQ->front == cQ->rear){ // front와 rear의 값이 같으면 Queue가 비어 있는 것임을 체크
        printf("Queuse is empty");
        return 0;
    }
    return 1;
}

/* complete the function */
int isFull(QueueType *cQ)
{
    if(cQ->front == (cQ->rear + 1)% MAX_QUEUE_SIZE){ //front와 rear + 1의 값이 같으면 Queue가 꽉 차있는 것임을 체크
        printf("Queue is full");
        return 0;
    }
    return 1;
}


/* complete the function */
void enQueue(QueueType *cQ, element item)
{
    if(isFull(cQ)){
        cQ->queue[(++cQ->rear)%MAX_QUEUE_SIZE] = item; //queue에 rear가 가리키는 index에 입력 받은 값을 저장
    }
}

/* complete the function */
void deQueue(QueueType *cQ, element *item)
{
    if(isEmpty(cQ)){
        cQ->queue[(++cQ->front)%MAX_QUEUE_SIZE] = 0; //queue에 front가 가리키는 index에 저장된 값을 삭제
    }
}


void printQ(QueueType *cQ)
{
	int i, first, last;

	first = (cQ->front + 1)%MAX_QUEUE_SIZE; //front +1이 MAX_QUEUE_SIZE를 넘어 갔을때 값을 줄여주기 위해 MAX_QUEUE_SIZE로 나누어줌
	last = (cQ->rear + 1)%MAX_QUEUE_SIZE; //rear +1이 MAX_QUEUE_SIZE를 넘어 갔을때 값을 줄여주기 위해 MAX_QUEUE_SIZE로 나누어줌

	printf("Circular Queue : [");

	i = first;
	while(i != last){ //queue의 first값부터 last 값을 순서대로 출력
		printf("%3c", cQ->queue[i]);
		i = (i+1)%MAX_QUEUE_SIZE;

	}
	printf(" ]\n");
}


void debugQ(QueueType *cQ)
{

	printf("\n---DEBUG\n");
	for(int i = 0; i < MAX_QUEUE_SIZE; i++)
	{
		if(i == cQ->front) {
			printf("  [%d] = front\n", i); // queue의 front값을 찾아 출력
			continue;
		}
		printf("  [%d] = %c\n", i, cQ->queue[i]); // queue의 모든 값을 출력

	}
	printf("front = %d, rear = %d\n", cQ->front, cQ->rear); // front와 rear 출력
}

