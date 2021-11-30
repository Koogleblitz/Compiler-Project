/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 18 "phase2.y"

   #include <stdio.h>
   #include <string.h>
   #include <stdlib.h>
   #include <vector>
   #include <map>
   #include <iostream>
   #include <sstream>
   #include <string>
   #include <cstring>
   using namespace std;

   void yyerror(const char *msg);
   int yylex(void);
   string indexifyTemp(void);
   string indexifyElse(void);
   string indexifyEndif(void);
   string indexifyLoopB(void);
   string indexifyLoopE(void);

   extern int currLine;
   int myError = 0;
   int otherError = 0;
   
   char *identToken;
   char *identToken2;
   //static int index = 0;
   //char tempNum[10] = "0123456789";
   int label = 1;
   int numberToken;
   int productionID = 0;

   char list_of_function_names[100][100];
   char* funcList[100];
   int  count_names = 0;


   int mainFunc = 0;
   int funcBool = 0;
   int zeroArrbool = 0;
   char *mainStr = "main";
   char *sub = "sub";
   char *add = "add";
   char *mult = "mult";
   char *zero = "0";
   


//#define YYDEBUG 1
//yydebug=1;

#line 122 "phase2.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PHASE2_TAB_H_INCLUDED
# define YY_YY_PHASE2_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    BEGIN_PARAMS = 258,
    END_PARAMS = 259,
    BEGIN_LOCALS = 260,
    END_LOCALS = 261,
    BEGIN_BODY = 262,
    END_BODY = 263,
    FUNCTION = 264,
    MAIN = 265,
    RETURN = 266,
    L_SQUARE_BRACKET = 267,
    R_SQUARE_BRACKET = 268,
    INTEGER = 269,
    ARRAY = 270,
    OF = 271,
    IF = 272,
    THEN = 273,
    ENDIF = 274,
    ELSE = 275,
    WHILE = 276,
    DO = 277,
    BEGINLOOP = 278,
    ENDLOOP = 279,
    CONTINUE = 280,
    READ = 281,
    WRITE = 282,
    AND = 283,
    OR = 284,
    NOT = 285,
    TRUE = 286,
    FALSE = 287,
    SUB = 288,
    ADD = 289,
    MULT = 290,
    DIV = 291,
    MOD = 292,
    EQ = 293,
    NEQ = 294,
    LT = 295,
    GT = 296,
    LTE = 297,
    GTE = 298,
    SEMICOLON = 299,
    COLON = 300,
    COMMA = 301,
    L_PAREN = 302,
    R_PAREN = 303,
    ASSIGN = 304,
    NUMBER = 305,
    IDENT = 306
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 76 "phase2.y"

  //int int_val;
  char* op_val;
  char *leaf;
  char container[30];

  char root[4000];
  
  struct nonTerminal 
  {
    char content[2000];
	char tempCode [2000];
	char name[10];
	char type[10];
	char val[15];
  } node;

  struct terminal 
  {
    char name[30];
	char content[200];
	char type[10];
  } term;

  

#line 253 "phase2.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PHASE2_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   192

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  173

#define YYUNDEFTOK  2
#define YYMAXUTOK   306


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   153,   153,   177,   184,   189,   212,   219,   228,   234,
     238,   242,   248,   275,   298,   302,   321,   326,   341,   352,
     366,   380,   395,   410,   417,   427,   450,   463,   497,   535,
     537,   543,   552,   562,   568,   577,   587,   589,   591,   595,
     602,   606,   614,   623,   671,   692,   701,   712,   723,   734,
     786,   800,   809,   817,   824,   828,   876,   879,   883,   896,
     904,   917,   924,   937,   971,   976,   978,   980,   982,   984,
     986,   990,   992,   994,   996,   998,  1000,  1003,  1013,  1028,
    1033
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BEGIN_PARAMS", "END_PARAMS",
  "BEGIN_LOCALS", "END_LOCALS", "BEGIN_BODY", "END_BODY", "FUNCTION",
  "MAIN", "RETURN", "L_SQUARE_BRACKET", "R_SQUARE_BRACKET", "INTEGER",
  "ARRAY", "OF", "IF", "THEN", "ENDIF", "ELSE", "WHILE", "DO", "BEGINLOOP",
  "ENDLOOP", "CONTINUE", "READ", "WRITE", "AND", "OR", "NOT", "TRUE",
  "FALSE", "SUB", "ADD", "MULT", "DIV", "MOD", "EQ", "NEQ", "LT", "GT",
  "LTE", "GTE", "SEMICOLON", "COLON", "COMMA", "L_PAREN", "R_PAREN",
  "ASSIGN", "NUMBER", "IDENT", "$accept", "prog_start", "functions",
  "function", "end_body", "paramlocal", "function_ident", "ident",
  "declarations", "declaration", "idents", "statement", "statements",
  "expression", "multiplicative_expression", "term", "expressions",
  "bool_exp", "relation_and_exp", "relation_exp", "comp", "var", "vars", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306
};
# endif

