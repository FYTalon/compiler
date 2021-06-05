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
#line 1 "src/parser.y" /* yacc.c:339  */

#include "node.h"
#include "ir.h"
#include <cstdio>
#include <cstdlib>
#include "parser.hpp"
#define YYERROR_VERBOSE true
#define YYDEBUG 1
using namespace std;

extern int yydebug;

extern int yylex();
extern int yyget_lineno();
extern int yylex_destroy();
void yyerror(const char *s) { printf("Error:%s\nat line: %d: \n", s, yyget_lineno()); yylex_destroy(); if (!yydebug) exit(1); }


#line 85 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:339  */

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
   by #include "parser.hpp".  */
#ifndef YY_YY_MNT_HGFS_LAB_COMPILER_LIB_PARSER_HPP_INCLUDED
# define YY_YY_MNT_HGFS_LAB_COMPILER_LIB_PARSER_HPP_INCLUDED
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
    IDENTIFIER = 258,
    DINTEGER = 259,
    OINTEGER = 260,
    HINTEGER = 261,
    IF = 262,
    ELSE = 263,
    WHILE = 264,
    BREAK = 265,
    CONTINUE = 266,
    RETURN = 267,
    CONST = 268,
    INT = 269,
    VOID = 270,
    ASSIGN = 271,
    EQ = 272,
    NQ = 273,
    LT = 274,
    LQ = 275,
    GT = 276,
    GQ = 277,
    AND = 278,
    OR = 279,
    NOT = 280,
    PLUS = 281,
    MINUS = 282,
    MUL = 283,
    DIV = 284,
    MOD = 285,
    LPAREN = 286,
    RPAREN = 287,
    LSQUARE = 288,
    RSQUARE = 289,
    LBRACE = 290,
    RBRACE = 291,
    COMMA = 292,
    SEMI = 293
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 20 "src/parser.y" /* yacc.c:355  */

    int token;
    NIdentifier* ident;
    NRoot* root;
    NDeclareStatement* declare_statement;
    NDeclare* declare;
    NExpression* expr;
    NArrayInitVal* array_init_val;
    NArrayIdentifier* array_identifier;
    NFunctionDefine* fundef;
    NFunctionDefineArgList* fundefarglist;
    NFunctionDefineArg* fundefarg;
    NArgList* arglist;
    NBlock* block;
    NStatement* stmt;

    string *str;
    NConditionExpression* cond;

#line 184 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MNT_HGFS_LAB_COMPILER_LIB_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 201 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:358  */

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
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   294

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  53
/* YYNRULES -- Number of rules.  */
#define YYNRULES  111
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  185

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   293

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
      35,    36,    37,    38
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    70,    70,    73,    76,    81,    88,    89,    92,    96,
     101,   105,   111,   114,   115,   118,   123,   128,   129,   132,
     135,   140,   143,   148,   152,   158,   161,   164,   169,   173,
     177,   181,   187,   190,   193,   196,   201,   205,   211,   212,
     215,   218,   223,   229,   233,   239,   240,   243,   244,   247,
     248,   251,   252,   253,   254,   255,   256,   257,   258,   259,
     262,   264,   267,   271,   275,   276,   278,   279,   281,   284,
     287,   291,   297,   298,   301,   304,   307,   312,   315,   316,
     317,   320,   321,   324,   325,   326,   329,   330,   333,   334,
     335,   336,   339,   340,   343,   344,   345,   348,   351,   356,
     357,   360,   361,   364,   365,   368,   369,   372,   373,   376,
     377,   380
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "DINTEGER", "OINTEGER",
  "HINTEGER", "IF", "ELSE", "WHILE", "BREAK", "CONTINUE", "RETURN",
  "CONST", "INT", "VOID", "ASSIGN", "EQ", "NQ", "LT", "LQ", "GT", "GQ",
  "AND", "OR", "NOT", "PLUS", "MINUS", "MUL", "DIV", "MOD", "LPAREN",
  "RPAREN", "LSQUARE", "RSQUARE", "LBRACE", "RBRACE", "COMMA", "SEMI",
  "$accept", "CompUnit", "Decl", "VarDecl", "ConstDecl", "BType",
  "ConstDef", "ConstDefSingle", "ConstDefArray", "Def", "DefSingle",
  "DefArray", "DefArrayName", "InitVal", "InitValArray",
  "InitValArrayInner", "FuncDef", "FuncFParams", "FuncFParam",
  "FuncFParamOne", "FuncFParamArray", "FuncRParams", "Block", "BlockItems",
  "BlockItem", "Stmt", "AssignStmt", "IfStmt", "WhileStmt", "BreakStmt",
  "ContinueStmt", "ReturnStmt", "Exp", "Cond", "ArrayItem", "LVal",
  "PrimaryExp", "Number", "Integer", "UnaryOp", "MulOp", "PlusOp", "RelOp",
  "EqOp", "UnaryExp", "FunctionCall", "MulExp", "AddExp", "RelExp",
  "EqExp", "LAndExp", "LOrExp", "IDENT", YY_NULLPTR
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
     285,   286,   287,   288,   289,   290,   291,   292,   293
};
# endif

