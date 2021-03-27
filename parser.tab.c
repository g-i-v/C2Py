/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 7 "parser.y" /* yacc.c:339  */

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


#line 82 "parser.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.tab.h".  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    NAME = 258,
    STRING_TOKEN = 259,
    INTEGER = 260,
    FLOAT = 261,
    GT = 262,
    LT = 263,
    NE = 264,
    EQ = 265,
    GE = 266,
    LE = 267,
    TOKEN_ASS = 268,
    TOKEN_ADD = 269,
    TOKEN_SUB = 270,
    TOKEN_MUL = 271,
    TOKEN_DIV = 272,
    LB = 273,
    RB = 274,
    LSB = 275,
    RSB = 276,
    LCB = 277,
    RCB = 278,
    PRINT = 279,
    SCAN = 280,
    PRINT_INT = 281,
    PRINT_STRING = 282,
    PRINT_FLOAT = 283,
    INT_TOKEN = 284,
    CHAR_TOKEN = 285,
    FLOAT_TOKEN = 286,
    TOKEN_COL = 287,
    TOKEN_COM = 288,
    TOKEN_SEM = 289,
    TOKEN_QUO = 290,
    TOKEN_E = 291,
    IO_VAR = 292,
    EOL = 293,
    FOR = 294,
    IO_FLOAT = 295,
    IO_INT = 296,
    IO_STRING = 297,
    IF = 298,
    ELSE = 299
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 23 "parser.y" /* yacc.c:355  */

    struct statement* stat;
    struct expression* express;
    struct symbol* symb;
    char* string_lit;
    int int_lit;
    float float_lit;
		struct in_out* in_out;

#line 177 "parser.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 194 "parser.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   225

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  171

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   299

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    63,    63,    67,    68,    72,    73,    77,    78,    79,
      80,    81,    85,    86,    87,    88,    89,    90,    91,    95,
      96,    97,   100,   101,   102,   103,   104,   106,   110,   111,
     112,   113,   114,   115,   119,   124,   125,   126,   127,   128,
     130,   131,   132,   133,   134,   135,   136,   140,   143,   147,
     148,   149,   153,   157,   158,   159,   160,   165,   166,   167,
     168,   172,   173,   174,   175,   179,   180
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NAME", "STRING_TOKEN", "INTEGER",
  "FLOAT", "GT", "LT", "NE", "EQ", "GE", "LE", "TOKEN_ASS", "TOKEN_ADD",
  "TOKEN_SUB", "TOKEN_MUL", "TOKEN_DIV", "LB", "RB", "LSB", "RSB", "LCB",
  "RCB", "PRINT", "SCAN", "PRINT_INT", "PRINT_STRING", "PRINT_FLOAT",
  "INT_TOKEN", "CHAR_TOKEN", "FLOAT_TOKEN", "TOKEN_COL", "TOKEN_COM",
  "TOKEN_SEM", "TOKEN_QUO", "TOKEN_E", "IO_VAR", "EOL", "FOR", "IO_FLOAT",
  "IO_INT", "IO_STRING", "IF", "ELSE", "$accept", "root", "function",
  "statements", "statement", "expression", "term", "factor", "condition",
  "forStm", "assign", "init", "forIncrement", "block", "ifStm", "printStm",
  "printStr", "outTail", "scanStm", "castingFunc", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299
};
# endif

#define YYPACT_NINF -126

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-126)))

