/* postfix.c
혻*
혻* 혻Data Structures, Homework #5
혻* 혻School of Computer Science at Chungbuk National University
혻*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_STACK_SIZE 10
#define MAX_EXPRESSION_SIZE 20

/* stack �댁뿉�� �곗꽑�쒖쐞, lparen = 0 媛��� ��쓬 */
typedef enum{
	lparen = 0,/* ( �쇱そ 愿꾪샇 */
	rparen = 9, /* ) �ㅻⅨ履� 愿꾪샇*/
	times = 7,  /* * 怨깆뀍 */
	divide = 6, /* / �섎닓�� */
	plus = 5, /* + �㏃뀍 */
	minus = 4,  /* - 類꾩뀍 */
	operand = 1 /* �쇱뿰�곗옄 */
} precedence;

char infixExp[MAX_EXPRESSION_SIZE]; 	/* infix expression�� ���ν븯�� 諛곗뿴 */
char postfixExp[MAX_EXPRESSION_SIZE];	/* postfix濡� 蹂�寃쎈맂 臾몄옄�댁쓣 ���ν븯�� 諛곗뿴 */
char postfixStack[MAX_STACK_SIZE];	/* postfix濡� 蹂��섏쓣 �꾪빐 �꾩슂�� �ㅽ깮 */
int evalStack[MAX_STACK_SIZE];		/* 怨꾩궛�� �꾪빐 �꾩슂�� �ㅽ깮 */

int postfixStackTop = -1; /* postfixStack�� top */
int evalStackTop = -1;	  /* evalStack�� top */

int evalResult = 0;	 /* 怨꾩궛 寃곌낵瑜� ���� */

void postfixpush(char x);
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

	do{
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

void postfixPush(char x)
{
    postfixStack[++postfixStackTop] = x;
}

char postfixPop()
{
 char x;
 if(postfixStackTop == -1)
  return '\0';
 else {
 	x = postfixStack[postfixStackTop--];
 }
 return x;
}

void evalPush(int x)
{
evalStack[++evalStackTop] = x;
}

int evalPop()
{
if(evalStackTop == -1)
return -1;
else
return evalStack[evalStackTop--];
}

/**
혻* infix expression�� �낅젰諛쏅뒗��.
혻* infixExp�먮뒗 �낅젰�� 媛믪쓣 ���ν븳��.
혻*/
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
혻* 臾몄옄�섎굹瑜� �꾨떖諛쏆븘, postfixExp�� 異붽�
혻*/
void charCat(char* c)
{
	if (postfixExp == '\0')
		strncpy(postfixExp, c, 1);
	else
		strncat(postfixExp, c, 1);
}

/**
혻* infixExp�� 臾몄옄瑜� �섎굹�� �쎌뼱媛�硫댁꽌 stack�� �댁슜�섏뿬 postfix濡� 蹂�寃쏀븳��.
혻* 蹂�寃쎈맂 postfix�� postFixExp�� ���λ맂��.
혻*/
void toPostfix()
{
	/* infixExp�� 臾몄옄 �섎굹�⑹쓣 �쎄린�꾪븳 �ъ씤�� */
	char *exp = infixExp;
	char x; /* 臾몄옄�섎굹瑜� �꾩떆濡� ���ν븯湲� �꾪븳 蹂��� */
    int idx = 0;

	while(*exp != '\0')
	{
        x=getToken(*exp);
        if(x == operand){
            postfixExp[idx++] = *exp++;
            
        }
        else if( x==lparen)
            postfixPush(*exp++);
        else if (x==rparen){
            while(getToken(postfixStack[postfixStackTop])!=lparen){
                postfixExp[idx++] = postfixPop();
            }
            postfixPop();
            *exp++;
        }
        else if( postfixStackTop == -1 || getToken(postfixStack[postfixStackTop]) < x){
            postfixPush(*exp++);
        }
        else if(getToken(postfixStack[postfixStackTop]) >= x){
            postfixExp[idx++] = postfixPop();
            
            postfixPush(*exp++);
        }
        else{
            postfixExp[idx++] = postfixPop();
            
        }
	}

    while(postfixStackTop != -1){
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
    while(postfixExp[idx] != '\0'){
        x=getToken(postfixExp[idx]);
        if(x==operand){
            evalPush(postfixExp[idx++] - 48);
        }
        else{
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
    evalResult = evalPop();
}