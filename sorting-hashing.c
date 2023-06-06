/*
 * sorting-hashing.c
 *
 *  Sorting & Hashing
 *  School of Computer Science at Chungbuk National University
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ARRAY_SIZE         13   /* prime number */
#define MAX_HASH_TABLE_SIZE    MAX_ARRAY_SIZE

/* 함수 선언 */
int initialize(int **a);
int freeArray(int *a);
void printArray(int *a);

int selectionSort(int *a);
int insertionSort(int *a);
int bubbleSort(int *a);
int shellSort(int *a);
/* recursive function 쇰줈 援ы쁽 */
int quickSort(int *a, int n);


/* hash code generator, key % MAX_HASH_TABLE_SIZE */
int hashCode(int key);

/* array a 먮     hash table   留뚮뱺  . */
int hashing(int *a, int **ht);

/* hash table 먯꽌 key瑜  李얠븘 hash table   index return */
int search(int *ht, int key);


int main()
{
   char command;
   int *array = NULL;
   int *hashtable = NULL;
   int key = -1;
   int index = -1;

   srand(time(NULL));
    printf("---------2022040014 ---- ohjaesik -------\n" );
   do{
      printf("----------------------------------------------------------------\n");
      printf("                        Sorting & Hashing                       \n");
      printf("----------------------------------------------------------------\n");
      printf(" Initialize       = z           Quit             = q\n");
      printf(" Selection Sort   = s           Insertion Sort   = i\n");
      printf(" Bubble Sort      = b           Shell Sort       = l\n");
      printf(" Quick Sort       = k           Print Array      = p\n");
      printf(" Hashing          = h           Search(for Hash) = e\n");
      printf("----------------------------------------------------------------\n");

      printf("Command = ");
      scanf(" %c", &command);

      switch(command) {
      case 'z': case 'Z':
         initialize(&array);
         break;
      case 'q': case 'Q':
         freeArray(array);
         break;
      case 's': case 'S':
         selectionSort(array);
         break;
      case 'i': case 'I':
         insertionSort(array);
         break;
      case 'b': case 'B':
         bubbleSort(array);
         break;
      case 'l': case 'L':
         shellSort(array);
         break;
      case 'k': case 'K':
         printf("Quick Sort: \n");
         printf("----------------------------------------------------------------\n");
         printArray(array);
         quickSort(array, MAX_ARRAY_SIZE);
         printf("----------------------------------------------------------------\n");
         printArray(array);

         break;

      case 'h': case 'H':
         printf("Hashing: \n");
         printf("----------------------------------------------------------------\n");
         printArray(array);
         hashing(array, &hashtable);
         printArray(hashtable);
         break;

      case 'e': case 'E':
         printf("Your Key = ");
         scanf("%d", &key);
         printArray(hashtable);
         index = search(hashtable, key);
            if (index == -1)break;
         printf("key = %d, index = %d,  hashtable[%d] = %d\n", key, index, index, hashtable[index]);
         break;

      case 'p': case 'P':
         printArray(array);
         break;
      default:
         printf("\n       >>>>>   Concentration!!   <<<<<     \n");
         break;
      }

   }while(command != 'q' && command != 'Q');

   return 1;
}

int initialize(int** a)
{
   int *temp = NULL;

   /* array가 NULL 이라면 사용할 메모리 할당 */
   if(*a == NULL) {
      temp = (int*)malloc(sizeof(int) * MAX_ARRAY_SIZE);
      *a = temp;  /* 할당된 메모리값을 a가 가리키도록 함 --> main에 존재하는 a로 받아온 공간에 크기를 바꿈*/
   } else
      temp = *a;

   /* 할당된 메모리에 랜덤으로 값 삽입 */
   for(int i = 0; i < MAX_ARRAY_SIZE; i++)
      temp[i] = rand() % MAX_ARRAY_SIZE;

   return 0;
}

int freeArray(int *a) // array의 메모리 해제
{
   if(a != NULL)
      free(a);
   return 0;
}

void printArray(int *a) // array의 값 출력
{
   if (a == NULL) { // array가 비어있다는 것을 알림
      printf("nothing to print.\n");
      return;
   }
   for(int i = 0; i < MAX_ARRAY_SIZE; i++) 
      printf("a[%02d] ", i);
   printf("\n");
   for(int i = 0; i < MAX_ARRAY_SIZE; i++) //array의 값 출력
      printf("%5d ", a[i]);
   printf("\n");
}


int selectionSort(int *a) // 선택정렬
{
   int min;
   int minindex;
   int i, j;

   printf("Selection Sort: \n");
   printf("----------------------------------------------------------------\n");

   printArray(a);

   for (i = 0; i < MAX_ARRAY_SIZE; i++)
   {
      minindex = i;
      min = a[i];
      for(j = i+1; j < MAX_ARRAY_SIZE; j++) 
      {
         if (min > a[j]) // 배열에서 가장 작은 원소를 찾음
         {
            min = a[j]; // min에 가장 작은 원소 저장
            minindex = j;  // 가장 작은 원소의 인덱스값 저장
         }
      }
      a[minindex] = a[i]; // 기존에 가장 작은 값을 가진 인덱스 값에 현재 i인덱스의 값 삽입
      a[i] = min; // min을 삽입
   }

   printf("----------------------------------------------------------------\n");
   printArray(a); //정렬 결과 출력
   return 0;
}

