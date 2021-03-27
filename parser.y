/*
 *      - - C 2 PYTHON : PARSER - -
 */


/* Declarations */
%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>

	#include "AST.h"

	int type_check(struct expression* exp_1, struct expression* exp_2);
	extern int yyerror(char const* s);
	extern FILE *fp;
	int yylex();
	extern struct symbol* lookUp(char* sym);
	struct symbol symtab[NHASH];

%}

%union{
    struct statement* stat;
    struct expression* express;
    struct symbol* symb;
    char* string_lit;
    int int_lit;
    float float_lit;
		struct in_out* in_out;
}

/* Tokens */

%token <symb> NAME
%token <string_lit> STRING_TOKEN
%token <int_lit> INTEGER
%token <float_lit> FLOAT

%left GT LT NE EQ GE LE
%right TOKEN_ASS
%left TOKEN_ADD TOKEN_SUB
%left TOKEN_MUL TOKEN_DIV

%token LB RB LSB RSB LCB RCB PRINT SCAN PRINT_INT PRINT_STRING PRINT_FLOAT INT_TOKEN CHAR_TOKEN FLOAT_TOKEN
%token TOKEN_COL TOKEN_COM TOKEN_SEM TOKEN_QUO TOKEN_E IO_VAR EOL FOR IO_FLOAT IO_INT IO_STRING

%nonassoc IF
%nonassoc ELSE

/* Non terminal symbols */

%type <express> expression term factor condition init  assign castingFunc
%type <stat> root function statement statements block forStm ifStm printStm scanStm
%type <symb> forIncrement
%type <in_out> printStr outTail

%%

/* Grammar */

root:
			  function		{printf("\n\nParsing completed!\n"); exit(0);}
			;

function:
			  function statements		{eval_statement($2);} /*statementFree($2);} // the way to include all the possible statements of the input program into the whole parse tree*/
		  | /* NULL */                      {int xyz = 0;}
			;

statements:
			  statements statement		{$$ = statements_statement_create(STATEMENT_BLOCK, $1, $2);}
			| statement               {$$=$1;}
			;

statement:
			 expression {$$ = exp_statement_create(STATEMENT_EXP, $1);}
			| forStm
			| ifStm
			| scanStm
			| printStm
			;

expression:
			  expression TOKEN_ADD term {if(type_check($1,$3)==1){$$ = expression_create(EXPRESSION_SUM, $1, $3, $1->type);} else exit(0);}
			| expression TOKEN_SUB term {if(type_check($1,$3)==1){$$ = expression_create(EXPRESSION_SUB, $1, $3, $1->type);} else exit(0);}
			| term
			| condition
			| init
			| NAME {$$ = expression_name($1->type,lookUp($1->name));}
			| assign
			;

term:
			  term TOKEN_MUL factor {if(type_check($1,$3)==1){$$ = expression_create(EXPRESSION_MUL, $1, $3, $1->type);} else exit(0);}
			| term TOKEN_DIV factor {if(type_check($1,$3)==1){$$ = expression_create(EXPRESSION_DIV, $1, $3, $1->type);} else exit(0);}
			| factor {$$ = $1;}
			;

factor:	LB expression RB {$$ = expression_create(EXPRESSION_BRACKET, $2, NULL, $2->type);}
			| INTEGER {$$ = expression_integer($1);}
			| FLOAT {$$ = expression_float($1);}
			| NAME {$$ = expression_name($1->type,lookUp($1->name));}
			| NAME LSB NAME RSB {if($3->type == SYMBOL_INT) $$ = expression_vector_var(SYMBOL_INT, $1, $3);
															else printf("Index is not an Integer");}
			| NAME LSB INTEGER RSB {$$ = expression_vector_int(SYMBOL_INT, $1, expression_integer($3));}
			;