#define YYTABLE_NINF -26

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -126,    13,    50,  -126,    88,  -126,  -126,    80,     5,    28,
       6,    60,    47,    44,    64,    50,  -126,   173,    26,  -126,
    -126,  -126,  -126,  -126,  -126,  -126,  -126,    66,    16,   154,
       3,    43,   -10,    84,    -9,    89,    80,  -126,    80,    80,
      80,    80,    80,    80,    42,    42,    42,    42,    68,   103,
     108,    85,   115,   109,    73,   107,  -126,  -126,   -25,   -11,
      77,    80,   139,  -126,    -8,   140,  -126,   132,    80,   173,
     129,    52,    52,    52,    52,    52,    52,   130,    26,    26,
    -126,  -126,  -126,  -126,  -126,     9,    11,  -126,  -126,  -126,
    -126,   116,   135,   136,  -126,   164,   138,   141,   142,   143,
     124,   153,   171,  -126,   152,   145,   167,   187,   188,  -126,
    -126,  -126,    87,  -126,   159,   160,   161,  -126,   162,   163,
    -126,   192,    50,   155,  -126,  -126,  -126,    46,   165,   166,
     168,  -126,  -126,   184,   181,    34,   -16,   182,   185,   202,
     204,   205,   195,   167,  -126,   193,  -126,   191,   194,   196,
      93,   197,  -126,  -126,    80,  -126,  -126,   178,   180,   214,
     186,   199,  -126,  -126,   198,  -126,   167,   203,  -126,   189,
    -126
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     2,     1,    17,    23,    24,     0,     0,     0,
       0,     0,     0,     0,     0,     3,     6,     7,    14,    21,
      15,     8,    18,    16,     9,    11,    10,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     5,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    23,
      24,     0,     0,     0,     0,     0,    22,    53,     0,     0,
       0,     0,     0,    41,     0,     0,    46,     0,     0,     0,
      15,    28,    32,    33,    29,    30,    31,    25,    12,    13,
      19,    20,    37,    35,    36,     0,     0,    39,    38,    26,
      27,     0,     0,     0,    57,     0,     0,     0,     0,     0,
       0,     0,     0,    43,     0,     0,     0,     0,     0,    56,
      54,    55,     0,    52,     0,     0,     0,    40,     0,     0,
      45,     0,     0,    49,    65,    66,    58,     0,     0,     0,
       0,    42,    44,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    48,     0,    51,     0,     0,     0,
       0,     0,    47,    34,     0,    59,    60,     0,     0,     0,
       0,    15,    63,    61,     0,    62,     0,     0,    50,     0,
      64
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -126,  -126,  -126,    99,   -14,    -7,    55,    94,   -34,  -126,
     190,  -126,  -126,  -125,  -126,  -126,  -126,  -126,  -126,  -126
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    15,    16,    17,    18,    19,    20,    21,
      22,    23,   134,   123,    24,    25,    59,    96,    26,    53
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      29,    37,    70,    61,    65,   102,   122,    57,    94,    32,
      62,   146,    32,     3,    34,    91,    92,    93,   153,    54,
      52,    55,    95,    30,    63,    66,   103,   145,   107,    69,
     108,    71,    72,    73,    74,    75,    76,     4,    58,     5,
       6,   168,    46,    47,    29,    77,    31,     5,     6,   137,
      34,   138,     7,     4,   100,     5,     6,   144,     8,     9,
       7,   105,    35,    10,    11,    12,    44,    45,     7,     4,
      48,    49,    50,    13,     8,     9,    33,    14,    60,    10,
      11,    12,    36,     4,    51,     5,     6,    64,     4,    13,
       5,     6,    67,    14,    89,    10,    11,    12,     7,    78,
      79,    27,    82,     7,   -25,   -25,   126,   127,    28,    10,
      11,    12,   158,   159,    85,    11,    86,    97,    98,    99,
     161,    37,    38,    39,    40,    41,    42,    43,    90,    44,
      45,    38,    39,    40,    41,    42,    43,    83,    44,    45,
      80,    81,    84,    88,   101,    27,   104,    69,   106,    87,
      28,   109,    38,    39,    40,    41,    42,    43,   117,    44,
      45,    38,    39,    40,    41,    42,    43,   112,    44,    45,
     110,   111,   113,    56,   118,   119,   114,   115,   116,   121,
      38,    39,    40,    41,    42,    43,   120,    44,    45,   122,
     124,   125,   128,   129,   130,   133,   131,   132,   142,   136,
     143,   139,   140,   147,   141,   149,   148,   150,   151,   152,
     155,   154,   162,   156,   163,   157,   160,   164,   166,   167,
     165,   135,   169,   170,     0,    68
};