#define YYPACT_NINF -140

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-140)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     107,    33,  -140,    70,    65,  -140,   -14,    45,    70,  -140,
      70,  -140,    58,  -140,  -140,  -140,    70,  -140,    70,  -140,
    -140,  -140,  -140,    16,     2,  -140,  -140,  -140,    18,    21,
       6,  -140,    36,  -140,    60,   263,   263,    14,   263,    60,
     263,    75,    70,    29,  -140,  -140,    72,   222,  -140,  -140,
    -140,  -140,  -140,  -140,  -140,   263,    77,    80,    83,  -140,
    -140,  -140,   263,  -140,  -140,  -140,    96,    71,   100,  -140,
      71,    75,    40,    93,  -140,  -140,   136,  -140,    99,    75,
      33,   263,  -140,  -140,  -140,    56,   112,  -140,   263,   263,
    -140,  -140,  -140,  -140,   263,   263,   103,  -140,    75,  -140,
     120,   121,   115,   116,    37,  -140,  -140,  -140,    70,  -140,
     172,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,   117,
      41,   122,  -140,  -140,   123,  -140,   256,  -140,   124,   125,
    -140,    96,  -140,    44,    71,  -140,   263,   263,  -140,  -140,
    -140,   126,  -140,  -140,  -140,   263,  -140,  -140,  -140,  -140,
    -140,  -140,  -140,   263,   128,    71,    66,    85,   142,   144,
     134,  -140,   131,    71,   208,  -140,  -140,  -140,  -140,   263,
    -140,  -140,   263,   263,   263,   208,  -140,   162,    71,    66,
      85,   142,  -140,   208,  -140
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,    12,     0,     0,     4,     0,     0,     0,     5,
       0,   111,     0,     1,     2,     3,     0,     7,     0,     6,
       8,    17,    18,    22,    20,    10,    13,    14,     0,     0,
       0,     9,    20,    11,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    37,    38,    39,     0,    21,    78,
      79,    80,    82,    86,    87,     0,     0,    73,    75,    94,
      76,    77,     0,    81,    99,    96,   101,    68,    72,    19,
      25,     0,     0,     0,    16,    15,     0,    34,    40,     0,
       0,     0,    27,    31,    30,     0,     0,    23,     0,     0,
      95,    83,    84,    85,     0,     0,     0,    32,     0,    24,
       0,     0,     0,     0,     0,    45,    53,    49,     0,    54,
       0,    47,    50,    51,    55,    56,    57,    58,    59,     0,
      75,     0,    35,    36,     0,    26,     0,    74,     0,     0,
     100,   102,    97,     0,    44,    33,     0,     0,    64,    65,
      66,     0,    46,    48,    52,     0,    41,    42,    29,    28,
      71,    70,    98,     0,     0,   103,   105,   107,   109,    69,
       0,    67,     0,    43,     0,    88,    89,    90,    91,     0,
      92,    93,     0,     0,     0,     0,    60,    61,   104,   106,
     108,   110,    63,     0,    62
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -140,  -140,    26,  -140,  -140,     8,   155,  -140,  -140,   164,
    -140,  -140,    49,   -30,   -32,  -140,   183,   151,   109,  -140,
    -140,  -140,   -40,  -140,    81,  -139,  -140,  -140,  -140,  -140,
    -140,  -140,   -33,    53,  -140,   -60,  -140,  -140,  -140,  -140,
    -140,   -64,  -140,  -140,   -49,  -140,    97,   -36,    22,    20,
      27,  -140,    11
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,   107,     6,     7,    42,    25,    26,    27,    20,
      21,    22,    23,    69,    48,    85,     9,    43,    44,    45,
      46,   133,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   154,    57,    58,    59,    60,    61,    62,
      94,    63,   169,   172,    64,    65,    66,    67,   156,   157,
     158,   159,    68
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      70,    77,    56,    95,    70,    73,    95,    74,     8,    10,
      75,    70,     8,    90,    12,    84,   120,    83,    36,    24,
       2,    29,    86,    16,    17,   177,     5,    32,     2,    29,
      14,    97,    34,    37,    39,    38,   182,    40,    41,   122,
      11,    49,    50,    51,   184,   130,    71,     2,   124,    35,
     120,    35,    36,    78,    38,   128,   129,   145,   135,    28,
     134,    79,    52,    53,    54,    13,    80,    28,    55,    38,
      95,   141,    98,    11,    89,   140,   152,    80,     1,     2,
       3,   153,    18,    19,   108,   165,   166,   167,   168,    30,
      70,    95,   125,   126,   149,    47,   148,    53,    54,    95,
     155,   155,   170,   171,   120,    81,    11,    49,    50,    51,
      76,    87,   162,    88,    95,   120,    89,   163,   108,    32,
       1,     2,     3,   120,    91,    92,    93,    99,    52,    53,
      54,    96,   121,   178,    55,   132,   155,   155,   155,    11,
      49,    50,    51,   100,   127,   101,   102,   103,   104,     1,
       2,   136,   137,   138,   139,   144,   146,   147,   150,   151,
     164,    52,    53,    54,   161,   173,   175,    55,   174,   176,
     183,    76,   105,    33,   106,    11,    49,    50,    51,   100,
      31,   101,   102,   103,   104,     1,     2,    15,    72,   123,
     160,   143,   131,   180,   179,     0,     0,    52,    53,    54,
       0,   181,     0,    55,     0,     0,     0,    76,   142,     0,
     106,    11,    49,    50,    51,   100,     0,   101,   102,   103,
     104,     0,     0,     0,     0,    11,    49,    50,    51,     0,
       0,     0,     0,    52,    53,    54,     0,     0,     0,    55,
       0,     0,     0,    76,     0,     0,   106,    52,    53,    54,
       0,     0,     0,    55,     0,     0,     0,    47,    82,    11,
      49,    50,    51,     0,     0,     0,    11,    49,    50,    51,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    52,    53,    54,     0,     0,     0,    55,    52,    53,
      54,    47,     0,     0,    55
};

