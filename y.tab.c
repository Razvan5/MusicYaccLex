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
#line 1 "limbaj.y" /* yacc.c:339  */

#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h>
extern FILE* yyin;
extern char* yytext;
extern int yylineno;
void yyerror (char const *s) {
   fprintf (stderr, "%s la linia %d\n", s,yylineno);
 }
int yylex();
using namespace std;
//string nume_scope,tuple<string ID,multimap<int tip/poz,string ID,valoare/tip>,int returntype la fct/metoda/numberofvalues la vector,int ,string stare,randul>

//GLOBALE
unordered_multimap<string,tuple<string,multimap<string,string>,string,string,int>>symbol_table; 
unordered_multimap<string,tuple<string,multimap<string,string>,string,string,int>>::iterator iterator_symbol_table;
multimap<string, string> lista_var; //multimapul din tuplu
tuple<string, multimap<string, string>, string, string, int> continut; //tuplus din symbol_table
map<string,string> nume_valoare_parametru;
map<string,string> nume_valoare_parametru2;


string valGlobala1,valGlobala2;
string signaturaApel;

int nr_IF=0,nr_WHILE=0;

set<tuple<string,string,string,string>> lista_main_init;
set<tuple<string,string,string,string>> lista_fct_init;
set<tuple<string,string,string,string>> lista_global_init;
set<tuple<string,string,string,string>> lista_while_init;
set<tuple<string,string,string,string>> lista_if_init;
set<tuple<string,string,string,string>> lista_for_init;
set<tuple<string,string,string,string>> lista_clasa_init;
set<tuple<string,string,string,string>> lista_metoda_init;

/* bool typeCheck(string leftSide,string rightSide){
        
        string typeLeft,typeRight;
        if(leftSide[0]!='\"' && leftSide[0]!='\'' && leftSide[0]!='-' && leftSide[0]!='1' && leftSide[0]!='2' && leftSide[0]!='3' && leftSide[0]!='4' && leftSide[0]!='5' && leftSide[0]!='6' && leftSide[0]!='7' && leftSide[0]!='8' && leftSide[0]!='9' && leftSide[0]!='0'  ){
                for(auto it : symbol_table){
                        if(get<0>(it->second)==typeLeft)
                                typeLeft=get<3>(it->second);
                }
        }
        if(rightSide[0]!='\"' && rightSide[0]!='\'' && rightSide[0]!='-' && rightSide[0]!='1' && rightSide[0]!='2' && rightSide[0]!='3' && rightSide[0]!='4' && rightSide[0]!='5' && rightSide[0]!='6' && rightSide[0]!='7' && rightSide[0]!='8' && rightSide[0]!='9' && rightSide[0]!='0'  ){
                for(auto it : symbol_table){
                        if(get<0>(it->second)==typeLeft)
                                typeRight=get<3>(it->second);
                }
        }
        if(rightSide[0]=='\"'){
                typeLeft="string";
        }
        if(rightSide[0]=='\''){
                typeRight="char";
        }
} */
bool verifDuplicate(string cuv_de_cautat,set<tuple<string,string,string,string>> lista,int line){

        for(auto l:lista){
                if(cuv_de_cautat==get<1>(l)){
                        return true;
                }
        }
        return false;

}

//Hurdy-Gurdy

#line 139 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    OBIECT = 258,
    FUNCTIE = 259,
    BOX = 260,
    DEFAULT = 261,
    CASE = 262,
    ELSE = 263,
    INCLUDE = 264,
    LOWT = 265,
    BIGT = 266,
    LEQ = 267,
    BEQ = 268,
    EQUAL = 269,
    NOTEQUAL = 270,
    INCREMENT = 271,
    DECREMENT = 272,
    IN = 273,
    MAIN = 274,
    PROG_BEGIN = 275,
    PROG_END = 276,
    INT = 277,
    INT_NR = 278,
    FLOAT = 279,
    FLOAT_NR = 280,
    CHAR = 281,
    CHAR_VAL = 282,
    STRING = 283,
    STRING_VAL = 284,
    BOOL = 285,
    BOOL_VAL = 286,
    CLASS = 287,
    METODE = 288,
    STRUCT = 289,
    ASSIGN = 290,
    DEFINE = 291,
    IF = 292,
    SWITCH = 293,
    WHILE = 294,
    FOR = 295,
    OR = 296,
    AND = 297,
    NOT = 298,
    SOL = 299,
    ENDSOL = 300,
    ID = 301,
    EVAL = 302,
    RETURN = 303
  };
#endif
/* Tokens.  */
#define OBIECT 258
#define FUNCTIE 259
#define BOX 260
#define DEFAULT 261
#define CASE 262
#define ELSE 263
#define INCLUDE 264
#define LOWT 265
#define BIGT 266
#define LEQ 267
#define BEQ 268
#define EQUAL 269
#define NOTEQUAL 270
#define INCREMENT 271
#define DECREMENT 272
#define IN 273
#define MAIN 274
#define PROG_BEGIN 275
#define PROG_END 276
#define INT 277
#define INT_NR 278
#define FLOAT 279
#define FLOAT_NR 280
#define CHAR 281
#define CHAR_VAL 282
#define STRING 283
#define STRING_VAL 284
#define BOOL 285
#define BOOL_VAL 286
#define CLASS 287
#define METODE 288
#define STRUCT 289
#define ASSIGN 290
#define DEFINE 291
#define IF 292
#define SWITCH 293
#define WHILE 294
#define FOR 295
#define OR 296
#define AND 297
#define NOT 298
#define SOL 299
#define ENDSOL 300
#define ID 301
#define EVAL 302
#define RETURN 303

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 73 "limbaj.y" /* yacc.c:355  */

  char* strval;

#line 279 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 296 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   474

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  35
/* YYNRULES -- Number of rules.  */
#define YYNRULES  155
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  416

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,    50,     2,     2,     2,     2,
      57,    59,    62,    58,    53,     2,    64,    61,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    54,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    55,     2,    56,    49,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,    63,    52,    60,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   125,   125,   161,   163,   208,   254,   255,   275,   276,
     289,   290,   291,   294,   430,   545,   659,   773,   888,   892,
     896,   900,   904,   909,   913,   917,   921,   925,   930,   936,
     942,   949,   956,   962,   968,   974,   980,   986,   992,   998,
    1004,  1028,  1033,  1042,  1051,  1060,  1069,  1079,  1088,  1097,
    1106,  1115,  1127,  1142,  1149,  1150,  1151,  1152,  1153,  1155,
    1160,  1161,  1162,  1163,  1164,  1167,  1169,  1173,  1177,  1181,
    1185,  1192,  1196,  1201,  1206,  1211,  1216,  1221,  1222,  1225,
    1238,  1255,  1268,  1284,  1297,  1311,  1324,  1334,  1346,  1358,
    1370,  1382,  1394,  1407,  1419,  1431,  1443,  1457,  1469,  1482,
    1493,  1508,  1512,  1516,  1520,  1544,  1552,  1559,  1566,  1570,
    1574,  1578,  1591,  1595,  1601,  1608,  1615,  1619,  1623,  1627,
    1631,  1638,  1683,  1689,  1693,  1697,  1701,  1705,  1710,  1714,
    1718,  1722,  1726,  1730,  1738,  1739,  1740,  1742,  1747,  1769,
    1793,  1794,  1798,  1817,  1818,  1823,  1838,  1842,  1844,  1848,
    1862,  1866,  1868,  1888,  1910,  1914
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "OBIECT", "FUNCTIE", "BOX", "DEFAULT",
  "CASE", "ELSE", "INCLUDE", "LOWT", "BIGT", "LEQ", "BEQ", "EQUAL",
  "NOTEQUAL", "INCREMENT", "DECREMENT", "IN", "MAIN", "PROG_BEGIN",
  "PROG_END", "INT", "INT_NR", "FLOAT", "FLOAT_NR", "CHAR", "CHAR_VAL",
  "STRING", "STRING_VAL", "BOOL", "BOOL_VAL", "CLASS", "METODE", "STRUCT",
  "ASSIGN", "DEFINE", "IF", "SWITCH", "WHILE", "FOR", "OR", "AND", "NOT",
  "SOL", "ENDSOL", "ID", "EVAL", "RETURN", "'^'", "'#'", "'{'", "'}'",
  "','", "'@'", "'['", "']'", "'('", "'+'", "')'", "'~'", "'/'", "'*'",
  "'|'", "'.'", "$accept", "start", "continut", "beforeMain",
  "includeSiDefinuri", "functiiSiClase", "functii", "parametrii", "clase",
  "continut_clasa", "functii_clasa", "onlyMain", "continut_main",
  "returnuri", "initializari", "initializari_clasa", "box", "init_nr",
  "init_float", "init_char", "init_string", "init_bool", "atribuiri",
  "expresie", "expresie_bool", "rezultat", "operatie_bool", "instructiuni",
  "while_instruct", "if_instruct", "for_instruct", "apel_fct",
  "apel_fct_parametrii", "apel_clasa", "eval_fct", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,    94,
      35,   123,   125,    44,    64,    91,    93,    40,    43,    41,
     126,    47,    42,   124,    46
};
# endif

#define YYPACT_NINF -159

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-159)))