static const yytype_int16 yycheck[] =
{
       7,    15,    36,    13,    13,    13,    22,     4,    19,     3,
      20,   136,     3,     0,     3,    40,    41,    42,   143,     3,
      27,     5,    33,    18,    34,    34,    34,    43,    19,    36,
      19,    38,    39,    40,    41,    42,    43,     3,    35,     5,
       6,   166,    16,    17,    51,     3,    18,     5,     6,     3,
       3,     5,    18,     3,    61,     5,     6,    23,    24,    25,
      18,    68,    18,    29,    30,    31,    14,    15,    18,     3,
       4,     5,     6,    39,    24,    25,    16,    43,    35,    29,
      30,    31,    18,     3,    18,     5,     6,     3,     3,    39,
       5,     6,     3,    43,    21,    29,    30,    31,    18,    44,
      45,    13,    34,    18,    16,    17,    19,    20,    20,    29,
      30,    31,    19,    20,    29,    30,    31,    40,    41,    42,
     154,   135,     7,     8,     9,    10,    11,    12,    21,    14,
      15,     7,     8,     9,    10,    11,    12,    34,    14,    15,
      46,    47,    34,    34,     5,    13,     6,   154,    19,    34,
      20,    35,     7,     8,     9,    10,    11,    12,    34,    14,
      15,     7,     8,     9,    10,    11,    12,     3,    14,    15,
      35,    35,    34,    19,    21,     4,    35,    35,    35,    34,
       7,     8,     9,    10,    11,    12,    34,    14,    15,    22,
       3,     3,    33,    33,    33,     3,    34,    34,    14,    44,
      19,    36,    36,    21,    36,     3,    21,     3,     3,    14,
      19,    18,    34,    19,    34,    19,    19,     3,    19,    21,
      34,   122,    19,    34,    -1,    35
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    46,    47,     0,     3,     5,     6,    18,    24,    25,
      29,    30,    31,    39,    43,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    59,    60,    63,    13,    20,    50,
      18,    18,     3,    16,     3,    18,    18,    49,     7,     8,
       9,    10,    11,    12,    14,    15,    16,    17,     4,     5,
       6,    18,    50,    64,     3,     5,    19,     4,    35,    61,
      35,    13,    20,    34,     3,    13,    34,     3,    55,    50,
      53,    50,    50,    50,    50,    50,    50,     3,    51,    51,
      52,    52,    34,    34,    34,    29,    31,    34,    34,    21,
      21,    40,    41,    42,    19,    33,    62,    40,    41,    42,
      50,     5,    13,    34,     6,    50,    19,    19,    19,    35,
      35,    35,     3,    34,    35,    35,    35,    34,    21,     4,
      34,    34,    22,    58,     3,     3,    19,    20,    33,    33,
      33,    34,    34,     3,    57,    48,    44,     3,     5,    36,
      36,    36,    14,    19,    23,    43,    58,    21,    21,     3,
       3,     3,    14,    58,    18,    19,    19,    19,    19,    20,
      19,    53,    34,    34,     3,    34,    19,    21,    58,    19,
      34
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    49,    49,    49,
      49,    49,    50,    50,    50,    50,    50,    50,    50,    51,
      51,    51,    52,    52,    52,    52,    52,    52,    53,    53,
      53,    53,    53,    53,    54,    55,    55,    55,    55,    55,
      56,    56,    56,    56,    56,    56,    56,    57,    58,    59,
      59,    59,    60,    61,    61,    61,    61,    62,    62,    62,
      62,    63,    63,    63,    63,    64,    64
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,     1,     1,
       1,     1,     3,     3,     1,     1,     1,     1,     1,     3,
       3,     1,     3,     1,     1,     1,     4,     4,     3,     3,
       3,     3,     3,     3,     8,     4,     4,     4,     4,     4,
       5,     3,     6,     4,     6,     5,     3,     3,     3,     5,
      11,     7,     5,     1,     3,     3,     3,     1,     3,     6,
       6,    10,    10,    10,    13,     4,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 63 "parser.y" /* yacc.c:1646  */
    {printf("\n\nParsing completed!\n"); exit(0);}
#line 1390 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 67 "parser.y" /* yacc.c:1646  */
    {eval_statement((yyvsp[0].stat));}
#line 1396 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 68 "parser.y" /* yacc.c:1646  */
    {int xyz = 0;}
#line 1402 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 72 "parser.y" /* yacc.c:1646  */
    {(yyval.stat) = statements_statement_create(STATEMENT_BLOCK, (yyvsp[-1].stat), (yyvsp[0].stat));}
#line 1408 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 73 "parser.y" /* yacc.c:1646  */
    {(yyval.stat)=(yyvsp[0].stat);}
#line 1414 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 77 "parser.y" /* yacc.c:1646  */
    {(yyval.stat) = exp_statement_create(STATEMENT_EXP, (yyvsp[0].express));}
#line 1420 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 85 "parser.y" /* yacc.c:1646  */
    {if(type_check((yyvsp[-2].express),(yyvsp[0].express))==1){(yyval.express) = expression_create(EXPRESSION_SUM, (yyvsp[-2].express), (yyvsp[0].express), (yyvsp[-2].express)->type);} else exit(0);}
#line 1426 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 86 "parser.y" /* yacc.c:1646  */
    {if(type_check((yyvsp[-2].express),(yyvsp[0].express))==1){(yyval.express) = expression_create(EXPRESSION_SUB, (yyvsp[-2].express), (yyvsp[0].express), (yyvsp[-2].express)->type);} else exit(0);}
#line 1432 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 90 "parser.y" /* yacc.c:1646  */
    {(yyval.express) = expression_name((yyvsp[0].symb)->type,lookUp((yyvsp[0].symb)->name));}
#line 1438 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 95 "parser.y" /* yacc.c:1646  */
    {if(type_check((yyvsp[-2].express),(yyvsp[0].express))==1){(yyval.express) = expression_create(EXPRESSION_MUL, (yyvsp[-2].express), (yyvsp[0].express), (yyvsp[-2].express)->type);} else exit(0);}
#line 1444 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 96 "parser.y" /* yacc.c:1646  */
    {if(type_check((yyvsp[-2].express),(yyvsp[0].express))==1){(yyval.express) = expression_create(EXPRESSION_DIV, (yyvsp[-2].express), (yyvsp[0].express), (yyvsp[-2].express)->type);} else exit(0);}
#line 1450 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 97 "parser.y" /* yacc.c:1646  */
    {(yyval.express) = (yyvsp[0].express);}
#line 1456 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 100 "parser.y" /* yacc.c:1646  */
    {(yyval.express) = expression_create(EXPRESSION_BRACKET, (yyvsp[-1].express), NULL, (yyvsp[-1].express)->type);}
#line 1462 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 101 "parser.y" /* yacc.c:1646  */
    {(yyval.express) = expression_integer((yyvsp[0].int_lit));}
#line 1468 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 102 "parser.y" /* yacc.c:1646  */
    {(yyval.express) = expression_float((yyvsp[0].float_lit));}
#line 1474 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 103 "parser.y" /* yacc.c:1646  */
    {(yyval.express) = expression_name((yyvsp[0].symb)->type,lookUp((yyvsp[0].symb)->name));}
#line 1480 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 104 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[-1].symb)->type == SYMBOL_INT) (yyval.express) = expression_vector_var(SYMBOL_INT, (yyvsp[-3].symb), (yyvsp[-1].symb));
															else printf("Index is not an Integer");}
