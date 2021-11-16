/*
	TODO:
	- comma sep expression
	-relation_exp
	-error handling
	-pneumonic errors
	-array handingl
*/

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
   char *identToken2;
   int numberToken;
   int productionID = 0;

   char list_of_function_names[100][100];
   char* funcList[100];
   int  count_names = 0;


   int mainFunc = 0;
   int funcBool = 0;
   int zeroArrbool = 0;
   char *mainStr = "main";
   char *func = "sub";
   char *zero = "0";
   


//#define YYDEBUG 1
//yydebug=1;
%}



%start prog_start



%union {
  char *leaf;
  char container[30];

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
  } term;

  
}

%define parse.error verbose


%type <root> functions function function_ident
%type <node> declaration declarations statement statements var term ident idents expressions comma_sep_expressions expression multiplicative_expression 
%type <node> vars bool_exp relation_exp relation_and_exp paramlocal
%type <container> end_body 
%type <leaf> NUMBER IDENT comp
//%type <container> locals

%token BEGIN_PARAMS END_PARAMS BEGIN_LOCALS END_LOCALS BEGIN_BODY END_BODY
%token FUNCTION MAIN
%token RETURN
%token L_SQUARE_BRACKET
%token R_SQUARE_BRACKET
%token INTEGER ARRAY OF
%token IF THEN ENDIF ELSE
%token WHILE DO BEGINLOOP ENDLOOP  
%token CONTINUE
%token READ WRITE
%token AND OR NOT TRUE FALSE
%token SUB ADD MULT DIV MOD
%token EQ NEQ LT GT LTE GTE
%token SEMICOLON COLON COMMA L_PAREN R_PAREN ASSIGN
%token NUMBER 
%token IDENT

//%type <leaf> ident 
//%type <op_val> var
//%type <op_val> ident
//%type <op_val> expression
//%type <op_val> multiplicative_expression
//%type <op_val> term
// %token FUNCTION RETURN MAIN
// %token L_SQUARE_BRACKET
// %token R_SQUARE_BRACKET
// %token INTEGER ARRAY OF
// %token IF THEN ENDIF ELSE
// %token WHILE DO BEGINLOOP ENDLOOP  CONTINUE
// %token READ WRITE
// %token AND OR NOT TRUE FALSE
// %token SUB ADD MULT DIV MOD
// %token EQ NEQ LT GT LTE GTE
// %token SEMICOLON COLON COMMA L_PAREN R_PAREN ASSIGN
// %token <op_val> NUMBER 
// %token <op_val> IDENT

%%

prog_start: 
	functions
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
				printf("%s",$1);	
			}
			
		};

functions: 
	function functions
		{
			strcpy($$, $1);
			strcat($$, "\n");
			strcat($$, $2);
		};
	| /*epsilon*/
		{
			strcpy($$, "");
		};

function: 
	function_ident SEMICOLON
	paramlocal declarations paramlocal
	paramlocal declarations paramlocal
	paramlocal statements end_body 
	{
		strcpy($$, "\nfunc ");
		strcat($$,	$1);
		strcat($$, "\n");
		strcat($$, $3.content);
		strcat($$, $4.content);
		strcat($$, $5.content);
		strcat($$, $6.content);
		strcat($$, $7.content);
		strcat($$, $8.content);
		strcat($$, $9.content);		
		strcat($$, $10.content);
		strcat($$, "\nendfunc ");

	
	};

end_body: 
	END_BODY 
	{
   		//printf("endfunc\n");
   		strcpy($$, "endfunc ");
	};

paramlocal:
	BEGIN_PARAMS
		{
			// char *token2 = identToken;
     		// printf("   _--%s--_\n   ", token2);

			strcpy($$.content, "");	
			
		}
	| END_PARAMS
		{
			// char *token2 = identToken;
     		// printf("   _--%s--_\n   ", token2);
			strcpy($$.content, "");	
		}
	| BEGIN_LOCALS
		{
			strcpy($$.content, "");	
		}
	| END_LOCALS
		{
			strcpy($$.content, "");	
		}
	| BEGIN_BODY
		{
			strcpy($$.content, "");	
		};

function_ident: 
	FUNCTION ident 
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
			 strcpy($$, $2.content);
			 //strcpy(list_of_function_names[count_names], $2.content);




		};


ident:
	IDENT
		{ 
			if ($1 == "main") {mainFunc = 1;	}
			strcpy($$.content, $1);
			strcpy($$.name, $1);
			//printf("%s",$1);
		};