#define YYTABLE_NINF -114

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -3,    25,    32,    21,    64,    65,    35,  -159,    66,    41,
    -159,   208,   205,    25,    53,    79,    82,    90,    93,    98,
      35,   107,   160,   162,   176,   179,   139,   171,   205,   205,
    -159,   155,    59,  -159,    62,  -159,    75,  -159,    63,  -159,
     184,  -159,  -159,   164,   169,   180,   194,   196,   197,   212,
    -159,  -159,  -159,    25,    83,    83,   207,    83,   223,     0,
     225,    83,    93,    88,   238,   239,   245,   254,   260,   285,
     290,  -159,  -159,  -159,  -159,   123,    83,   264,  -159,  -159,
     257,    79,   271,    82,   272,   184,    90,   275,  -159,     7,
      98,   237,   237,   237,   237,   237,   282,   295,   300,   304,
     305,   184,   306,   286,    83,   301,   290,   290,   290,   290,
    -159,  -159,  -159,   290,    45,   312,  -159,   140,    79,   184,
    -159,    82,  -159,    90,   307,  -159,    93,  -159,   302,   168,
     308,  -159,   316,   317,   318,   319,   320,   315,   321,   322,
     323,   324,   244,  -159,     7,     7,   325,   333,     6,  -159,
     290,  -159,  -159,  -159,  -159,  -159,  -159,   326,   123,   146,
     327,   328,   329,   331,   154,  -159,    83,    83,    83,    83,
    -159,  -159,  -159,  -159,    90,  -159,     7,  -159,  -159,   131,
     -19,   289,  -159,  -159,    98,   184,   184,   184,    24,   184,
     334,   340,   341,   342,   343,    79,    82,    90,    93,    98,
    -159,   332,   336,   337,   309,    78,   338,   339,  -159,    45,
     333,   261,   273,   131,   281,   287,    45,    45,    45,  -159,
    -159,   310,   311,   335,   344,  -159,   345,   346,    14,  -159,
      47,     7,  -159,  -159,  -159,  -159,  -159,  -159,     5,  -159,
      96,   135,   141,   237,   358,   144,   290,   290,   290,   290,
     290,   244,   244,   244,   244,   244,   362,   352,   353,     7,
    -159,  -159,  -159,  -159,  -159,  -159,   292,  -159,  -159,  -159,
    -159,  -159,  -159,  -159,  -159,   347,   348,   349,   350,   351,
     354,   123,   355,    83,   237,    83,   237,    12,   237,  -159,
      83,     7,   237,   356,   357,   360,   366,   367,  -159,  -159,
    -159,  -159,  -159,   371,   290,   290,   359,  -159,  -159,  -159,
    -159,  -159,  -159,  -159,   363,  -159,   364,  -159,   365,   184,
    -159,   368,   370,  -159,  -159,  -159,  -159,  -159,  -159,   251,
     374,   375,   378,   237,   237,   237,   372,   237,   237,   393,
     394,   395,   396,   397,   386,   390,  -159,   184,  -159,  -159,
    -159,   237,  -159,  -159,   387,   388,   389,   391,   392,  -159,
     398,   202,  -159,   381,   385,   399,   400,   401,   290,   402,
     403,   237,   237,   237,   237,   237,   404,   409,   412,   405,
     406,   407,   408,   410,  -159,   290,   290,   417,   419,   420,
     421,   422,   423,   424,   290,   290,   290,   290,   290,  -159,
    -159,   425,   426,   427,   428,   429,   251,   251,   251,   251,
     251,  -159,  -159,  -159,  -159,  -159
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,     0,     1,     0,     0,
       2,     0,    12,     9,     0,     0,     0,     0,     0,     0,
       5,     0,     0,     0,     0,     0,     0,     0,    12,    12,
       7,     0,    78,    66,    78,    67,    78,    68,    95,    69,
      78,    70,     4,     0,     0,     0,     0,     0,     0,     0,
       3,    10,    11,     8,     0,     0,    81,     0,    85,     0,
      90,     0,     0,    99,     0,     0,     0,     0,     0,     0,
       0,     6,   108,   109,   110,    78,     0,    82,   112,   113,
       0,     0,    86,     0,    91,    78,     0,    96,    93,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    78,     0,     0,     0,     0,    64,    59,    61,    60,
     134,   135,   136,    63,   143,     0,   111,     0,     0,    78,
      79,     0,    83,     0,    92,    87,     0,   122,     0,     0,
     100,    97,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    40,     0,     0,     0,     0,     0,    65,
      62,    52,    58,    53,    55,    54,    57,   148,    78,     0,
     151,   149,   150,     0,    78,   153,     0,     0,     0,     0,
      80,    77,    84,    88,     0,    94,     0,   124,   125,    78,
       0,     0,   126,   127,     0,    78,    78,    78,    26,    78,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      76,     0,     0,     0,     0,     0,     0,     0,    56,   143,
     111,   124,   125,    78,   126,   127,   143,   143,   143,   142,
     152,     0,     0,     0,     0,    89,     0,     0,     0,   123,
       0,     0,   128,   129,   130,   131,   132,   133,     0,    98,
      23,    24,    25,     0,     0,    27,     0,     0,     0,     0,
       0,    66,    67,    68,    69,    70,     0,     0,     0,     0,
     101,   102,   103,   155,   154,   144,   123,   147,   145,   146,
     104,   105,   106,   107,   120,     0,     0,     0,     0,     0,
       0,    78,     0,     0,     0,     0,     0,     0,     0,    21,
       0,     0,     0,     0,     0,     0,     0,     0,    71,    72,
      73,    74,    75,     0,     0,     0,     0,   116,   117,   118,
     119,   114,   115,   121,    36,    18,    37,    19,    31,    78,
      20,    38,    39,    22,    13,    14,    15,    16,    17,     0,
       0,     0,     0,     0,     0,     0,    29,     0,     0,     0,
       0,     0,     0,     0,     0,   139,   137,    78,    32,    33,
      30,     0,    34,    35,     0,     0,     0,     0,     0,    41,
       0,     0,    28,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   138,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   140,
     141,     0,     0,     0,     0,     0,    47,    48,    49,    50,
      51,    42,    43,    44,    45,    46
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -159,  -159,  -159,   379,     3,   195,  -159,   -80,  -159,  -159,
    -158,  -159,   -88,  -159,    -8,    31,   -32,   -76,   -74,   -79,
     -61,   -84,   -66,   -21,   -63,   201,  -159,  -159,  -159,  -159,
    -159,  -105,     4,  -118,  -159
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     5,    12,     6,    27,    28,   137,    29,    97,
     344,    50,   105,   106,   107,   201,   229,    33,    35,    37,
      39,    41,   108,   161,   162,   181,   238,   109,   110,   111,
     112,    78,   163,    79,   113
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      56,    88,    58,    20,    60,   120,   131,   125,    63,   122,
     165,   183,   138,   139,   140,   141,    30,     1,   152,   153,
     154,   155,   230,   231,   182,   156,   130,    84,   177,    72,
     178,    73,     7,    77,    80,    74,    82,   127,   127,   318,
      87,   215,   170,   116,   173,   127,    85,   172,   160,   128,
     128,   281,    75,   124,   214,   117,    71,   128,   319,   -78,
     276,     3,   208,   159,   129,   175,   180,     8,    72,   147,
      73,   129,   157,     9,    74,     4,   127,   243,   127,    55,
     204,   202,   203,   150,    11,   207,    10,   171,   128,    13,
     128,   158,    14,   278,    54,   225,   180,    57,    61,    31,
     239,    72,   159,    73,   129,   260,    72,    74,    73,   127,
      59,    43,    74,   226,    55,   255,    62,    55,   253,   251,
     183,   128,   252,    89,    75,    32,   210,   206,    34,    75,
      55,   283,   220,   182,   200,   159,    36,   254,   117,    38,
      76,    90,   262,   160,    40,   221,   222,   223,   224,   284,
     160,   160,   160,   240,   241,   242,   244,   245,   293,   294,
     295,   296,   297,   289,    44,   277,    45,   279,   280,   211,
     285,   212,   227,   228,   114,    74,   287,   127,    55,   291,
      46,   266,   114,    47,   261,    48,    55,   115,   286,   128,
      49,   177,   213,   178,   288,   115,   306,   292,   166,   127,
     167,   168,   169,   159,   315,   114,   317,    53,   320,    55,
      64,   128,   323,   265,   179,    65,   330,   331,   369,   370,
     267,   268,   269,    51,    52,   129,    66,    21,   322,    22,
      15,    23,    16,    24,    17,    25,    18,    26,    19,    55,
      67,    69,    68,   200,   200,   200,   200,   200,   411,   412,
     413,   414,   415,   348,   349,   350,    70,   352,   353,   132,
      81,   133,   314,   134,   316,   135,   195,   136,   196,   321,
     197,   362,   198,   339,   199,   340,    83,   341,    86,   342,
     376,   343,   298,   299,   300,   301,   302,   336,    96,    91,
      92,   379,   380,   381,   382,   383,    93,   392,   393,   232,
     233,   234,   235,   236,   237,    94,   401,   402,   403,   404,
     405,    95,    15,   119,    16,   361,    17,   118,    18,  -108,
      19,  -108,  -108,  -108,   121,   123,   142,    98,   126,    99,
     100,  -109,   149,  -109,  -109,  -109,   101,   102,   103,  -112,
     143,  -112,  -112,  -112,   104,  -113,   151,  -113,  -113,  -113,
    -111,   144,  -111,  -111,  -111,   145,   146,   148,   164,   176,
     174,   184,   185,   186,   187,   188,   189,   190,   205,   270,
     271,   101,   259,   191,   192,   193,   194,   256,   246,   209,
     216,   217,   218,   219,   247,   248,   249,   250,   257,   258,
     263,   264,   275,   290,   272,   303,   304,   305,   360,    42,
       0,   324,   325,   273,   274,   326,   307,   308,   309,   310,
     311,   327,   328,   312,   313,   329,   333,   334,   335,   345,
     346,   337,   332,   338,   347,   351,   354,   355,   356,   357,
     358,   359,   371,   363,   364,   365,   372,   366,   367,   282,
       0,     0,   368,     0,     0,     0,     0,     0,     0,   384,
     373,   374,   375,   385,   377,   378,   386,   387,   388,   389,
     390,   394,   391,   395,   396,   397,   398,     0,   399,   400,
     406,   407,   408,   409,   410
};