#line 1487 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 106 "parser.y" /* yacc.c:1646  */
    {(yyval.express) = expression_vector_int(SYMBOL_INT, (yyvsp[-3].symb), expression_integer((yyvsp[-1].int_lit)));}
#line 1493 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 110 "parser.y" /* yacc.c:1646  */
    {if(type_check((yyvsp[-2].express),(yyvsp[0].express))==1) (yyval.express) = expression_create(EXPRESSION_GT, (yyvsp[-2].express), (yyvsp[0].express),(yyvsp[-2].express)->type); else exit(0);}
#line 1499 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 111 "parser.y" /* yacc.c:1646  */
    {if(type_check((yyvsp[-2].express),(yyvsp[0].express))==1) (yyval.express) = expression_create(EXPRESSION_EQ, (yyvsp[-2].express), (yyvsp[0].express),(yyvsp[-2].express)->type); else exit(0);}
#line 1505 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 112 "parser.y" /* yacc.c:1646  */
    {if(type_check((yyvsp[-2].express),(yyvsp[0].express))==1) (yyval.express) = expression_create(EXPRESSION_GE, (yyvsp[-2].express), (yyvsp[0].express),(yyvsp[-2].express)->type); else exit(0);}
#line 1511 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 113 "parser.y" /* yacc.c:1646  */
    {if(type_check((yyvsp[-2].express),(yyvsp[0].express))==1) (yyval.express) = expression_create(EXPRESSION_LE, (yyvsp[-2].express), (yyvsp[0].express),(yyvsp[-2].express)->type); else exit(0);}
#line 1517 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 114 "parser.y" /* yacc.c:1646  */
    {if(type_check((yyvsp[-2].express),(yyvsp[0].express))==1) (yyval.express) = expression_create(EXPRESSION_LT, (yyvsp[-2].express), (yyvsp[0].express),(yyvsp[-2].express)->type); else exit(0);}
#line 1523 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 115 "parser.y" /* yacc.c:1646  */
    {if(type_check((yyvsp[-2].express),(yyvsp[0].express))==1) (yyval.express) = expression_create(EXPRESSION_NE, (yyvsp[-2].express), (yyvsp[0].express),(yyvsp[-2].express)->type); else exit(0);}
