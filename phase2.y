%{
   #include<stdio.h>
   void yyerror(const char *msg);
   extern int currLine;
   int myError = 0;
   int otherError = 0;
   
   char *identToken;
   int numberToken;
   int productionID = 0;

//#define YYDEBUG 1
//yydebug=1;
%}


%error-verbose
%start prog_start
%token BEGIN_PARAMS END_PARAMS BEGIN_LOCALS END_LOCALS BEGIN_BODY END_BODY
%token FUNCTION RETURN MAIN
%token L_SQUARE_BRACKET
%token R_SQUARE_BRACKET
%token INTEGER ARRAY OF
%token IF THEN ENDIF ELSE
%token WHILE DO BEGINLOOP ENDLOOP  CONTINUE
%token READ WRITE
%token AND OR NOT TRUE FALSE
%token SUB ADD MULT DIV MOD
%token EQ NEQ LT GT LTE GTE
%token SEMICOLON COLON COMMA L_PAREN R_PAREN ASSIGN
%token NUMBER IDENT

%%

prog_start: 
	functions
		{printf("prog_start -> functions\n");};

functions: 
	/* epsilon */
		{printf("functions -> epsilon\n");}
	| function functions
		{printf("functions -> function functions\n");};

function: 
	FUNCTION ident SEMICOLON
	BEGIN_PARAMS declarations END_PARAMS
	BEGIN_LOCALS declarations END_LOCALS
	BEGIN_BODY statements END_BODY
		{printf("function -> FUNCTION IDENT SEMICOLON BEGIN_PARAMS declarations END_PARAMS BEGIN_LOCALS declarations END_LOCALS BEGIN_BODY statements END_BODY\n", identToken);};

ident:
	IDENT
		{printf("ident -> IDENT %s\n", identToken);};

declarations: 
	/* epsilon */
		{printf("declarations -> epsilon\n");}
	| declaration SEMICOLON declarations
		{printf("declarations -> declaration SEMICOLON declarations\n");};

declaration: 
	identifiers COLON INTEGER
		{printf("declaration -> identifiers COLON INTEGER\n");}
	| identifiers COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER
		{printf("declaration -> identifiers COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER\n");};

identifiers: 
	ident
		{printf("identifiers -> ident\n");}
	| ident COMMA identifiers
		{printf("identifiers -> ident COMMA identifiers\n", identToken);};


statement: 
	var ASSIGN expression
		{printf("statement -> var ASSIGN expression\n");}
	| IF bool_exp THEN statements ENDIF
		{printf("statement -> IF bool_exp THEN statements ENDIF\n");}
	| IF bool_exp THEN statements ELSE statements ENDIF
		{printf("statement -> IF bool_exp THEN statements ELSE statements ENDIF\n");}
	| WHILE bool_exp BEGINLOOP statements ENDLOOP
		{printf("statement -> WHILE bool_exp BEGINLOOP statements ENDLOOP\n");}
	| DO BEGINLOOP statements ENDLOOP WHILE bool_exp
		{printf("statement -> DO BEGINLOOP statements ENDLOOP WHILE bool_exp\n");}
	| READ vars
		{printf("statement -> READ vars\n");}
	| WRITE vars
		{printf("statement -> WRITE vars\n");}
	| CONTINUE
		{printf("statement -> CONTINUE\n");}
	| RETURN expression
		{printf("statement -> RETURN expression\n");};
	
statements: 
	statement SEMICOLON/* epsilon */
		{printf("statements -> epsilon\n");}
	| statement SEMICOLON statements
		{printf("statements -> statement SEMICOLON statements\n");};

expression: 
	multiplicative_expression
		{printf("expression -> multiplicative_expression\n");}
	| multiplicative_expression ADD expression
		{printf("expression -> multiplicative_expression ADD multiplicative_expression\n");}
	| multiplicative_expression SUB expression
		{printf("expression -> multiplicative_expression SUB multiplicative_expression\n");};

multiplicative_expression: 
	term
		{printf("multiplicative_expression -> term\n");}
	| term MULT multiplicative_expression
		{printf("multiplicative_expression -> term MULT multiplicative_expression\n");}
	| term DIV multiplicative_expression
		{printf("multiplicative_expression -> term DIV multiplicative_expression\n");}
	| term MOD multiplicative_expression
		{printf("multiplicative_expression -> term MOD multiplicative_expression\n");};

term: 
	var
		{printf("term -> var\n");}
	| SUB var
		{printf("term -> SUB var\n");}
	| NUMBER
		{printf("term -> NUMBER\n");}
	| SUB NUMBER
		{printf("term -> SUB NUMBER\n");}
	| L_PAREN expression R_PAREN
		{printf("term -> L_PAREN expression R_PAREN\n");}
	| SUB L_PAREN expression R_PAREN
		{printf("term -> SUB L_PAREN expression R_PAREN\n");}
	| ident L_PAREN expressions R_PAREN
		{printf("term -> ident L_PAREN expressions R_PAREN\n");};

expressions: 
	/* epsilon */
		{printf("expressions -> epsilon\n");}
	| comma_sep_expressions
		{printf("expressions -> comma_sep_expressions\n");};

comma_sep_expressions: 
	expression
		{printf("comma_sep_expressions -> expression\n");}
	| expression COMMA comma_sep_expressions
		{printf("comma_sep_expressions -> expression COMMA comma_sep_expressions\n");};

bool_exp:
	relation_and_exp
		{printf("bool_exp -> relation_and_exp\n");}
	| relation_and_exp OR bool_exp
		{printf("bool_exp -> relation_and_exp OR relation_and_exp\n");};

relation_and_exp:
	relation_exp
		{printf("relation_and_exp -> relation_exp\n");}
	| relation_exp AND relation_and_exp
		{printf("relation_and_exp -> relation_exp AND relation_exp\n");};

relation_exp:
	expression comp expression
		{printf("relation_exp -> expression comp expression\n");}
	| NOT expression comp expression
		{printf("relation_exp -> NOT expression comp expression\n");}
	| TRUE
		{printf("relation_exp -> TRUE\n");}
	| NOT TRUE
		{printf("relation_exp -> NOT TRUE\n");}
	| FALSE
		{printf("relation_exp -> FALSE\n");}
	| NOT FALSE
		{printf("relation_exp -> NOT FALSE\n");}
	| L_PAREN bool_exp R_PAREN
		{printf("relation_exp -> L_PAREN bool_exp R_PAREN\n");}
	| NOT L_PAREN bool_exp R_PAREN
		{printf("relation_exp -> NOT L_PAREN bool_exp R_PAREN\n");};

comp:
	EQ
		{printf("comp -> EQ\n");}
	| NEQ
		{printf("comp -> NEQ\n");}
	| LT
		{printf("comp -> LT\n");}
	| GT
		{printf("comp -> GT\n");}
	| LTE
		{printf("comp -> LTE\n");}
	| GTE
		{printf("comp -> GTE\n");};

var: 
	ident
		{printf("var -> ident\n");}
	| ident L_SQUARE_BRACKET expression R_SQUARE_BRACKET
		{printf("var -> ident L_SQUARE_BRACKET expression R_SQUARE_BRACKET\n");};
vars:
	var
		{printf("vars -> var\n");}
	| var COMMA vars
		{printf("vars -> var COMMA vars\n");};
	

%%

int main(int argc, char **argv)
{
   return yyparse();
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