static const yytype_int16 yycheck[] =
{
      36,    41,    35,    67,    40,    38,    70,    39,     0,     1,
      40,    47,     4,    62,     3,    47,    76,    47,    16,     8,
      14,    10,    55,    37,    38,   164,     0,    16,    14,    18,
       4,    71,    16,    31,    16,    33,   175,    16,    32,    79,
       3,     4,     5,     6,   183,    94,    32,    14,    81,    33,
     110,    33,    16,    42,    33,    88,    89,    16,    98,    10,
      96,    32,    25,    26,    27,     0,    37,    18,    31,    33,
     134,   104,    32,     3,    33,    38,    32,    37,    13,    14,
      15,    37,    37,    38,    76,    19,    20,    21,    22,    31,
     126,   155,    36,    37,   126,    35,   126,    26,    27,   163,
     136,   137,    17,    18,   164,    33,     3,     4,     5,     6,
      35,    34,   145,    33,   178,   175,    33,   153,   110,   108,
      13,    14,    15,   183,    28,    29,    30,    34,    25,    26,
      27,    31,    33,   169,    31,    32,   172,   173,   174,     3,
       4,     5,     6,     7,    32,     9,    10,    11,    12,    13,
      14,    31,    31,    38,    38,    38,    34,    34,    34,    34,
      32,    25,    26,    27,    38,    23,    32,    31,    24,    38,
       8,    35,    36,    18,    38,     3,     4,     5,     6,     7,
      16,     9,    10,    11,    12,    13,    14,     4,    37,    80,
     137,   110,    95,   173,   172,    -1,    -1,    25,    26,    27,
      -1,   174,    -1,    31,    -1,    -1,    -1,    35,    36,    -1,
      38,     3,     4,     5,     6,     7,    -1,     9,    10,    11,
      12,    -1,    -1,    -1,    -1,     3,     4,     5,     6,    -1,
      -1,    -1,    -1,    25,    26,    27,    -1,    -1,    -1,    31,
      -1,    -1,    -1,    35,    -1,    -1,    38,    25,    26,    27,
      -1,    -1,    -1,    31,    -1,    -1,    -1,    35,    36,     3,
       4,     5,     6,    -1,    -1,    -1,     3,     4,     5,     6,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    26,    27,    -1,    -1,    -1,    31,    25,    26,
      27,    35,    -1,    -1,    31
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    13,    14,    15,    40,    41,    42,    43,    44,    55,
      44,     3,    91,     0,    41,    55,    37,    38,    37,    38,
      48,    49,    50,    51,    91,    45,    46,    47,    51,    91,
      31,    48,    91,    45,    16,    33,    16,    31,    33,    16,
      16,    32,    44,    56,    57,    58,    59,    35,    53,     4,
       5,     6,    25,    26,    27,    31,    71,    73,    74,    75,
      76,    77,    78,    80,    83,    84,    85,    86,    91,    52,
      86,    32,    56,    71,    53,    52,    35,    61,    91,    32,
      37,    33,    36,    52,    53,    54,    71,    34,    33,    33,
      83,    28,    29,    30,    79,    80,    31,    61,    32,    34,
       7,     9,    10,    11,    12,    36,    38,    41,    44,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      74,    33,    61,    57,    71,    36,    37,    32,    71,    71,
      83,    85,    32,    60,    86,    61,    31,    31,    38,    38,
      38,    71,    36,    63,    38,    16,    34,    34,    52,    53,
      34,    34,    32,    37,    72,    86,    87,    88,    89,    90,
      72,    38,    71,    86,    32,    19,    20,    21,    22,    81,
      17,    18,    82,    23,    24,    32,    38,    64,    86,    87,
      88,    89,    64,     8,    64
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    40,    40,    40,    41,    41,    42,    42,
      43,    43,    44,    45,    45,    46,    47,    48,    48,    49,
      49,    50,    50,    51,    51,    52,    53,    53,    54,    54,
      54,    54,    55,    55,    55,    55,    56,    56,    57,    57,
      58,    59,    59,    60,    60,    61,    61,    62,    62,    63,
      63,    64,    64,    64,    64,    64,    64,    64,    64,    64,
      65,    66,    66,    67,    68,    69,    70,    70,    71,    72,
      73,    73,    74,    74,    75,    75,    75,    76,    77,    77,
      77,    78,    78,    79,    79,    79,    80,    80,    81,    81,
      81,    81,    82,    82,    83,    83,    83,    84,    84,    85,
      85,    86,    86,    87,    87,    88,    88,    89,    89,    90,
      90,    91
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     1,     1,     2,     2,     2,     3,
       3,     3,     1,     1,     1,     3,     3,     1,     1,     3,
       1,     3,     1,     4,     4,     1,     3,     2,     3,     3,
       1,     1,     5,     6,     5,     6,     3,     1,     1,     1,
       2,     4,     4,     3,     1,     2,     3,     1,     2,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       4,     5,     7,     5,     2,     2,     2,     3,     1,     1,
       4,     4,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     3,     4,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     1
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
#line 70 "src/parser.y" /* yacc.c:1646  */
    { 
            (yyval.root)->context.push_back((yyvsp[0].declare_statement)); 
        }
#line 1443 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 73 "src/parser.y" /* yacc.c:1646  */
    { 
            (yyval.root)->context.push_back((yyvsp[0].fundef)); 
        }
#line 1451 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 76 "src/parser.y" /* yacc.c:1646  */
    { 
            root = new NRoot(); 
            (yyval.root) = root; 
            (yyval.root)->context.push_back((yyvsp[0].declare_statement)); 
        }
#line 1461 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 81 "src/parser.y" /* yacc.c:1646  */
    { 
            root = new NRoot(); 
            (yyval.root) = root; 
            (yyval.root)->context.push_back((yyvsp[0].fundef)); 
        }
#line 1471 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 88 "src/parser.y" /* yacc.c:1646  */
    { (yyval.declare_statement) = (yyvsp[-1].declare_statement); }
#line 1477 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 89 "src/parser.y" /* yacc.c:1646  */
    { (yyval.declare_statement) = (yyvsp[-1].declare_statement); }
#line 1483 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 92 "src/parser.y" /* yacc.c:1646  */
    {
            (yyval.declare_statement) = new NDeclareStatement((yyvsp[-1].token));
            (yyval.declare_statement)->child.push_back((yyvsp[0].declare));
        }
#line 1492 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 96 "src/parser.y" /* yacc.c:1646  */
    {
            (yyval.declare_statement) = (yyvsp[-2].declare_statement);
            (yyval.declare_statement)->child.push_back((yyvsp[0].declare));
        }
#line 1501 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 101 "src/parser.y" /* yacc.c:1646  */
    { 
            (yyval.declare_statement) = new NDeclareStatement((yyvsp[-1].token));
            (yyval.declare_statement)->child.push_back((yyvsp[0].declare));
        }
#line 1510 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 105 "src/parser.y" /* yacc.c:1646  */
    {
            (yyval.declare_statement) = (yyvsp[-2].declare_statement);
            (yyval.declare_statement)->child.push_back((yyvsp[0].declare));
        }
#line 1519 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 111 "src/parser.y" /* yacc.c:1646  */
    { (yyval.token) = (yyvsp[0].token); }
#line 1525 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 114 "src/parser.y" /* yacc.c:1646  */
    { (yyval.declare) = (yyvsp[0].declare); }
#line 1531 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 115 "src/parser.y" /* yacc.c:1646  */
    { (yyval.declare) = (yyvsp[0].declare); }
#line 1537 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 118 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.declare) = new NVarDeclare((yyvsp[-2].ident), (yyvsp[0].expr), true);
            }
