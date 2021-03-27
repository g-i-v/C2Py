
extern int yylineno;
extern int yyerror(char const *s);

typedef enum{

    SYMBOL_UNDEF,
    SYMBOL_INT,
    SYMBOL_FLOAT,
    SYMBOL_STRING

 } symbol_type;

 typedef enum{

    STATEMENT_EXP,
    STATEMENT_IF_ELSE,
    STATEMENT_IF,
    STATEMENT_ELSEIF,
    STATEMENT_FOR,
    STATEMENT_PRINT,
    STATEMENT_INPUT,
    STATEMENT_BLOCK

 } statement_type;

 typedef enum{
     EXPRESSION_SUM,
     EXPRESSION_SUB,
     EXPRESSION_MUL,
     EXPRESSION_DIV,
     EXPRESSION_GT,
     EXPRESSION_LT,
     EXPRESSION_GE,
     EXPRESSION_LE,
     EXPRESSION_EQ,
     EXPRESSION_NE,
     EXPRESSION_ASS,
     EXPRESSION_INTVEC,
     EXPRESSION_CHARVEC,
     EXPRESSION_FLOATVEC,
     EXPRESSION_BRACKET,
     EXPRESSION_NAME,
     EXPRESSION_INT,
     EXPRESSION_FLOAT,
     EXPRESSION_STR,
     EXPRESSION_CASTING,
     EXPRESSION_VEC_INT,
     EXPRESSION_VEC_VAR
 } expression_type;

 typedef enum{
   N_IO,
   LAST_IO,
   PRINT_STR,
   INOUT_STRING,
   INOUT_VEC,
   INOUT_INT,
   INOUT_FLOAT,
   INOUT_VEC_VAR,
   INOUT_VEC_INT,
   CLOSING
 } in_out_type;

 typedef struct statement{

     in_out_type iOkind;
     statement_type kind;
     struct expression *init_exp;
     struct expression *exp;
     struct expression *next_exp;
     struct statement *body;
     struct statement *else_body;
     struct statement *next;
     struct in_out *in_out_string;
     struct in_out *in_out_tail;

 } statement;

typedef struct symbol{
    char* name;
    symbol_type type;
} symbol;

#define  NHASH 9999
extern struct symbol symtab[NHASH];

struct symbol* lookUp(char* sym);


    typedef struct in_out{
          in_out_type kind;
          char* string_lit;
          char* in_out_type;
          struct in_out *in_out_string;
          struct in_out *in_out_tail;
          struct symbol* sym;
          struct symbol* index;
          int int_index;
      } in_out;


typedef struct expression{

    expression_type kind;
    symbol_type type;
    struct expression *left;
    struct expression *right;
    struct symbol* s;
    struct symbol* i;
    int int_lit;
    float float_lit;
    char* string_lit;


} expression;

struct expression* expression_create(expression_type kind, struct expression* L, struct expression* R, symbol_type type);
struct expression* expression_name(symbol_type type,struct symbol* s);
struct expression* expression_casting(expression_type kind, symbol_type type, struct symbol *s);
struct expression* expression_integer(int i);
struct expression* expression_float(float f);
struct expression* expression_string(char* str);
struct expression* expression_vector_var(symbol_type type, struct symbol *sym, struct symbol *index);
struct expression* expression_vector_int(symbol_type type, struct symbol *sym, struct expression *i);

struct statement* statements_statement_create(statement_type kind, struct statement *body, struct statement *next);
struct statement* exp_statement_create(statement_type kind, struct expression *exp);
struct statement* if_else_statement_create(statement_type kind, struct expression *exp, struct expression *next_exp, struct statement *body, struct statement *else_body);
struct statement* for_statement_create(statement_type kind, struct expression *init_exp, struct expression *exp, struct statement *body);
struct statement* block_statement_create(statement_type kind, struct statement *body);
struct statement* print_statement_create(statement_type kind, struct in_out *in_out_string, struct in_out *in_out_tail);
struct statement* scan_statement_create(statement_type kind, in_out_type type, struct in_out *in_out_tail);

struct in_out* in_out_tail_create(in_out_type kind, struct symbol *sym, struct symbol *index, int i);
struct in_out* in_out_string_create(char* string, in_out_type kind);

void eval_statement(struct statement* statement);
void eval_expression(struct expression* e);
void eval_statement_function(struct statement* statement);
void eval_expression_function(struct expression* e);
void eval_scanStm(in_out_type kind, struct in_out* in_out_tail);
void eval_printStm(struct in_out* in_out_string, struct in_out* in_out_tail);
void eval_string(struct in_out* string);