condition:
			  expression GT expression {if(type_check($1,$3)==1) $$ = expression_create(EXPRESSION_GT, $1, $3,$1->type); else exit(0);}
			| expression EQ expression {if(type_check($1,$3)==1) $$ = expression_create(EXPRESSION_EQ, $1, $3,$1->type); else exit(0);}
			| expression GE expression {if(type_check($1,$3)==1) $$ = expression_create(EXPRESSION_GE, $1, $3,$1->type); else exit(0);}
			| expression LE expression {if(type_check($1,$3)==1) $$ = expression_create(EXPRESSION_LE, $1, $3,$1->type); else exit(0);}
			| expression LT expression {if(type_check($1,$3)==1) $$ = expression_create(EXPRESSION_LT, $1, $3,$1->type); else exit(0);}
			| expression NE expression {if(type_check($1,$3)==1) $$ = expression_create(EXPRESSION_NE, $1, $3,$1->type); else exit(0);}
			;

forStm:
			FOR LB assign expression TOKEN_SEM forIncrement  RB block {if($3->type==SYMBOL_INT){ if($3->left->s->name == $4->left->s->name && $4->left->s->name == $6->name) $$ = for_statement_create(STATEMENT_FOR, $3, $4, $8);
																														else yyerror("For arguments have different variables ");}}
		;

assign:
				NAME TOKEN_ASS INTEGER TOKEN_SEM { $$ = expression_create(EXPRESSION_ASS, expression_name(SYMBOL_INT,lookUp($1->name)), expression_integer($3) , SYMBOL_INT);}
			| NAME TOKEN_ASS FLOAT TOKEN_SEM { $$ = expression_create(EXPRESSION_ASS, expression_name(SYMBOL_FLOAT,lookUp($1->name)), expression_float($3) , SYMBOL_FLOAT);}
			|	NAME TOKEN_ASS STRING_TOKEN  TOKEN_SEM { $$ = expression_create(EXPRESSION_ASS, expression_name(SYMBOL_STRING,lookUp($1->name)), expression_string($3) , SYMBOL_STRING);}
			|	NAME TOKEN_ASS castingFunc TOKEN_SEM { $$ = expression_create(EXPRESSION_ASS, expression_name($3->type,lookUp($1->name)), $3 , $3->type);}
			|	NAME TOKEN_ASS expression TOKEN_SEM {if($1->type==$3->type) $$ = expression_create(EXPRESSION_ASS, expression_name($3->type,lookUp($1->name)), $3 , $3->type);}	;
init:
			 	INT_TOKEN NAME TOKEN_ASS expression TOKEN_SEM		{if($4->type == SYMBOL_INT){ $$ = expression_create(EXPRESSION_ASS, expression_name($4->type,lookUp($2->name)), $4, $4->type);}}
			| INT_TOKEN NAME TOKEN_SEM 	{$$ = expression_create(EXPRESSION_ASS, expression_name(SYMBOL_INT,lookUp($2->name)), expression_integer(0), SYMBOL_INT);}
			| INT_TOKEN NAME LSB INTEGER RSB TOKEN_SEM  {$$ = expression_create(EXPRESSION_INTVEC, expression_name(SYMBOL_INT,lookUp($2->name)), expression_integer($4), SYMBOL_INT);}
			| CHAR_TOKEN TOKEN_MUL NAME TOKEN_SEM {$$ = expression_create(EXPRESSION_ASS, expression_name(SYMBOL_STRING,lookUp($3->name)), expression_string("\'\'"), SYMBOL_STRING);}
			| CHAR_TOKEN TOKEN_MUL NAME TOKEN_ASS STRING_TOKEN TOKEN_SEM {$$ = expression_create(EXPRESSION_ASS, expression_name(SYMBOL_STRING,lookUp($3->name)), expression_string($5), SYMBOL_STRING);}
			| FLOAT_TOKEN NAME TOKEN_ASS FLOAT TOKEN_SEM 	{ $$ = expression_create(EXPRESSION_ASS, expression_name(SYMBOL_FLOAT,lookUp($2->name)), expression_float($4), SYMBOL_FLOAT);}
			| FLOAT_TOKEN NAME TOKEN_SEM 	{ $$ = expression_create(EXPRESSION_ASS, expression_name(SYMBOL_FLOAT,lookUp($2->name)), expression_float(0.0), SYMBOL_FLOAT);}
		  ;