declarations: 
	/* epsilon */
		{}
	| declaration SEMICOLON declarations
		{
			strcpy($$.content, $1.content);
			//strcat($$.content, ", ");
		  	strcat($$.content, $3.content);
		};

declaration: 
	idents COLON INTEGER
		{
		  	strcpy($$.content, $1.content);
			//printf("IDlist identified");
		}
	| IDENT COLON INTEGER
		{	

    	//    char *token = $1;
    	//    printf(". %s\n", token);



			strcpy($$.content, ". ");
			strcat($$.content, $1);
			strcat($$.content, "\n");

		}
	| IDENT COMMA IDENT COLON INTEGER
		{
			strcpy($$.content, ". ");
			strcat($$.content, $1);
			strcat($$.content, "\n");
			strcat($$.content, ". ");
			strcat($$.content, $3);
			strcat($$.content, "\n");
		}
	| IDENT COMMA IDENT COMMA IDENT COLON INTEGER
		{
			strcpy($$.content, "_");
			strcat($$.content, $1);
			strcat($$.content, "\n");
			strcat($$.content, "_");
			strcat($$.content, $3);
			strcat($$.content, "\n");
			strcat($$.content, "_");
			strcat($$.content, $5);
			strcat($$.content, "\n");
		}
	| IDENT COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER
		{
			strcpy($$.content, ". [] _" );			
			strcat($$.content, $1);
			strcat($$.content, ", ");			
			strcat($$.content, $5);	
			strcat($$.content, "\n");	

			//printf("number: %s", $5);
			if (strcmp($5, zero) == 0) { 
				zeroArrbool = 1;	
			
			}		
		}
	| IDENT COMMA IDENT COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER
		{
			strcpy($$.content, ". [] _" );			
			strcat($$.content, $1);
			strcat($$.content, ", _");
			strcat($$.content, $3);
			strcat($$.content, ", _");			
			strcat($$.content, $7);	
			strcat($$.content, "\n");		

			//printf("number: %s", $7);
			if (strcmp($7, zero) == 0) { 
				zeroArrbool = 1;	
			}		
		}
	| IDENT COMMA IDENT COMMA IDENT COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER
		{
			strcpy($$.content, ". [] _" );			
			strcat($$.content, $1);
			strcat($$.content, ", _");
			strcat($$.content, $3);
			strcat($$.content, ", _");
			strcat($$.content, $5);
			strcat($$.content, ", _");			
			strcat($$.content, $9);	
			strcat($$.content, "\n");				
		};


