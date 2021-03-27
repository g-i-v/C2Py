# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include "AST.h"
# include "parser.tab.h"

FILE *fp;
struct symbol symtab[NHASH];

void eval_statement(struct statement* statement){

  if(!statement){
    return;
  }

  switch(statement->kind){

    case STATEMENT_EXP:
      if(!(statement->exp->left) || !(statement->exp->right)){
        yyerror("Invalid statement");
        return;
      }
      eval_expression(statement->exp);
      fprintf(fp,"\n");
      break;

    case STATEMENT_IF:
      fprintf(fp, "if ");
      eval_expression(statement->exp);
      fprintf(fp,":\n");
      eval_statement(statement->body);
      break;

    case STATEMENT_ELSEIF:
      fprintf(fp, "if ");
      eval_expression(statement->exp);
      fprintf(fp,":\n\t");
      eval_statement(statement->body);
      fprintf(fp,"elif ");
      eval_expression(statement->next_exp);
      fprintf(fp,":\n\t");
      eval_statement(statement->else_body);
      break;

    case STATEMENT_IF_ELSE:
    fprintf(fp, "if ");
    eval_expression(statement->exp);
    fprintf(fp,":\n\t");
    eval_statement(statement->body);
    fprintf(fp,"else:\n\t");
    eval_statement(statement->else_body);
    break;

    case STATEMENT_FOR:

      fprintf(fp,"for ");
      if(statement->init_exp->left->s->name)
        fprintf(fp,"%s in range(",statement->init_exp->left->s->name);
        fprintf(fp,"%d,",statement->init_exp->right->int_lit);
      if(statement->exp->right->int_lit)
       fprintf(fp,"%d):\n\t",statement->exp->right->int_lit);
      if(statement->body)
        { if(statement->body->body->kind!=STATEMENT_FOR)
          fprintf(fp,"\t");
        eval_statement(statement->body);}
        fprintf(fp,"\n");
      break;

    case STATEMENT_PRINT:

     if(statement->in_out_string->kind == PRINT_STR){
        fprintf(fp,"print(");
       fprintf(fp,"%s",statement->in_out_string->string_lit);
       fprintf(fp,")\n");
     }

     else  if(statement->in_out_string->kind == INOUT_STRING && statement->in_out_tail->sym->type == SYMBOL_STRING){
      fprintf(fp,"print(");
      fprintf(fp,"%s",statement->in_out_tail->sym->name);
      fprintf(fp,")\n");}

      else  if(statement->in_out_string->kind == INOUT_STRING && statement->in_out_tail->sym->type != SYMBOL_STRING)
        yyerror("Variable is not a string");

        else if(statement->in_out_string->kind == INOUT_INT && statement->in_out_tail->kind==INOUT_VEC_INT){
          fprintf(fp,"print(%s[%d])",statement->in_out_tail->sym->name,statement->in_out_tail->int_index);
        }
        else if(statement->in_out_string->kind == INOUT_INT && statement->in_out_tail->kind==INOUT_VEC_VAR){
              fprintf(fp,"print(%s[%s])",statement->in_out_tail->sym->name,statement->in_out_tail->index->name);
        }

      else  if(statement->in_out_string->kind == INOUT_INT && statement->in_out_tail->sym->type == SYMBOL_INT){

       fprintf(fp,"print(");
       fprintf(fp,"%s",statement->in_out_tail->sym->name);
       fprintf(fp,")\n");}

      else  if(statement->in_out_string->kind == INOUT_INT && statement->in_out_tail->sym->type != SYMBOL_INT)
        yyerror("Variable is not an integer");

       else  if(statement->in_out_string->kind == INOUT_FLOAT && statement->in_out_tail->sym->type == SYMBOL_FLOAT){
        fprintf(fp,"print(");
        fprintf(fp,"%s",statement->in_out_tail->sym->name);
        fprintf(fp,")\n");}

      else  if(statement->in_out_string->kind == INOUT_FLOAT && statement->in_out_tail->sym->type != SYMBOL_FLOAT){
        yyerror("Variable is not a float");}

     else if(statement->in_out_tail->kind==CLOSING){
       fprintf(fp,")");}
     break;

    case STATEMENT_INPUT:
      eval_scanStm(statement->iOkind ,statement->in_out_tail);
      break;

    case STATEMENT_BLOCK:
    if(statement->body)
      eval_statement(statement->body);
    if((statement->next))
      eval_statement(statement->next);
    break;

  }

}

void eval_scanStm(in_out_type type, struct in_out* in_out_tail){

  if(type == INOUT_STRING){
    fprintf(fp,"%s = raw_input()",in_out_tail->sym->name);
  }

  if(type == INOUT_INT || type == INOUT_FLOAT){
    fprintf(fp,"%s = input()",in_out_tail->sym->name);
  }

  if(type == INOUT_VEC){
    fprintf(fp,"%s.append(int(input()))",in_out_tail->sym->name);
  }
}

void eval_printStm(struct in_out* in_out_string, struct in_out* in_out_tail){

  if(in_out_tail->kind==N_IO){
    fprintf(fp,"%s",in_out_tail->sym->name);
  }

}

void eval_string(struct in_out* print_string){

  if(!print_string){
    return;
  }

    fprintf(fp,"%s",print_string->string_lit);

}

void eval_expression(struct expression* e){

  if(!e){
    return;
  }

  if(e->kind == EXPRESSION_BRACKET){
    fprintf(fp,"(");
    eval_expression(e->left);
    fprintf(fp,")");
    return;
  }

  eval_expression(e->left);

  switch(e->kind){
    case EXPRESSION_SUM:
      fprintf(fp,"+");
      break;
    case EXPRESSION_SUB:
      fprintf(fp,"-");
      break;
    case EXPRESSION_MUL:
      fprintf(fp,"*");
      break;
    case EXPRESSION_DIV:
      fprintf(fp,"/");
      break;
    case EXPRESSION_GT:
      fprintf(fp,">");
      break;
    case EXPRESSION_LT:
      fprintf(fp,"<");
      break;
    case EXPRESSION_GE:
      fprintf(fp,">=");
      break;
    case EXPRESSION_LE:
      fprintf(fp,"<=");
      break;
    case EXPRESSION_EQ:
      fprintf(fp,"==");
      break;
    case EXPRESSION_NE:
      fprintf(fp,"!=");
      break;
    case EXPRESSION_ASS:
      fprintf(fp,"=");
      break;
    case EXPRESSION_INTVEC:
      fprintf(fp," = []");
      break;
    case EXPRESSION_VEC_VAR:
      fprintf(fp,"%s[%s]",e->s->name,e->i->name);
      break;
    case EXPRESSION_VEC_INT:
      fprintf(fp,"%s[%d]",e->s->name,e->int_lit);
      break;
    case EXPRESSION_NAME:
      fprintf(fp,"%s",e->s->name);
      break;
    case EXPRESSION_INT:
      fprintf(fp,"%d",e->int_lit);
      break;
    case EXPRESSION_FLOAT:
      fprintf(fp,"%f",e->float_lit);
      break;
    case EXPRESSION_STR:
      fprintf(fp,"%s",e->string_lit);
      break;
    case EXPRESSION_BRACKET:
      break;
    case EXPRESSION_CASTING:
      if(e->type==SYMBOL_INT){
        fprintf(fp,"int(");}
      else if(e->type==SYMBOL_FLOAT){
      fprintf(fp,"float(");}
      fprintf(fp,"%s)",e->s->name);
      break;

  }

 if(e->kind!=EXPRESSION_INTVEC)
  eval_expression(e->right);
}
