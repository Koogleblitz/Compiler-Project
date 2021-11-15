%{
   #include <stdio.h>
   #include <string.h>
   #include <stdlib.h>
   //#include <string>

   void yyerror(const char *msg);
   extern int currLine;
   int myError = 0;
   int otherError = 0;
   
   char *identToken;
   int numberToken;
   int productionID = 0;

   char list_of_function_names[100][100];
   int  count_names = 0;

//#define YYDEBUG 1
//yydebug=1;
%}



%start prog_start



%union {
  char *op_val;
  char *str_val;
  char *container;
  char root[4000];
  
  struct nonTerminal 
  {
    char content[500];
	char cheese[10];
	char theory[10];
	char guitar[10];
  } node;

  struct terminal 
  {
    char name[10];
  } leaf;
}

%define parse.error verbose


%type <root> functions function 
%type <root> declaration declarations statement statements function_ident

%type <op_val> var
%type <op_val> ident
%type <op_val> expression
%type <op_val> multiplicative_expression
%type <op_val> term



%token BEGIN_PARAMS END_PARAMS BEGIN_LOCALS END_LOCALS BEGIN_BODY END_BODY
%type <container> end_body
//%type <container> locals


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
%token <op_val> NUMBER 
%token <op_val> IDENT

%%

prog_start: 
	functions
		{
			printf("%s",$1);
		};

functions: 
	function functions
		{
			strcpy($$, $1);
			strcat($$, "\n");
			strcat($$, $2);
		};
	|		{strcpy($$, "");}

function: function_ident
	SEMICOLON
	BEGIN_PARAMS declarations END_PARAMS
	BEGIN_LOCALS declarations END_LOCALS
	BEGIN_BODY statements end_body 
	{
		strcpy($$, "func ");
		strcat($$,	$1);
		strcat($$, "\n");
		strcat($$,	$4);
		strcat($$, $7);
		strcat($$, $10);
		strcat($$, "endfunc ");
	};

end_body: 
	END_BODY 
	{
   		//printf("endfunc\n");
   		strcpy($$, "endfunc ");
	}








function_ident: FUNCTION ident 
	{
     	// char *token = identToken;
     	// printf("func %s\n", token);
     	// strcpy(list_of_function_names[count_names], token);
     	// count_names++;

		 //strcpy($$, "func ");
		 strcat($$, $2);

		 strcpy(list_of_function_names[count_names], $2);
		 count_names++;

	}


ident:
	IDENT
		{ 
			//TODO: distinguish between an array and a normal ident
			//$$ = $1; 
			strcpy($$, $1);
		};

declarations: 
	/* epsilon */
		{}
	| declaration SEMICOLON declarations
		{
			strcpy($$, $1);
		  	//strcat($$, $2);
		  	strcat($$, $3);
		};

declaration: 
	IDENT COLON INTEGER
	{

    	//    char *token = $1;
    	//    printf(". %s\n", token);
		strcpy($$, ".");
		strcat($$, $1);
		strcat($$, "\n");

	}
	| IDENT COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER
		{};

statement: 
	var ASSIGN expression
	{
  		// char *dest = $1;
  		// char *src  = $3;
  		// printf("= %s, %s\n", dest, src);

		  strcpy($$, "= ");
		  strcat($$, $1);
		  strcat($$, ", ");
		  strcat($$, $3);
		  strcat($$, "\n");
		  
	}
	| IF bool_exp THEN statements ENDIF
		{}
	| IF bool_exp THEN statements ELSE statements ENDIF
		{}
	| WHILE bool_exp BEGINLOOP statements ENDLOOP
		{}
	| DO BEGINLOOP statements ENDLOOP WHILE bool_exp
		{}
	| READ vars
		{}
	| WRITE vars
		{}
	| CONTINUE
		{}
	| RETURN expression
		{};
	
statements: 
	statement SEMICOLON/* epsilon */
		{}
	| statement SEMICOLON statements
		{
			strcpy($$, $1);
		  	//strcat($$, $2);
		  	strcat($$, $3);
		};

