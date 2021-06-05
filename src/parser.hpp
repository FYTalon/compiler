/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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

#ifndef YY_YY_MNT_HGFS_LAB_COMPILER_SRC_PARSER_HPP_INCLUDED
# define YY_YY_MNT_HGFS_LAB_COMPILER_SRC_PARSER_HPP_INCLUDED
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
#line 20 "src/parser.y" /* yacc.c:1909  */

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

#line 113 "/mnt/hgfs/lab/compiler/src/parser.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MNT_HGFS_LAB_COMPILER_SRC_PARSER_HPP_INCLUDED  */
