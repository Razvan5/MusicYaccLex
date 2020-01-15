%{
#include <stdio.h>
#include "y.tab.h"
#include <bits/stdc++.h>
using namespace std;
%}
%option noyywrap
%%

"Let the music begin:"          {yylval.strval=strdup(yytext);return PROG_BEGIN;}
"The music has ended!"          {yylval.strval=strdup(yytext);return PROG_END;}

"Concert"                       {yylval.strval=strdup(yytext);return MAIN;}
"nota_intreaga"                 {yylval.strval=strdup(yytext);return INT;}
-?[1-9][0-9]*|0                 {yylval.strval=strdup(yytext);return INT_NR;}
"nota_Re"                       {yylval.strval=strdup(yytext);return FLOAT;}
-?([1-9][0-9]*|0)\.[0-9]+       {yylval.strval=strdup(yytext);return FLOAT_NR;}
"nota_muzicala"                 {yylval.strval=strdup(yytext);return CHAR;}
\'(\\.|[^(\")\\])\'             {yylval.strval=strdup(yytext);return CHAR_VAL;}
"partitura"                     {yylval.strval=strdup(yytext);return STRING;}
\"[_a-zA-Z][_a-zA-Z0-9]*\"      {yylval.strval=strdup(yytext);return STRING_VAL;}
"gama"                          {yylval.strval=strdup(yytext);return BOOL;}
"DO"|"FA"                       {yylval.strval=strdup(yytext);return BOOL_VAL;}

"Bass"                          {yylval.strval=strdup(yytext);return CLASS;}
"Instrumente"                   {yylval.strval=strdup(yytext);return METODE;}
"Difuzor"                       {yylval.strval=strdup(yytext);return FUNCTIE;}
"Reverb"                        {yylval.strval=strdup(yytext);return RETURN;}
"Microfon"                      {yylval.strval=strdup(yytext);return OBIECT;}

"Moshpit"                       {yylval.strval=strdup(yytext);return STRUCT;}
"canta"                         {yylval.strval=strdup(yytext);return IN;}

"@Compunem"                     {yylval.strval=strdup(yytext);return DEFINE;}
"include"                       {yylval.strval=strdup(yytext);return INCLUDE;}

"proba"                         {yylval.strval=strdup(yytext);return IF;}
"altfel"                        {yylval.strval=strdup(yytext);return ELSE;}
"vocaliza"                      {yylval.strval=strdup(yytext);return SWITCH;}
"sunet"                         {yylval.strval=strdup(yytext);return CASE;}
"growl"                         {yylval.strval=strdup(yytext);return DEFAULT;}
"repetitie"                     {yylval.strval=strdup(yytext);return WHILE;}
"forte"                         {yylval.strval=strdup(yytext);return FOR;}
 
"SOL"                           {yylval.strval=strdup(yytext);return OR;}
"SI"                            {yylval.strval=strdup(yytext);return AND;}
"|="                            {yylval.strval=strdup(yytext);return NOT;}
"<<"                            {yylval.strval=strdup(yytext);return LOWT;}
">>"                            {yylval.strval=strdup(yytext);return BIGT;}
"<="                            {yylval.strval=strdup(yytext);return LEQ;}
">="                            {yylval.strval=strdup(yytext);return BEQ;}
"?="                            {yylval.strval=strdup(yytext);return EQUAL;}
"=|="                           {yylval.strval=strdup(yytext);return NOTEQUAL;}
"<->"                           {yylval.strval=strdup(yytext);return ASSIGN;}

"crescendo"                     {yylval.strval=strdup(yytext);return INCREMENT;}
"decrescendo"                   {yylval.strval=strdup(yytext);return DECREMENT;}

"Eval"                          {yylval.strval=strdup(yytext);return EVAL;}

"CheiaSol||"                    {yylval.strval=strdup(yytext);return SOL;}
"||"                            {yylval.strval=strdup(yytext);return ENDSOL;}

[_a-zA-Z][_a-zA-Z0-9]*          {yylval.strval=strdup(yytext);return ID;}
[ \t] ;
\n                              {yylineno++;}
.                               {return yytext[0];}

 
