%{
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
%}
%union{
  char* strval;
}
%token<strval>OBIECT 
%token<strval>FUNCTIE 
%token<strval>BOX 
%token<strval>DEFAULT 
%token<strval>CASE 
%token<strval>ELSE 
%token<strval>INCLUDE 
%token<strval>LOWT 
%token<strval>BIGT 
%token<strval>LEQ 
%token<strval>BEQ 
%token<strval>EQUAL 
%token<strval>NOTEQUAL 
%token<strval>INCREMENT 
%token<strval>DECREMENT 
%token<strval>IN 
%token<strval>MAIN 
%token<strval>PROG_BEGIN 
%token<strval>PROG_END 
%token<strval>INT 
%token<strval>INT_NR 
%token<strval>FLOAT 
%token<strval>FLOAT_NR 
%token<strval>CHAR 
%token<strval>CHAR_VAL 
%token<strval>STRING 
%token<strval>STRING_VAL 
%token<strval>BOOL 
%token<strval>BOOL_VAL 
%token<strval>CLASS 
%token<strval>METODE 
%token<strval>STRUCT 
%token<strval>ASSIGN 
%token<strval>DEFINE 
%token<strval>IF 
%token<strval>SWITCH 
%token<strval>WHILE
%token<strval>FOR 
%token<strval>OR 
%token<strval>AND 
%token<strval>NOT 
%token<strval>SOL 
%token<strval>ENDSOL 
%token<strval>ID 
%token<strval>EVAL
%token<strval>RETURN
%start start
%left LOWT BIGT LEQ BEQ EQUAL NOTEQUAL AND OR
%%
start: PROG_BEGIN continut PROG_END 
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
;
continut:includeSiDefinuri  beforeMain functiiSiClase onlyMain
        ;
beforeMain:'^'initializari beforeMain 
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
          |'^'initializari 
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
          ;

includeSiDefinuri:'#' INCLUDE '{'ID'}' includeSiDefinuri
                 |DEFINE ID INT_NR includeSiDefinuri 
                 {
                        //verificare redeclarare
                        for (iterator_symbol_table = symbol_table.begin(); iterator_symbol_table != symbol_table.end(); iterator_symbol_table++) {
                                
                                string repeatingConstant($<strval>2);
                                
                                if(get<0>(iterator_symbol_table->second)==repeatingConstant){
                                        printf("Constanta redeclarata la linia %d \n",yylineno);
                                        return -1;
                                }

                        }
                        //inserare const
                        lista_var.insert(make_pair("int", $<strval>3));
                        continut=make_tuple($<strval>2, lista_var, "CST", "0", yylineno);
                        symbol_table.insert(make_pair("GLOBAL",continut));
                        //stergere
                        lista_var.clear();
                 }
                 |'#' INCLUDE '{'ID'}'
                 |DEFINE ID INT_NR 
                 {
                        //inserare const
                        lista_var.insert(make_pair("int", $<strval>3));
                        continut=make_tuple($<strval>2, lista_var, "CST", "0", yylineno);
                        symbol_table.insert(make_pair("GLOBAL",continut));
                        //stergere
                        lista_var.clear();

                 }
                 ;

/*sectiunea functii si clase*/
functiiSiClase: functii functiiSiClase
              | clase functiiSiClase
              | /*epsilon*/
              ;