forIncrement:
			NAME TOKEN_ADD TOKEN_ADD {$$=$1;}
				;
block:
			  LCB statements RCB {$$ = block_statement_create(STATEMENT_BLOCK, $2);}
			;

ifStm:
			  IF LB condition RB block {$$ = if_else_statement_create(STATEMENT_IF, $3, NULL, $5, NULL);}
			| IF LB condition RB block ELSE IF LB condition RB block {$$ = if_else_statement_create(STATEMENT_ELSEIF, $3, $9, $5, $11);}
			| IF LB condition RB block ELSE block {$$ = if_else_statement_create(STATEMENT_IF_ELSE, $3, NULL,  $5, $7);}
			;

printStm:
			  PRINT LB printStr outTail TOKEN_SEM {$$ = print_statement_create(STATEMENT_PRINT, $3, $4);}
			 ;

printStr:
				STRING_TOKEN {$$ = in_out_string_create($1, PRINT_STR); }
			| TOKEN_QUO IO_INT TOKEN_QUO  {$$ = in_out_string_create(NULL, INOUT_INT);}
	  	| TOKEN_QUO IO_STRING TOKEN_QUO {$$ = in_out_string_create(NULL, INOUT_STRING); }
			| TOKEN_QUO IO_FLOAT TOKEN_QUO {$$ = in_out_string_create(NULL, INOUT_FLOAT);}

			;

outTail:
			RB {$$ = in_out_tail_create(CLOSING,NULL,NULL,0);}
		| TOKEN_COM NAME RB {$$ = in_out_tail_create(N_IO,lookUp($2->name),NULL,0);}
		| TOKEN_COM NAME LSB NAME RSB RB {$$ = in_out_tail_create(INOUT_VEC_VAR,lookUp($2->name),lookUp($4->name),0);}
		| TOKEN_COM NAME LSB INTEGER RSB RB {$$ = in_out_tail_create(INOUT_VEC_INT,lookUp($2->name),NULL,$4);}
			;

scanStm:
		  SCAN LB TOKEN_QUO IO_INT TOKEN_QUO TOKEN_COM TOKEN_E NAME RB TOKEN_SEM {$$ = scan_statement_create(STATEMENT_INPUT, INOUT_INT, in_out_tail_create(LAST_IO,lookUp($8->name),NULL,0));}
		| SCAN LB TOKEN_QUO IO_STRING TOKEN_QUO TOKEN_COM TOKEN_E NAME RB TOKEN_SEM {$$ = scan_statement_create(STATEMENT_INPUT, INOUT_STRING, in_out_tail_create(LAST_IO,lookUp($8->name),NULL,0));}
		| SCAN LB TOKEN_QUO IO_FLOAT TOKEN_QUO TOKEN_COM TOKEN_E NAME RB TOKEN_SEM {$$ = scan_statement_create(STATEMENT_INPUT, INOUT_FLOAT, in_out_tail_create(LAST_IO,lookUp($8->name),NULL,0));}
		| SCAN LB TOKEN_QUO IO_INT TOKEN_QUO TOKEN_COM TOKEN_E NAME LSB NAME RSB RB TOKEN_SEM {$$ = scan_statement_create(STATEMENT_INPUT, INOUT_VEC, in_out_tail_create(LAST_IO,lookUp($8->name),NULL,0));}
		;

castingFunc:
			LB INT_TOKEN RB NAME					{ $$ = expression_casting(EXPRESSION_CASTING, SYMBOL_INT, $4);}
		|	LB FLOAT_TOKEN RB NAME				{ $$ = expression_casting(EXPRESSION_CASTING, SYMBOL_FLOAT, $4);}

%%


/* hash a symbol */
static unsigned symHash(char *sym){
	unsigned int hash = 0;
	unsigned c;
	while(c = *sym++){
		hash = hash*9 ^ c;
	}

	return hash;
}

struct symbol* lookUp(char* sym){