#define YYPACT_NINF (-56)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       1,   -33,    36,   -56,     1,   -12,   -56,   -56,   -56,   -56,
      91,   -56,   -56,   -56,   -56,   -56,    27,    30,    35,    91,
      42,    44,    86,    54,   -33,    91,    27,   100,   -56,   104,
      79,   -56,    27,   -56,   -56,    71,   120,    75,    91,   138,
     -56,   140,   108,    91,   139,   106,   122,    16,   143,   141,
     -56,   147,    60,    40,    40,   137,   -56,   -33,   -33,   151,
     121,   156,   117,   -56,   152,   119,    62,    60,   -56,     8,
     -56,   112,   -28,   -56,    52,   -56,   -56,    40,   101,   -13,
     144,   -56,   -17,    16,   125,   -56,   127,   -56,    60,    16,
     -56,   -56,    60,   153,   161,    60,   -56,   -56,   129,    60,
      60,    60,    60,    60,    60,   -56,   -56,    40,   101,    90,
     -27,   -56,   -56,   -56,   -56,   -56,   -56,    60,    16,    40,
      40,    16,   154,   -33,   -33,   162,   -56,   -56,   -56,   160,
     131,   -56,   -56,     2,   -56,   -56,   -56,   -56,   -56,    20,
      60,   -56,   -56,   128,   144,   -56,   157,   159,   136,   -56,
     142,   -56,   169,   -56,    60,   -56,   -56,   -56,   -56,    16,
     -56,    40,   -33,   -33,   -56,   -56,   165,   158,   145,   145,
     -56,   -33,   145
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     2,     4,     0,    13,    12,     1,     3,
       0,     7,     8,     9,    10,    11,    14,     0,    23,     0,
       0,     0,     0,     0,     0,     0,    14,     0,    17,     0,
       0,    24,    14,    15,    16,     0,     0,     0,     0,     0,
      18,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      19,     0,     0,     0,     0,     0,    38,     0,     0,    77,
       0,     0,     0,    20,     0,     0,     0,     0,    51,    77,
      39,    42,    45,    49,     0,    65,    67,     0,     0,     0,
      59,    61,     0,     0,    30,    36,    33,    37,     0,    40,
       6,     5,     0,     0,     0,     0,    52,    50,     0,    56,
       0,     0,     0,     0,     0,    66,    68,     0,     0,     0,
       0,    71,    72,    73,    74,    75,    76,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    41,    25,    21,     0,
       0,    53,    57,     0,    44,    43,    46,    47,    48,     0,
       0,    69,    63,     0,    60,    62,     0,     0,    31,    80,
      34,    78,     0,    54,     0,    55,    70,    64,    26,     0,
      28,     0,     0,     0,    22,    58,     0,    29,    32,    35,
      27,     0,    79
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -56,   -56,   181,   -56,   -56,    -8,   -56,    -1,    32,   -56,
     166,   -56,   -55,   -48,   -42,   -56,   -56,   -53,    67,    69,
      84,   -44,    92
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    91,    16,     5,    69,    19,    20,
      21,    60,    61,    78,    71,    72,   133,    79,    80,    81,
     117,    73,   149
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       7,    82,   119,    62,    70,   118,   121,   102,   103,   104,
       1,    25,   119,    84,    86,    18,   119,    32,     6,    98,
      88,   141,    97,    18,   110,    18,   108,    52,   122,   109,
      43,    18,    10,    53,   126,    47,     8,    54,    55,    62,
     125,    56,    57,    58,   127,    62,    59,   130,   154,   119,
     155,   132,   134,   135,   139,    99,    59,    59,    33,   109,
     136,   137,   138,   143,    38,    59,   146,     6,   156,   142,
      74,    75,    76,    66,    62,    22,    23,    62,    17,   148,
     150,    24,    59,   105,   106,    66,    26,    77,    59,    27,
      68,     6,   157,    66,    11,    12,    13,    14,    15,   107,
      28,    29,    68,     6,   166,    30,   165,    67,   167,    95,
      68,     6,    96,     6,    34,    62,    35,    59,   168,   169,
      59,    39,    59,    59,    36,    37,    42,   172,   111,   112,
     113,   114,   115,   116,    40,    41,    50,    51,   131,   111,
     112,   113,   114,   115,   116,   100,   101,   158,   159,    85,
      87,    44,    45,    46,    64,    48,    49,    63,    59,    65,
      83,    59,    59,    88,    90,    89,    92,   128,    93,    94,
      59,   123,   120,   124,   129,   151,   152,   131,   147,   153,
     161,   160,   162,   164,   170,     9,   144,   119,   163,   145,
      31,   171,   140
};