functii:INT FUNCTIE ID '{'parametrii'}' SOL continut_main ENDSOL
        {
                //cout<<$<strval>8<<' ';    
           
                multimap<string, string>temporar;
                temporar.insert(make_pair("0","NA-1"));

                string numeFunctieCuSignatura=$<strval>3;

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
       |FLOAT FUNCTIE ID '{'parametrii'}' SOL continut_main ENDSOL
       {
                multimap<string, string>temporar;
                temporar.insert(make_pair("0","NA-1"));

                string numeFunctieCuSignatura=$<strval>3;

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
       |CHAR FUNCTIE ID '{'parametrii'}' SOL continut_main ENDSOL
       {
                multimap<string, string>temporar;
                temporar.insert(make_pair("0","NA-1"));

                string numeFunctieCuSignatura=$<strval>3;

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
       |STRING FUNCTIE ID '{'parametrii'}' SOL continut_main ENDSOL
       {
                multimap<string, string>temporar;
                temporar.insert(make_pair("0","NA-1"));

                string numeFunctieCuSignatura=$<strval>3;

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
       |BOOL FUNCTIE ID '{'parametrii'}' SOL continut_main ENDSOL
       {
                multimap<string, string>temporar;
                temporar.insert(make_pair("0","NA-1"));

                string numeFunctieCuSignatura=$<strval>3;

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
       ; 
/*mergem doar la inturi acum*/
parametrii: INT ID box ',' parametrii
          {                  
                lista_var.insert(make_pair("int", $<strval>2));
          }
          | FLOAT ID box ',' parametrii
          {    
                lista_var.insert(make_pair("float", $<strval>2));
          }
          | CHAR ID box ',' parametrii
          {
                lista_var.insert(make_pair("char", $<strval>2));
          }
          | STRING ID ',' parametrii
          {
                lista_var.insert(make_pair("string", $<strval>2));
          }
          | BOOL ID box ',' parametrii
          {
                lista_var.insert(make_pair("bool", $<strval>2));
          }

          | INT ID box
          {
                lista_var.insert(make_pair("int", $<strval>2));
          }
          | FLOAT ID box
          {
                lista_var.insert(make_pair("float", $<strval>2));
          }
          | CHAR ID box
          {
                lista_var.insert(make_pair("char", $<strval>2));
          }
          | STRING ID 
          {
                lista_var.insert(make_pair("string", $<strval>2));
          }
          | BOOL ID box
          {
                lista_var.insert(make_pair("bool", $<strval>2));
          }
         
          | CHAR ID box ASSIGN ID box ',' parametrii
          {
                lista_var.insert(make_pair("char", $<strval>2));

          }
          
          | CHAR ID box ASSIGN ID box
          {
                lista_var.insert(make_pair("char", $<strval>2));

          }
         
          | CHAR ID box ASSIGN CHAR_VAL ',' parametrii
          {     
                //cout<<"merge"<<$<strval>2<<' ';
                nume_valoare_parametru[$<strval>2]=$<strval>5;  
                lista_var.insert(make_pair("char", $<strval>2));
          }
          
          | CHAR ID box ASSIGN CHAR_VAL
          {
                //cout<<"merge"<<$<strval>2<<' ';  
                nume_valoare_parametru[$<strval>2]=$<strval>5;    
                lista_var.insert(make_pair("char", $<strval>2));

          }
          | INT ID box ASSIGN expresie ',' parametrii
          {
                nume_valoare_parametru[$<strval>2]=$<strval>5;    
                lista_var.insert(make_pair("int", $<strval>2));

          }
          | FLOAT ID box ASSIGN expresie ',' parametrii
          {
                nume_valoare_parametru[$<strval>2]=$<strval>5;    
                lista_var.insert(make_pair("float", $<strval>2));

          }
          | STRING ID box ASSIGN expresie ',' parametrii
          {
                nume_valoare_parametru[$<strval>2]=$<strval>5;    
                lista_var.insert(make_pair("string", $<strval>2));

          }
          | BOOL ID box ASSIGN expresie_bool ',' parametrii
          {
                //cout<<$<strval>5;
                nume_valoare_parametru[$<strval>2]=$<strval>5;
                lista_var.insert(make_pair("bool", $<strval>2));
          }
          | INT ID box ASSIGN expresie
          { 
                nume_valoare_parametru[$<strval>2]=$<strval>5;
                lista_var.insert(make_pair("int", $<strval>2));

          }
          | FLOAT ID box ASSIGN expresie
          {
                nume_valoare_parametru[$<strval>2]=$<strval>5;
                lista_var.insert(make_pair("float", $<strval>2));

          }
          | STRING ID box ASSIGN expresie
          {
                nume_valoare_parametru[$<strval>2]=$<strval>5;
                lista_var.insert(make_pair("string", $<strval>2));

          }
          | BOOL ID box ASSIGN expresie_bool
          {
                nume_valoare_parametru[$<strval>2]=$<strval>5;
                lista_var.insert(make_pair("bool", $<strval>2));
          }
          ;
clase:CLASS ID SOL continut_clasa ENDSOL
        {
                multimap<string,string> temporar,temporar2;
                temporar2.insert(make_pair("0","NA-1"));
                for(auto i : lista_fct_init){
                        temporar.insert(make_pair(get<0>(i),get<1>(i)));

                        continut=make_tuple(get<1>(i),lista_var, "VAR", get<0>(i), 0);
                        symbol_table.insert(make_pair($<strval>2,continut)); 
                }
                for(auto g: lista_global_init){
                        temporar.insert(make_pair(get<0>(g),get<1>(g)));

                        continut=make_tuple(get<1>(g), lista_var, "FCT", get<0>(g), 0);
                        symbol_table.insert(make_pair($<strval>2,continut)); 
                }
                continut=make_tuple($<strval>2, temporar, "CLS", "0", 0);
                symbol_table.insert(make_pair("GLOBAL",continut)); 
                temporar.clear();
                lista_fct_init.clear();
                lista_global_init.clear();

        }
     ;
continut_clasa:OBIECT SOL initializari_clasa ENDSOL METODE SOL functii_clasa ENDSOL
              {
                        $<strval>$=$<strval>3;
              }
              ;
functii_clasa:INT METODE ID '{'parametrii'}' SOL continut_main ENDSOL functii_clasa
             {
                string numeMetodaCuSignatura=$<strval>3;
                for(auto v:lista_var){
                        numeMetodaCuSignatura+=("_"+get<0>(v));
                }
                lista_global_init.insert(make_tuple("int",numeMetodaCuSignatura,"FCT","0"));
                lista_var.clear();
             }
             |FLOAT METODE ID '{'parametrii'}' SOL continut_main ENDSOL functii_clasa  
             {
                      string numeMetodaCuSignatura=$<strval>3;
                for(auto v:lista_var){
                        numeMetodaCuSignatura+=("_"+get<0>(v));
                }
                lista_global_init.insert(make_tuple("float",numeMetodaCuSignatura,"FCT","0"));
                lista_var.clear();
             }
             |CHAR METODE ID '{'parametrii'}' SOL continut_main ENDSOL functii_clasa
             {
                      string numeMetodaCuSignatura=$<strval>3;
                for(auto v:lista_var){
                        numeMetodaCuSignatura+=("_"+get<0>(v));
                }
                lista_global_init.insert(make_tuple("char",numeMetodaCuSignatura,"FCT","0"));
                lista_var.clear();
             }
             |STRING METODE ID '{'parametrii'}' SOL continut_main ENDSOL functii_clasa
             {
                      string numeMetodaCuSignatura=$<strval>3;
                for(auto v:lista_var){
                        numeMetodaCuSignatura+=("_"+get<0>(v));
                }
                lista_global_init.insert(make_tuple("string",numeMetodaCuSignatura,"FCT","0"));
                lista_var.clear();
             }
             |BOOL METODE ID '{'parametrii'}' SOL continut_main ENDSOL functii_clasa
             {
                      string numeMetodaCuSignatura=$<strval>3;
                for(auto v:lista_var){
                        numeMetodaCuSignatura+=("_"+get<0>(v));
                }
                lista_global_init.insert(make_tuple("bool",numeMetodaCuSignatura,"FCT","0"));
                lista_var.clear();
             }
             
             |INT METODE ID '{'parametrii'}' SOL continut_main ENDSOL
             {
                      string numeMetodaCuSignatura=$<strval>3;
                for(auto v:lista_var){
                        numeMetodaCuSignatura+=("_"+get<0>(v));
                }
                lista_global_init.insert(make_tuple("int",numeMetodaCuSignatura,"FCT","0"));
                lista_var.clear();
             }
             |FLOAT METODE ID '{'parametrii'}' SOL continut_main ENDSOL
             {
                      string numeMetodaCuSignatura=$<strval>3;
                for(auto v:lista_var){
                        numeMetodaCuSignatura+=("_"+get<0>(v));
                }
                lista_global_init.insert(make_tuple("float",numeMetodaCuSignatura,"FCT","0"));
                lista_var.clear();
             }
             |CHAR METODE ID '{'parametrii'}' SOL continut_main ENDSOL
             {
                      string numeMetodaCuSignatura=$<strval>3;
                for(auto v:lista_var){
                        numeMetodaCuSignatura+=("_"+get<0>(v));
                }
                lista_global_init.insert(make_tuple("char",numeMetodaCuSignatura,"FCT","0"));
                lista_var.clear();
             }
             |STRING METODE ID '{'parametrii'}' SOL continut_main ENDSOL
             {
                      string numeMetodaCuSignatura=$<strval>3;
                for(auto v:lista_var){
                        numeMetodaCuSignatura+=("_"+get<0>(v));
                }
                lista_global_init.insert(make_tuple("string",numeMetodaCuSignatura,"FCT","0"));
                lista_var.clear();
             }
             |BOOL METODE ID '{'parametrii'}' SOL continut_main ENDSOL
             {
                      string numeMetodaCuSignatura=$<strval>3;
                for(auto v:lista_var){
                        numeMetodaCuSignatura+=("_"+get<0>(v));
                }
                lista_global_init.insert(make_tuple("bool",numeMetodaCuSignatura,"FCT","0"));
                lista_var.clear();
             }
             ;
        
/*sectiunea main*/
onlyMain:MAIN SOL continut_main ENDSOL
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
        ;
continut_main: initializari continut_main
                {
                        $<strval>$=$<strval>1;
                        
                        //cout<<$<strval>1<<endl;

                }
             | instructiuni continut_main
             | atribuiri continut_main
             | '@' expresie continut_main
             | eval_fct continut_main
             | returnuri continut_main

             | initializari
             {
                     //cout<<$<strval>1<<endl;
                     $<strval>$=$<strval>1;
             }
             | instructiuni
             | atribuiri
             | '@' expresie
             | eval_fct
             | returnuri
             ;
/*sectiunea returnuri*/
returnuri:RETURN ID;
/*sectiunea init*/
initializari: INT init_nr 
            {       //cout<<$<strval>2<<endl;
                    $<strval>$=$<strval>2;
            }
            | FLOAT init_float
            {
                    $<strval>$=$<strval>2;
            }
            | CHAR init_char 
            {
                    $<strval>$=$<strval>2;
            }
            | STRING init_string 
            {
                    $<strval>$=$<strval>2;
            }
            | BOOL init_bool 
            {
                    //cout<<$<strval>2;
                    $<strval>$=$<strval>2;
            }
            ;

initializari_clasa: INT init_nr initializari_clasa
                  {
                        $<strval>$=$<strval>2;
                  }
                  | FLOAT init_float initializari_clasa
                  {
                        $<strval>$=$<strval>2;

                  }
                  | CHAR init_char initializari_clasa
                  {
                        $<strval>$=$<strval>2;

                  }
                  | STRING init_string initializari_clasa
                  {
                        $<strval>$=$<strval>2;

                  }
                  | BOOL init_bool initializari_clasa
                  {

                        $<strval>$=$<strval>2;
                  }
                  | initializari
                  {
                        $<strval>$=$<strval>1;
                  }
                  ;
box:'['expresie']' box
   |/*epsilon*/
   ;

init_nr: ID box ',' init_nr 
        {
                 for(auto l:lista_fct_init){
                        if($<strval>1==get<1>(l)){
                                printf("1.Rescriere variabila intr-o initializare la linia %d\n",yylineno);
                                return -5;
                        }
                } 
                lista_fct_init.insert(make_tuple("int",$<strval>1,"NA-1","VAR"));
                lista_if_init.insert(make_tuple("int",$<strval>1,"NA-1","VAR"));

               
        } 
        | ID ASSIGN expresie ',' init_nr
        {
                
                 for(auto l:lista_fct_init){
                        if($<strval>1==get<1>(l)){
                                printf("2.Rescriere variabila intr-o initializare la linia %d\n",yylineno);
                                return -5;
                        }
                } 
                
                $<strval>$=$<strval>3;
                lista_fct_init.insert(make_tuple("int",$<strval>1,$<strval>3,"VAR"));
                 lista_if_init.insert(make_tuple("int",$<strval>1,$<strval>3,"VAR"));

                
                
        }
        | ID box
        {
                for(auto l:lista_fct_init){
                        if($<strval>1==get<1>(l)){
                                printf("3.Rescriere variabila intr-o initializare la linia %d\n",yylineno);
                                return -5;
                        }
                } 
                lista_fct_init.insert(make_tuple("int",$<strval>1,"NA-1","VAR"));
                lista_if_init.insert(make_tuple("int",$<strval>1,"NA-1","VAR"));

                
        } 
        | ID ASSIGN expresie
        {

                for(auto l:lista_fct_init){
                        if($<strval>1==get<1>(l)){
                                printf("4.Rescriere variabila intr-o initializare la linia %d\n",yylineno);
                                return -5;
                        }
                } 
                $<strval>$=$<strval>3;
                lista_fct_init.insert(make_tuple("int",$<strval>1,$<strval>3,"VAR"));
                 lista_if_init.insert(make_tuple("int",$<strval>1,$<strval>3,"VAR"));


        }
        ;
init_float:ID box ',' init_float
        {
               
               for(auto l:lista_fct_init){
                        if($<strval>1==get<1>(l)){
                                printf("5.Rescriere variabila intr-o initializare la linia %d\n",yylineno);
                                return -5;
                        }
                } 
                lista_fct_init.insert(make_tuple("float",$<strval>1,"NA-1","VAR"));
                lista_if_init.insert(make_tuple("float",$<strval>1,"NA-1","VAR"));
                
        } 
        | ID ASSIGN expresie ',' init_float
        {
                
               for(auto l:lista_fct_init){
                        if($<strval>1==get<1>(l)){
                                printf("6.Rescriere variabila intr-o initializare la linia %d\n",yylineno);
                                return -5;
                        }
                } 
                $<strval>$=$<strval>3;
                lista_fct_init.insert(make_tuple("float",$<strval>1,$<strval>3,"VAR"));
                lista_if_init.insert(make_tuple("float",$<strval>1,"NA-1","VAR"));

        }
        | ID box
        {
               
               for(auto l:lista_fct_init){
                        if($<strval>1==get<1>(l)){
                                printf("7.Rescriere variabila intr-o initializare la linia %d\n",yylineno);
                                return -5;
                        }
                } 
                lista_fct_init.insert(make_tuple("float",$<strval>1,"NA-1","VAR"));
                lista_if_init.insert(make_tuple("float",$<strval>1,"NA-1","VAR"));

        } 
        | ID ASSIGN expresie
        {  
                
                $<strval>$=$<strval>3;
                lista_fct_init.insert(make_tuple("float",$<strval>1,$<strval>3,"VAR"));
                lista_if_init.insert(make_tuple("float",$<strval>1,"NA-1","VAR"));

        }
        ;

init_char: ID box ',' init_char
         {
                for(auto l:lista_fct_init){
                        if($<strval>1==get<1>(l)){
                                printf("8.Rescriere variabila intr-o initializare la linia %d\n",yylineno);
                                return -5;
                        }
                } 
                lista_fct_init.insert(make_tuple("char",$<strval>1,"NA-1","VAR"));
                lista_if_init.insert(make_tuple("char",$<strval>1,"NA-1","VAR"));

         }
         | ID ASSIGN CHAR_VAL ',' init_char
         {
                 for(auto l:lista_fct_init){
                        if($<strval>1==get<1>(l)){
                                printf("9.Rescriere variabila intr-o initializare la linia %d\n",yylineno);
                                return -5;
                        }
                } 
                lista_fct_init.insert(make_tuple("char",$<strval>1,$<strval>3,"VAR"));
                lista_if_init.insert(make_tuple("char",$<strval>1,$<strval>3,"VAR"));

         }
         | ID ASSIGN ID box ',' init_char
         {
                 for(auto l:lista_fct_init){
                        if($<strval>1==get<1>(l)){
                                printf("10.Rescriere variabila intr-o initializare la linia %d\n",yylineno);
                                return -5;
                        }
                } 
                lista_fct_init.insert(make_tuple("char",$<strval>1,$<strval>3,"VAR"));
                lista_if_init.insert(make_tuple("char",$<strval>1,$<strval>3,"VAR"));

         }
         | ID box
         {
                 for(auto l:lista_fct_init){
                        if($<strval>1==get<1>(l)){
                                printf("11.Rescriere variabila intr-o initializare la linia %d\n",yylineno);
                                return -5;
                        }
                } 
                lista_fct_init.insert(make_tuple("char",$<strval>1,"NA-1","VAR"));
                lista_if_init.insert(make_tuple("char",$<strval>1,"NA-1","VAR"));

         }
         | ID ASSIGN CHAR_VAL
         {
                 for(auto l:lista_fct_init){
                        if($<strval>1==get<1>(l)){
                                printf("12.Rescriere variabila intr-o initializare la linia %d\n",yylineno);
                                return -5;
                        }
                } 
                lista_fct_init.insert(make_tuple("char",$<strval>1,$<strval>3,"VAR"));
                lista_if_init.insert(make_tuple("char",$<strval>1,$<strval>3,"VAR"));

         }
         | ID ASSIGN ID box
         {
                 for(auto l:lista_fct_init){
                        if($<strval>1==get<1>(l)){
                                printf("13.Rescriere variabila intr-o initializare la linia %d\n",yylineno);
                                return -5;
                        }
                } 
                lista_fct_init.insert(make_tuple("char",$<strval>1,$<strval>3,"VAR"));
                lista_if_init.insert(make_tuple("char",$<strval>1,$<strval>3,"VAR"));

         }
         ;
init_string: ID ',' init_string
           {
                   for(auto l:lista_fct_init){
                        if($<strval>1==get<1>(l)){
                                printf("14.Rescriere variabila intr-o initializare la linia %d\n",yylineno);
                                return -5;
                        }
                } 
                lista_fct_init.insert(make_tuple("string",$<strval>1,"NA-1","VAR"));
                lista_if_init.insert(make_tuple("string",$<strval>1,"NA-1","VAR"));

           }
           | ID ASSIGN expresie ',' init_string
           {
                   for(auto l:lista_fct_init){
                        if($<strval>1==get<1>(l)){
                                printf("15.Rescriere variabila intr-o initializare la linia %d\n",yylineno);
                                return -5;
                        }
                } 
                $<strval>$=$<strval>3;
                lista_fct_init.insert(make_tuple("string",$<strval>1,$<strval>3,"VAR"));
                lista_if_init.insert(make_tuple("string",$<strval>1,$<strval>3,"VAR"));
           }
           | ID 
           {
                   for(auto l:lista_fct_init){
                        if($<strval>1==get<1>(l)){
                                printf("16.Rescriere variabila intr-o initializare la linia %d\n",yylineno);
                                return -5;
                        }
                } 
                lista_fct_init.insert(make_tuple("string",$<strval>1,"NA-1","VAR"));
                lista_if_init.insert(make_tuple("string",$<strval>1,"NA-1","VAR"));

           }
           | ID ASSIGN expresie
           {
                   for(auto l:lista_fct_init){
                        if($<strval>1==get<1>(l)){
                                printf("17.Rescriere variabila intr-o initializare la linia %d\n",yylineno);
                                return -5;
                        }
                } 
                $<strval>$=$<strval>3;
                lista_fct_init.insert(make_tuple("string",$<strval>1,$<strval>3,"VAR"));
                lista_if_init.insert(make_tuple("string",$<strval>1,$<strval>3,"VAR"));

           }
           ;
init_bool:  ID box ',' init_bool
          {
                  for(auto l:lista_fct_init){
                        if($<strval>1==get<1>(l)){
                                printf("18.Rescriere variabila intr-o initializare la linia %d\n",yylineno);
                                return -5;
                        }
                } 
                lista_fct_init.insert(make_tuple("bool",$<strval>1,"NA-1","VAR"));
                lista_if_init.insert(make_tuple("bool",$<strval>1,"NA-1","VAR"));

          }
          | ID box ASSIGN expresie_bool ',' init_bool
          {
                  for(auto l:lista_fct_init){
                        if($<strval>1==get<1>(l)){
                                printf("19.Rescriere variabila intr-o initializare la linia %d\n",yylineno);
                                return -5;
                        }
                } 
                $<strval>$=$<strval>4;
                lista_fct_init.insert(make_tuple("bool",$<strval>1,$<strval>4,"VAR"));
                lista_if_init.insert(make_tuple("bool",$<strval>1,$<strval>4,"VAR"));

          }
          | ID box
          {
                  for(auto l:lista_fct_init){
                        if($<strval>1==get<1>(l)){
                                printf("20.Rescriere variabila intr-o initializare la linia %d\n",yylineno);
                                return -5;
                        }
                } 
                lista_fct_init.insert(make_tuple("bool",$<strval>1,"NA-1","VAR"));
                lista_if_init.insert(make_tuple("bool",$<strval>1,"NA-1","VAR"));
          }
          | ID box ASSIGN expresie_bool
          {
                  for(auto l:lista_fct_init){
                        if($<strval>1==get<1>(l)){
                                printf("21.Rescriere variabila intr-o initializare la linia %d\n",yylineno);
                                return -5;
                        }
                }

                $<strval>$=$<strval>4;
                lista_fct_init.insert(make_tuple("bool",$<strval>1,$<strval>4,"VAR"));
                lista_if_init.insert(make_tuple("bool",$<strval>1,$<strval>4,"VAR"));
          }
          ;
/*sectiunea atribuiri*/
atribuiri:ID box ASSIGN CHAR_VAL
         {

         }
         |ID box ASSIGN expresie 
         {

         }
         |ID box ASSIGN expresie_bool
         ;
/*sectiunea  expresie*/

expresie: '('expresie '+' expresie ')'
        { 

                if(strchr($<strval>2,'.')!=NULL && strchr($<strval>4,'.')!=NULL){
                        sprintf($<strval>$,"%.2f",(atof($<strval>2) + atof($<strval>4))); 
                }
                else 
                if(strchr($<strval>2,'\"')!=NULL && strchr($<strval>4,'\"')!=NULL){
                        char s[200],t[200];
                        strcpy(s,$<strval>2);
                        s[strlen(s)-1]='\0';
                        strcpy(t,$<strval>4+1);

                        sprintf($<strval>$,"%s",strcat(s,t)); 
                }
                else if(atoi($<strval>2)!=0 && atoi($<strval>4)!=0){
                        sprintf($<strval>$,"%d",(atoi($<strval>2) + atoi($<strval>4))); 
                }
                else{
                     printf("Eroare de tipuri diferite in expresie deasupra liniei %d\n ",yylineno);
                        return -11;
                }
                
        }
        | '('expresie '~' expresie ')' 
        {
                if(strchr($<strval>2,'.')!=NULL && strchr($<strval>2,'.')!=NULL){
                        sprintf($<strval>$,"%.2f",(atof($<strval>2) - atof($<strval>4))); 
                }
                else
                sprintf($<strval>$,"%d",(atoi($<strval>2) - atoi($<strval>4)));
        }
        | '('expresie '/' expresie ')'
        {
                if(strchr($<strval>2,'.')!=NULL && strchr($<strval>2,'.')!=NULL){
                        sprintf($<strval>$,"%.2f",(atof($<strval>2) / atof($<strval>4))); 
                }
                else sprintf($<strval>$,"%d",(atoi($<strval>2) / atoi($<strval>4))); 
        } 
        | '('expresie '*' expresie ')' 
        {
                if(strchr($<strval>2,'.')!=NULL && strchr($<strval>2,'.')!=NULL){
                        sprintf($<strval>$,"%.2f",(atof($<strval>2) * atof($<strval>4))); 
                }
                else sprintf($<strval>$,"%d",(atoi($<strval>2) * atoi($<strval>4))); 
        }
        | INT_NR 
        {
          $<strval>$=$<strval>1;
        }
        | FLOAT_NR
        {
         $<strval>$=$<strval>1;
        }
        | STRING_VAL
        {
         $<strval>$=$<strval>1;
        }
        | ID box
        {
                
          for(auto i:symbol_table){
                  if(i.first=="GLOBAL"  && get<0>(i.second)==$<strval>1){
                        //cout<<get<0>(i.second);
                         for(auto j:(get<1>(i.second)))
                                strcpy($<strval>$,j.second.c_str());
                  }
          }
         
          
        }
        | apel_fct
        {
                $<strval>$=0;
        }
        | apel_clasa
        {
                $<strval>$=0;
        }
        ;

expresie_bool: '(' expresie_bool OR expresie_bool ')'
             {
                     if(strcmp($<strval>3,"DO")==0){
                              $<strval>$="DO";
                     }
                     else  $<strval>$=$<strval>4;
             }
             | '(' expresie_bool AND expresie_bool ')'
             {
                     if(strcmp($<strval>3,"FA")==0){
                              $<strval>$="FA";
                     }
                     else  $<strval>$=$<strval>4;
             }
             | '(' ID OR ID ')'
             {
                
             }
             | '(' ID AND ID ')'
             {

             }
             | '(' ID AND expresie_bool ')'
             {

             }
             | '(' expresie_bool OR ID ')'
             {

             }
             | NOT '('expresie_bool')'
             {
                     if(strcmp($<strval>3,"DO")==0){
                             $<strval>$="FA";
                     }
                     else $<strval>$="DO";
             }
             | '(' rezultat operatie_bool rezultat ')'
             {
                     
                if(strcmp($<strval>3,"<<")==0){
                      if(atoi($<strval>2) < atoi($<strval>4)){
                            $<strval>$="DO";
                      }
                      else $<strval>$="FA";
                }
                if(strcmp($<strval>3,">>")==0){
                        if(atoi($<strval>2) > atoi($<strval>4)){
                            $<strval>$="DO";
                      }
                      else $<strval>$="FA";
                        
                }
                if(strcmp($<strval>3,"?=")==0){
                        if(atoi($<strval>2) == atoi($<strval>4)){
                            $<strval>$="DO";
                      }
                      else $<strval>$="FA";
                        
                }
                if(strcmp($<strval>3,"<=")==0){
                        if(atoi($<strval>2) <= atoi($<strval>4)){
                            $<strval>$="DO";
                      }
                      else $<strval>$="FA";
                        
                }
                if(strcmp($<strval>3,">=")==0){
                        if(atoi($<strval>2) >= atoi($<strval>4)){
                            $<strval>$="DO";
                      }
                      else $<strval>$="FA";
                        
                }
                if(strcmp($<strval>3,"=|=")==0){
                        if(atoi($<strval>2) != atoi($<strval>4)){
                            $<strval>$="DO";
                      }
                      else $<strval>$="FA";
                        
                }
             }
             | BOOL_VAL
             {
                $<strval>$=$<strval>1;
             }
             ;

rezultat:ID box
        {
                $<strval>$=$<strval>1;
        }
        |INT_NR
        {
                $<strval>$=$<strval>1; 
        }
        |FLOAT_NR
        {
                $<strval>$=$<strval>1;
        }
        |apel_fct
        {
                $<strval>$=0;
        }
        |apel_clasa
        {
                $<strval>$=0;
        }
        ;
operatie_bool:LOWT
             {
                      $<strval>$=$<strval>1;
             }
             |BIGT
             {
                     $<strval>$=$<strval>1;
             }
             |LEQ
             {
                     $<strval>$=$<strval>1;
             }
             |BEQ
             {
                     $<strval>$=$<strval>1;
             }
             |EQUAL
             {
                     $<strval>$=$<strval>1;
             }
             |NOTEQUAL
             {
                     $<strval>$=$<strval>1;
             }
             ;

/*sectiunea instructiuni*/

instructiuni: while_instruct
            | if_instruct
            | for_instruct
            ;
while_instruct:WHILE '{' expresie_bool '}' SOL continut_main ENDSOL
              {
                        
              }
              ;
if_instruct:IF '{' expresie_bool '}' SOL continut_main ENDSOL ELSE SOL continut_main ENDSOL
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
           |IF '{' expresie_bool '}' SOL continut_main ENDSOL
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
           ;
for_instruct:FOR '{'atribuiri '|' expresie_bool '|' ID box INCREMENT'}'SOL continut_main ENDSOL
            |FOR '{'atribuiri '|' expresie_bool '|' ID box DECREMENT'}'SOL continut_main ENDSOL
            ;

/*aperui fct*/
apel_fct: ID '{' apel_fct_parametrii '}'
        {
                signaturaApel=$<strval>1+signaturaApel;
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
        ;
apel_fct_parametrii:
                   |CHAR_VAL ',' apel_fct_parametrii
                   {
                           signaturaApel="_char"+signaturaApel;
                           //cout<<signaturaApel;
                   }
                   |expresie ',' apel_fct_parametrii
                   {

                           if(strchr($<strval>1,'.')!=NULL)
                           {
                                signaturaApel="_float"+signaturaApel;
                           }
                           else
                           if($<strval>1[0]=='-' || $<strval>1[0]=='0' || $<strval>1[0]=='1'|| $<strval>1[0]=='2' || $<strval>1[0]=='3' || $<strval>1[0]=='4' || $<strval>1[0]=='5' || $<strval>1[0]=='6' || $<strval>1[0]=='7' || $<strval>1[0]=='8' || $<strval>1[0]=='9')
                           {
                                signaturaApel="_int"+signaturaApel;
                           }
                           else  signaturaApel="_string"+signaturaApel;
                           
                   }
                   |expresie_bool ',' apel_fct_parametrii
                   {
                        signaturaApel="_bool"+signaturaApel;
                   }
                   |atribuiri ',' apel_fct_parametrii
                  
                   |CHAR_VAL
                   {
                           signaturaApel="_char"+signaturaApel;
                   }
                   |expresie
                   {
                           if(strchr($<strval>1,'.')!=NULL)
                           {
                                signaturaApel="_float"+signaturaApel;
                           }
                           else
                           if($<strval>1[0]=='-' || $<strval>1[0]=='0' || $<strval>1[0]=='1'|| $<strval>1[0]=='2' || $<strval>1[0]=='3' || $<strval>1[0]=='4' || $<strval>1[0]=='5' || $<strval>1[0]=='6' || $<strval>1[0]=='7' || $<strval>1[0]=='8' || $<strval>1[0]=='9')
                           {
                                signaturaApel="_int"+signaturaApel;
                           }
                           else signaturaApel="_string"+signaturaApel;
                           
                   }
                   |expresie_bool
                   {
                           signaturaApel="_bool"+signaturaApel;
                   }
                   |atribuiri
                   ;
apel_clasa:ID '.' ID box
          {
                  bool isClassAlright=false;
                  for(auto x:symbol_table){
                          if((x.first)=="GLOBAL" && get<2>(x.second)=="CLS"){
                                if($<strval>1==get<0>(x.second)){
                                         for(auto q:symbol_table){
                                                 if(q.first==$<strval>1 && get<0>(q.second)==$<strval>3){
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
          |ID '.' apel_fct
          {
                  bool isClassAlright=false;
                  for(auto x:symbol_table){
                          if((x.first)=="GLOBAL" && get<2>(x.second)=="CLS"){
                                if($<strval>1==get<0>(x.second)){
                                        for(auto q:symbol_table){
                                                 if(q.first==$<strval>1 && get<0>(q.second)==$<strval>3){
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
          ;
/*sectiunea eval*/
eval_fct:EVAL '{'expresie_bool'}'
        {
                cout<<"Valoare returnata: "<<$<strval>3<<endl;
        }
        |EVAL '{'expresie'}'
        {
                cout<<"Valoare returnata: "<<$<strval>3<<endl;
        }
        ;

%%
int yyerror(char * s){
printf("eroare: %s la linia:%d\n",s,yylineno);
}

int main(int argc, char** argv){
        
        yyin=fopen(argv[1],"r");
        yyparse();
}