    struct symbol *sp = &symtab[symHash(sym)%NHASH];
    int scount = NHASH;

    while((--scount >= 0)){
        if(sp->name && !strcmp(sp->name, sym))
            return sp;

        if(!sp->name){      /* new entry */
            sp->name = strdup(sym);
            sp->type = SYMBOL_UNDEF;
            return sp;
        }

        if(++sp >= symtab+NHASH){sp = symtab;        /* try the next entry */}

    }

    yyerror("Symbol table overflow\n");
    abort();        /* tried them all, table is full */
}

struct statement* statements_statement_create(statement_type kind, struct statement* body, struct statement* next){

 	 struct statement* s = calloc(3,sizeof(struct statement));

 	 if(!s){
 		 printf("Out of space!");
 		 exit(1);
 	 }

 	 s->kind = kind;
	 s->body = body;
	 s->next = next;

  }

	struct statement* exp_statement_create(statement_type kind, struct expression* exp){

	    struct statement* s = calloc(2, sizeof(struct statement));

	    if(!s){
	        printf("Out of space!");
	        exit(1);
	    }

			s->kind = kind;
			s->exp = exp;

	    return s;
	}

	struct statement* if_else_statement_create(statement_type kind, struct expression *exp, struct expression *next_exp, struct statement *body, struct statement *else_body){

	    struct statement* s = calloc(5, sizeof(struct statement));

	    if(!s){
	        printf("Out of space!");
	        exit(1);
	    }

	    s->kind = kind;
	    s->exp = exp;
			s->next_exp = next_exp;
	    s->body = body;
	    s->else_body = else_body;

	    return s;

	}

	struct statement* for_statement_create(statement_type kind, struct expression *init_exp, struct expression *exp, struct statement *body){

	    struct statement* s = calloc(4,sizeof(struct statement));

	    if(!s){
	        printf("Out of space!");
	        exit(1);
	    }

	    s->kind = kind;
	    s->init_exp = init_exp;
	    s->exp = exp;
	    s->body = body;

	    return s;

	}

	struct statement* block_statement_create(statement_type kind, struct statement *body){

	    struct statement* s = calloc(2, sizeof(struct statement));

	    if(!s){
	        printf("Out of space!");
	        exit(1);
	    }

	    s->kind = kind;
	    s->body = body;

	    return s;

	}

		struct statement* print_statement_create(statement_type kind, struct in_out* printStrings, struct in_out* ioTail){

				struct statement* s = calloc(3, sizeof(struct statement));

				if(!s){
						printf("Out of space!");
						exit(1);
				}
				s->kind = STATEMENT_PRINT;
				s->in_out_string = printStrings;
				s->in_out_tail = ioTail;

				return s;

		}

		struct statement* scan_statement_create(statement_type kind, in_out_type type, struct in_out* ioTail){

				struct statement* s = calloc(3, sizeof(struct statement));

				if(!s){
						printf("Out of space!");
						exit(1);
				}

				s->kind = STATEMENT_INPUT;
				s->iOkind = type;
				s->in_out_tail = ioTail;

				return s;

		}

		struct in_out* in_out_string_create(char* str, in_out_type kind){

				struct in_out* iO = calloc(2, sizeof(struct in_out));

				if(!iO){
						printf("Out of space!");
						exit(1);
				}
        if(kind==PRINT_STR){
				iO->string_lit = strdup(str);}
				else{iO->string_lit = strdup("empty string");}
				iO->kind = kind;

				return iO;

		}

		struct in_out* in_out_tail_create(in_out_type kind, struct symbol* sym, struct symbol* index, int i){

				struct in_out* iO = calloc(3, sizeof(struct in_out));

				if(!iO){
						printf("Out of space!");
						exit(1);
				}

				iO->kind = kind;
				iO->sym = sym;
				iO->index = index;
				iO->int_index = i;

				return iO;

		}