#line 1545 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 123 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.declare) = new NArrayDeclare((yyvsp[-2].array_identifier), (yyvsp[0].array_init_val), true);
            }
#line 1553 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 128 "src/parser.y" /* yacc.c:1646  */
    { (yyval.declare) = (yyvsp[0].declare); }
#line 1559 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 129 "src/parser.y" /* yacc.c:1646  */
    { (yyval.declare) = (yyvsp[0].declare); }
#line 1565 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 132 "src/parser.y" /* yacc.c:1646  */
    {
            (yyval.declare) = new NVarDeclare((yyvsp[-2].ident), (yyvsp[0].expr));
        }
#line 1573 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 135 "src/parser.y" /* yacc.c:1646  */
    {
            (yyval.declare) = new NVarDeclare((yyvsp[0].ident));
        }
#line 1581 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 140 "src/parser.y" /* yacc.c:1646  */
    {
            (yyval.declare) = new NArrayDeclare((yyvsp[-2].array_identifier), (yyvsp[0].array_init_val));
        }
#line 1589 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 143 "src/parser.y" /* yacc.c:1646  */
    {
            (yyval.declare) = new NArrayDeclare((yyvsp[0].array_identifier));
        }
#line 1597 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 148 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.array_identifier) = (yyvsp[-3].array_identifier);
                (yyval.array_identifier)->shape.push_back((yyvsp[-1].expr));
            }
