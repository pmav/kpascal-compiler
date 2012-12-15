/**
 * Compiladores 2008/2009
 *
 * Pedro Miguel de Almeida Verruma
 * verruma@student.dei.uc.pt
 * Nº 2006128853
 */

%{

#include <stdio.h>
#include "y.tab.h"
#include "../functions/structures.h"

%}

A [aA]
B [bB]
C [cC]
D [dD]
E [eE]
F [fF]
G [gG]
H [hH]
I [iI]
J [jJ]
K [kK]
L [lL]
M [mM]
N [nN]
O [oO]
P [pP]
Q [qQ]
R [rR]
S [sS]
T [tT]
U [uU]
V [vV]
W [wW]
X [xX]
Y [yY]
Z [zZ]

%%

{P}{R}{O}{G}{R}{A}{M}    return(PROGRAM);
{V}{A}{R}                return(VAR);
{F}{U}{N}{C}{T}{I}{O}{N} return(FUNCTION);
{I}{F}                   return(IF);
{T}{H}{E}{N}             return(THEN);
{E}{L}{S}{E}             return(ELSE);
{W}{H}{I}{L}{E}          return(WHILE);
{D}{O}                   return(DO);
{W}{R}{I}{T}{E}{L}{N}    return(WRITELN);
{B}{E}{G}{I}{N}          return(PBEGIN);
{E}{N}{D}                return(END);

{I}{N}{T}{E}{G}{E}{R}    return(DTINTEGER);
{B}{O}{O}{L}{E}{A}{N}    return(DTBOOLEAN);
{C}{H}{A}{R}             return(DTCHAR);
{S}{T}{R}{I}{N}{G}       return(DTSTRING);
{R}{E}{A}{L}             return(DTREAL);

{T}{R}{U}{E}             return(TRUE);
{F}{A}{L}{S}{E}          return(FALSE);

{O}{R}                   return(OR);
{D}{I}{V}                return(DIV);
{M}{O}{D}                return(MOD);
{A}{N}{D}                return(AND);

\'[^\']*\'              { int i; char *string = (char *)malloc(yyleng - 2);
                          for (i = 0; i < yyleng - 2; i++) {
                              string[i] = yytext[i+1];
                          }
                          yylval.string = string;
                          return STRING;
                        }

[a-zA-Z]([a-zA-Z0-9])*  { yylval.identifier = (char*)yytext; return IDENTIFIER; }
[0-9]+                  { yylval.digseq = atoi(yytext); return DIGSEQ; }
[0-9]+"."([0-9]+)?	    { yylval.fdigseq = atof(yytext); return FDIGSEQ;}

":="   return(ASSIGNMENT);

":"    return(COLON);
","    return(COMMA);
"."    return(DOT);
";"    return(SEMICOLON);

"="    return(EQUAL);
">="   return(GE);
">"    return(GT);
"<="   return(LE);
"<"    return(LT);
"<>"   return(NOTEQUAL);

"-"    return(MINUS);
"+"    return(PLUS);
"/"    return(SLASH);
"*"    return(STAR);

"("    return(LPAREN);
")"    return(RPAREN);

"(*"   |
"{"    { register int c;
         while ((c = input())) {
            if (c == '}') {
                break;
            } else {
                if (c == '*') {
                    if ((c = input()) == ')') {
                        break;
                    } else {
                        unput (c);
                    }
                } else {
                    if (c == '\n') {
                        line_number++;
                    } else {
                        if (c == 0) {
                            commenteof();
                        }
                    }
                }
            }
        }
    }

[ \t\f]    ;

\n    { line_number++; }

.     { printf("ERROR at line %d: '%c' illegal charcter!\n", line_number, yytext[0]); return 0; }

%%

commenteof() {
 fprintf (stderr, "ERROR at line %d: unexpected EOF inside comment!\n", line_number);
 return 0;
}

yywrap (void) {
}