expression: 
	multiplicative_expression
	{
		//**TODO: create a struct assign $$ as an object with different fields
		//$$ = $1; 
		strcpy($$, $1);
	}
	| multiplicative_expression ADD expression
	{     
  		// char *src1 =  $1;
  		// char *src2 =  $3;
  		// char *dest = "_temp";
  		// printf("+ %s, %s, %s\n", dest, src1, src2);
  		// $$ = dest;

		strcpy($$, "+_temp ");
		//strcat($$, "_temp ");
		strcat($$, $1);
		strcat($$, ", ");
		strcat($$, $3);
		strcat($$, "\n");
		
	}
	| multiplicative_expression SUB expression
	{
  		// char *src1 =  $1;
  		// char *src2 =  $3;
  		// char *dest = "_temp";
  		// printf("- %s, %s, %s\n", dest, src1, src2);
  		// $$ = dest;

		strcpy($$, "-_temp ");
		//strcat($$, "_temp ");
		strcat($$, $1);
		strcat($$, ", ");
		strcat($$, $3);
		strcat($$, "\n");
	
	};

multiplicative_expression: 
	term
		{ 
			//$$ = $1;
			strcpy($$, $1);

		}
	| term MULT multiplicative_expression
		{
			strcpy($$, "filler:"); 
		}
	| term DIV multiplicative_expression
		{
			strcpy($$, "filler:"); 
		}
	| term MOD multiplicative_expression
		{
			strcpy($$, "filler:"); 
		}
		;

term: 
	var
		{ 
			//$$ = $1;
			strcpy($$, $1); 
		}
	| SUB var
		{ 
			//$$ = "SLDKFJDSLKJ";
			strcpy($$, "filler "); 
		}
	| NUMBER
		{ 
			//$$ = $1;
			strcpy($$, $1); 
		}
	| SUB NUMBER
		{ 
			//$$ = "SLDKFJDSLKJ";
			strcpy($$, "filler "); 
		}
	| L_PAREN expression R_PAREN
		{ 
			//$$ = "SLDKFJDSLKJ";
			strcpy($$, "filler "); 
		}
	| SUB L_PAREN expression R_PAREN
		{ 
			//$$ = "SLDKFJDSLKJ";
			strcpy($$, "filler "); 
		}
	| ident L_PAREN expressions R_PAREN
		{ 
			//$$ = "SLDKFJDSLKJ";
			strcpy($$, "filler "); 
		};

expressions: 
	/* epsilon */
		{}
	| comma_sep_expressions
		{};

comma_sep_expressions: 
	expression
		{}
	| expression COMMA comma_sep_expressions
		{};

bool_exp:
	relation_and_exp
		{}
	| relation_and_exp OR bool_exp
		{};

relation_and_exp:
	relation_exp
		{}
	| relation_exp AND relation_and_exp
		{};

relation_exp:
	expression comp expression
		{}
	| NOT expression comp expression
		{}
	| TRUE
		{}
	| NOT TRUE
		{}
	| FALSE
		{}
	| NOT FALSE
		{}
	| L_PAREN bool_exp R_PAREN
		{}
	| NOT L_PAREN bool_exp R_PAREN
		{};

comp:
	EQ
		{}
	| NEQ
		{}
	| LT
		{}
	| GT
		{}
	| LTE
		{}
	| GTE
		{};

var:  ident
{ 
    $$ = $1; 

}

	| ident L_SQUARE_BRACKET expression R_SQUARE_BRACKET
		{ 
			//$$ = 0;  /*garbage */
			strcpy($$, "garbage ");
		};
vars:
	var
		{}
	| var COMMA vars
		{};
	

%%

int main(int argc, char **argv)
{
   yyparse();
   /*int i =0;
   for(i =0; i < count_names; i++ ) {
     printf("%s\n", list_of_function_names[i]);
   }*/

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