/*
 * EXPRESSIONS
 */

 struct expression* expression_create(expression_type kind, struct expression* left, struct expression* right, symbol_type type){

	 struct expression* e = calloc(4,sizeof(struct expression));

	 if(!e){
		 printf("Out of space!");
		 exit(1);
	 }

	 e->kind = kind;
	 e->left = left;
	 e->right = right;
	 e->type = type;

	 return e;
 }

 struct expression* expression_name(symbol_type type, struct symbol *s){

	 struct expression* e = calloc(4,sizeof(struct expression));

	 if(!e){
		 printf("Out of space!");
		 exit(1);
	 }

	 e->kind = EXPRESSION_NAME;
	 e->s = s;
	 e->s->type = type;
	 e->type = type;

 return e;
 }

 struct expression* expression_casting(expression_type kind, symbol_type type, struct symbol *s){

	 struct expression* e = calloc(4,sizeof(struct expression));

	 if(!e){
		 printf("Out of space!");
		 exit(1);
	 }

	 e->kind = kind;
	 e->s = s;
	 e->s->type = type;
	 e->type = type;

 return e;
 }

 struct expression* expression_vector_var(symbol_type type, struct symbol *s, struct symbol *index){

	 struct expression* e = calloc(4,sizeof(struct expression));

	 if(!e){
		 printf("Out of space!");
		 exit(1);
	 }

	 e->kind = EXPRESSION_VEC_VAR;
	 e->s = s;
	 e->s->type = type;
	 e->i = index;
	 e->type = type;

 }

 struct expression* expression_vector_int(symbol_type type, struct symbol *s, struct expression *i){

	 struct expression* e = calloc(4,sizeof(struct expression));

	 if(!e){
		 printf("Out of space!");
		 exit(1);
	 }

	 e->kind = EXPRESSION_VEC_INT;
	 e->s = s;
	 e->s->type = type;
	 e->int_lit = i->int_lit;
	 e->type = type;

 }

  struct expression* expression_integer(int i){

	struct expression* e = calloc(3,sizeof(struct expression));

	if(!e){
		printf("Out of space!");
		exit(1);
	}

	e->kind = EXPRESSION_INT;
	e->type = SYMBOL_INT;
	e->int_lit = i;
	return e;

 }

 struct expression* expression_float(float f){

	 struct expression* e = calloc(3,sizeof(struct expression));

	 if(!e){
		 printf("Out of space!");
		 exit(1);
	 }

	 e->kind = EXPRESSION_FLOAT;
	 e->type = SYMBOL_FLOAT;
	 e->float_lit = f;
	 return e;
 }

 struct expression* expression_string(char* str){
     struct expression* e = calloc(3, sizeof(struct expression));

     if(!e){
         printf("Out of space!");
         exit(1);
     }

     e->kind = EXPRESSION_STR;
     e->string_lit = strdup(str);
     e->type = SYMBOL_STRING;
     return e;

     }

 int type_check(struct expression* exp_1, struct expression* exp_2){

		 char* outMessage = "";
     char* var;

     if((exp_1->type)!=SYMBOL_UNDEF && (exp_2->type)!=SYMBOL_UNDEF){
         if((exp_1->type)==(exp_2->type))
             return 1;
         else{
             yyerror("Type of terms is not the same");
             return 0;
         }
     }else if((exp_1->type)==SYMBOL_UNDEF && (exp_2->type)!=SYMBOL_UNDEF){
             var = strdup(exp_1->s->name);
             outMessage = strcat(var," has no type.");
             yyerror(outMessage);
             return 0;
     }else if((exp_1->type)!=SYMBOL_UNDEF && (exp_2->type)==SYMBOL_UNDEF){
             var = strdup(exp_2->s->name);
             outMessage = strcat(var," has no type.");
             yyerror(outMessage);
             return 0;
     }else
         return 0;
 }

 int yyerror(char const *s) {
     fprintf(stderr, "<Line %d> %s\n", yylineno, s);
     return 0;
 }

 int main(int argc, char **argv){

		fp = fopen("out.py","ab+");

     if(yyparse()!=0){
         printf("Parse failed.\n");
     }

     return 0;
 }