#line 1606 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 152 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.array_identifier) = new NArrayIdentifier((yyvsp[-3].ident));
                (yyval.array_identifier)->shape.push_back((yyvsp[-1].expr));
            }
#line 1615 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 158 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1621 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 161 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.array_init_val) = (yyvsp[-1].array_init_val);
            }
#line 1629 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 164 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.array_init_val) = new NArrayInitVal(true);
            }
#line 1637 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 169 "src/parser.y" /* yacc.c:1646  */
    {
                    (yyval.array_init_val) = (yyvsp[-2].array_init_val);
                    (yyval.array_init_val)->value.push_back((yyvsp[0].array_init_val));
                }
#line 1646 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 173 "src/parser.y" /* yacc.c:1646  */
    {
                    (yyval.array_init_val) = (yyvsp[-2].array_init_val);
                    (yyval.array_init_val)->value.push_back(new NArrayInitVal(true, (yyvsp[0].expr)));
                }
#line 1655 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 177 "src/parser.y" /* yacc.c:1646  */
    {
                    (yyval.array_init_val) = new NArrayInitVal();
                    (yyval.array_init_val)->value.push_back((yyvsp[0].array_init_val));
                }
#line 1664 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 181 "src/parser.y" /* yacc.c:1646  */
    {
                    (yyval.array_init_val) = new NArrayInitVal();
                    (yyval.array_init_val)->value.push_back(new NArrayInitVal(true, (yyvsp[0].expr)));
                }
