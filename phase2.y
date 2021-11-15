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
    char content[2000];
	char name[10];
	char type[10];
  } node;

  struct terminal 
  {
    char name[30];
	char content[200];
	char type[10];
  } leaf;
}

%define parse.error verbose


%type <root> functions function function_ident
%type <node> declaration declarations statement statements var term ident expressions comma_sep_expressions expression multiplicative_expression vars idents
//%type <leaf> ident 

//%type <op_val> var
//%type <op_val> ident
//%type <op_val> expression
//%type <op_val> multiplicative_expression
//%type <op_val> term



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
		strcat($$,	$4.content);
		strcat($$, $7.content);
		strcat($$, $10.content);
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
		 strcat($$, $2.content);

		 strcpy(list_of_function_names[count_names], $2.content);
		 count_names++;

	}


ident:
	IDENT
		{ 
			//TODO: distinguish between an array and a normal ident
			//$$ = $1; 
			strcpy($$.content, $1);
		};














declarations: 
	/* epsilon */
		{}
	| declaration SEMICOLON declarations
		{
			strcpy($$.content, $1.content);
		  	//strcat($$, $2);
		  	strcat($$.content, $3.content);
		};

declaration: 
	IDENT COLON INTEGER
		{	

    	//    char *token = $1;
    	//    printf(". %s\n", token);



			strcpy($$.content, ".");
			strcat($$.content, $1);
			strcat($$.content, "\n");

		}
	| idents COLON INTEGER
		{
		  	strcat($$.content, $1.content);
		}
	| IDENT COMMA IDENT COLON INTEGER
		{
			strcpy($$.content, ".");
			strcat($$.content, $1);
			strcat($$.content, "\n");

			strcpy($$.content, ".");
			strcat($$.content, $3);
			strcat($$.content, "\n");
		}
	| IDENT COMMA IDENT COMMA IDENT COLON INTEGER
		{
			strcpy($$.content, ".");
			strcat($$.content, $1);
			strcat($$.content, "\n");

			strcpy($$.content, ".");
			strcat($$.content, $3);
			strcat($$.content, "\n");

			strcpy($$.content, ".");
			strcat($$.content, $5);
			strcat($$.content, "\n");
		}
	| IDENT COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER
		{
			//TODO: arrays
			printf("horray! we found an array!   ");
		};


idents: 
	/*epsilon*/
		{
			// strcpy($$.content, $1);
			// strcpy($$.name, $1)
		}
	| ident COMMA idents
		{
			strcpy($$.content, ".");
			strcat($$.content, $1.content);
			strcat($$.content, "\n");
			strcat($$.content, $3.content);
		};