#line 1529 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 119 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[-5].express)->type==SYMBOL_INT){ if((yyvsp[-5].express)->left->s->name == (yyvsp[-4].express)->left->s->name && (yyvsp[-4].express)->left->s->name == (yyvsp[-2].symb)->name) (yyval.stat) = for_statement_create(STATEMENT_FOR, (yyvsp[-5].express), (yyvsp[-4].express), (yyvsp[0].stat));
																														else yyerror("For arguments have different variables ");}}
#line 1536 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 124 "parser.y" /* yacc.c:1646  */
    { (yyval.express) = expression_create(EXPRESSION_ASS, expression_name(SYMBOL_INT,lookUp((yyvsp[-3].symb)->name)), expression_integer((yyvsp[-1].int_lit)) , SYMBOL_INT);}
#line 1542 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 125 "parser.y" /* yacc.c:1646  */
    { (yyval.express) = expression_create(EXPRESSION_ASS, expression_name(SYMBOL_FLOAT,lookUp((yyvsp[-3].symb)->name)), expression_float((yyvsp[-1].float_lit)) , SYMBOL_FLOAT);}
#line 1548 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 126 "parser.y" /* yacc.c:1646  */
    { (yyval.express) = expression_create(EXPRESSION_ASS, expression_name(SYMBOL_STRING,lookUp((yyvsp[-3].symb)->name)), expression_string((yyvsp[-1].string_lit)) , SYMBOL_STRING);}
#line 1554 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 127 "parser.y" /* yacc.c:1646  */
    { (yyval.express) = expression_create(EXPRESSION_ASS, expression_name((yyvsp[-1].express)->type,lookUp((yyvsp[-3].symb)->name)), (yyvsp[-1].express) , (yyvsp[-1].express)->type);}
#line 1560 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 128 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[-3].symb)->type==(yyvsp[-1].express)->type) (yyval.express) = expression_create(EXPRESSION_ASS, expression_name((yyvsp[-1].express)->type,lookUp((yyvsp[-3].symb)->name)), (yyvsp[-1].express) , (yyvsp[-1].express)->type);}
#line 1566 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 130 "parser.y" /* yacc.c:1646  */
    {if((yyvsp[-1].express)->type == SYMBOL_INT){ (yyval.express) = expression_create(EXPRESSION_ASS, expression_name((yyvsp[-1].express)->type,lookUp((yyvsp[-3].symb)->name)), (yyvsp[-1].express), (yyvsp[-1].express)->type);}}
#line 1572 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 131 "parser.y" /* yacc.c:1646  */
    {(yyval.express) = expression_create(EXPRESSION_ASS, expression_name(SYMBOL_INT,lookUp((yyvsp[-1].symb)->name)), expression_integer(0), SYMBOL_INT);}
#line 1578 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 132 "parser.y" /* yacc.c:1646  */
    {(yyval.express) = expression_create(EXPRESSION_INTVEC, expression_name(SYMBOL_INT,lookUp((yyvsp[-4].symb)->name)), expression_integer((yyvsp[-2].int_lit)), SYMBOL_INT);}
#line 1584 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 133 "parser.y" /* yacc.c:1646  */
    {(yyval.express) = expression_create(EXPRESSION_ASS, expression_name(SYMBOL_STRING,lookUp((yyvsp[-1].symb)->name)), expression_string("\'\'"), SYMBOL_STRING);}
#line 1590 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 134 "parser.y" /* yacc.c:1646  */
    {(yyval.express) = expression_create(EXPRESSION_ASS, expression_name(SYMBOL_STRING,lookUp((yyvsp[-3].symb)->name)), expression_string((yyvsp[-1].string_lit)), SYMBOL_STRING);}
#line 1596 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 135 "parser.y" /* yacc.c:1646  */
    { (yyval.express) = expression_create(EXPRESSION_ASS, expression_name(SYMBOL_FLOAT,lookUp((yyvsp[-3].symb)->name)), expression_float((yyvsp[-1].float_lit)), SYMBOL_FLOAT);}
#line 1602 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 136 "parser.y" /* yacc.c:1646  */
    { (yyval.express) = expression_create(EXPRESSION_ASS, expression_name(SYMBOL_FLOAT,lookUp((yyvsp[-1].symb)->name)), expression_float(0.0), SYMBOL_FLOAT);}
#line 1608 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 140 "parser.y" /* yacc.c:1646  */
    {(yyval.symb)=(yyvsp[-2].symb);}