static const yytype_int16 yycheck[] =
{
      32,    62,    34,    11,    36,    81,    90,    86,    40,    83,
     115,   129,    92,    93,    94,    95,    13,    20,   106,   107,
     108,   109,    41,    42,   129,   113,    89,    27,    23,    23,
      25,    25,     0,    54,    55,    29,    57,    31,    31,    27,
      61,   159,   118,    75,   123,    31,    46,   121,   114,    43,
      43,    46,    46,    85,   159,    76,    53,    43,    46,    35,
      46,    36,   150,    57,    57,   126,   129,    46,    23,   101,
      25,    57,    27,     9,    29,    50,    31,    53,    31,    55,
     146,   144,   145,   104,    49,   148,    21,   119,    43,    23,
      43,    46,    51,    46,    35,   174,   159,    35,    35,    46,
     184,    23,    57,    25,    57,    27,    23,    29,    25,    31,
      35,     4,    29,   176,    55,   199,    53,    55,   197,   195,
     238,    43,   196,    35,    46,    46,   158,   148,    46,    46,
      55,    35,   164,   238,   142,    57,    46,   198,   159,    46,
      57,    53,   205,   209,    46,   166,   167,   168,   169,    53,
     216,   217,   218,   185,   186,   187,   188,   189,   246,   247,
     248,   249,   250,   243,     4,   228,     4,   230,   231,    23,
      35,    25,    41,    42,    51,    29,    35,    31,    55,    35,
       4,   213,    51,     4,   205,    46,    55,    64,    53,    43,
      19,    23,    46,    25,    53,    64,   259,    53,    58,    31,
      60,    61,    62,    57,   284,    51,   286,    52,   288,    55,
      46,    43,   292,   209,    46,    46,   304,   305,    16,    17,
     216,   217,   218,    28,    29,    57,    46,    22,   291,    24,
      22,    26,    24,    28,    26,    30,    28,    32,    30,    55,
      46,    44,    46,   251,   252,   253,   254,   255,   406,   407,
     408,   409,   410,   333,   334,   335,    44,   337,   338,    22,
      53,    24,   283,    26,   285,    28,    22,    30,    24,   290,
      26,   351,    28,    22,    30,    24,    53,    26,    53,    28,
     368,    30,   251,   252,   253,   254,   255,   319,     3,    51,
      51,   371,   372,   373,   374,   375,    51,   385,   386,    10,
      11,    12,    13,    14,    15,    51,   394,   395,   396,   397,
     398,    51,    22,    56,    24,   347,    26,    53,    28,    58,
      30,    60,    61,    62,    53,    53,    44,    37,    53,    39,
      40,    58,    46,    60,    61,    62,    46,    47,    48,    58,
      45,    60,    61,    62,    54,    58,    45,    60,    61,    62,
      58,    51,    60,    61,    62,    51,    51,    51,    46,    57,
      53,    53,    46,    46,    46,    46,    46,    52,    35,    59,
      59,    46,    63,    52,    52,    52,    52,    45,    44,    53,
      53,    53,    53,    52,    44,    44,    44,    44,    52,    52,
      52,    52,    46,    35,    59,    33,    44,    44,     8,    20,
      -1,    45,    45,    59,    59,    45,    59,    59,    59,    59,
      59,    45,    45,    59,    59,    44,    53,    53,    53,    45,
      45,    53,    63,    53,    46,    53,    33,    33,    33,    33,
      33,    45,    51,    46,    46,    46,    51,    46,    46,   238,
      -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      51,    51,    51,    44,    52,    52,    44,    52,    52,    52,
      52,    44,    52,    44,    44,    44,    44,    -1,    45,    45,
      45,    45,    45,    45,    45
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    20,    66,    36,    50,    67,    69,     0,    46,     9,
      21,    49,    68,    23,    51,    22,    24,    26,    28,    30,
      79,    22,    24,    26,    28,    30,    32,    70,    71,    73,
      69,    46,    46,    82,    46,    83,    46,    84,    46,    85,
      46,    86,    68,     4,     4,     4,     4,     4,    46,    19,
      76,    70,    70,    52,    35,    55,    81,    35,    81,    35,
      81,    35,    53,    81,    46,    46,    46,    46,    46,    44,
      44,    69,    23,    25,    29,    46,    57,    88,    96,    98,
      88,    53,    88,    53,    27,    46,    53,    88,    85,    35,
      53,    51,    51,    51,    51,    51,     3,    74,    37,    39,
      40,    46,    47,    48,    54,    77,    78,    79,    87,    92,
      93,    94,    95,    99,    51,    64,    81,    88,    53,    56,
      82,    53,    83,    53,    81,    84,    53,    31,    43,    57,
      89,    86,    22,    24,    26,    28,    30,    72,    72,    72,
      72,    72,    44,    45,    51,    51,    51,    81,    51,    46,
      88,    45,    77,    77,    77,    77,    77,    27,    46,    57,
      87,    88,    89,    97,    46,    96,    58,    60,    61,    62,
      82,    81,    83,    84,    53,    85,    57,    23,    25,    46,
      89,    90,    96,    98,    53,    46,    46,    46,    46,    46,
      52,    52,    52,    52,    52,    22,    24,    26,    28,    30,
      79,    80,    89,    89,    87,    35,    88,    89,    77,    53,
      81,    23,    25,    46,    96,    98,    53,    53,    53,    52,
      81,    88,    88,    88,    88,    84,    89,    41,    42,    81,
      41,    42,    10,    11,    12,    13,    14,    15,    91,    86,
      81,    81,    81,    53,    81,    81,    44,    44,    44,    44,
      44,    82,    83,    84,    85,    86,    45,    52,    52,    63,
      27,    88,    89,    52,    52,    97,    81,    97,    97,    97,
      59,    59,    59,    59,    59,    46,    46,    89,    46,    89,
      89,    46,    90,    35,    53,    35,    53,    35,    53,    72,
      35,    35,    53,    77,    77,    77,    77,    77,    80,    80,
      80,    80,    80,    33,    44,    44,    89,    59,    59,    59,
      59,    59,    59,    59,    88,    72,    88,    72,    27,    46,
      72,    88,    89,    72,    45,    45,    45,    45,    45,    44,
      77,    77,    63,    53,    53,    53,    81,    53,    53,    22,
      24,    26,    28,    30,    75,    45,    45,    46,    72,    72,
      72,    53,    72,    72,    33,    33,    33,    33,    33,    45,
       8,    81,    72,    46,    46,    46,    46,    46,    44,    16,
      17,    51,    51,    51,    51,    51,    77,    52,    52,    72,
      72,    72,    72,    72,    45,    44,    44,    52,    52,    52,
      52,    52,    77,    77,    44,    44,    44,    44,    44,    45,
      45,    77,    77,    77,    77,    77,    45,    45,    45,    45,
      45,    75,    75,    75,    75,    75
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    65,    66,    67,    68,    68,    69,    69,    69,    69,
      70,    70,    70,    71,    71,    71,    71,    71,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    72,
      73,    74,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    76,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    78,    79,    79,    79,    79,
      79,    80,    80,    80,    80,    80,    80,    81,    81,    82,
      82,    82,    82,    83,    83,    83,    83,    84,    84,    84,
      84,    84,    84,    85,    85,    85,    85,    86,    86,    86,
      86,    87,    87,    87,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    90,    90,    90,    90,    90,    91,    91,
      91,    91,    91,    91,    92,    92,    92,    93,    94,    94,
      95,    95,    96,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    98,    98,    99,    99
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     4,     3,     2,     6,     4,     5,     3,
       2,     2,     0,     9,     9,     9,     9,     9,     5,     5,
       5,     4,     5,     3,     3,     3,     2,     3,     8,     6,
       7,     5,     7,     7,     7,     7,     5,     5,     5,     5,
       5,     8,    10,    10,    10,    10,    10,     9,     9,     9,
       9,     9,     4,     2,     2,     2,     3,     2,     2,     1,
       1,     1,     2,     1,     1,     2,     2,     2,     2,     2,
       2,     3,     3,     3,     3,     3,     1,     4,     0,     4,
       5,     2,     3,     4,     5,     2,     3,     4,     5,     6,
       2,     3,     4,     3,     5,     1,     3,     4,     6,     2,
       4,     4,     4,     4,     5,     5,     5,     5,     1,     1,
       1,     2,     1,     1,     5,     5,     5,     5,     5,     5,
       4,     5,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     7,    11,     7,
      13,    13,     4,     0,     3,     3,     3,     3,     1,     1,
       1,     1,     4,     3,     4,     4
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
#line 126 "limbaj.y" /* yacc.c:1646  */
    {
        printf("Program corect!\n");

	/* continut=make_tuple("var1", lista_var, "VAR", 0, 0);

	lista_var.insert(make_pair(0, "parametru1"));
        lista_var.insert(make_pair(2, "parametru2"));

	continut2= make_tuple("fct2", lista_var, "FCT", 2, 0);

	symbol_table.insert(make_pair("GLOBAL",continut));
	symbol_table.insert(make_pair("GLOBAL",continut2)); */

        ofstream file_table("symbol_table.txt");

       for (iterator_symbol_table = symbol_table.begin(); iterator_symbol_table != symbol_table.end(); iterator_symbol_table++) {

                file_table<<"SCOPE: "<<iterator_symbol_table->first << " "
			  <<"ID OBIECT: "<< get<0>(iterator_symbol_table->second)<<" LISTA_VALORI(index,val)/LISTA_PARAMETRII(tip,ID): ";

		for (multimap<string, string>::iterator i = (get<1>(iterator_symbol_table->second)).begin(); i != (get<1>(iterator_symbol_table->second)).end();++i) {
			file_table <<"["<< i->first << " " << i->second<<"] ";
		}

		file_table<<"TIP OBIECT: "<< get<2>(iterator_symbol_table->second) << " "
			 <<"RETURN TYPE/VECTOR END: "<< get<3>(iterator_symbol_table->second) << " "
			 <<"DEPTH: "<< get<4>(iterator_symbol_table->second) << " "
			 << endl;

	}

        file_table.close();

}
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 164 "limbaj.y" /* yacc.c:1646  */
    {
                 multimap<string,string> temporar;
                 string duplicate[100];
                 int i=0;
                 for(auto n : lista_fct_init){
                        
                        temporar.insert(make_pair("0",get<2>(n)));
                        int val;
                        

                        //if(get<2>(n)[0]!='\"' && get<2>(n)[0]!='\'' && get<2>(n)[0]!='-' && get<2>(n)[0]!='1' && get<2>(n)[0]!='2' && get<2>(n)[0]!='3' && get<2>(n)[0]!='4' && get<2>(n)[0]!='5' && get<2>(n)[0]!='6' && get<2>(n)[0]!='7' && get<2>(n)[0]!='8' && get<2>(n)[0]!='9' && get<2>(n)[0]!='0'  ){
                                duplicate[i]=(get<1>(n));
                                i++;
                                for(unordered_multimap<string,tuple<string,multimap<string,string>,string,string,int>>::iterator iterator_symbol_table=symbol_table.begin();iterator_symbol_table!=symbol_table.end();iterator_symbol_table++){                                
                                        //cout<<get<0>(iterator_symbol_table->second)<<endl;
                                        if(iterator_symbol_table->first=="GLOBAL"){
                                                if(get<1>(n)==get<0>(iterator_symbol_table->second)){
                                                      
                                                }
                                        } 
                                }
                        //}
                        continut = make_tuple(get<1>(n),temporar,get<3>(n),get<0>(n), 0/*alt var pt depth*/);
                        symbol_table.insert(make_pair("GLOBAL",continut));
                        temporar.clear();
                }
                //se verifca in lista de parametrii daca sunt duplicate

                for(int j=0;j<=i;j++){
                        //cout<<duplicate[j]<<' ';
                        for(int k=j+1;k<=i;k++){
                               
                                if(duplicate[j]==duplicate[k]){
                                         
                                        printf("Exista variabile globale care au fost redeclarate!  %d\n",yylineno);
                                        return -4; 
                                }
                        }
                }

                temporar.clear();
                lista_fct_init.clear();
                
          }
#line 1736 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 209 "limbaj.y" /* yacc.c:1646  */
    {
                 multimap<string,string> temporar;
                 string duplicate[100];
                 int i=0;
                 for(auto n : lista_fct_init){
                        
                        temporar.insert(make_pair("0",get<2>(n)));
                        int val;
                        

                        //if(get<2>(n)[0]!='\"' && get<2>(n)[0]!='\'' && get<2>(n)[0]!='-' && get<2>(n)[0]!='1' && get<2>(n)[0]!='2' && get<2>(n)[0]!='3' && get<2>(n)[0]!='4' && get<2>(n)[0]!='5' && get<2>(n)[0]!='6' && get<2>(n)[0]!='7' && get<2>(n)[0]!='8' && get<2>(n)[0]!='9' && get<2>(n)[0]!='0'  ){
                                duplicate[i]=(get<1>(n));
                                i++;
                                for(unordered_multimap<string,tuple<string,multimap<string,string>,string,string,int>>::iterator iterator_symbol_table=symbol_table.begin();iterator_symbol_table!=symbol_table.end();iterator_symbol_table++){                                
                                        //cout<<get<0>(iterator_symbol_table->second)<<endl;
                                        if(iterator_symbol_table->first=="GLOBAL"){
                                                if(get<1>(n)==get<0>(iterator_symbol_table->second)){
                                                      
                                                }
                                        } 
                                }
                        //}
                        continut = make_tuple(get<1>(n),temporar,get<3>(n),get<0>(n), 0/*alt var pt depth*/);
                        symbol_table.insert(make_pair("GLOBAL",continut));
                        temporar.clear();
                }
                //se verifca in lista de parametrii daca sunt duplicate

                for(int j=0;j<=i;j++){
                        //cout<<duplicate[j]<<' ';
                        for(int k=j+1;k<=i;k++){
                               
                                if(duplicate[j]==duplicate[k]){
                                         
                                        printf("Exista variabile globale care au fost redeclarate!  %d\n",yylineno);
                                        return -4; 
                                }
                        }
                }

                temporar.clear();
                lista_fct_init.clear();
          }
#line 1784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 256 "limbaj.y" /* yacc.c:1646  */
    {
                        //verificare redeclarare
                        for (iterator_symbol_table = symbol_table.begin(); iterator_symbol_table != symbol_table.end(); iterator_symbol_table++) {
                                
                                string repeatingConstant((yyvsp[-2].strval));
                                
                                if(get<0>(iterator_symbol_table->second)==repeatingConstant){
                                        printf("Constanta redeclarata la linia %d \n",yylineno);
                                        return -1;
                                }

                        }
                        //inserare const
                        lista_var.insert(make_pair("int", (yyvsp[-1].strval)));
                        continut=make_tuple((yyvsp[-2].strval), lista_var, "CST", "0", yylineno);
                        symbol_table.insert(make_pair("GLOBAL",continut));
                        //stergere
                        lista_var.clear();
                 }
#line 1808 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 277 "limbaj.y" /* yacc.c:1646  */
    {
                        //inserare const
                        lista_var.insert(make_pair("int", (yyvsp[0].strval)));
                        continut=make_tuple((yyvsp[-1].strval), lista_var, "CST", "0", yylineno);
                        symbol_table.insert(make_pair("GLOBAL",continut));
                        //stergere
                        lista_var.clear();

                 }
#line 1822 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 295 "limbaj.y" /* yacc.c:1646  */
    {
                //cout<<$<strval>8<<' ';    
           
                multimap<string, string>temporar;
                temporar.insert(make_pair("0","NA-1"));

                string numeFunctieCuSignatura=(yyvsp[-6].strval);

                for (multimap<string, string>::iterator i = lista_var.begin(); i != lista_var.end(); ++i) {
                        numeFunctieCuSignatura+="_"+(i->first);
                }
                
                //cout<<i->first<<' '<<i->second<<endl;
                for(multimap<string,string>::iterator j = nume_valoare_parametru.begin(); j!=nume_valoare_parametru.end();++j){
                                if(j->first!="-"){
                                        for (multimap<string, string>::iterator i = lista_var.begin(); i != lista_var.end(); ++i) {
                                                if(i->second==j->first){
                                                        //cout<<j->first<<' '<<j->second<<endl;
                                                        temporar.clear();
                                                        temporar.insert(make_pair("0",j->second));

                                                        continut = make_tuple(i->second, temporar, "VAR",i->first,yylineno);
                                                        symbol_table.insert(make_pair(numeFunctieCuSignatura,continut));
                                                }
                                }
                        temporar.clear();
                        temporar.insert(make_pair("0","NA-1"));
                        }
                 }
                nume_valoare_parametru.clear(); 
                nume_valoare_parametru.insert(make_pair("-","-"));

                map<string,bool> aFostPusDeja;
                for(multimap<string,string>::iterator k=lista_var.begin();k!=lista_var.end();k++){
                        //cout<<k->first<<' '<<k->second<<' ';
                        for(unordered_multimap<string,tuple<string,multimap<string,string>,string,string,int>>::iterator iterator_symbol_table=symbol_table.begin();iterator_symbol_table!=symbol_table.end();iterator_symbol_table++){
                                if(iterator_symbol_table->first==numeFunctieCuSignatura && k->second==get<0>(iterator_symbol_table->second)){
                                        //cout<<k->second<<"=="<<get<0>(iterator_symbol_table->second)<<endl;
                                        aFostPusDeja.insert(make_pair(k->second,true));
                                }
                        }
                }

                temporar.clear();
                temporar.insert(make_pair("0","NA-1"));
                for(multimap<string,string>::iterator k=lista_var.begin();k!=lista_var.end();k++){
                        if(aFostPusDeja[k->second]!=true){
                                aFostPusDeja.insert(make_pair(k->second,false));
                                //cout<<k->second<<' '<<aFostPusDeja[k->second]<<' ';
                        } 
                }   
               
                for(multimap<string,string>::iterator k=lista_var.begin();k!=lista_var.end();k++){
                        if(aFostPusDeja[k->second]==false){
                                continut = make_tuple(k->second, temporar, "VAR",k->first,yylineno);
                                symbol_table.insert(make_pair(numeFunctieCuSignatura,continut)); 
                        } 
                }


                int nr=0;
                for (iterator_symbol_table = symbol_table.begin(); iterator_symbol_table != symbol_table.end(); iterator_symbol_table++) {
                        
                        if(iterator_symbol_table->first=="GLOBAL" && get<0>(iterator_symbol_table->second)==numeFunctieCuSignatura){
                                nr++;
                                //cout<<get<0>(iterator_symbol_table->second)<<' '<<numeFunctieCuSignatura<<endl;
                                 if(nr>=1){
                                        //cout<<nr;
                                        printf("Doua functii nu pot avea aceasi signatura si acelasi nume! la linia %d\n",yylineno);
                                        return -2;
                                } 
                        }
                
                }

                temporar.clear();
                //tipul,valoarea,tipul obiectului var,vect,fct etc,
                string s1,s2,s3,s4;
                for(auto n : lista_fct_init){
                        
                        temporar.insert(make_pair("0",get<2>(n)));
                        int val;

                        if(get<2>(n)[0]!='\"' && get<2>(n)[0]!='\'' && get<2>(n)[0]!='-' && get<2>(n)[0]!='1' && get<2>(n)[0]!='2' && get<2>(n)[0]!='3' && get<2>(n)[0]!='4' && get<2>(n)[0]!='5' && get<2>(n)[0]!='6' && get<2>(n)[0]!='7' && get<2>(n)[0]!='8' && get<2>(n)[0]!='9' && get<2>(n)[0]!='0'  ){
                           //cout<<(get<2>(n))<<endl;

                                for(unordered_multimap<string,tuple<string,multimap<string,string>,string,string,int>>::iterator iterator_symbol_table=symbol_table.begin();iterator_symbol_table!=symbol_table.end();iterator_symbol_table++){                                
                                        if(iterator_symbol_table->first==numeFunctieCuSignatura){
                                                if(get<2>(n)==get<0>(iterator_symbol_table->second)){
                                                        temporar.clear();
                                                        for(auto t:get<1>(iterator_symbol_table->second)){
                                                                temporar.insert({"0",t.second});
                                                        }
                                                }
                                        } 
                                }
                        }

                        continut = make_tuple(get<1>(n),temporar,get<3>(n),get<0>(n), 0/*alt var pt depth*/);
                        symbol_table.insert(make_pair(numeFunctieCuSignatura,continut));
                        temporar.clear();
                }
                temporar.clear();
                lista_fct_init.clear();

                //se verifca in lista de parametrii daca sunt duplicate
                string duplicate[100];
                int i=0;
                        for(unordered_multimap<string,tuple<string,multimap<string,string>,string,string,int>>::iterator iterator_symbol_table=symbol_table.begin();iterator_symbol_table!=symbol_table.end();iterator_symbol_table++){                                
                                        if(iterator_symbol_table->first==numeFunctieCuSignatura){
                                                
                                                duplicate[i]=get<0>(iterator_symbol_table->second);
                                                i++;
                                        } 
                        }
                

                for(int j=0;j<=i;j++){
                        for(int k=j+1;k<=i;k++){
                               
                                if(duplicate[j]==duplicate[k]){
                                         
                                        printf("Parametrii cu acelasi identificator sau redeclarari in functia de la linia  %d\n",yylineno);
                                        return -3; 
                                }
                        }
                }
                

            continut=make_tuple(numeFunctieCuSignatura, lista_var, "FCT", "int", 0);
            symbol_table.insert(make_pair("GLOBAL",continut)); 

            lista_var.clear();
             
        }
#line 1962 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 431 "limbaj.y" /* yacc.c:1646  */
    {
                multimap<string, string>temporar;
                temporar.insert(make_pair("0","NA-1"));

                string numeFunctieCuSignatura=(yyvsp[-6].strval);

                for (multimap<string, string>::iterator i = nume_valoare_parametru.begin(); i != nume_valoare_parametru.end(); ++i) {
                        //cout<<(i->first)<<' '<<i->second<<' ';
                }
                //cout<<endl;
                for (multimap<string, string>::iterator i = lista_var.begin(); i != lista_var.end(); ++i) {
                        numeFunctieCuSignatura+="_"+(i->first);
                }

                
                        //cout<<i->first<<' '<<i->second<<endl;
                for(multimap<string,string>::iterator j = nume_valoare_parametru.begin(); j!=nume_valoare_parametru.end();++j){
                                if(j->first!="-"){
                                        for (multimap<string, string>::iterator i = lista_var.begin(); i != lista_var.end(); ++i) {
                                                if(i->second==j->first){
                                                        //cout<<j->first<<' '<<j->second<<endl;
                                                        temporar.clear();
                                                        temporar.insert(make_pair("0",j->second));

                                                        continut = make_tuple(i->second, temporar, "VAR",i->first, 0/*alt var pt depth*/);
                                                        symbol_table.insert(make_pair(numeFunctieCuSignatura,continut));
                                                }
                                }
                        temporar.clear();
                        temporar.insert(make_pair("0","NA-1"));
                        }
                 }
                nume_valoare_parametru.clear(); 
                nume_valoare_parametru.insert(make_pair("-","-"));

                map<string,bool> aFostPusDeja;
                for(multimap<string,string>::iterator k=lista_var.begin();k!=lista_var.end();k++){
                        //cout<<k->first<<' '<<k->second<<' ';
                        for(unordered_multimap<string,tuple<string,multimap<string,string>,string,string,int>>::iterator iterator_symbol_table=symbol_table.begin();iterator_symbol_table!=symbol_table.end();iterator_symbol_table++){
                                if(iterator_symbol_table->first==numeFunctieCuSignatura && k->second==get<0>(iterator_symbol_table->second)){
                                        //cout<<k->second<<"=="<<get<0>(iterator_symbol_table->second)<<endl;
                                        aFostPusDeja.insert(make_pair(k->second,true));
                                }
                        }
                }

                temporar.clear();
                temporar.insert(make_pair("0","NA-1"));
                for(multimap<string,string>::iterator k=lista_var.begin();k!=lista_var.end();k++){
                        if(aFostPusDeja[k->second]!=true){
                                aFostPusDeja.insert(make_pair(k->second,false));
                                //cout<<k->second<<' '<<aFostPusDeja[k->second]<<' ';
                        } 
                }   
               
                for(multimap<string,string>::iterator k=lista_var.begin();k!=lista_var.end();k++){
                        if(aFostPusDeja[k->second]==false){
                                continut = make_tuple(k->second, temporar, "VAR","", 0/*alt var pt depth*/);
                                symbol_table.insert(make_pair(numeFunctieCuSignatura,continut)); 
                        } 
                }         

                int nr=0;
                for (iterator_symbol_table = symbol_table.begin(); iterator_symbol_table != symbol_table.end(); iterator_symbol_table++) {
                        
                        if(iterator_symbol_table->first=="GLOBAL" && get<0>(iterator_symbol_table->second)==numeFunctieCuSignatura){
                                nr++;
                                //cout<<get<0>(iterator_symbol_table->second)<<' '<<numeFunctieCuSignatura<<endl;
                                 if(nr>=1){
                                        //cout<<nr;
                                        printf("Doua functii nu pot avea aceasi signatura si acelasi nume! la linia %d\n",yylineno);
                                        return -2;
                                } 
                        }
                
                }

                 temporar.clear();
                string s1,s2,s3,s4;
                for(auto n : lista_fct_init){
                        
                        temporar.insert(make_pair("0",get<2>(n)));
                        continut = make_tuple(get<1>(n),temporar,get<3>(n),get<0>(n), 0/*alt var pt depth*/);
                        symbol_table.insert(make_pair(numeFunctieCuSignatura,continut));
                        temporar.clear();
                }
                temporar.clear();
                lista_fct_init.clear();

                //se verifca in lista de parametrii daca sunt duplicate
                string duplicate[100];
                int i=0;
                        for(unordered_multimap<string,tuple<string,multimap<string,string>,string,string,int>>::iterator iterator_symbol_table=symbol_table.begin();iterator_symbol_table!=symbol_table.end();iterator_symbol_table++){                                
                                        if(iterator_symbol_table->first==numeFunctieCuSignatura){
                                                
                                                duplicate[i]=get<0>(iterator_symbol_table->second);
                                                i++;
                                        } 
                        }
                for(int j=0;j<=i;j++){
                        for(int k=j+1;k<=i;k++){
                               
                                if(duplicate[j]==duplicate[k]){
                                         
                                        printf("Parametrii cu acelasi identificator la linia %d\n",yylineno);
                                        return -3; 
                                }
                        }
                }
            continut=make_tuple(numeFunctieCuSignatura, lista_var, "FCT", "float", 0);
            symbol_table.insert(make_pair("GLOBAL",continut)); 
            lista_var.clear();
              
       }
#line 2081 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 546 "limbaj.y" /* yacc.c:1646  */
    {
                multimap<string, string>temporar;
                temporar.insert(make_pair("0","NA-1"));

                string numeFunctieCuSignatura=(yyvsp[-6].strval);

                for (multimap<string, string>::iterator i = nume_valoare_parametru.begin(); i != nume_valoare_parametru.end(); ++i) {
                        //cout<<(i->first)<<' '<<i->second<<' ';
                }
                //cout<<endl;
                for (multimap<string, string>::iterator i = lista_var.begin(); i != lista_var.end(); ++i) {
                        numeFunctieCuSignatura+="_"+(i->first);
                }

                
                        //cout<<i->first<<' '<<i->second<<endl;
                for(multimap<string,string>::iterator j = nume_valoare_parametru.begin(); j!=nume_valoare_parametru.end();++j){
                                if(j->first!="-"){
                                        for (multimap<string, string>::iterator i = lista_var.begin(); i != lista_var.end(); ++i) {
                                                if(i->second==j->first){
                                                        //cout<<j->first<<' '<<j->second<<endl;
                                                        temporar.clear();
                                                        temporar.insert(make_pair("0",j->second));

                                                        continut = make_tuple(i->second, temporar, "VAR",i->first, 0/*alt var pt depth*/);
                                                        symbol_table.insert(make_pair(numeFunctieCuSignatura,continut));
                                                }
                                }
                        temporar.clear();
                        temporar.insert(make_pair("0","NA-1"));
                        }
                 }
                nume_valoare_parametru.clear(); 
                nume_valoare_parametru.insert(make_pair("-","-"));

                map<string,bool> aFostPusDeja;
                for(multimap<string,string>::iterator k=lista_var.begin();k!=lista_var.end();k++){
                        //cout<<k->first<<' '<<k->second<<' ';
                        for(unordered_multimap<string,tuple<string,multimap<string,string>,string,string,int>>::iterator iterator_symbol_table=symbol_table.begin();iterator_symbol_table!=symbol_table.end();iterator_symbol_table++){
                                if(iterator_symbol_table->first==numeFunctieCuSignatura && k->second==get<0>(iterator_symbol_table->second)){
                                        //cout<<k->second<<"=="<<get<0>(iterator_symbol_table->second)<<endl;
                                        aFostPusDeja.insert(make_pair(k->second,true));
                                }
                        }
                }

                temporar.clear();
                temporar.insert(make_pair("0","NA-1"));
                for(multimap<string,string>::iterator k=lista_var.begin();k!=lista_var.end();k++){
                        if(aFostPusDeja[k->second]!=true){
                                aFostPusDeja.insert(make_pair(k->second,false));
                                //cout<<k->second<<' '<<aFostPusDeja[k->second]<<' ';
                        } 
                }   
               
                for(multimap<string,string>::iterator k=lista_var.begin();k!=lista_var.end();k++){
                        if(aFostPusDeja[k->second]==false){
                                continut = make_tuple(k->second, temporar, "VAR","", 0/*alt var pt depth*/);
                                symbol_table.insert(make_pair(numeFunctieCuSignatura,continut)); 
                        } 
                }         
                int nr=0;
                for (iterator_symbol_table = symbol_table.begin(); iterator_symbol_table != symbol_table.end(); iterator_symbol_table++) {
                        
                        if(iterator_symbol_table->first=="GLOBAL" && get<0>(iterator_symbol_table->second)==numeFunctieCuSignatura){
                                nr++;
                                //cout<<get<0>(iterator_symbol_table->second)<<' '<<numeFunctieCuSignatura<<endl;
                                 if(nr>=1){
                                       //cout<<nr;
                                        printf("Doua functii nu pot avea aceasi signatura si acelasi nume! la linia %d\n",yylineno);
                                        return -2;
                                } 
                        }
                
                }

                temporar.clear();
                string s1,s2,s3,s4;
                for(auto n : lista_fct_init){
                        
                        temporar.insert(make_pair("0",get<2>(n)));
                        continut = make_tuple(get<1>(n),temporar,get<3>(n),get<0>(n), 0/*alt var pt depth*/);
                        symbol_table.insert(make_pair(numeFunctieCuSignatura,continut));
                        temporar.clear();
                }
                temporar.clear();
                lista_fct_init.clear();

                //se verifca in lista de parametrii daca sunt duplicate
                string duplicate[100];
                int i=0;
                        for(unordered_multimap<string,tuple<string,multimap<string,string>,string,string,int>>::iterator iterator_symbol_table=symbol_table.begin();iterator_symbol_table!=symbol_table.end();iterator_symbol_table++){                                
                                        if(iterator_symbol_table->first==numeFunctieCuSignatura){
                                                
                                                duplicate[i]=get<0>(iterator_symbol_table->second);
                                                i++;
                                        } 
                        }
                for(int j=0;j<=i;j++){
                        for(int k=j+1;k<=i;k++){
                               
                                if(duplicate[j]==duplicate[k]){
                                         
                                        printf("Parametrii cu acelasi identificator la linia %d\n",yylineno);
                                        return -3; 
                                }
                        }
                }
            continut=make_tuple(numeFunctieCuSignatura, lista_var, "FCT", "char", 0);
            symbol_table.insert(make_pair("GLOBAL",continut)); 
            lista_var.clear();
              
       }
#line 2199 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 660 "limbaj.y" /* yacc.c:1646  */
    {
                multimap<string, string>temporar;
                temporar.insert(make_pair("0","NA-1"));

                string numeFunctieCuSignatura=(yyvsp[-6].strval);

                for (multimap<string, string>::iterator i = nume_valoare_parametru.begin(); i != nume_valoare_parametru.end(); ++i) {
                        //cout<<(i->first)<<' '<<i->second<<' ';
                }
                //cout<<endl;
                for (multimap<string, string>::iterator i = lista_var.begin(); i != lista_var.end(); ++i) {
                        numeFunctieCuSignatura+="_"+(i->first);
                }

                
                        //cout<<i->first<<' '<<i->second<<endl;
                for(multimap<string,string>::iterator j = nume_valoare_parametru.begin(); j!=nume_valoare_parametru.end();++j){
                                if(j->first!="-"){
                                        for (multimap<string, string>::iterator i = lista_var.begin(); i != lista_var.end(); ++i) {
                                                if(i->second==j->first){
                                                        //cout<<j->first<<' '<<j->second<<endl;
                                                        temporar.clear();
                                                        temporar.insert(make_pair("0",j->second));

                                                        continut = make_tuple(i->second, temporar, "VAR",i->first, 0/*alt var pt depth*/);
                                                        symbol_table.insert(make_pair(numeFunctieCuSignatura,continut));
                                                }
                                }
                        temporar.clear();
                        temporar.insert(make_pair("0","NA-1"));
                        }
                 }
                nume_valoare_parametru.clear(); 
                nume_valoare_parametru.insert(make_pair("-","-"));

                map<string,bool> aFostPusDeja;
                for(multimap<string,string>::iterator k=lista_var.begin();k!=lista_var.end();k++){
                        //cout<<k->first<<' '<<k->second<<' ';
                        for(unordered_multimap<string,tuple<string,multimap<string,string>,string,string,int>>::iterator iterator_symbol_table=symbol_table.begin();iterator_symbol_table!=symbol_table.end();iterator_symbol_table++){
                                if(iterator_symbol_table->first==numeFunctieCuSignatura && k->second==get<0>(iterator_symbol_table->second)){
                                        //cout<<k->second<<"=="<<get<0>(iterator_symbol_table->second)<<endl;
                                        aFostPusDeja.insert(make_pair(k->second,true));
                                }
                        }
                }

                temporar.clear();
                temporar.insert(make_pair("0","NA-1"));
                for(multimap<string,string>::iterator k=lista_var.begin();k!=lista_var.end();k++){
                        if(aFostPusDeja[k->second]!=true){
                                aFostPusDeja.insert(make_pair(k->second,false));
                                //cout<<k->second<<' '<<aFostPusDeja[k->second]<<' ';
                        } 
                }   
               
                for(multimap<string,string>::iterator k=lista_var.begin();k!=lista_var.end();k++){
                        if(aFostPusDeja[k->second]==false){
                                continut = make_tuple(k->second, temporar, "VAR","", 0/*alt var pt depth*/);
                                symbol_table.insert(make_pair(numeFunctieCuSignatura,continut)); 
                        } 
                }         
                int nr=0;
                for (iterator_symbol_table = symbol_table.begin(); iterator_symbol_table != symbol_table.end(); iterator_symbol_table++) {
                        
                        if(iterator_symbol_table->first=="GLOBAL" && get<0>(iterator_symbol_table->second)==numeFunctieCuSignatura){
                                nr++;
                                //cout<<get<0>(iterator_symbol_table->second)<<' '<<numeFunctieCuSignatura<<endl;
                                 if(nr>=1){
                                       //cout<<nr;
                                        printf("Doua functii nu pot avea aceasi signatura si acelasi nume! la linia %d\n",yylineno);
                                        return -2;
                                } 
                        }
                
                }

                temporar.clear();
                string s1,s2,s3,s4;
                for(auto n : lista_fct_init){
                        
                        temporar.insert(make_pair("0",get<2>(n)));
                        continut = make_tuple(get<1>(n),temporar,get<3>(n),get<0>(n), 0/*alt var pt depth*/);
                        symbol_table.insert(make_pair(numeFunctieCuSignatura,continut));
                        temporar.clear();
                }
                temporar.clear();
                lista_fct_init.clear();

                //se verifca in lista de parametrii daca sunt duplicate
                string duplicate[100];
                int i=0;
                        for(unordered_multimap<string,tuple<string,multimap<string,string>,string,string,int>>::iterator iterator_symbol_table=symbol_table.begin();iterator_symbol_table!=symbol_table.end();iterator_symbol_table++){                                
                                        if(iterator_symbol_table->first==numeFunctieCuSignatura){
                                                
                                                duplicate[i]=get<0>(iterator_symbol_table->second);
                                                i++;
                                        } 
                        }
                for(int j=0;j<=i;j++){
                        for(int k=j+1;k<=i;k++){
                               
                                if(duplicate[j]==duplicate[k]){
                                         
                                        printf("Parametrii cu acelasi identificator la linia %d\n",yylineno);
                                        return -3; 
                                }
                        }
                }
            continut=make_tuple(numeFunctieCuSignatura, lista_var, "FCT", "string", 0);
            symbol_table.insert(make_pair("GLOBAL",continut)); 
            lista_var.clear();
              
       }
#line 2317 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 774 "limbaj.y" /* yacc.c:1646  */
    {
                multimap<string, string>temporar;
                temporar.insert(make_pair("0","NA-1"));

                string numeFunctieCuSignatura=(yyvsp[-6].strval);

                for (multimap<string, string>::iterator i = nume_valoare_parametru.begin(); i != nume_valoare_parametru.end(); ++i) {
                        //cout<<(i->first)<<' '<<i->second<<' ';
                }
                //cout<<endl;
                for (multimap<string, string>::iterator i = lista_var.begin(); i != lista_var.end(); ++i) {
                        numeFunctieCuSignatura+="_"+(i->first);
                }

                
                        //cout<<i->first<<' '<<i->second<<endl;
                for(multimap<string,string>::iterator j = nume_valoare_parametru.begin(); j!=nume_valoare_parametru.end();++j){
                                if(j->first!="-"){
                                        for (multimap<string, string>::iterator i = lista_var.begin(); i != lista_var.end(); ++i) {
                                                if(i->second==j->first){
                                                        //cout<<j->first<<' '<<j->second<<endl;
                                                        temporar.clear();
                                                        temporar.insert(make_pair("0",j->second));

                                                        continut = make_tuple(i->second, temporar, "VAR",i->first, 0/*alt var pt depth*/);
                                                        symbol_table.insert(make_pair(numeFunctieCuSignatura,continut));
                                                }
                                }
                        temporar.clear();
                        temporar.insert(make_pair("0","NA-1"));
                        }
                 }
                nume_valoare_parametru.clear(); 
                nume_valoare_parametru.insert(make_pair("-","-"));

                map<string,bool> aFostPusDeja;
                for(multimap<string,string>::iterator k=lista_var.begin();k!=lista_var.end();k++){
                        //cout<<k->first<<' '<<k->second<<' ';
                        for(unordered_multimap<string,tuple<string,multimap<string,string>,string,string,int>>::iterator iterator_symbol_table=symbol_table.begin();iterator_symbol_table!=symbol_table.end();iterator_symbol_table++){
                                if(iterator_symbol_table->first==numeFunctieCuSignatura && k->second==get<0>(iterator_symbol_table->second)){
                                        //cout<<k->second<<"=="<<get<0>(iterator_symbol_table->second)<<endl;
                                        aFostPusDeja.insert(make_pair(k->second,true));
                                }
                        }
                }

                temporar.clear();
                temporar.insert(make_pair("0","NA-1"));
                for(multimap<string,string>::iterator k=lista_var.begin();k!=lista_var.end();k++){
                        if(aFostPusDeja[k->second]!=true){
                                aFostPusDeja.insert(make_pair(k->second,false));
                                //cout<<k->second<<' '<<aFostPusDeja[k->second]<<' ';
                        } 
                }   
               
                for(multimap<string,string>::iterator k=lista_var.begin();k!=lista_var.end();k++){
                        if(aFostPusDeja[k->second]==false){
                                continut = make_tuple(k->second, temporar, "VAR","", 0/*alt var pt depth*/);
                                symbol_table.insert(make_pair(numeFunctieCuSignatura,continut)); 
                        } 
                }         
                int nr=0;
                for (iterator_symbol_table = symbol_table.begin(); iterator_symbol_table != symbol_table.end(); iterator_symbol_table++) {
                        
                        if(iterator_symbol_table->first=="GLOBAL" && get<0>(iterator_symbol_table->second)==numeFunctieCuSignatura){
                                nr++;
                                //cout<<get<0>(iterator_symbol_table->second)<<' '<<numeFunctieCuSignatura<<endl;
                                 if(nr>=1){
                                        //cout<<nr;
                                        printf("Doua functii nu pot avea aceasi signatura si acelasi nume! la linia %d\n",yylineno);
                                        return -2;
                                } 
                        }
                
                }

                temporar.clear();
                for(auto n : lista_fct_init){
                        
                        temporar.insert(make_pair("0",get<2>(n)));
                        continut = make_tuple(get<1>(n),temporar,get<3>(n),get<0>(n), 0/*alt var pt depth*/);
                        symbol_table.insert(make_pair(numeFunctieCuSignatura,continut));
                        temporar.clear();
                }
                temporar.clear();
                lista_fct_init.clear();

                //se verifca in lista de parametrii daca sunt duplicate
                string duplicate[100];
                int i=0;
                        for(unordered_multimap<string,tuple<string,multimap<string,string>,string,string,int>>::iterator iterator_symbol_table=symbol_table.begin();iterator_symbol_table!=symbol_table.end();iterator_symbol_table++){                                
                                        if(iterator_symbol_table->first==numeFunctieCuSignatura){
                                                
                                                duplicate[i]=get<0>(iterator_symbol_table->second);
                                                i++;
                                        } 
                        }
                for(int j=0;j<=i;j++){
                        for(int k=j+1;k<=i;k++){
                               
                                if(duplicate[j]==duplicate[k]){
                                         
                                        printf("Parametrii cu acelasi identificator la linia %d\n",yylineno);
                                        return -3; 
                                }
                        }
                }
            continut=make_tuple(numeFunctieCuSignatura, lista_var, "FCT", "bool", 0);
            symbol_table.insert(make_pair("GLOBAL",continut)); 
            lista_var.clear();
              
       }
#line 2434 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 889 "limbaj.y" /* yacc.c:1646  */
    {                  
                lista_var.insert(make_pair("int", (yyvsp[-3].strval)));
          }
#line 2442 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 893 "limbaj.y" /* yacc.c:1646  */
    {    
                lista_var.insert(make_pair("float", (yyvsp[-3].strval)));
          }
#line 2450 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 897 "limbaj.y" /* yacc.c:1646  */
    {
                lista_var.insert(make_pair("char", (yyvsp[-3].strval)));
          }
#line 2458 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 901 "limbaj.y" /* yacc.c:1646  */
    {
                lista_var.insert(make_pair("string", (yyvsp[-2].strval)));
          }
#line 2466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 905 "limbaj.y" /* yacc.c:1646  */
    {
                lista_var.insert(make_pair("bool", (yyvsp[-3].strval)));
          }
#line 2474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 910 "limbaj.y" /* yacc.c:1646  */
    {
                lista_var.insert(make_pair("int", (yyvsp[-1].strval)));
          }
#line 2482 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 914 "limbaj.y" /* yacc.c:1646  */
    {
                lista_var.insert(make_pair("float", (yyvsp[-1].strval)));
          }
#line 2490 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 918 "limbaj.y" /* yacc.c:1646  */
    {
                lista_var.insert(make_pair("char", (yyvsp[-1].strval)));
          }
#line 2498 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 922 "limbaj.y" /* yacc.c:1646  */
    {
                lista_var.insert(make_pair("string", (yyvsp[0].strval)));
          }
#line 2506 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 926 "limbaj.y" /* yacc.c:1646  */
    {
                lista_var.insert(make_pair("bool", (yyvsp[-1].strval)));
          }
#line 2514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 931 "limbaj.y" /* yacc.c:1646  */
    {
                lista_var.insert(make_pair("char", (yyvsp[-6].strval)));

          }
#line 2523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 937 "limbaj.y" /* yacc.c:1646  */
    {
                lista_var.insert(make_pair("char", (yyvsp[-4].strval)));

          }
#line 2532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 943 "limbaj.y" /* yacc.c:1646  */
    {     
                //cout<<"merge"<<$<strval>2<<' ';
                nume_valoare_parametru[(yyvsp[-5].strval)]=(yyvsp[-2].strval);  
                lista_var.insert(make_pair("char", (yyvsp[-5].strval)));
          }
#line 2542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 950 "limbaj.y" /* yacc.c:1646  */
    {
                //cout<<"merge"<<$<strval>2<<' ';  
                nume_valoare_parametru[(yyvsp[-3].strval)]=(yyvsp[0].strval);    
                lista_var.insert(make_pair("char", (yyvsp[-3].strval)));

          }
#line 2553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 957 "limbaj.y" /* yacc.c:1646  */
    {
                nume_valoare_parametru[(yyvsp[-5].strval)]=(yyvsp[-2].strval);    
                lista_var.insert(make_pair("int", (yyvsp[-5].strval)));

          }
#line 2563 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 963 "limbaj.y" /* yacc.c:1646  */
    {
                nume_valoare_parametru[(yyvsp[-5].strval)]=(yyvsp[-2].strval);    
                lista_var.insert(make_pair("float", (yyvsp[-5].strval)));

          }
#line 2573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 969 "limbaj.y" /* yacc.c:1646  */
    {
                nume_valoare_parametru[(yyvsp[-5].strval)]=(yyvsp[-2].strval);    
                lista_var.insert(make_pair("string", (yyvsp[-5].strval)));

          }
#line 2583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 975 "limbaj.y" /* yacc.c:1646  */
    {
                //cout<<$<strval>5;
                nume_valoare_parametru[(yyvsp[-5].strval)]=(yyvsp[-2].strval);
                lista_var.insert(make_pair("bool", (yyvsp[-5].strval)));
          }
#line 2593 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 981 "limbaj.y" /* yacc.c:1646  */
    { 
                nume_valoare_parametru[(yyvsp[-3].strval)]=(yyvsp[0].strval);
                lista_var.insert(make_pair("int", (yyvsp[-3].strval)));

          }
#line 2603 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 987 "limbaj.y" /* yacc.c:1646  */
    {
                nume_valoare_parametru[(yyvsp[-3].strval)]=(yyvsp[0].strval);
                lista_var.insert(make_pair("float", (yyvsp[-3].strval)));

          }
#line 2613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 993 "limbaj.y" /* yacc.c:1646  */
    {
                nume_valoare_parametru[(yyvsp[-3].strval)]=(yyvsp[0].strval);
                lista_var.insert(make_pair("string", (yyvsp[-3].strval)));

          }
#line 2623 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 999 "limbaj.y" /* yacc.c:1646  */
    {
                nume_valoare_parametru[(yyvsp[-3].strval)]=(yyvsp[0].strval);
                lista_var.insert(make_pair("bool", (yyvsp[-3].strval)));
          }
#line 2632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 1005 "limbaj.y" /* yacc.c:1646  */
    {
                multimap<string,string> temporar,temporar2;
                temporar2.insert(make_pair("0","NA-1"));
                for(auto i : lista_fct_init){
                        temporar.insert(make_pair(get<0>(i),get<1>(i)));

                        continut=make_tuple(get<1>(i),lista_var, "VAR", get<0>(i), 0);
                        symbol_table.insert(make_pair((yyvsp[-3].strval),continut)); 
                }
                for(auto g: lista_global_init){
                        temporar.insert(make_pair(get<0>(g),get<1>(g)));

                        continut=make_tuple(get<1>(g), lista_var, "FCT", get<0>(g), 0);
                        symbol_table.insert(make_pair((yyvsp[-3].strval),continut)); 
                }
                continut=make_tuple((yyvsp[-3].strval), temporar, "CLS", "0", 0);
                symbol_table.insert(make_pair("GLOBAL",continut)); 
                temporar.clear();
                lista_fct_init.clear();
                lista_global_init.clear();

        }
#line 2659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 1029 "limbaj.y" /* yacc.c:1646  */
    {
                        (yyval.strval)=(yyvsp[-5].strval);
              }
#line 2667 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 1034 "limbaj.y" /* yacc.c:1646  */
    {
                string numeMetodaCuSignatura=(yyvsp[-7].strval);
                for(auto v:lista_var){
                        numeMetodaCuSignatura+=("_"+get<0>(v));
                }
                lista_global_init.insert(make_tuple("int",numeMetodaCuSignatura,"FCT","0"));
                lista_var.clear();
             }
#line 2680 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 1043 "limbaj.y" /* yacc.c:1646  */
    {
                      string numeMetodaCuSignatura=(yyvsp[-7].strval);
                for(auto v:lista_var){
                        numeMetodaCuSignatura+=("_"+get<0>(v));
                }
                lista_global_init.insert(make_tuple("float",numeMetodaCuSignatura,"FCT","0"));
                lista_var.clear();
             }
#line 2693 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 1052 "limbaj.y" /* yacc.c:1646  */
    {
                      string numeMetodaCuSignatura=(yyvsp[-7].strval);
                for(auto v:lista_var){
                        numeMetodaCuSignatura+=("_"+get<0>(v));
                }
                lista_global_init.insert(make_tuple("char",numeMetodaCuSignatura,"FCT","0"));
                lista_var.clear();
             }
#line 2706 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 1061 "limbaj.y" /* yacc.c:1646  */
    {
                      string numeMetodaCuSignatura=(yyvsp[-7].strval);
                for(auto v:lista_var){
                        numeMetodaCuSignatura+=("_"+get<0>(v));
                }
                lista_global_init.insert(make_tuple("string",numeMetodaCuSignatura,"FCT","0"));
                lista_var.clear();
             }
#line 2719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 1070 "limbaj.y" /* yacc.c:1646  */
    {
                      string numeMetodaCuSignatura=(yyvsp[-7].strval);
                for(auto v:lista_var){
                        numeMetodaCuSignatura+=("_"+get<0>(v));
                }
                lista_global_init.insert(make_tuple("bool",numeMetodaCuSignatura,"FCT","0"));
                lista_var.clear();
             }
#line 2732 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 1080 "limbaj.y" /* yacc.c:1646  */
    {
                      string numeMetodaCuSignatura=(yyvsp[-6].strval);
                for(auto v:lista_var){
                        numeMetodaCuSignatura+=("_"+get<0>(v));
                }
                lista_global_init.insert(make_tuple("int",numeMetodaCuSignatura,"FCT","0"));
                lista_var.clear();
             }
#line 2745 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 1089 "limbaj.y" /* yacc.c:1646  */
    {
                      string numeMetodaCuSignatura=(yyvsp[-6].strval);
                for(auto v:lista_var){
                        numeMetodaCuSignatura+=("_"+get<0>(v));
                }
                lista_global_init.insert(make_tuple("float",numeMetodaCuSignatura,"FCT","0"));
                lista_var.clear();
             }
#line 2758 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 1098 "limbaj.y" /* yacc.c:1646  */
    {
                      string numeMetodaCuSignatura=(yyvsp[-6].strval);
                for(auto v:lista_var){
                        numeMetodaCuSignatura+=("_"+get<0>(v));
                }
                lista_global_init.insert(make_tuple("char",numeMetodaCuSignatura,"FCT","0"));
                lista_var.clear();
             }
#line 2771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 1107 "limbaj.y" /* yacc.c:1646  */
    {
                      string numeMetodaCuSignatura=(yyvsp[-6].strval);
                for(auto v:lista_var){
                        numeMetodaCuSignatura+=("_"+get<0>(v));
                }
                lista_global_init.insert(make_tuple("string",numeMetodaCuSignatura,"FCT","0"));
                lista_var.clear();
             }
#line 2784 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 1116 "limbaj.y" /* yacc.c:1646  */
    {
                      string numeMetodaCuSignatura=(yyvsp[-6].strval);
                for(auto v:lista_var){
                        numeMetodaCuSignatura+=("_"+get<0>(v));
                }
                lista_global_init.insert(make_tuple("bool",numeMetodaCuSignatura,"FCT","0"));
                lista_var.clear();
             }
#line 2797 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 1128 "limbaj.y" /* yacc.c:1646  */
    {
                multimap<string,string> temporar;
                for(auto n : lista_fct_init){
                        
                       // cout<<get<1>(n)<<endl;
                        temporar.insert(make_pair("0",get<2>(n)));
                        continut=make_tuple(get<1>(n), temporar, "VAR", get<0>(n), 0);
                        symbol_table.insert(make_pair("MAIN",continut)); 
                        temporar.clear();                                        
                        
                }
               //cout<<$<strval>3<<endl; 
        }
#line 2815 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 1143 "limbaj.y" /* yacc.c:1646  */
    {
                        (yyval.strval)=(yyvsp[-1].strval);
                        
                        //cout<<$<strval>1<<endl;

                }
#line 2826 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1156 "limbaj.y" /* yacc.c:1646  */
    {
                     //cout<<$<strval>1<<endl;
                     (yyval.strval)=(yyvsp[0].strval);
             }
#line 2835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1170 "limbaj.y" /* yacc.c:1646  */
    {       //cout<<$<strval>2<<endl;
                    (yyval.strval)=(yyvsp[0].strval);
            }
#line 2843 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1174 "limbaj.y" /* yacc.c:1646  */
    {
                    (yyval.strval)=(yyvsp[0].strval);
            }
#line 2851 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1178 "limbaj.y" /* yacc.c:1646  */
    {
                    (yyval.strval)=(yyvsp[0].strval);
            }
#line 2859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1182 "limbaj.y" /* yacc.c:1646  */
    {
                    (yyval.strval)=(yyvsp[0].strval);
            }
#line 2867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 1186 "limbaj.y" /* yacc.c:1646  */
    {
                    //cout<<$<strval>2;
                    (yyval.strval)=(yyvsp[0].strval);
            }
#line 2876 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1193 "limbaj.y" /* yacc.c:1646  */
    {
                        (yyval.strval)=(yyvsp[-1].strval);
                  }
#line 2884 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1197 "limbaj.y" /* yacc.c:1646  */
    {
                        (yyval.strval)=(yyvsp[-1].strval);

                  }
#line 2893 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 1202 "limbaj.y" /* yacc.c:1646  */
    {
                        (yyval.strval)=(yyvsp[-1].strval);

                  }
#line 2902 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 1207 "limbaj.y" /* yacc.c:1646  */
    {
                        (yyval.strval)=(yyvsp[-1].strval);

                  }
#line 2911 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 1212 "limbaj.y" /* yacc.c:1646  */
    {

                        (yyval.strval)=(yyvsp[-1].strval);
                  }
#line 2920 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 1217 "limbaj.y" /* yacc.c:1646  */
    {
                        (yyval.strval)=(yyvsp[0].strval);
                  }
#line 2928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 1226 "limbaj.y" /* yacc.c:1646  */
    {
                 for(auto l:lista_fct_init){
                        if((yyvsp[-3].strval)==get<1>(l)){
                                printf("1.Rescriere variabila intr-o initializare la linia %d\n",yylineno);
                                return -5;
                        }
                } 
                lista_fct_init.insert(make_tuple("int",(yyvsp[-3].strval),"NA-1","VAR"));
                lista_if_init.insert(make_tuple("int",(yyvsp[-3].strval),"NA-1","VAR"));

               
        }
#line 2945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 1239 "limbaj.y" /* yacc.c:1646  */
    {
                
                 for(auto l:lista_fct_init){
                        if((yyvsp[-4].strval)==get<1>(l)){
                                printf("2.Rescriere variabila intr-o initializare la linia %d\n",yylineno);
                                return -5;
                        }
                } 
                
                (yyval.strval)=(yyvsp[-2].strval);
                lista_fct_init.insert(make_tuple("int",(yyvsp[-4].strval),(yyvsp[-2].strval),"VAR"));
                 lista_if_init.insert(make_tuple("int",(yyvsp[-4].strval),(yyvsp[-2].strval),"VAR"));

                
                
        }
#line 2966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 1256 "limbaj.y" /* yacc.c:1646  */
    {
                for(auto l:lista_fct_init){
                        if((yyvsp[-1].strval)==get<1>(l)){
                                printf("3.Rescriere variabila intr-o initializare la linia %d\n",yylineno);
                                return -5;
                        }
                } 
                lista_fct_init.insert(make_tuple("int",(yyvsp[-1].strval),"NA-1","VAR"));
                lista_if_init.insert(make_tuple("int",(yyvsp[-1].strval),"NA-1","VAR"));

                
        }
#line 2983 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 1269 "limbaj.y" /* yacc.c:1646  */
    {

                for(auto l:lista_fct_init){
                        if((yyvsp[-2].strval)==get<1>(l)){
                                printf("4.Rescriere variabila intr-o initializare la linia %d\n",yylineno);
                                return -5;
                        }
                } 
                (yyval.strval)=(yyvsp[0].strval);
                lista_fct_init.insert(make_tuple("int",(yyvsp[-2].strval),(yyvsp[0].strval),"VAR"));
                 lista_if_init.insert(make_tuple("int",(yyvsp[-2].strval),(yyvsp[0].strval),"VAR"));


        }
#line 3002 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 1285 "limbaj.y" /* yacc.c:1646  */
    {
               
               for(auto l:lista_fct_init){
                        if((yyvsp[-3].strval)==get<1>(l)){
                                printf("5.Rescriere variabila intr-o initializare la linia %d\n",yylineno);
                                return -5;
                        }
                } 
                lista_fct_init.insert(make_tuple("float",(yyvsp[-3].strval),"NA-1","VAR"));
                lista_if_init.insert(make_tuple("float",(yyvsp[-3].strval),"NA-1","VAR"));
                
        }
#line 3019 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 1298 "limbaj.y" /* yacc.c:1646  */
    {
                
               for(auto l:lista_fct_init){
                        if((yyvsp[-4].strval)==get<1>(l)){
                                printf("6.Rescriere variabila intr-o initializare la linia %d\n",yylineno);
                                return -5;
                        }
                } 
                (yyval.strval)=(yyvsp[-2].strval);
                lista_fct_init.insert(make_tuple("float",(yyvsp[-4].strval),(yyvsp[-2].strval),"VAR"));
                lista_if_init.insert(make_tuple("float",(yyvsp[-4].strval),"NA-1","VAR"));

        }
#line 3037 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 1312 "limbaj.y" /* yacc.c:1646  */
    {
               
               for(auto l:lista_fct_init){
                        if((yyvsp[-1].strval)==get<1>(l)){
                                printf("7.Rescriere variabila intr-o initializare la linia %d\n",yylineno);
                                return -5;
                        }
                } 
                lista_fct_init.insert(make_tuple("float",(yyvsp[-1].strval),"NA-1","VAR"));
                lista_if_init.insert(make_tuple("float",(yyvsp[-1].strval),"NA-1","VAR"));

        }
#line 3054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 1325 "limbaj.y" /* yacc.c:1646  */
    {  
                
                (yyval.strval)=(yyvsp[0].strval);
                lista_fct_init.insert(make_tuple("float",(yyvsp[-2].strval),(yyvsp[0].strval),"VAR"));
                lista_if_init.insert(make_tuple("float",(yyvsp[-2].strval),"NA-1","VAR"));

        }
#line 3066 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 1335 "limbaj.y" /* yacc.c:1646  */
    {
                for(auto l:lista_fct_init){
                        if((yyvsp[-3].strval)==get<1>(l)){
                                printf("8.Rescriere variabila intr-o initializare la linia %d\n",yylineno);
                                return -5;
                        }
                } 
                lista_fct_init.insert(make_tuple("char",(yyvsp[-3].strval),"NA-1","VAR"));
                lista_if_init.insert(make_tuple("char",(yyvsp[-3].strval),"NA-1","VAR"));

         }
#line 3082 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 1347 "limbaj.y" /* yacc.c:1646  */
    {
                 for(auto l:lista_fct_init){
                        if((yyvsp[-4].strval)==get<1>(l)){
                                printf("9.Rescriere variabila intr-o initializare la linia %d\n",yylineno);
                                return -5;
                        }
                } 
                lista_fct_init.insert(make_tuple("char",(yyvsp[-4].strval),(yyvsp[-2].strval),"VAR"));
                lista_if_init.insert(make_tuple("char",(yyvsp[-4].strval),(yyvsp[-2].strval),"VAR"));

         }
#line 3098 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 1359 "limbaj.y" /* yacc.c:1646  */
    {
                 for(auto l:lista_fct_init){
                        if((yyvsp[-5].strval)==get<1>(l)){
                                printf("10.Rescriere variabila intr-o initializare la linia %d\n",yylineno);
                                return -5;
                        }
                } 
                lista_fct_init.insert(make_tuple("char",(yyvsp[-5].strval),(yyvsp[-3].strval),"VAR"));
                lista_if_init.insert(make_tuple("char",(yyvsp[-5].strval),(yyvsp[-3].strval),"VAR"));

         }
#line 3114 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 1371 "limbaj.y" /* yacc.c:1646  */
    {
                 for(auto l:lista_fct_init){
                        if((yyvsp[-1].strval)==get<1>(l)){
                                printf("11.Rescriere variabila intr-o initializare la linia %d\n",yylineno);
                                return -5;
                        }
                } 
                lista_fct_init.insert(make_tuple("char",(yyvsp[-1].strval),"NA-1","VAR"));
                lista_if_init.insert(make_tuple("char",(yyvsp[-1].strval),"NA-1","VAR"));

         }
#line 3130 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 1383 "limbaj.y" /* yacc.c:1646  */
    {
                 for(auto l:lista_fct_init){
                        if((yyvsp[-2].strval)==get<1>(l)){
                                printf("12.Rescriere variabila intr-o initializare la linia %d\n",yylineno);
                                return -5;
                        }
                } 
                lista_fct_init.insert(make_tuple("char",(yyvsp[-2].strval),(yyvsp[0].strval),"VAR"));
                lista_if_init.insert(make_tuple("char",(yyvsp[-2].strval),(yyvsp[0].strval),"VAR"));

         }
#line 3146 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 1395 "limbaj.y" /* yacc.c:1646  */
    {
                 for(auto l:lista_fct_init){
                        if((yyvsp[-3].strval)==get<1>(l)){
                                printf("13.Rescriere variabila intr-o initializare la linia %d\n",yylineno);
                                return -5;
                        }
                } 
                lista_fct_init.insert(make_tuple("char",(yyvsp[-3].strval),(yyvsp[-1].strval),"VAR"));
                lista_if_init.insert(make_tuple("char",(yyvsp[-3].strval),(yyvsp[-1].strval),"VAR"));

         }
#line 3162 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 1408 "limbaj.y" /* yacc.c:1646  */
    {
                   for(auto l:lista_fct_init){
                        if((yyvsp[-2].strval)==get<1>(l)){
                                printf("14.Rescriere variabila intr-o initializare la linia %d\n",yylineno);
                                return -5;
                        }
                } 
                lista_fct_init.insert(make_tuple("string",(yyvsp[-2].strval),"NA-1","VAR"));
                lista_if_init.insert(make_tuple("string",(yyvsp[-2].strval),"NA-1","VAR"));

           }
#line 3178 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 1420 "limbaj.y" /* yacc.c:1646  */
    {
                   for(auto l:lista_fct_init){
                        if((yyvsp[-4].strval)==get<1>(l)){
                                printf("15.Rescriere variabila intr-o initializare la linia %d\n",yylineno);
                                return -5;
                        }
                } 
                (yyval.strval)=(yyvsp[-2].strval);
                lista_fct_init.insert(make_tuple("string",(yyvsp[-4].strval),(yyvsp[-2].strval),"VAR"));
                lista_if_init.insert(make_tuple("string",(yyvsp[-4].strval),(yyvsp[-2].strval),"VAR"));
           }
#line 3194 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 1432 "limbaj.y" /* yacc.c:1646  */
    {
                   for(auto l:lista_fct_init){
                        if((yyvsp[0].strval)==get<1>(l)){
                                printf("16.Rescriere variabila intr-o initializare la linia %d\n",yylineno);
                                return -5;
                        }
                } 
                lista_fct_init.insert(make_tuple("string",(yyvsp[0].strval),"NA-1","VAR"));
                lista_if_init.insert(make_tuple("string",(yyvsp[0].strval),"NA-1","VAR"));

           }
#line 3210 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 1444 "limbaj.y" /* yacc.c:1646  */
    {
                   for(auto l:lista_fct_init){
                        if((yyvsp[-2].strval)==get<1>(l)){
                                printf("17.Rescriere variabila intr-o initializare la linia %d\n",yylineno);
                                return -5;
                        }
                } 
                (yyval.strval)=(yyvsp[0].strval);
                lista_fct_init.insert(make_tuple("string",(yyvsp[-2].strval),(yyvsp[0].strval),"VAR"));
                lista_if_init.insert(make_tuple("string",(yyvsp[-2].strval),(yyvsp[0].strval),"VAR"));

           }
#line 3227 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 1458 "limbaj.y" /* yacc.c:1646  */
    {
                  for(auto l:lista_fct_init){
                        if((yyvsp[-3].strval)==get<1>(l)){
                                printf("18.Rescriere variabila intr-o initializare la linia %d\n",yylineno);
                                return -5;
                        }
                } 
                lista_fct_init.insert(make_tuple("bool",(yyvsp[-3].strval),"NA-1","VAR"));
                lista_if_init.insert(make_tuple("bool",(yyvsp[-3].strval),"NA-1","VAR"));

          }
#line 3243 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 1470 "limbaj.y" /* yacc.c:1646  */
    {
                  for(auto l:lista_fct_init){
                        if((yyvsp[-5].strval)==get<1>(l)){
                                printf("19.Rescriere variabila intr-o initializare la linia %d\n",yylineno);
                                return -5;
                        }
                } 
                (yyval.strval)=(yyvsp[-2].strval);
                lista_fct_init.insert(make_tuple("bool",(yyvsp[-5].strval),(yyvsp[-2].strval),"VAR"));
                lista_if_init.insert(make_tuple("bool",(yyvsp[-5].strval),(yyvsp[-2].strval),"VAR"));

          }
#line 3260 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 1483 "limbaj.y" /* yacc.c:1646  */
    {
                  for(auto l:lista_fct_init){
                        if((yyvsp[-1].strval)==get<1>(l)){
                                printf("20.Rescriere variabila intr-o initializare la linia %d\n",yylineno);
                                return -5;
                        }
                } 
                lista_fct_init.insert(make_tuple("bool",(yyvsp[-1].strval),"NA-1","VAR"));
                lista_if_init.insert(make_tuple("bool",(yyvsp[-1].strval),"NA-1","VAR"));
          }
#line 3275 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 1494 "limbaj.y" /* yacc.c:1646  */
    {
                  for(auto l:lista_fct_init){
                        if((yyvsp[-3].strval)==get<1>(l)){
                                printf("21.Rescriere variabila intr-o initializare la linia %d\n",yylineno);
                                return -5;
                        }
                }

                (yyval.strval)=(yyvsp[0].strval);
                lista_fct_init.insert(make_tuple("bool",(yyvsp[-3].strval),(yyvsp[0].strval),"VAR"));
                lista_if_init.insert(make_tuple("bool",(yyvsp[-3].strval),(yyvsp[0].strval),"VAR"));
          }
#line 3292 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 1509 "limbaj.y" /* yacc.c:1646  */
    {

         }
#line 3300 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 1513 "limbaj.y" /* yacc.c:1646  */
    {

         }
#line 3308 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 1521 "limbaj.y" /* yacc.c:1646  */
    { 

                if(strchr((yyvsp[-3].strval),'.')!=NULL && strchr((yyvsp[-1].strval),'.')!=NULL){
                        sprintf((yyval.strval),"%.2f",(atof((yyvsp[-3].strval)) + atof((yyvsp[-1].strval)))); 
                }
                else 
                if(strchr((yyvsp[-3].strval),'\"')!=NULL && strchr((yyvsp[-1].strval),'\"')!=NULL){
                        char s[200],t[200];
                        strcpy(s,(yyvsp[-3].strval));
                        s[strlen(s)-1]='\0';
                        strcpy(t,(yyvsp[-1].strval)+1);

                        sprintf((yyval.strval),"%s",strcat(s,t)); 
                }
                else if(atoi((yyvsp[-3].strval))!=0 && atoi((yyvsp[-1].strval))!=0){
                        sprintf((yyval.strval),"%d",(atoi((yyvsp[-3].strval)) + atoi((yyvsp[-1].strval)))); 
                }
                else{
                     printf("Eroare de tipuri diferite in expresie deasupra liniei %d\n ",yylineno);
                        return -11;
                }
                
        }
#line 3336 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 1545 "limbaj.y" /* yacc.c:1646  */
    {
                if(strchr((yyvsp[-3].strval),'.')!=NULL && strchr((yyvsp[-3].strval),'.')!=NULL){
                        sprintf((yyval.strval),"%.2f",(atof((yyvsp[-3].strval)) - atof((yyvsp[-1].strval)))); 
                }
                else
                sprintf((yyval.strval),"%d",(atoi((yyvsp[-3].strval)) - atoi((yyvsp[-1].strval))));
        }
#line 3348 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 1553 "limbaj.y" /* yacc.c:1646  */
    {
                if(strchr((yyvsp[-3].strval),'.')!=NULL && strchr((yyvsp[-3].strval),'.')!=NULL){
                        sprintf((yyval.strval),"%.2f",(atof((yyvsp[-3].strval)) / atof((yyvsp[-1].strval)))); 
                }
                else sprintf((yyval.strval),"%d",(atoi((yyvsp[-3].strval)) / atoi((yyvsp[-1].strval)))); 
        }
#line 3359 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 1560 "limbaj.y" /* yacc.c:1646  */
    {
                if(strchr((yyvsp[-3].strval),'.')!=NULL && strchr((yyvsp[-3].strval),'.')!=NULL){
                        sprintf((yyval.strval),"%.2f",(atof((yyvsp[-3].strval)) * atof((yyvsp[-1].strval)))); 
                }
                else sprintf((yyval.strval),"%d",(atoi((yyvsp[-3].strval)) * atoi((yyvsp[-1].strval)))); 
        }
#line 3370 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 1567 "limbaj.y" /* yacc.c:1646  */
    {
          (yyval.strval)=(yyvsp[0].strval);
        }
#line 3378 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 1571 "limbaj.y" /* yacc.c:1646  */
    {
         (yyval.strval)=(yyvsp[0].strval);
        }
#line 3386 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1575 "limbaj.y" /* yacc.c:1646  */
    {
         (yyval.strval)=(yyvsp[0].strval);
        }
#line 3394 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1579 "limbaj.y" /* yacc.c:1646  */
    {
                
          for(auto i:symbol_table){
                  if(i.first=="GLOBAL"  && get<0>(i.second)==(yyvsp[-1].strval)){
                        //cout<<get<0>(i.second);
                         for(auto j:(get<1>(i.second)))
                                strcpy((yyval.strval),j.second.c_str());
                  }
          }
         
          
        }
#line 3411 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1592 "limbaj.y" /* yacc.c:1646  */
    {
                (yyval.strval)=0;
        }
#line 3419 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1596 "limbaj.y" /* yacc.c:1646  */
    {
                (yyval.strval)=0;
        }
#line 3427 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1602 "limbaj.y" /* yacc.c:1646  */
    {
                     if(strcmp((yyvsp[-2].strval),"DO")==0){
                              (yyval.strval)="DO";
                     }
                     else  (yyval.strval)=(yyvsp[-1].strval);
             }
#line 3438 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1609 "limbaj.y" /* yacc.c:1646  */
    {
                     if(strcmp((yyvsp[-2].strval),"FA")==0){
                              (yyval.strval)="FA";
                     }
                     else  (yyval.strval)=(yyvsp[-1].strval);
             }
#line 3449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1616 "limbaj.y" /* yacc.c:1646  */
    {
                
             }
#line 3457 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1620 "limbaj.y" /* yacc.c:1646  */
    {

             }
#line 3465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1624 "limbaj.y" /* yacc.c:1646  */
    {

             }
#line 3473 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 1628 "limbaj.y" /* yacc.c:1646  */
    {

             }
#line 3481 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 1632 "limbaj.y" /* yacc.c:1646  */
    {
                     if(strcmp((yyvsp[-1].strval),"DO")==0){
                             (yyval.strval)="FA";
                     }
                     else (yyval.strval)="DO";
             }
#line 3492 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 1639 "limbaj.y" /* yacc.c:1646  */
    {
                     
                if(strcmp((yyvsp[-2].strval),"<<")==0){
                      if(atoi((yyvsp[-3].strval)) < atoi((yyvsp[-1].strval))){
                            (yyval.strval)="DO";
                      }
                      else (yyval.strval)="FA";
                }
                if(strcmp((yyvsp[-2].strval),">>")==0){
                        if(atoi((yyvsp[-3].strval)) > atoi((yyvsp[-1].strval))){
                            (yyval.strval)="DO";
                      }
                      else (yyval.strval)="FA";
                        
                }
                if(strcmp((yyvsp[-2].strval),"?=")==0){
                        if(atoi((yyvsp[-3].strval)) == atoi((yyvsp[-1].strval))){
                            (yyval.strval)="DO";
                      }
                      else (yyval.strval)="FA";
                        
                }
                if(strcmp((yyvsp[-2].strval),"<=")==0){
                        if(atoi((yyvsp[-3].strval)) <= atoi((yyvsp[-1].strval))){
                            (yyval.strval)="DO";
                      }
                      else (yyval.strval)="FA";
                        
                }
                if(strcmp((yyvsp[-2].strval),">=")==0){
                        if(atoi((yyvsp[-3].strval)) >= atoi((yyvsp[-1].strval))){
                            (yyval.strval)="DO";
                      }
                      else (yyval.strval)="FA";
                        
                }
                if(strcmp((yyvsp[-2].strval),"=|=")==0){
                        if(atoi((yyvsp[-3].strval)) != atoi((yyvsp[-1].strval))){
                            (yyval.strval)="DO";
                      }
                      else (yyval.strval)="FA";
                        
                }
             }
#line 3541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 1684 "limbaj.y" /* yacc.c:1646  */
    {
                (yyval.strval)=(yyvsp[0].strval);
             }
#line 3549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 1690 "limbaj.y" /* yacc.c:1646  */
    {
                (yyval.strval)=(yyvsp[-1].strval);
        }
#line 3557 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 1694 "limbaj.y" /* yacc.c:1646  */
    {
                (yyval.strval)=(yyvsp[0].strval); 
        }
#line 3565 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 1698 "limbaj.y" /* yacc.c:1646  */
    {
                (yyval.strval)=(yyvsp[0].strval);
        }
#line 3573 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 1702 "limbaj.y" /* yacc.c:1646  */
    {
                (yyval.strval)=0;
        }
#line 3581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 1706 "limbaj.y" /* yacc.c:1646  */
    {
                (yyval.strval)=0;
        }
#line 3589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 1711 "limbaj.y" /* yacc.c:1646  */
    {
                      (yyval.strval)=(yyvsp[0].strval);
             }
#line 3597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1715 "limbaj.y" /* yacc.c:1646  */
    {
                     (yyval.strval)=(yyvsp[0].strval);
             }
#line 3605 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1719 "limbaj.y" /* yacc.c:1646  */
    {
                     (yyval.strval)=(yyvsp[0].strval);
             }
#line 3613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 1723 "limbaj.y" /* yacc.c:1646  */
    {
                     (yyval.strval)=(yyvsp[0].strval);
             }
#line 3621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 1727 "limbaj.y" /* yacc.c:1646  */
    {
                     (yyval.strval)=(yyvsp[0].strval);
             }
#line 3629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 1731 "limbaj.y" /* yacc.c:1646  */
    {
                     (yyval.strval)=(yyvsp[0].strval);
             }
#line 3637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1743 "limbaj.y" /* yacc.c:1646  */
    {
                        
              }
#line 3645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1748 "limbaj.y" /* yacc.c:1646  */
    {
                multimap<string,string>temporar;
                for(auto n : lista_fct_init){
                        //cout<<get<1>(n)<<endl;
                        temporar.insert(make_pair("0",get<2>(n)));
                        int val;
                                for(unordered_multimap<string,tuple<string,multimap<string,string>,string,string,int>>::iterator iterator_symbol_table=symbol_table.begin();iterator_symbol_table!=symbol_table.end();iterator_symbol_table++){                                
                                        if(iterator_symbol_table->first=="MAIN"){
                                                if(get<1>(n)==get<0>(iterator_symbol_table->second)){
                                                      
                                                }
                                        } 
                                }
                
                        continut = make_tuple(get<1>(n),temporar,get<3>(n),get<0>(n), 0/*alt var pt depth*/);
                        symbol_table.insert(make_pair("IF"+to_string(nr_IF),continut));
                        temporar.clear();
                        nr_IF++;
                }
                lista_fct_init.clear();
           }
#line 3671 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1770 "limbaj.y" /* yacc.c:1646  */
    {
                multimap<string,string>temporar;
                for(auto n : lista_fct_init){
                        //cout<<get<1>(n)<<endl;
                        temporar.insert(make_pair("0",get<2>(n)));
                        int val;
                                for(unordered_multimap<string,tuple<string,multimap<string,string>,string,string,int>>::iterator iterator_symbol_table=symbol_table.begin();iterator_symbol_table!=symbol_table.end();iterator_symbol_table++){                                
                                        if(iterator_symbol_table->first=="MAIN"){
                                                if(get<1>(n)==get<0>(iterator_symbol_table->second)){
                                                      
                                                }
                                        } 
                                }
                
                        continut = make_tuple(get<1>(n),temporar,get<3>(n),get<0>(n), 0/*alt var pt depth*/);
                        symbol_table.insert(make_pair("IF"+to_string(nr_IF),continut));
                        temporar.clear();
                }
                lista_fct_init.clear();
                nr_IF++;

           }
#line 3698 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 1799 "limbaj.y" /* yacc.c:1646  */
    {
                signaturaApel=(yyvsp[-3].strval)+signaturaApel;
                //cout<<signaturaApel;
                bool isDefinedandSignature=false;
                for(auto g:symbol_table)
                {
                        //cout<<g.first<<endl;
                        if(signaturaApel==g.first){     
                                isDefinedandSignature=true;
                        }
                }
                signaturaApel="";
                if(isDefinedandSignature==false){
                        printf("Functia nu are aceasi signatura sau nu este definita!");
                        return -9;
                }
        }
#line 3720 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1819 "limbaj.y" /* yacc.c:1646  */
    {
                           signaturaApel="_char"+signaturaApel;
                           //cout<<signaturaApel;
                   }
#line 3729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1824 "limbaj.y" /* yacc.c:1646  */
    {

                           if(strchr((yyvsp[-2].strval),'.')!=NULL)
                           {
                                signaturaApel="_float"+signaturaApel;
                           }
                           else
                           if((yyvsp[-2].strval)[0]=='-' || (yyvsp[-2].strval)[0]=='0' || (yyvsp[-2].strval)[0]=='1'|| (yyvsp[-2].strval)[0]=='2' || (yyvsp[-2].strval)[0]=='3' || (yyvsp[-2].strval)[0]=='4' || (yyvsp[-2].strval)[0]=='5' || (yyvsp[-2].strval)[0]=='6' || (yyvsp[-2].strval)[0]=='7' || (yyvsp[-2].strval)[0]=='8' || (yyvsp[-2].strval)[0]=='9')
                           {
                                signaturaApel="_int"+signaturaApel;
                           }
                           else  signaturaApel="_string"+signaturaApel;
                           
                   }
#line 3748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1839 "limbaj.y" /* yacc.c:1646  */
    {
                        signaturaApel="_bool"+signaturaApel;
                   }
#line 3756 "y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1845 "limbaj.y" /* yacc.c:1646  */
    {
                           signaturaApel="_char"+signaturaApel;
                   }
#line 3764 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1849 "limbaj.y" /* yacc.c:1646  */
    {
                           if(strchr((yyvsp[0].strval),'.')!=NULL)
                           {
                                signaturaApel="_float"+signaturaApel;
                           }
                           else
                           if((yyvsp[0].strval)[0]=='-' || (yyvsp[0].strval)[0]=='0' || (yyvsp[0].strval)[0]=='1'|| (yyvsp[0].strval)[0]=='2' || (yyvsp[0].strval)[0]=='3' || (yyvsp[0].strval)[0]=='4' || (yyvsp[0].strval)[0]=='5' || (yyvsp[0].strval)[0]=='6' || (yyvsp[0].strval)[0]=='7' || (yyvsp[0].strval)[0]=='8' || (yyvsp[0].strval)[0]=='9')
                           {
                                signaturaApel="_int"+signaturaApel;
                           }
                           else signaturaApel="_string"+signaturaApel;
                           
                   }
#line 3782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1863 "limbaj.y" /* yacc.c:1646  */
    {
                           signaturaApel="_bool"+signaturaApel;
                   }
#line 3790 "y.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1869 "limbaj.y" /* yacc.c:1646  */
    {
                  bool isClassAlright=false;
                  for(auto x:symbol_table){
                          if((x.first)=="GLOBAL" && get<2>(x.second)=="CLS"){
                                if((yyvsp[-3].strval)==get<0>(x.second)){
                                         for(auto q:symbol_table){
                                                 if(q.first==(yyvsp[-3].strval) && get<0>(q.second)==(yyvsp[-1].strval)){
                                                       isClassAlright=true;
                                                 }
                                        }
                                }
                          }
                  }

                  if(isClassAlright==false){
                          printf("Obiect utilizat gresit la linia %d ",yylineno);
                          return -10;
                  }
          }
#line 3814 "y.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 1889 "limbaj.y" /* yacc.c:1646  */
    {
                  bool isClassAlright=false;
                  for(auto x:symbol_table){
                          if((x.first)=="GLOBAL" && get<2>(x.second)=="CLS"){
                                if((yyvsp[-2].strval)==get<0>(x.second)){
                                        for(auto q:symbol_table){
                                                 if(q.first==(yyvsp[-2].strval) && get<0>(q.second)==(yyvsp[0].strval)){
                                                       isClassAlright=true;
                                                 }
                                        }
                                }
                          }
                  }

                  if(isClassAlright==false){
                          printf("Obiect-functie utilizat gresit la linia %d ",yylineno);
                          return -10;
                  }
          }
#line 3838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 1911 "limbaj.y" /* yacc.c:1646  */
    {
                cout<<"Valoare returnata: "<<(yyvsp[-1].strval)<<endl;
        }
#line 3846 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 1915 "limbaj.y" /* yacc.c:1646  */
    {
                cout<<"Valoare returnata: "<<(yyvsp[-1].strval)<<endl;
        }
#line 3854 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3858 "y.tab.c" /* yacc.c:1646  */
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
#line 1920 "limbaj.y" /* yacc.c:1906  */

int yyerror(char * s){
printf("eroare: %s la linia:%d\n",s,yylineno);
}

int main(int argc, char** argv){
        
        yyin=fopen(argv[1],"r");
        yyparse();
}