idents: 
	ident
		{
			strcpy($$.content, "_");
			strcat($$.content, $1.content);

			strcpy($$.name, $1.name);
		}
	| ident COMMA idents
		{
			strcpy($$.content, "_");
			strcat($$.content, $1.content);
			strcat($$.content, "\n, ");
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
		{
			//TODO: do control flow rules for phase3.2
		}
	| IF bool_exp THEN statements ELSE statements ENDIF
		{}
	| WHILE bool_exp BEGINLOOP statements ENDLOOP
		{}
	| DO BEGINLOOP statements ENDLOOP WHILE bool_exp
		{}
	| READ var
		{
			strcpy($$.content, ".< ");
			strcat($$.content, $2.content);
			strcat($$.content, "\n");
		}
	| READ var COMMA var
		{
			strcpy($$.content, ".< ");
			strcat($$.content, $2.content);
			strcat($$.content, "\n.< ");
			strcat($$.content, $4.content);
			strcat($$.content, "\n ");
	
		}
	| READ var COMMA var COMMA var
		{
			strcpy($$.content, ".< ");
			strcat($$.content, $2.content);
			strcat($$.content, "\n.< ");
			strcat($$.content, $4.content);
			strcat($$.content, "\n.< ");		
			strcat($$.content, $6.content);
			strcat($$.content, "\n");
		}
	| WRITE var
		{
			strcpy($$.content, ".> ");
			strcat($$.content, $2.content);
			strcat($$.content, "\n");
		}
	| WRITE var COMMA var
		{
			strcpy($$.content, ".> ");
			strcat($$.content, $2.content);
			strcat($$.content, "\n.> ");
			strcat($$.content, $4.content);
			strcat($$.content, "\n");
	
		}
	| WRITE var COMMA var COMMA var
		{
			strcpy($$.content, ".> ");
			strcat($$.content, $2.content);
			strcat($$.content, "\n.> ");
			strcat($$.content, $4.content);
			strcat($$.content, "\n.> ");		
			strcat($$.content, $6.content);
			strcat($$.content, "\n");
		}
	| READ vars
		{/*replaced with new rules above*/}
	| WRITE vars
		{/*replaced with new rules above*/}
	| CONTINUE
		{
			strcpy($$.content, "continue");
		}
	| RETURN expression
		{
			strcpy($$.content, $2.content);
			strcpy($$.name, $2.name);
		};
	
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
			strcat($$.content, "\n. __temp__\n");
			strcat($$.content, "+ __temp__, ");
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
			strcat($$.content, "+ __temp__, ");
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
			strcat($$.content, ", ");
			strcat($$.content, $1.content); 
			strcat($$.content, "\n. __temp__\n");
			strcat($$.content, "* __temp__, ");
			strcat($$.content, $1.name);
		}
	| term DIV multiplicative_expression
		{
			strcpy($$.content, $3.content);
			strcat($$.content, ", ");
			strcat($$.content, $1.content); 
			strcat($$.content, "\n. __temp__\n");
			strcat($$.content, "/__temp__, ");
			strcat($$.content, $1.name);
		}
	| term MOD multiplicative_expression
		{
			strcpy($$.content, $3.content);
			strcat($$.content, ", ");
			strcat($$.content, $1.content); 
			strcat($$.content, "\n. __temp__\n");
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
			strcpy($$.content, $1);
			strcpy($$.type, $1);
			strcpy($$.name, $1);
		}
	| SUB NUMBER
		{ 
			strcpy($$.content, "-");
			strcat($$.content, $2);
			
			strcpy($$.type, $2); 
			strcpy($$.name, $2);
		}
	| L_PAREN expression R_PAREN
		{ 
			//$$ = "SLDKFJDSLKJ";
			strcpy($$.content, $2.name);
			

		}
	| SUB L_PAREN expression R_PAREN
		{ 
			strcpy($$.content, $3.name); 
		}
	| ident L_PAREN expressions R_PAREN
		{ 
			//char *token = identToken;
     		//printf("___%s___\n", token);

			//printf("_name:__%s___\n", $1.name);
			//printf("_content:__%s___\n", $1.content);


			if (strcmp($1.content, func) == 0) { // match!
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
				 strcpy(c, $1.content);
				 //printf("---%s---\n", c);
				 
				 if (strcmp(c, list_of_function_names[i]) == 0) { 
					//funcBool = 1;
					//printf("--%s--\n", list_of_function_names[i]);

				}
   			}

			strcpy($$.content, $3.name); 
		};

expressions: 
	/* epsilon */
		{
			strcpy($$.content, ""); 
		}
	| expression
		{
			strcpy($$.content, $1.content);
		}
	| expressions COMMA expression
		{
			strcpy($$.content, $1.content);
			strcat($$.content, "\n");
			strcat($$.content, $3.content);
		};




	

bool_exp:
	relation_and_exp
		{
			strcpy($$.content, $1.content);
			strcpy($$.name, $1.name );
		}
	| bool_exp OR relation_and_exp
		{
			strcpy($$.content, $1.content);
			strcat($$.content, "\n");
			strcat($$.content, $3.content);
			strcat($$.content, "\n");	
			strcat($$.content, ". __temp__\n|| __temp__, ");		
			strcat($$.content, $1.content);
			strcat($$.content, ", ");
			strcat($$.content, $3.content);
		};

relation_and_exp:
	relation_exp
		{
			strcpy($$.content, $1.content );
			strcpy($$.name, $1.name );
		}
	| relation_and_exp AND relation_exp 
		{
			strcpy($$.content, $1.content);
			strcat($$.content, "\n");
			strcat($$.content, $3.content);
			strcat($$.content, "\n");	
			strcat($$.content, ". __temp__\n&& __temp__, ");		
			strcat($$.content, $1.content);
			strcat($$.content, ", ");
			strcat($$.content, $3.content);	
		};

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
		{strcpy($$, "==");	}
	| NEQ
		{strcpy($$, "!=");	}
	| LT
		{strcpy($$, "<");	}
	| GT
		{strcpy($$, ">");	}
	| LTE
		{strcpy($$, "<=");	}
	| GTE
		{strcpy($$, ">=");	};

var:  ident
	{	 
    	strcpy($$.content, $1.content);
		strcpy($$.type, "ident");

	}

| ident L_SQUARE_BRACKET expression R_SQUARE_BRACKET
	{ 
		//$$ = 0;  /*garbage */

		

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
			strcpy($$.content, $1.content);
			strcat($$.content, ", ");
			strcat($$.content, $3.content);
		};
	

%%

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