#line 1673 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 187 "src/parser.y" /* yacc.c:1646  */
    {
            (yyval.fundef) = new NFunctionDefine((yyvsp[-4].token), (yyvsp[-3].ident), new NFunctionDefineArgList(), (yyvsp[0].block));
        }
#line 1681 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 190 "src/parser.y" /* yacc.c:1646  */
    {
            (yyval.fundef) = new NFunctionDefine((yyvsp[-5].token), (yyvsp[-4].ident), (yyvsp[-2].fundefarglist), (yyvsp[0].block));
        }
#line 1689 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 193 "src/parser.y" /* yacc.c:1646  */
    {
            (yyval.fundef) = new NFunctionDefine((yyvsp[-4].token), (yyvsp[-3].ident), new NFunctionDefineArgList(), (yyvsp[0].block));
        }
#line 1697 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 196 "src/parser.y" /* yacc.c:1646  */
    {
            (yyval.fundef) = new NFunctionDefine((yyvsp[-5].token), (yyvsp[-4].ident), (yyvsp[-2].fundefarglist), (yyvsp[0].block));
        }
#line 1705 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 201 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.fundefarglist) = (yyvsp[-2].fundefarglist);
                (yyval.fundefarglist)->list.push_back((yyvsp[0].fundefarg));
            }
#line 1714 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 205 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.fundefarglist) = new NFunctionDefineArgList();
                (yyval.fundefarglist)->list.push_back((yyvsp[0].fundefarg));
            }
#line 1723 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 211 "src/parser.y" /* yacc.c:1646  */
    { (yyval.fundefarg) = (yyvsp[0].fundefarg); }
#line 1729 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 212 "src/parser.y" /* yacc.c:1646  */
    { (yyval.fundefarg) = (yyvsp[0].fundefarg); }
#line 1735 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 215 "src/parser.y" /* yacc.c:1646  */
    { (yyval.fundefarg) = new NFunctionDefineArgVar((yyvsp[-1].token), (yyvsp[0].ident)); }
#line 1741 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 218 "src/parser.y" /* yacc.c:1646  */
    {
                    (yyval.fundefarg) = new NFunctionDefineArgArray((yyvsp[-3].token), 
                        new NArrayIdentifier((yyvsp[-2].ident)));
                    ((NFunctionDefineArgArray*)(yyval.fundefarg))->name->shape.push_back(new NNumber());
                }
#line 1751 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 223 "src/parser.y" /* yacc.c:1646  */
    {
                    (yyval.fundefarg) = (yyvsp[-3].fundefarg);
                    ((NFunctionDefineArgArray*)(yyval.fundefarg))->name->shape.push_back((yyvsp[-1].expr));
                }
#line 1760 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 229 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.arglist) = (yyvsp[-2].arglist);
                (yyvsp[-2].arglist)->list.push_back((yyvsp[0].expr));
            }
#line 1769 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 233 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.arglist) = new NArgList();
                (yyval.arglist)->list.push_back((yyvsp[0].expr));
            }
#line 1778 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 239 "src/parser.y" /* yacc.c:1646  */
    { (yyval.block) = new NBlock(); }
#line 1784 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 240 "src/parser.y" /* yacc.c:1646  */
    { (yyval.block) = (yyvsp[-1].block); }
#line 1790 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 243 "src/parser.y" /* yacc.c:1646  */
    { (yyval.block) = new NBlock(); (yyval.block)->stmts.push_back((yyvsp[0].stmt)); }
#line 1796 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 244 "src/parser.y" /* yacc.c:1646  */
    { (yyval.block) = (yyvsp[-1].block); (yyval.block)->stmts.push_back((yyvsp[0].stmt)); }
#line 1802 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 247 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].declare_statement); }
#line 1808 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 248 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1814 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 251 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1820 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 252 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new NEval((yyvsp[-1].expr)); }
#line 1826 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 253 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new NVoid(); }
#line 1832 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 254 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].block); }
#line 1838 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 255 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1844 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 256 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1850 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 257 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1856 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 258 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1862 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 259 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1868 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 262 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new NAssignment((yyvsp[-3].ident), (yyvsp[-1].expr)); }
#line 1874 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 264 "src/parser.y" /* yacc.c:1646  */
    {
            (yyval.stmt) = new NIfElse((yyvsp[-2].cond), (yyvsp[0].stmt), new NVoid());
        }
