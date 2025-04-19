%{ 
    #include <stdio.h> 
    int flag = 0; 
%} 

%token NUMBER 
%left '+' '-'
%left '*' '/' '%'
%left '(' ')'

%% 

ArithmeticExpression: E {
    printf("Result=%d\n", $$); 
    return 0; 
}; 

E:E'+'E {$$=$1+$3;} 
  |E'-'E {$$=$1-$3;} 
  |E'*'E {$$=$1*$3;} 
  |E'/'E {$$=$1/$3;} 
  |E'%'E {$$=$1%$3;} 
  |'('E')' {$$=$2;} 
  | NUMBER {$$=$1;} ; 

%% 

void main() { 
    printf("Enter expression: "); 
    yyparse(); 
    if (flag == 0) 
        printf("Entered arithmetic expression is valid\n"); 
} 

void yyerror() { 
    printf("Entered arithmetic expression is invalid\n"); 
    flag=1; 
} 
