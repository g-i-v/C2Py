/*
 *      - - C 2 PYTHON LEXER - -
 */

/*
 * Declaration section
 */
%option noyywrap  yylineno

%{
     /* TODO: add inclusion of libraries */
    #include <stdlib.h>
    #include <stdio.h>
    #include <assert.h>

    #include "AST.h"
    #include "parser.tab.h"

    struct symbol* lookUp(char* sym);
    static unsigned symHash(char *sym);

    struct symbol symtab[NHASH];
    YYSTYPE yylval;

%}

/* Identifier and keywords */
digit           [0-9]
letter          [a-zA-Z]
whiteSpace      [" "]

/* Integers */
nonzerodigit    [1-9]
bininteger      0(b|B)(0|1)+
hexinteger      0(x|X)([0-9]|[a-fA-F])+
octinteger      0(o|O)[0-7]+|0[0-7]+
decimalinteger  [1-9][0-9]*|0

/* Floating Point */
exponential     (e|E)(\+|-)?[0-9]+
pointfloat      ([0-9]+)?(\.[0-9]+)|([0-9]+)\.
expfloat        ([0-9]+|([0-9]+)?(\.[0-9]+)|([0-9]+)\.)(e|E)(\+|-)?[0-9]+
ecomm		       	(&)

%%
  /*
   * Rules section
   */

    /* String literals */


    /* Single character operators */
"+"                                             {return TOKEN_ADD;}
"-"                                             {return TOKEN_SUB;}
"*"                                             {return TOKEN_MUL;}
"/"                                             {return TOKEN_DIV;}
"="                                             {return TOKEN_ASS;}
":"                                             {return TOKEN_COL;}
","                                             {return TOKEN_COM;}
";"                                             {return TOKEN_SEM;}
"("                                             { return LB;}
")"                                             {return RB;}
"["                                             {return LSB;}
"]"                                             {return RSB;}
"{"                                             {return LCB;}
"}"                                             {return RCB;}

">"                                             {return GT;}
"<"                                             {return LT;}
"!="                                            {return NE;}
"=="                                            {return EQ;}
">="                                            {return GE;}
"<="                                            {return LE;}
"%d"                                            {return IO_INT;}
"%s"										                      	{return IO_STRING;}
"%f"									                       		{return IO_FLOAT;}
"\""                                            {return TOKEN_QUO;}

    /* Keywords */

auto                                            {printf("Reserved word: %s\n", yytext);}
break                                           {printf("Reserved word: %s\n", yytext);}
case	                                          {printf("Reserved word: %s\n", yytext);}
char	                                          {return CHAR_TOKEN;}
const	                                          {printf("Reserved word: %s\n", yytext);}
continue                                        {printf("Reserved word: %s\n", yytext);}
do                                              {printf("Reserved word: %s\n", yytext);}
double                                          {printf("Reserved word: %s\n", yytext);}
else                                            {return ELSE;}
enum                                            {printf("Reserved word: %s\n", yytext);}
extern                                          {printf("Reserved word: %s\n", yytext);}
float                                           {return FLOAT_TOKEN;}
for                                             {return FOR;}
goto                                            {printf("Reserved word: %s\n", yytext);}
if                                              {return IF;}
int                                             {return INT_TOKEN;}
long                                            {printf("Reserved word: %s\n", yytext);}
register                                        {printf("Reserved word: %s\n", yytext);}
return                                          {printf("Reserved word: %s\n", yytext);}
scanf                                           {return SCAN;}
short                                           {printf("Reserved word: %s\n", yytext);}
signed                                          {printf("Reserved word: %s\n", yytext);}
sizeof                                          {printf("Reserved word: %s\n", yytext);}
static                                          {printf("Reserved word: %s\n", yytext);}
struct                                          {printf("Reserved word: %s\n", yytext);}
switch                                          {printf("Reserved word: %s\n", yytext);}
printf                                          {return PRINT;}
typedef                                         {printf("Reserved word: %s\n", yytext);}
union                                           {printf("Reserved word: %s\n", yytext);}
unsigned                                        {printf("Reserved word: %s\n", yytext);}
void                                            {printf("Reserved word: %s\n", yytext);}
volatile                                        {printf("Reserved word: %s\n", yytext);}
while                                           {printf("Reserved word: %s\n", yytext);}

{ecomm}                           {return TOKEN_E;}
    /* Variables */
\"({letter}|{digit}|{whiteSpace})*\"        { yylval.string_lit = strdup(yytext);return STRING_TOKEN;}
    /* Identifiers */
({letter}|\_)({letter}|{digit}|\_)*                               { yylval.symb = lookUp(yytext); return NAME;}
    /* Numeric literals */
{decimalinteger}|{octinteger}|{hexinteger}|{bininteger}           {yylval.int_lit = atoi(yytext); return INTEGER;}

{pointfloat}|{expfloat}                                           {yylval.float_lit=atof(yytext); return FLOAT;}


[ ]                                       {/**/}

\n                    {}

%%
/**/