statement: 
	var ASSIGN expression
	{
  		// char *dest = $1;
  		// char *src  = $3;
  		// printf("= %s, %s\n", dest, src);

		  strcpy($$.content, "= ");
		  strcat($$.content, $1.content);
		  strcat($$.content, ", ");
		  strcat($$.content, $3.content);
		  strcat($$.content, "\n");
		  
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
		{
			strcpy($$.content, $1.content);
		}
	| statement SEMICOLON statements
		{
			strcpy($$.content, $1.content);
		  	//strcat($$, $2);
		  	strcat($$.content, $3.content);
		};

expression: 
	multiplicative_expression
	{
		//**TODO: create a struct assign $$ as an object with different fields
		//$$ = $1; 
		strcpy($$.content, $1.content);
	}
	| multiplicative_expression ADD expression
	{     
  		// char *src1 =  $1;
  		// char *src2 =  $3;
  		// char *dest = "__temp__";
  		// printf("+ %s, %s, %s\n", dest, src1, src2);
  		// $$ = dest;

		// strcpy($$, "+__temp__ ");
		// //strcat($$, "__temp__ ");
		// strcat($$, $1);
		// strcat($$, ", ");
		// strcat($$, $3);
		// strcat($$, "\n");

		strcpy($$.content, $3.content);

		strcat($$.content, $1.content);
		strcat($$.content, "\n.");
		strcat($$.content, "__temp__\n");
		strcat($$.content, "+__temp__, ");
		strcat($$.content, $1.content);
		strcat($$.content, ", ");
		strcat($$.content, $3.content);

		
	}
	| multiplicative_expression SUB expression
	{
  		// char *src1 =  $1;
  		// char *src2 =  $3;
  		// char *dest = "__temp__";
  		// printf("- %s, %s, %s\n", dest, src1, src2);
  		// $$ = dest;

		// strcpy($$, "-__temp__ ");
		// //strcat($$, "__temp__ ");
		// strcat($$, $1);
		// strcat($$, ", ");
		// strcat($$, $3);
		// strcat($$, "\n");

		strcpy($$.content, $3.content);

		strcat($$.content, $1.content);
		strcat($$.content, "\n.");
		strcat($$.content, "__temp__\n");
		strcat($$.content, "+__temp__, ");
		strcat($$.content, $1.content);
		strcat($$.content, ", ");
		strcat($$.content, $3.content);

	
	};

multiplicative_expression: 
	term
		{ 
			//$$ = $1;
			strcpy($$.content, $1.content);

		}
	| term MULT multiplicative_expression
		{
			strcpy($$.content, $3.content);
			strcat($$.content, $1.content); 
			strcat($$.content, "\n.__temp__\n");
			strcat($$.content, "*__temp__, ");
			strcat($$.content, $1.name);
		}
	| term DIV multiplicative_expression
		{
			strcpy($$.content, $3.content);
			strcat($$.content, $1.content); 
			strcat($$.content, "\n.__temp__\n");
			strcat($$.content, "/__temp__, ");
			strcat($$.content, $1.name);
		}
	| term MOD multiplicative_expression
		{
			strcpy($$.content, $3.content);
			strcat($$.content, $1.content); 
			strcat($$.content, "\n.__temp__\n");
			strcat($$.content, "%_tmp, ");
			strcat($$.content, $1.name);
		};

term: 
	var
		{ 
			strcpy($$.content, $1.content);			
			strcpy($$.name, $1.name);
			strcpy($$.type, $1.type);

			//$$ = $1;
			if($1.type == "ident"){
				strcpy($$.content, ". __temp__\n"); 
				strcat($$.content, "=__temp__, ");
				strcat($$.content, $1.content);			
			}
			else if($1.type == "array"){
				strcpy($$.content, "=[], ");
				strcat($$.content, $1.name);
							
			}

		}
	| SUB var
		{ 
			//$$ = "SLDKFJDSLKJ";
			if($2.type == "ident"){
				strcpy($$.content, ". __temp__\n"); 
				strcat($$.content, "=__temp__, ");
				strcat($$.content, $2.content);			
			}
			else if($2.type == "array"){
				strcpy($$.content, "=[], ");
				strcat($$.content, $2.name);
							
			}
		}
	| NUMBER
		{ 
			//$$ = $1;
			strcpy($$.content, $1);
			strcpy($$.type, $1);
		}
	| SUB NUMBER
		{ 
			strcpy($$.content, "-");
			strcat($$.content, $2);
			strcpy($$.type, $2); 
		}
	| L_PAREN expression R_PAREN
		{ 
			//$$ = "SLDKFJDSLKJ";
			strcpy($$.content, $2.name);

		}
	| SUB L_PAREN expression R_PAREN
		{ 
			//$$ = "SLDKFJDSLKJ";
			strcpy($$.content, $3.name); 
		}
	| ident L_PAREN expressions R_PAREN
		{ 
			//$$ = "SLDKFJDSLKJ";
			strcpy($$.content, $3.name); 
		};

expressions: 
	/* epsilon */
		{
			strcpy($$.content, ""); 
		}
	| comma_sep_expressions
		{};

comma_sep_expressions: 
	expression
		{
			strcpy($$.content, $1.content);
		}
	| expression COMMA comma_sep_expressions
		{
			strcpy($$.content, $1.content);
			strcat($$.content, "\n");
			strcat($$.content, $3.content);
		};
	

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
    	strcpy($$.content, $1.content);
		strcpy($$.type, "ident");

	}

| ident L_SQUARE_BRACKET expression R_SQUARE_BRACKET
	{ 
		//$$ = 0;  /*garbage */

		//*TODO: this is the array
		

		strcpy($$.content, ".[] ");
		strcat($$.content, $1.name);
		strcat($$.content, ", ");
		strcat($$.content, $3.content);

		strcpy($$.name, $1.name);
		strcpy($$.type, "array");
	};
vars:
	var
		{
			strcpy($$.content, $1.content);
			strcpy($$.type, $1.type);
		}
	| var COMMA vars
		{
			//TODO: output error if var and vars are of different type
			//TODO: find the "leaves" and give them "signitures", a thing that is composed of the leaf will inherit the signature as its first token
			strcat($$.content, $1.content);
			strcat($$.content, ", ");
			strcat($$.content, $3.content);
		};
	

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