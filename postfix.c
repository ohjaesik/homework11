/**
 * postfix.c
 *
 * School of Computer Science,
 * Chungbuk National University
 */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STACK_SIZE 10
#define MAX_EXPRESSION_SIZE 20

/* stack 내에서 우선순위는 내림차순, lparen = 0 가장 낮음 */
typedef enum{
	lparen = 0, /* ( 왼쪽 괄호 */
	rparen = 9, /* ) 오른쪽 괄호*/
	times = 7, /* * 곱셈 */
	divide = 6, /* / 나눗셈 */
	plus = 5, /* + 덧셈 */
	minus = 4, /* - 뺄셈 */
	operand = 1 /* 피연산자 */
} precedence;

char infixExp[MAX_EXPRESSION_SIZE]; 	
char postfixExp[MAX_EXPRESSION_SIZE];	
char postfixStack[MAX_STACK_SIZE];	
int evalStack[MAX_STACK_SIZE];		

int postfixStackTop = -1; 
int evalStackTop = -1;	 
int evalResult = 0;	 

void postfixpush(char x); // 함수 선언
char postfixPop();
void evalPush(int x);
int evalPop();
void getInfix();
precedence getToken(char symbol);
precedence getPriority(char x);
void charCat(char* c);
void toPostfix();
void debug();
void reset();
void evaluation();

int main()
{
	char command;

	printf("----- ohjaesik ------ 2022040014-----");
	do{ // 함수를 사용하기 위한 반복문
		printf("----------------------------------------------------------------\n");
		printf(" 혻 혻 혻 혻 혻 혻 혻 Infix to Postfix, then Evaluation 혻 혻 혻 혻 혻 혻 혻 \n");
		printf("----------------------------------------------------------------\n");
		printf(" Infix=i, 혻 Postfix=p, 혻Eval=e, 혻 Debug=d, 혻 Reset=r, 혻 Quit=q \n");
		printf("----------------------------------------------------------------\n");

		printf("Command = ");
		scanf(" %c", &command);

		switch(command) {
		case 'i': case 'I':
			getInfix();
			break;
		case 'p': case 'P':
			toPostfix();
			break;
		case 'e': case 'E':
			evaluation();
			break;
		case 'd': case 'D':
			debug();
			break;
		case 'r': case 'R':
			reset();
			break;
		case 'q': case 'Q':
			break;
		default:
			printf("\n 혻 혻 혻 >>>>> 혻 Concentration!! 혻 <<<<< 혻 혻 \n");
			break;
		}

	}while(command != 'q' && command != 'Q');

	return 1;
}

void postfixPush(char x) // postfixPush 구현
{
    postfixStack[++postfixStackTop] = x;
}

char postfixPop() // postfixPop 구현
{
 char x;
 if(postfixStackTop == -1)
  return '\0';
 else {
 	x = postfixStack[postfixStackTop--];
 }
 return x;
}

void evalPush(int x) // evalPush 구현
{
evalStack[++evalStackTop] = x;
}

int evalPop() //evalPop 구현
{
if(evalStackTop == -1)
return -1;
else
return evalStack[evalStackTop--];
}

/**
 * infix expression을 입력받는다.
 * infixExp에는 입력된 값을 저장한다.
 */
void getInfix()
{
printf("Type the expression >>> ");
scanf("%s",infixExp);
}

precedence getToken(char symbol)
{
	switch(symbol) {
	case '(' : return lparen;
	case ')' : return rparen;
	case '+' : return plus;
	case '-' : return minus;
	case '/' : return divide;
	case '*' : return times;
	default : return operand;
	}
}

precedence getPriority(char x)
{
	return getToken(x);
}

/**
 * 문자하나를 전달받아, postfixExp에 추가
 */
void charCat(char* c)
{
	if (postfixExp == '\0')
		strncpy(postfixExp, c, 1);
	else
		strncat(postfixExp, c, 1);
}

/**
 * infixExp의 문자를 하나씩 읽어가면서 stack을 이용하여 postfix로 변경한다.
 * 변경된 postfix는 postFixExp에 저장된다.
 */
void toPostfix()
{
	/* infixExp의 문자 하나씩을 읽기위한 포인터 */
	char *exp = infixExp;
	int idx = 0;
	/* exp를 증가시켜가면서, 문자를 읽고 postfix로 변경 */
	while(*exp != '\0'){ // exp가 끝날 때까지 반복
        
        if(getPriority(*exp)== operand){  //exp가 숫자일 경우 배열에 추가
            postfixExp[idx++] = *exp++;
            
        }
        else if( getPriority(*exp)==lparen) // exp가 '('일 경우 배열에 우선적으로 추가
            postfixPush(*exp++);
        else if (getToken(*exp)==rparen){ // exp가 ')'가 나왔을 경우 '('가 나올 때까지 기호를 팝함.
            while(getToken(postfixStack[postfixStackTop])!=lparen){
                postfixExp[idx++] = postfixPop();
            }
            postfixPop(); // '('을 팝.
            *exp++;
        }
        else if( postfixStackTop == -1 || getToken(postfixStack[postfixStackTop]) < getToken(*exp)){ //우선 순위가 큰 기호 스택에 저장
            postfixPush(*exp++);
        }
        else {
			while(getToken(postfixStack[postfixStackTop]) >= getToken(*exp)){ // 우선 순위가 낮거나 같은 연산자들을 팝함.
            postfixExp[idx++] = postfixPop();
			}
            postfixPush(*exp++); // 이후 연산자 스택에 저장
        
		}
	}

    while(postfixStackTop != -1){ // 스택에 저장되어 있는 모든 연산자 출력
        postfixExp[idx++] = postfixPop();
            
    }


}
void debug()
{
	printf("\n---DEBUG\n");
	printf("infixExp = %s\n", infixExp);
	printf("postExp = %s\n", postfixExp);
	printf("eval result = %d\n", evalResult);

	printf("postfixStack : ");
	for(int i = 0; i < MAX_STACK_SIZE; i++)
		printf("%c ", postfixStack[i]);

	printf("\n");

}

void reset()
{
	infixExp[0] = '\0';
	postfixExp[0] = '\0';

	for(int i = 0; i < MAX_STACK_SIZE; i++)
		postfixStack[i] = '\0';
	postfixStackTop = -1;
	evalStackTop = -1;
	evalResult = 0;
}

void evaluation()
{
    int idx=0;
    int x;
    while(postfixExp[idx] != '\0'){ // postfix의 끝까지 도는 반복문
        x=getToken(postfixExp[idx]); //x에 postfixExp 배열의 token값을 할당
        if(x==operand){ //숫자면 int형으로 바꾸고 저장
            evalPush(postfixExp[idx++] - 48);
        }
        else{ // 연산자가 나왔을 시 연산자에 맞게 계산
            int intger2 = evalPop();
            int intger1 = evalPop();
            if(x==minus){
                evalPush(intger1 - intger2);
            }
            else if(x==times){
                evalPush(intger1 * intger2);
            }
            else if(x==divide){
                evalPush(intger1 / intger2);
            }
            else{
                evalPush(intger1 + intger2);
            }
            idx++;
        }
    }
    evalResult = evalPop(); // 스택에 첫번째값이 결과 값이므로 결과값을 evalResult에 할당.
}