#line 1882 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 267 "src/parser.y" /* yacc.c:1646  */
    {
            (yyval.stmt) = new NIfElse((yyvsp[-4].cond), (yyvsp[-2].stmt), (yyvsp[0].stmt));
        }
#line 1890 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 271 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.stmt) = new NWhile((yyvsp[-2].cond), (yyvsp[0].stmt));
            }
#line 1898 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 275 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new NBreak(); }
#line 1904 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 276 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new NContinue(); }
#line 1910 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 278 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new NReturn(); }
#line 1916 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 279 "src/parser.y" /* yacc.c:1646  */
    { (yyval.stmt) = new NReturn((yyvsp[-1].expr)); }
#line 1922 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 281 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 1928 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 284 "src/parser.y" /* yacc.c:1646  */
    { (yyval.cond) = new NConditionExpression((yyvsp[0].expr)); }
#line 1934 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 287 "src/parser.y" /* yacc.c:1646  */
    { 
            (yyval.array_identifier) = new NArrayIdentifier((yyvsp[-3].ident)); 
            (yyval.array_identifier)->shape.push_back((yyvsp[-1].expr));
        }
#line 1943 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 291 "src/parser.y" /* yacc.c:1646  */
    {
            (yyval.array_identifier) = (yyvsp[-3].array_identifier);
            (yyval.array_identifier)->shape.push_back((yyvsp[-1].expr));
        }
#line 1952 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 297 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ident) = (yyvsp[0].ident); }
#line 1958 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 298 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ident) = (yyvsp[0].array_identifier); }
#line 1964 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 301 "src/parser.y" /* yacc.c:1646  */
    {
            (yyval.expr) = (yyvsp[-1].expr);
        }
#line 1972 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 304 "src/parser.y" /* yacc.c:1646  */
    {
            (yyval.expr) = (yyvsp[0].ident);
        }
#line 1980 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 307 "src/parser.y" /* yacc.c:1646  */
    {
            (yyval.expr) = (yyvsp[0].expr);
        }
#line 1988 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 312 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new NNumber(*(yyvsp[0].str)); }
#line 1994 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 343 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 2000 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 344 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new NUnaryExpression((yyvsp[-1].token), (yyvsp[0].expr)); }
#line 2006 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 345 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 2012 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 348 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.expr) = new NFunctionCall((yyvsp[-2].ident), new NArgList());
            }
#line 2020 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 351 "src/parser.y" /* yacc.c:1646  */
    {
                (yyval.expr) = new NFunctionCall((yyvsp[-3].ident), (yyvsp[-1].arglist));
            }
#line 2028 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 356 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 2034 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 357 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new NBinaryExpression((yyvsp[-2].expr), (yyvsp[-1].token), (yyvsp[0].expr)); }
#line 2040 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 360 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 2046 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 361 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new NBinaryExpression((yyvsp[-2].expr), (yyvsp[-1].token), (yyvsp[0].expr)); }
#line 2052 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 364 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 2058 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 365 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new NBinaryExpression((yyvsp[-2].expr), (yyvsp[-1].token), (yyvsp[0].expr)); }
#line 2064 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 368 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 2070 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 369 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new NBinaryExpression((yyvsp[-2].expr), (yyvsp[-1].token), (yyvsp[0].expr)); }
#line 2076 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 372 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 2082 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 373 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new NBinaryExpression((yyvsp[-2].expr), (yyvsp[-1].token), (yyvsp[0].expr)); }
#line 2088 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 376 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = (yyvsp[0].expr); }
#line 2094 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 377 "src/parser.y" /* yacc.c:1646  */
    { (yyval.expr) = new NBinaryExpression((yyvsp[-2].expr), (yyvsp[-1].token), (yyvsp[0].expr)); }
#line 2100 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 380 "src/parser.y" /* yacc.c:1646  */
    { (yyval.ident) = new NIdentifier((yyvsp[0].str)); }
#line 2106 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
    break;


#line 2110 "/mnt/hgfs/lab/compiler/lib/parser.cpp" /* yacc.c:1646  */
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
#line 381 "src/parser.y" /* yacc.c:1906  */