int insertionSort(int *a) // 삽입정렬
{
   int i, j, t;

   printf("Insertion Sort: \n");
   printf("----------------------------------------------------------------\n");

   printArray(a);

   for(i = 1; i < MAX_ARRAY_SIZE; i++)
   {
      t = a[i]; // 배열 i의 값 저장
      j = i; // i 값 j에 할당
      while (a[j-1] > t && j > 0) 
      {
         a[j] = a[j-1]; //현재 배열 j의 값보다 앞에 있는 배열 j의 값이 크다면 한칸 이동 시킴.
         j--;
      }
      a[j] = t; // j의 위치에 t 삽입
   }

   printf("----------------------------------------------------------------\n");
   printArray(a);

   return 0;
}

int bubbleSort(int *a) // 버블 정렬
{
   int i, j, t;

   printf("Bubble Sort: \n");
   printf("----------------------------------------------------------------\n");

   printArray(a);

   for(i = 0; i < MAX_ARRAY_SIZE-1; i++)
   {
      for (j = 1; j < MAX_ARRAY_SIZE; j++)
      {
         if (a[j-1] > a[j]) // 배열의 처음부터 바로 다음원소와 비교하며 앞의 원소가 뒤의 원소보다 크다면 자리 교환.
         {
            t = a[j-1];
            a[j-1] = a[j];
            a[j] = t;
         }
      }
   }

   printf("----------------------------------------------------------------\n");
   printArray(a);

   return 0;
}

int shellSort(int *a) //셸 정렬
{
   int i, j, k, h, v;

   printf("Shell Sort: \n");
   printf("----------------------------------------------------------------\n");

   printArray(a);

   for (h = MAX_ARRAY_SIZE/2; h > 0; h /= 2) //간격 h, 절반으로 줄임
   {
      for (i = 0; i < h; i++)
      {
         for(j = i + h; j < MAX_ARRAY_SIZE; j += h) // h만큼 이동
         {
            v = a[j]; 
            k = j;
            while (k > h-1 && a[k-h] > v) //v보다 a[k-h]가 크다면
            {
               a[k] = a[k-h]; // a[k]에 a[k-h]값 삽입
               k -= h; // k를 h만큼 앞으로
            }
            a[k] = v; // a[k]에 v삽입
         }
      }
   }
   printf("----------------------------------------------------------------\n");
   printArray(a);

   return 0;
}

int quickSort(int *a, int n) //퀵 정렬
{
   int v, t;
   int i, j;

   if (n > 1)
   {
      v = a[n-1]; // 가장 마지막 원소를 피벗으로 설정
      i = -1;
      j = n - 1;

      while(1)
      {
         while(a[++i] < v); // 피벗의 값이 a[i]보다 커질때까지 뒤로 이동
         while(a[--j] > v); // 피벗의 값이 a[j]보다 작아질때까지 앞으로 이동

         if (i >= j) break; // 인덱스 i값이 j값보다 크다면 반복을 멈춤
         t = a[i]; //그렇지 않다면 i와 j의 값을 교환
         a[i] = a[j];
         a[j] = t;
      }
      t = a[i]; // 반복문이 끝난후 피벗값을 i의 위치와 교환
      a[i] = a[n-1];
      a[n-1] = t;

      quickSort(a, i); // 재귀호출
      quickSort(a+i+1, n-i-1);
   }


   return 0;
}

int hashCode(int key) { // 해쉬 값이 저장된 곳을 리턴
   return key % MAX_HASH_TABLE_SIZE;
}

int hashing(int *a, int **ht) // 해싱
{
   int *hashtable = NULL;

   /* hash table이 NULL이라면 hashtable에 메모리 할당  */
   if(*ht == NULL) {
      hashtable = (int*)malloc(sizeof(int) * MAX_ARRAY_SIZE);
      *ht = hashtable;  /*  좊떦   硫붾え由ъ쓽 二쇱냼瑜  蹂듭궗 --> main 먯꽌 諛곗뿴   control  좎닔  덈룄濡    */
   } else {
      hashtable = *ht;   /* hash table   NULL    꾨땶寃쎌슦, table  ы솢  , reset to -1 */
   }

   for(int i = 0; i < MAX_HASH_TABLE_SIZE; i++) // 해시테이블 값 초기화
      hashtable[i] = -1;

   int key = -1;
   int hashcode = -1;
   int index = -1;
   for (int i = 0; i < MAX_ARRAY_SIZE; i++)
   {
      key = a[i]; // 저장 값 할당
      hashcode = hashCode(key); // 저장 주소 할당

      if (hashtable[hashcode] == -1) // 해시값이 없을 때 
      {
         hashtable[hashcode] = key; // 해시테이블에 키 삽입
      } else    {

         index = hashcode; 

         while(hashtable[index] != -1) // 해시테이블에 값이 존재한다면
         { //하나씩 확인하면서 빈 해시테이블을 찾는다.
            index = (++index) % MAX_HASH_TABLE_SIZE;
         }
         hashtable[index] = key; // 빈 해시테이블에 값 할당.
      }
   }

   return 0;
}

int search(int *ht, int key) // 해시 테이블에 저장된 키값 찾기
{
   int index = hashCode(key);
    int circle = 0;
   if(ht[index] == key) // 원래 값의 해시 값에 원소와 키와 같다면 index리턴
      return index;

   while(ht[++index] != key) // 인덱스 값을 증가 시키면서 키를 찾음
   {
      index = index % MAX_HASH_TABLE_SIZE;
        circle ++;
        if(circle == MAX_HASH_TABLE_SIZE){
            printf("have not key in hash table \n"); //해시 테이블이 키값에 없을 때
            return -1;
        }
   }
   return index;
}