static const yytype_uint8 yycheck[] =
{
       1,    54,    29,    47,    52,    18,    23,    35,    36,    37,
       9,    19,    29,    57,    58,    16,    29,    25,    51,    67,
      12,    48,    66,    24,    77,    26,    74,    11,    83,    77,
      38,    32,    44,    17,    89,    43,     0,    21,    22,    83,
      88,    25,    26,    27,    92,    89,    47,    95,    46,    29,
      48,    99,   100,   101,   107,    47,    57,    58,    26,   107,
     102,   103,   104,   118,    32,    66,   121,    51,    48,   117,
      30,    31,    32,    33,   118,    45,    46,   121,    51,   123,
     124,    46,    83,    31,    32,    33,    44,    47,    89,    45,
      50,    51,   140,    33,     3,     4,     5,     6,     7,    47,
      14,    15,    50,    51,   159,    51,   154,    47,   161,    47,
      50,    51,    50,    51,    14,   159,    12,   118,   162,   163,
     121,    50,   123,   124,    45,    46,    51,   171,    38,    39,
      40,    41,    42,    43,    14,    15,    14,    15,    48,    38,
      39,    40,    41,    42,    43,    33,    34,    19,    20,    57,
      58,    13,    12,    45,    13,    16,    50,    14,   159,    12,
      23,   162,   163,    12,     8,    44,    49,    14,    16,    50,
     171,    46,    28,    46,    13,    13,    16,    48,    24,    48,
      21,    24,    46,    14,    19,     4,   119,    29,    46,   120,
      24,    46,   108
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     9,    53,    54,    55,    58,    51,    59,     0,    54,
      44,     3,     4,     5,     6,     7,    57,    51,    59,    60,
      61,    62,    45,    46,    46,    57,    44,    45,    14,    15,
      51,    62,    57,    60,    14,    12,    45,    46,    60,    50,
      14,    15,    51,    57,    13,    12,    45,    57,    16,    50,
      14,    15,    11,    17,    21,    22,    25,    26,    27,    59,
      63,    64,    73,    14,    13,    12,    33,    47,    50,    59,
      65,    66,    67,    73,    30,    31,    32,    47,    65,    69,
      70,    71,    69,    23,    73,    74,    73,    74,    12,    44,
       8,    56,    49,    16,    50,    47,    50,    73,    65,    47,
      33,    34,    35,    36,    37,    31,    32,    47,    65,    65,
      69,    38,    39,    40,    41,    42,    43,    72,    18,    29,
      28,    23,    64,    46,    46,    65,    64,    65,    14,    13,
      65,    48,    65,    68,    65,    65,    66,    66,    66,    69,
      72,    48,    65,    64,    70,    71,    64,    24,    73,    74,
      73,    13,    16,    48,    46,    48,    48,    65,    19,    20,
      24,    21,    46,    46,    14,    65,    64,    69,    73,    73,
      19,    46,    73
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    52,    53,    54,    54,    55,    56,    57,    57,    57,
      57,    57,    58,    59,    60,    60,    61,    61,    61,    61,
      61,    61,    61,    62,    62,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    63,
      64,    64,    65,    65,    65,    66,    66,    66,    66,    67,
      67,    67,    67,    67,    67,    67,    68,    68,    68,    69,
      69,    70,    70,    71,    71,    71,    71,    71,    71,    71,
      71,    72,    72,    72,    72,    72,    72,    73,    73,    74,
      74
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     0,    11,     1,     1,     1,     1,
       1,     1,     2,     1,     0,     3,     3,     3,     5,     7,
       8,    10,    12,     1,     3,     3,     5,     7,     5,     6,
       2,     4,     6,     2,     4,     6,     2,     2,     1,     2,
       2,     3,     1,     3,     3,     1,     3,     3,     3,     1,
       2,     1,     2,     3,     4,     4,     0,     1,     3,     1,
       3,     1,     3,     3,     4,     1,     2,     1,     2,     3,
       4,     1,     1,     1,     1,     1,     1,     1,     4,     1,
       3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
#line 154 "phase2.y"
                {
			if (mainFunc==0) {
        		yyerror("ERROR: no main function");
				yyerror("ERROR: no main function");
				yyerror("ERROR: no main function");
      		}
			else if (funcBool==1) {
        		yyerror("ERROR: call undefined function");
				yyerror("ERROR: call undefined function");
				yyerror("ERROR: call undefined function");
      		}
			else if (zeroArrbool==1) {
        		yyerror("ERROR: assigning number to zero-sized array");
				yyerror("ERROR: assigning number to zero-sized array");
				yyerror("ERROR: assigning number to zero-sized array");
      		}
			else{
				printf("%s",(yyvsp[0].root));	
			}
			
		}
#line 1572 "phase2.tab.c"
    break;

  case 3:
#line 178 "phase2.y"
                {
			strcpy((yyval.root), (yyvsp[-1].root));
			strcat((yyval.root), "\n");
			strcat((yyval.root), (yyvsp[0].root));
		}
#line 1582 "phase2.tab.c"
    break;

  case 4:
#line 184 "phase2.y"
                {
			strcpy((yyval.root), "");
		}
#line 1590 "phase2.tab.c"
    break;

  case 5:
#line 193 "phase2.y"
        {
		strcpy((yyval.root), "\nfunc ");
		strcat((yyval.root),	(yyvsp[-10].root));
		strcat((yyval.root), "\n");
		strcat((yyval.root), (yyvsp[-8].node).content);
		strcat((yyval.root), (yyvsp[-7].node).content);
		strcat((yyval.root), (yyvsp[-6].node).content);
		strcat((yyval.root), (yyvsp[-5].node).content);
		strcat((yyval.root), (yyvsp[-4].node).content);
		strcat((yyval.root), (yyvsp[-3].node).content);
		strcat((yyval.root), (yyvsp[-2].node).content);		
		strcat((yyval.root), (yyvsp[-1].node).content);
		strcat((yyval.root), (yyvsp[0].node).content);
		//strcat($$, "\nendfunc ");

	
	}
#line 1612 "phase2.tab.c"
    break;

  case 6:
#line 213 "phase2.y"
        {
   		//printf("endfunc\n");
   		strcpy((yyval.node).content, "endfunc");
	}
#line 1621 "phase2.tab.c"
    break;

  case 7:
#line 220 "phase2.y"
                {
			// char *token2 = identToken;
     		// printf("   _--%s--_\n   ", token2);

			//printf("BEGIN_PARAMS_--%s--_\n   ", $1.content);  
			strcpy((yyval.node).content, "");	
			
		}
#line 1634 "phase2.tab.c"
    break;

  case 8:
#line 229 "phase2.y"
                {
			// char *token2 = identToken;
     		// printf("   _--%s--_\n   ", token2);
			strcpy((yyval.node).content, "");	
		}
#line 1644 "phase2.tab.c"
    break;

  case 9:
#line 235 "phase2.y"
                {
			strcpy((yyval.node).content, "");	
		}
#line 1652 "phase2.tab.c"
    break;

  case 10:
#line 239 "phase2.y"
                {
			strcpy((yyval.node).content, "");	
		}
#line 1660 "phase2.tab.c"
    break;

  case 11:
#line 243 "phase2.y"
                {
			strcpy((yyval.node).content, "");	
		}
#line 1668 "phase2.tab.c"
    break;

  case 12:
#line 249 "phase2.y"
                {
    		char *token = identToken;
     		//printf("___%s___\n", token);

			if (strcmp(token, mainStr) == 0) { // match!
				mainFunc = 1;	
			}




     		 strcpy(list_of_function_names[count_names], token);
			 //strcpy(funcList[count_names], token);
     		 count_names++;

			 //strcpy($$, "func ");
			 strcpy((yyval.root), (yyvsp[0].node).content);
			 //strcpy(list_of_function_names[count_names], $2.content);




		}
#line 1696 "phase2.tab.c"
    break;

  case 13:
#line 276 "phase2.y"
                { 
			if ((yyvsp[0].leaf) == "main") {mainFunc = 1;	}
			strcpy((yyval.node).content, (yyvsp[0].leaf));
			strcpy((yyval.node).name, (yyvsp[0].leaf));
			//printf("%s",$$.content);
		}
#line 1707 "phase2.tab.c"
    break;

  case 14:
#line 298 "phase2.y"
                {
			/*These recursive rules are where the pneumonic errors are from, more specifically they come from epsilon where no code is there for the action*/
			strcpy((yyval.node).content, ""); 
		}
#line 1716 "phase2.tab.c"
    break;

  case 15:
#line 303 "phase2.y"
                {
			


			strcpy((yyval.node).content, (yyvsp[-2].node).content);
			//strcat($$.content, ", ");
			//strcat($$.content, "\n");
		  	strcat((yyval.node).content, (yyvsp[0].node).content);
		  	



			
			//printf("___%s___\n", $1.content);  
			//printf("ee__%s__bb\n", $1.content);  
		}
#line 1737 "phase2.tab.c"
    break;

  case 16:
#line 322 "phase2.y"
                {
		  	strcpy((yyval.node).content, (yyvsp[-2].node).content);
			//printf("IDlist identified");
		}
#line 1746 "phase2.tab.c"
    break;

  case 17:
#line 327 "phase2.y"
                {	

    	//    char *token = $1;
    	//    printf(". %s\n", token);



			strcpy((yyval.node).content, ". ");
			strcat((yyval.node).content, (yyvsp[-2].leaf));
			strcat((yyval.node).content, "\n");

			strcpy((yyval.node).name, (yyvsp[-2].leaf));

		}
#line 1765 "phase2.tab.c"
    break;

  case 18:
#line 342 "phase2.y"
                {
			strcpy((yyval.node).content, ". ");
			strcat((yyval.node).content, (yyvsp[-4].leaf));
			strcat((yyval.node).content, "\n");
			strcat((yyval.node).content, ". ");
			strcat((yyval.node).content, (yyvsp[-2].leaf));
			strcat((yyval.node).content, "\n");

			//strcpy($$.name, $1);
		}
#line 1780 "phase2.tab.c"
    break;

  case 19:
#line 353 "phase2.y"
                {
			strcpy((yyval.node).content, ". ");
			strcat((yyval.node).content, (yyvsp[-6].leaf));
			strcat((yyval.node).content, "\n");
			strcat((yyval.node).content, ". ");
			strcat((yyval.node).content, (yyvsp[-4].leaf));
			strcat((yyval.node).content, "\n");
			strcat((yyval.node).content, ". ");
			strcat((yyval.node).content, (yyvsp[-2].leaf));
			strcat((yyval.node).content, "\n");

			//strcpy($$.name, $1);
		}
#line 1798 "phase2.tab.c"
    break;

  case 20:
#line 367 "phase2.y"
                {
			strcpy((yyval.node).content, ". [] _" );			
			strcat((yyval.node).content, (yyvsp[-7].leaf));
			strcat((yyval.node).content, ", ");			
			strcat((yyval.node).content, (yyvsp[-3].leaf));	
			strcat((yyval.node).content, "\n");	

			//printf("number: %s", $5);
			if (strcmp((yyvsp[-3].leaf), zero) == 0) { 
				zeroArrbool = 1;	
			
			}		
		}
#line 1816 "phase2.tab.c"
    break;

  case 21:
#line 381 "phase2.y"
                {
			strcpy((yyval.node).content, ". [] _" );			
			strcat((yyval.node).content, (yyvsp[-9].leaf));
			strcat((yyval.node).content, ", .");
			strcat((yyval.node).content, (yyvsp[-7].leaf));
			strcat((yyval.node).content, ", .");			
			strcat((yyval.node).content, (yyvsp[-3].leaf));	
			strcat((yyval.node).content, "\n");		

			//printf("number: %s", $7);
			if (strcmp((yyvsp[-3].leaf), zero) == 0) { 
				zeroArrbool = 1;	
			}		
		}
#line 1835 "phase2.tab.c"
    break;

  case 22:
#line 396 "phase2.y"
                {
			strcpy((yyval.node).content, ". [] _" );			
			strcat((yyval.node).content, (yyvsp[-11].leaf));
			strcat((yyval.node).content, ", _");
			strcat((yyval.node).content, (yyvsp[-9].leaf));
			strcat((yyval.node).content, ", _");
			strcat((yyval.node).content, (yyvsp[-7].leaf));
			strcat((yyval.node).content, ", _");			
			strcat((yyval.node).content, (yyvsp[-3].leaf));	
			strcat((yyval.node).content, "\n");				
		}
#line 1851 "phase2.tab.c"
    break;

  case 23:
#line 411 "phase2.y"
                {
			strcpy((yyval.node).content, "_");
			strcat((yyval.node).content, (yyvsp[0].node).content);

			strcpy((yyval.node).name, (yyvsp[0].node).name);
		}
#line 1862 "phase2.tab.c"
    break;

  case 24:
#line 418 "phase2.y"
                {
			strcpy((yyval.node).content, "_");
			strcat((yyval.node).content, (yyvsp[-2].node).content);
			strcat((yyval.node).content, "\n, ");
			strcat((yyval.node).content, (yyvsp[0].node).content);
		}
#line 1873 "phase2.tab.c"
    break;

  case 25:
#line 428 "phase2.y"
        {
		
		strcpy((yyval.node).content, (yyvsp[0].node).tempCode);
		  strcat((yyval.node).content, "= ");
		  strcat((yyval.node).content, (yyvsp[-2].node).name);
		  strcat((yyval.node).content, ", ");

		  //strcat($$.content, $3.name);
		  if((yyvsp[0].node).type != "number"){
			strcat((yyval.node).content, (yyvsp[0].node).val);
		  }
		  else{
			strcat((yyval.node).content, (yyvsp[0].node).name);
		  }

		  strcat((yyval.node).content, "\n");

		  //cout<<"val:--"<<$3.val<<endl<<"--name:--"<<$3.name<<endl;

		  
	}
#line 1899 "phase2.tab.c"
    break;

  case 26:
#line 451 "phase2.y"
                {
			
			strcpy((yyval.node).content, (yyvsp[-3].node).tempCode);
			strcat((yyval.node).content, "! __temp__0, __temp__0\n?:= else0, __temp__0\n");
			strcat((yyval.node).content, (yyvsp[-1].node).content);
			strcat((yyval.node).content, "\n:= endif0:");

			



		}
#line 1916 "phase2.tab.c"
    break;

  case 27:
#line 464 "phase2.y"
                {
			//string tempIndex = "__temp__" + indexifyTemp();
			string tempIndex = (yyvsp[-5].node).name;
			string elseIndex = "else" + indexifyElse();
			string endifIndex = "endif" + indexifyEndif();
			

			strcpy((yyval.node).content, (yyvsp[-5].node).tempCode);


			string cheese = "! " + tempIndex + ", " + tempIndex + "\n" + "?:= " + elseIndex	+ ", " + tempIndex + "\n";
			char * charCheese = new char [cheese.length()+1];
			strcpy(charCheese, cheese.c_str());
			strcat((yyval.node).content, charCheese);

			strcat((yyval.node).content, (yyvsp[-3].node).content);

			
			string beans = ":= "+ endifIndex + "\n: " +elseIndex+ "\n";
			char * charBeans = new char [beans.length()+1];
			strcpy(charBeans, beans.c_str());
			strcat((yyval.node).content, charBeans);

			strcat((yyval.node).content, (yyvsp[-1].node).content);

			string theory = ": "+endifIndex+"\n";
			char * charTheory = new char [theory.length()+1];
			strcpy(charTheory, theory.c_str());
			strcat((yyval.node).content, charTheory);

			

		}
#line 1954 "phase2.tab.c"
    break;

  case 28:
#line 498 "phase2.y"
                {
			//string tempIndex = "__temp__" + indexifyTemp();
			string tempIndex = (yyvsp[-3].node).name;
			string loopBegIndex = "loop_begin" + indexifyLoopB();
			string loopEndIndex = "loop_end" + indexifyLoopE();

			//cout<<"bool name---"<<tempIndex<<"--"<<endl;

			string guitar = ": "+loopBegIndex+"\n";
			char * charGuitar = new char [guitar.length()+1];
			strcpy(charGuitar, guitar.c_str());
			strcpy((yyval.node).content, charGuitar);

	


			strcat((yyval.node).content, (yyvsp[-3].node).tempCode);

			
			string cheese = "! "+tempIndex+", "+tempIndex+"\n?:= "+loopEndIndex+", "+tempIndex+"\n";
			char * charCheese = new char [cheese.length()+1];
			strcpy(charCheese, cheese.c_str());
			strcat((yyval.node).content, charCheese);


			strcat((yyval.node).content, (yyvsp[-1].node).content);

			string  beans = ":= "+loopBegIndex+"\n: "+loopEndIndex+"\n";
			char * charBeans = new char [ beans.length()+1];
			strcpy(charBeans, beans.c_str());
			strcat((yyval.node).content, charBeans);


			
			

		}
#line 1996 "phase2.tab.c"
    break;

  case 29:
#line 536 "phase2.y"
                {}
#line 2002 "phase2.tab.c"
    break;

  case 30:
#line 538 "phase2.y"
                {
			strcpy((yyval.node).content, ".< ");
			strcat((yyval.node).content, (yyvsp[0].node).content);
			strcat((yyval.node).content, "\n");
		}
#line 2012 "phase2.tab.c"
    break;

  case 31:
#line 544 "phase2.y"
                {
			strcpy((yyval.node).content, ".< ");
			strcat((yyval.node).content, (yyvsp[-2].node).content);
			strcat((yyval.node).content, "\n.< ");
			strcat((yyval.node).content, (yyvsp[0].node).content);
			strcat((yyval.node).content, "\n ");
	
		}
#line 2025 "phase2.tab.c"
    break;

  case 32:
#line 553 "phase2.y"
                {
			strcpy((yyval.node).content, ".< ");
			strcat((yyval.node).content, (yyvsp[-4].node).content);
			strcat((yyval.node).content, "\n.< ");
			strcat((yyval.node).content, (yyvsp[-2].node).content);
			strcat((yyval.node).content, "\n.< ");		
			strcat((yyval.node).content, (yyvsp[0].node).content);
			strcat((yyval.node).content, "\n");
		}
#line 2039 "phase2.tab.c"
    break;

  case 33:
#line 563 "phase2.y"
                {
			strcpy((yyval.node).content, ".> ");
			strcat((yyval.node).content, (yyvsp[0].node).content);
			strcat((yyval.node).content, "\n");
		}
#line 2049 "phase2.tab.c"
    break;

  case 34:
#line 569 "phase2.y"
                {
			strcpy((yyval.node).content, ".> ");
			strcat((yyval.node).content, (yyvsp[-2].node).content);
			strcat((yyval.node).content, "\n.> ");
			strcat((yyval.node).content, (yyvsp[0].node).content);
			strcat((yyval.node).content, "\n");
	
		}
#line 2062 "phase2.tab.c"
    break;

  case 35:
#line 578 "phase2.y"
                {
			strcpy((yyval.node).content, ".> ");
			strcat((yyval.node).content, (yyvsp[-4].node).content);
			strcat((yyval.node).content, "\n.> ");
			strcat((yyval.node).content, (yyvsp[-2].node).content);
			strcat((yyval.node).content, "\n.> ");		
			strcat((yyval.node).content, (yyvsp[0].node).content);
			strcat((yyval.node).content, "\n");
		}
#line 2076 "phase2.tab.c"
    break;

  case 36:
#line 588 "phase2.y"
                {/*replaced with new rules above*/}
#line 2082 "phase2.tab.c"
    break;

  case 37:
#line 590 "phase2.y"
                {/*replaced with new rules above*/}
#line 2088 "phase2.tab.c"
    break;

  case 38:
#line 592 "phase2.y"
                {
			strcpy((yyval.node).content, "continue");
		}
#line 2096 "phase2.tab.c"
    break;

  case 39:
#line 596 "phase2.y"
                {
			strcpy((yyval.node).content, (yyvsp[0].node).content);
			strcpy((yyval.node).name, (yyvsp[0].node).name);
		}
#line 2105 "phase2.tab.c"
    break;

  case 40:
#line 603 "phase2.y"
                {
			strcpy((yyval.node).content, (yyvsp[-1].node).content);
		}
#line 2113 "phase2.tab.c"
    break;

  case 41:
#line 607 "phase2.y"
                {
			strcpy((yyval.node).content, (yyvsp[-2].node).content);
		  	//strcat($$, $2);
		  	strcat((yyval.node).content, (yyvsp[0].node).content);
		}
#line 2123 "phase2.tab.c"
    break;

  case 42:
#line 615 "phase2.y"
                {
		
			strcpy((yyval.node).content, (yyvsp[0].node).content);
			strcpy((yyval.node).name, (yyvsp[0].node).name);
			strcpy((yyval.node).type, (yyvsp[0].node).type);
			strcpy((yyval.node).tempCode, "");
			strcpy((yyval.node).val, (yyvsp[0].node).val);
		}
#line 2136 "phase2.tab.c"
    break;

  case 43:
#line 624 "phase2.y"
                {     
  		
		
			string tempIndex = "__temp__" + indexifyTemp();
			//string tempIndex = $1.name;
			
			
		
			string name = tempIndex;
			char * charName = new char [name.length()+1];
			strcpy(charName, name.c_str());
			//strcat($$.content, charName); 

			string cheese = ". "+tempIndex+"\n";
			char * charCheese = new char [cheese.length()+1];
			strcpy(charCheese, cheese.c_str());
			//strcat($$.content, charCheese);

			string beans = "+ "+tempIndex+", ";
			char * charBeans = new char [beans.length()+1];
			strcpy(charBeans, beans.c_str());
			//strcat($$.content, charBeans);
			
			strcpy((yyval.node).name, charName );
			strcpy((yyval.node).val, charName);

			
			strcpy((yyval.node).content, (yyvsp[-2].node).content);
			strcat((yyval.node).content, (yyvsp[0].node).content);
			
			
			strcpy((yyval.node).tempCode, charCheese);
			strcat((yyval.node).tempCode, charBeans);
			strcat((yyval.node).tempCode, (yyvsp[-2].node).val);
			strcat((yyval.node).tempCode, ", ");
			strcat((yyval.node).tempCode, (yyvsp[0].node).name);
			strcat((yyval.node).tempCode, "\n");

			//cout<<"multex tempcode:"<<endl<<"----"<<$$.tempCode<<"---"<<endl;
			cout<<"$$name--------"<<(yyval.node).name<<"------"<<endl;
			cout<<"charname--------"<<charName<<"------"<<endl;
			cout<<"tempIndex--------"<<tempIndex<<"------"<<endl;
			cout<<"val--------"<<(yyval.node).val<<"---------"<<endl;

			

		}
#line 2188 "phase2.tab.c"
    break;

  case 44:
#line 672 "phase2.y"
                {
  			
			strcpy((yyval.node).name, "__temp__");

			
			strcpy((yyval.node).content, (yyvsp[-2].node).content);
			strcat((yyval.node).content, (yyvsp[0].node).content);
			
			strcpy((yyval.node).tempCode, ". __temp__\n");
			strcat((yyval.node).tempCode, "- __temp__, ");
			strcat((yyval.node).tempCode, (yyvsp[-2].node).name);
			strcat((yyval.node).tempCode, ", ");
			strcat((yyval.node).tempCode, (yyvsp[0].node).name);
			strcat((yyval.node).tempCode, "\n");



		}
#line 2211 "phase2.tab.c"
    break;

  case 45:
#line 693 "phase2.y"
                { 
			//$$ = $1;
			strcpy((yyval.node).content, (yyvsp[0].node).content);
			strcpy((yyval.node).name, (yyvsp[0].node).name);
			strcpy((yyval.node).val, (yyvsp[0].node).val);
			strcpy((yyval.node).type, (yyvsp[0].node).type);
			
		}
#line 2224 "phase2.tab.c"
    break;

  case 46:
#line 702 "phase2.y"
                {
			strcpy((yyval.node).content, (yyvsp[0].node).content);
			strcat((yyval.node).content, ", ");
			strcat((yyval.node).content, (yyvsp[-2].node).content); 
			strcat((yyval.node).content, "\n. __temp__\n");
			strcat((yyval.node).content, "* __temp__, ");
			strcat((yyval.node).content, (yyvsp[-2].node).name);

			
		}
#line 2239 "phase2.tab.c"
    break;

  case 47:
#line 713 "phase2.y"
                {
			strcpy((yyval.node).content, (yyvsp[0].node).content);
			strcat((yyval.node).content, ", ");
			strcat((yyval.node).content, (yyvsp[-2].node).content); 
			strcat((yyval.node).content, "\n. __temp__\n");
			strcat((yyval.node).content, "/__temp__, ");
			strcat((yyval.node).content, (yyvsp[-2].node).name);

			
		}
#line 2254 "phase2.tab.c"
    break;

  case 48:
#line 724 "phase2.y"
                {
			strcpy((yyval.node).content, (yyvsp[0].node).content);
			strcat((yyval.node).content, ", ");
			strcat((yyval.node).content, (yyvsp[-2].node).content); 
			strcat((yyval.node).content, "\n. __temp__\n");
			strcat((yyval.node).content, "%_tmp, ");
			strcat((yyval.node).content, (yyvsp[-2].node).name);
		}
#line 2267 "phase2.tab.c"
    break;

  case 49:
#line 735 "phase2.y"
                { 

			string tempIndex = "__temp__" + indexifyTemp();

				//cout<<"term temp: --"<<tempIndex<<"--"<<endl;


			string name = tempIndex;
			char * charName = new char [name.length()+1];
			strcpy(charName, name.c_str());

			string cheese = ". "+tempIndex+"\n";
			char * charCheese = new char [cheese.length()+1];
			strcpy(charCheese, cheese.c_str());
	

			string beans = "= "+tempIndex+", ";
			char * charBeans = new char [beans.length()+1];
			strcpy(charBeans, beans.c_str());

			
			strcpy((yyval.node).type, (yyvsp[0].node).type);
				strcpy((yyval.node).name, charName);
				strcpy((yyval.node).val, (yyvsp[0].node).val);
				

				strcpy((yyval.node).content, charCheese); 
				strcat((yyval.node).content, charBeans);
				strcat((yyval.node).content, (yyvsp[0].node).name);	

				//cout<<"charName, $$name: --"<<charName<<"--"<<$$.name<<"--"<<tempIndex<<endl;	
			
			// if($1.type == "variable"){
				
			// 	strcpy($$.type, $1.type);
			// 	strcpy($$.name, charName);
				

			// 	strcpy($$.content, charCheese); 
			// 	strcat($$.content, charBeans);
			// 	strcat($$.content, $1.name);	

			// 	cout<<"charName, $$name: --"<<charName<<"--"<<$$.name<<"--"<<tempIndex<<endl;	
			// }
			// else if($1.type == "array"){
			// 	strcpy($$.content, "=[], ");
			// 	strcat($$.content, $1.name);
							
			// }

		}
#line 2323 "phase2.tab.c"
    break;

  case 50:
#line 787 "phase2.y"
                { 
			//$$ = "SLDKFJDSLKJ";
			if((yyvsp[0].node).type == "ident"){
				strcpy((yyval.node).content, ". __temp__\n"); 
				strcat((yyval.node).content, "=__temp__, ");
				strcat((yyval.node).content, (yyvsp[0].node).content);			
			}
			else if((yyvsp[0].node).type == "array"){
				strcpy((yyval.node).content, "=[], ");
				strcat((yyval.node).content, (yyvsp[0].node).name);
							
			}
		}
#line 2341 "phase2.tab.c"
    break;

  case 51:
#line 801 "phase2.y"
                { 
			
			strcpy((yyval.node).content, (yyvsp[0].leaf));
			strcpy((yyval.node).name, (yyvsp[0].leaf));
			strcpy((yyval.node).type, "number");
			strcpy((yyval.node).val, (yyvsp[0].leaf));
			
		}
#line 2354 "phase2.tab.c"
    break;

  case 52:
#line 810 "phase2.y"
                { 
			strcpy((yyval.node).content, "-");
			strcat((yyval.node).content, (yyvsp[0].leaf));
			
			strcpy((yyval.node).type, (yyvsp[0].leaf)); 
			strcpy((yyval.node).name, (yyvsp[0].leaf));
		}
#line 2366 "phase2.tab.c"
    break;

  case 53:
#line 818 "phase2.y"
                { 
			//$$ = "SLDKFJDSLKJ";
			strcpy((yyval.node).content, (yyvsp[-1].node).name);
			

		}
#line 2377 "phase2.tab.c"
    break;

  case 54:
#line 825 "phase2.y"
                { 
			strcpy((yyval.node).content, (yyvsp[-1].node).name); 
		}
#line 2385 "phase2.tab.c"
    break;

  case 55:
#line 829 "phase2.y"
                { 
			//char *token = identToken;
     		//printf("___%s___\n", token);

			//printf("_name:__%s___\n", $1.name);
			//printf("_content:__%s___\n", $1.content);


			if (strcmp((yyvsp[-3].node).content, sub) == 0) { // match!
				funcBool = 1;	
			}

			// char* search = strstr(funcList, $1.content);      
 			// if (search != NULL)                     
 			// {
     		// 	printf("Found string");
 			// }         


			// for(int i = 0; i <= 100; i++){
			// 	printf(funcList[i]);
			// }

			// for(int i =0; i < count_names; i++ ) {
     		// 	printf("%s\n", funcList[i]);
   			// }
			
			int i =0;
   			for(i =0; i < count_names; i++ ) {
   			  //printf("%s\n", list_of_function_names[i]);
				 //size_t size = strlen($1.content) + 1; 
			     char c[10]= "";
				 strcpy(c, (yyvsp[-3].node).content);
				 //printf("---%s---\n", c);
				 
				 if (strcmp(c, list_of_function_names[i]) == 0) { 
					//funcBool = 1;
					//printf("--%s--\n", list_of_function_names[i]);

				}
   			}

			strcpy((yyval.node).content, (yyvsp[-1].node).name); 
		}
#line 2434 "phase2.tab.c"
    break;

  case 56:
#line 876 "phase2.y"
                {
			strcpy((yyval.node).content, ""); 
		}
#line 2442 "phase2.tab.c"
    break;

  case 57:
#line 880 "phase2.y"
                {
			strcpy((yyval.node).content, (yyvsp[0].node).content);
		}
#line 2450 "phase2.tab.c"
    break;

  case 58:
#line 884 "phase2.y"
                {
			strcpy((yyval.node).content, (yyvsp[-2].node).content);
			strcat((yyval.node).content, "\n");
			strcat((yyval.node).content, (yyvsp[0].node).content);
		}
#line 2460 "phase2.tab.c"
    break;

  case 59:
#line 897 "phase2.y"
                {
			
			strcpy((yyval.node).content, (yyvsp[0].node).content);
			strcpy((yyval.node).tempCode, (yyvsp[0].node).tempCode);
			strcpy((yyval.node).name, (yyvsp[0].node).name );
			strcpy((yyval.node).val, (yyvsp[0].node).val);
		}
#line 2472 "phase2.tab.c"
    break;

  case 60:
#line 905 "phase2.y"
                {
			strcpy((yyval.node).content, (yyvsp[-2].node).content);
			strcat((yyval.node).content, "\n");
			strcat((yyval.node).content, (yyvsp[0].node).content);
			strcat((yyval.node).content, "\n");	
			strcat((yyval.node).content, ". __temp__\n|| __temp__, ");		
			strcat((yyval.node).content, (yyvsp[-2].node).content);
			strcat((yyval.node).content, ", ");
			strcat((yyval.node).content, (yyvsp[0].node).content);
		}
#line 2487 "phase2.tab.c"
    break;

  case 61:
#line 918 "phase2.y"
                {
			strcpy((yyval.node).content, (yyvsp[0].node).content );
			strcpy((yyval.node).tempCode, (yyvsp[0].node).tempCode);
			strcpy((yyval.node).name, (yyvsp[0].node).name );
			strcpy((yyval.node).val, (yyvsp[0].node).val);
		}
#line 2498 "phase2.tab.c"
    break;

  case 62:
#line 925 "phase2.y"
                {
			strcpy((yyval.node).content, (yyvsp[-2].node).content);
			strcat((yyval.node).content, "\n");
			strcat((yyval.node).content, (yyvsp[0].node).content);
			strcat((yyval.node).content, "\n");	
			strcat((yyval.node).content, ". __temp__\n&& __temp__, ");		
			strcat((yyval.node).content, (yyvsp[-2].node).content);
			strcat((yyval.node).content, ", ");
			strcat((yyval.node).content, (yyvsp[0].node).content);	
		}
#line 2513 "phase2.tab.c"
    break;

  case 63:
#line 938 "phase2.y"
                {
			//string tempIndex = "__temp__" + indexifyTemp();
			string tempIndex = (yyvsp[-2].node).name;

			//cout<<"rel_exp temp index: ---"<<tempIndex<<"---"<<endl;

			string name = tempIndex;
			char * charName = new char [name.length()+1];
			strcpy(charName, name.c_str());

			string cheese = ". "+tempIndex+"\n";
			char * charCheese = new char [cheese.length()+1];
			strcpy(charCheese, cheese.c_str());

			string beans = " "+tempIndex+", ";
			char * charBeans = new char [beans.length()+1];
			strcpy(charBeans, beans.c_str());


			strcpy((yyval.node).name, charName);
			strcpy((yyval.node).content, (yyvsp[-2].node).content);
			strcpy((yyval.node).val, (yyvsp[-2].node).val);

			strcpy((yyval.node).tempCode, charCheese);
			strcat((yyval.node).tempCode, (yyvsp[-1].leaf));			
			strcat((yyval.node).tempCode, charBeans);
			strcat((yyval.node).tempCode, (yyvsp[-2].node).val);	
			strcat((yyval.node).tempCode, " , ");
			strcat((yyval.node).tempCode, (yyvsp[0].node).val);	
			strcat((yyval.node).tempCode, "\n");


		}
#line 2551 "phase2.tab.c"
    break;

  case 64:
#line 972 "phase2.y"
                {


		}
#line 2560 "phase2.tab.c"
    break;

  case 65:
#line 977 "phase2.y"
                {}
#line 2566 "phase2.tab.c"
    break;

  case 66:
#line 979 "phase2.y"
                {}
#line 2572 "phase2.tab.c"
    break;

  case 67:
#line 981 "phase2.y"
                {}
#line 2578 "phase2.tab.c"
    break;

  case 68:
#line 983 "phase2.y"
                {}
#line 2584 "phase2.tab.c"
    break;

  case 69:
#line 985 "phase2.y"
                {}
#line 2590 "phase2.tab.c"
    break;

  case 70:
#line 987 "phase2.y"
                {}
#line 2596 "phase2.tab.c"
    break;

  case 71:
#line 991 "phase2.y"
                {strcpy((yyval.leaf), "==");	}
#line 2602 "phase2.tab.c"
    break;

  case 72:
#line 993 "phase2.y"
                {strcpy((yyval.leaf), "!=");	}
#line 2608 "phase2.tab.c"
    break;

  case 73:
#line 995 "phase2.y"
                {strcpy((yyval.leaf), "<");	}
#line 2614 "phase2.tab.c"
    break;

  case 74:
#line 997 "phase2.y"
                {strcpy((yyval.leaf), ">");	}
#line 2620 "phase2.tab.c"
    break;

  case 75:
#line 999 "phase2.y"
                {strcpy((yyval.leaf), "<=");	}
#line 2626 "phase2.tab.c"
    break;

  case 76:
#line 1001 "phase2.y"
                {strcpy((yyval.leaf), ">=");	}
#line 2632 "phase2.tab.c"
    break;

  case 77:
#line 1004 "phase2.y"
        {	 
		//strcpy($$.content, "_");
    	strcpy((yyval.node).content, (yyvsp[0].node).content);
		strcpy((yyval.node).val, (yyvsp[0].node).content);
		strcpy((yyval.node).name, (yyvsp[0].node).name);
		strcpy((yyval.node).type, "variable");

	}
#line 2645 "phase2.tab.c"
    break;

  case 78:
#line 1014 "phase2.y"
        { 
		//$$ = 0;  /*garbage */

		

		strcpy((yyval.node).content, ".[] ");
		strcat((yyval.node).content, (yyvsp[-3].node).name);
		strcat((yyval.node).content, ", ");
		strcat((yyval.node).content, (yyvsp[-1].node).content);

		strcpy((yyval.node).name, (yyvsp[-3].node).name);
		strcpy((yyval.node).type, "array");
	}
#line 2663 "phase2.tab.c"
    break;

  case 79:
#line 1029 "phase2.y"
                {
			strcpy((yyval.node).content, (yyvsp[0].node).content);
			strcpy((yyval.node).type, (yyvsp[0].node).type);
		}
#line 2672 "phase2.tab.c"
    break;

  case 80:
#line 1034 "phase2.y"
                {
			//TODO: output error if var and vars are of different type
			//TODO: find the "leaves" and give them "signitures", a thing that is composed of the leaf will inherit the signature as its first token
			strcpy((yyval.node).content, (yyvsp[-2].node).content);
			strcat((yyval.node).content, ", ");
			strcat((yyval.node).content, (yyvsp[0].node).content);
		}
#line 2684 "phase2.tab.c"
    break;


#line 2688 "phase2.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 1043 "phase2.y"


string indexifyTemp() {
  static int index1 = 0;
  return to_string(index1++);
}
string indexifyElse(void){
	static int index2 = 0;
	return to_string(index2++);
}
string indexifyEndif(void){
	static int index3 = 0;
	return to_string(index3++);
}
string indexifyLoopB(void){
	static int index4 = 0;
	return to_string(index4++);
}
string indexifyLoopE(void){
	static int index5 = 0;
	return to_string(index5++);
}


int main(int argc, char **argv)
{
   yyparse();
//    int i =0;
//    for(i =0; i < count_names; i++ ) {
//      printf("%s\n", list_of_function_names[i]);
//    }

   return 0;
}

void yyerror(const char *msg)
{
   if(myError == 0)
   {
      printf("** Line %d: %s\n", currLine, msg);
      otherError = 1;
   }
   else
   {
      if(otherError == 1)
      {
         printf("   (%s)\n", msg);
         otherError = 0;
      }
   }
   myError = 0;
}