#line 1614 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 143 "parser.y" /* yacc.c:1646  */
    {(yyval.stat) = block_statement_create(STATEMENT_BLOCK, (yyvsp[-1].stat));}
#line 1620 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 147 "parser.y" /* yacc.c:1646  */
    {(yyval.stat) = if_else_statement_create(STATEMENT_IF, (yyvsp[-2].express), NULL, (yyvsp[0].stat), NULL);}
#line 1626 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 148 "parser.y" /* yacc.c:1646  */
    {(yyval.stat) = if_else_statement_create(STATEMENT_ELSEIF, (yyvsp[-8].express), (yyvsp[-2].express), (yyvsp[-6].stat), (yyvsp[0].stat));}
#line 1632 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 149 "parser.y" /* yacc.c:1646  */
    {(yyval.stat) = if_else_statement_create(STATEMENT_IF_ELSE, (yyvsp[-4].express), NULL,  (yyvsp[-2].stat), (yyvsp[0].stat));}
#line 1638 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 153 "parser.y" /* yacc.c:1646  */
    {(yyval.stat) = print_statement_create(STATEMENT_PRINT, (yyvsp[-2].in_out), (yyvsp[-1].in_out));}
#line 1644 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 157 "parser.y" /* yacc.c:1646  */
    {(yyval.in_out) = in_out_string_create((yyvsp[0].string_lit), PRINT_STR); }
#line 1650 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 158 "parser.y" /* yacc.c:1646  */
    {(yyval.in_out) = in_out_string_create(NULL, INOUT_INT);}
#line 1656 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 159 "parser.y" /* yacc.c:1646  */
    {(yyval.in_out) = in_out_string_create(NULL, INOUT_STRING); }
#line 1662 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 160 "parser.y" /* yacc.c:1646  */
    {(yyval.in_out) = in_out_string_create(NULL, INOUT_FLOAT);}
#line 1668 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 165 "parser.y" /* yacc.c:1646  */
    {(yyval.in_out) = in_out_tail_create(CLOSING,NULL,NULL,0);}
#line 1674 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 166 "parser.y" /* yacc.c:1646  */
    {(yyval.in_out) = in_out_tail_create(N_IO,lookUp((yyvsp[-1].symb)->name),NULL,0);}
#line 1680 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 167 "parser.y" /* yacc.c:1646  */
    {(yyval.in_out) = in_out_tail_create(INOUT_VEC_VAR,lookUp((yyvsp[-4].symb)->name),lookUp((yyvsp[-2].symb)->name),0);}
#line 1686 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 168 "parser.y" /* yacc.c:1646  */
    {(yyval.in_out) = in_out_tail_create(INOUT_VEC_INT,lookUp((yyvsp[-4].symb)->name),NULL,(yyvsp[-2].int_lit));}
#line 1692 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 172 "parser.y" /* yacc.c:1646  */
    {(yyval.stat) = scan_statement_create(STATEMENT_INPUT, INOUT_INT, in_out_tail_create(LAST_IO,lookUp((yyvsp[-2].symb)->name),NULL,0));}
#line 1698 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 173 "parser.y" /* yacc.c:1646  */
    {(yyval.stat) = scan_statement_create(STATEMENT_INPUT, INOUT_STRING, in_out_tail_create(LAST_IO,lookUp((yyvsp[-2].symb)->name),NULL,0));}
#line 1704 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 174 "parser.y" /* yacc.c:1646  */
    {(yyval.stat) = scan_statement_create(STATEMENT_INPUT, INOUT_FLOAT, in_out_tail_create(LAST_IO,lookUp((yyvsp[-2].symb)->name),NULL,0));}
#line 1710 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 175 "parser.y" /* yacc.c:1646  */
    {(yyval.stat) = scan_statement_create(STATEMENT_INPUT, INOUT_VEC, in_out_tail_create(LAST_IO,lookUp((yyvsp[-5].symb)->name),NULL,0));}
#line 1716 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 179 "parser.y" /* yacc.c:1646  */
    { (yyval.express) = expression_casting(EXPRESSION_CASTING, SYMBOL_INT, (yyvsp[0].symb));}
#line 1722 "parser.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 180 "parser.y" /* yacc.c:1646  */
    { (yyval.express) = expression_casting(EXPRESSION_CASTING, SYMBOL_FLOAT, (yyvsp[0].symb));}
#line 1728 "parser.tab.c" /* yacc.c:1646  */
    break;


#line 1732 "parser.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 182 "parser.y" /* yacc.c:1906  */



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
