// #include "lexical.h"
#include "lexical.cpp"
#include <fstream>
#include "parseTree2AST.cpp"
#include "ASTnodes.cpp"
#include "semanticAnalyse.cpp"
#include "SymbolTable.cpp"


// #include "yyheader.h"

class _Program;

using namespace std;

extern MyType* ParseTreeHead;

extern _Program* getProgram(MyType *now);
extern void SemanticAnalyse(_Program *ASTRoot);

extern int yydebug;

// extern FILE* yyin;

// extern Lexer yylexer;

void dfs(MyType *now);


extern "C"{
    int yyparse();
}



int main(int argc, char** argv){
    yyLexer = yylex_init(argv[1]);
    
    yydebug = atoi(argv[2]);
    

    int ans = yyparse();

    yylex_exit();

    if(ParseTreeHead != NULL){
        dfs(ParseTreeHead);
    }
    else cout << "main:\tParseTreeHead is null" << endl;
    


    //开始语义分析
	cout << "Start SenmanticAnalsing......" << endl;
	_Program* ASTRoot=getProgram(ParseTreeHead);
	cout << "Transforming Succeeed!" << endl;
	SemanticAnalyse(ASTRoot);//语义分析
	cout << " SenmanticAnalsing Succeed!" << endl;

	system("pause");
    


    //词法分析使用
    // lexical(argv[1]);
    // system("pause");
    // return 0;
}

void dfs(MyType* now) {//遍历语法树
	if (now->children.size() == 0) {
		if (now->type == "")
		{
            cout << now->name << "\t->\t" << "empty" << endl;
        }

		return;
	}
	cout << now->name << "\t->";
	for (int i = 0; i < now->children.size(); i++) {
		if (now->children[i]->children.size() == 0 && now->children[i]->type != "")
		{
            cout << "\t\"" << now->children[i]->name << "\"" << "(" << now->children[i]->type << ")";
            // cout << "\t\"" << now->children[i]->name << "\"" << "(" << now->children[i]->type << ")";
            //cout << "\t\"" << now->children[i]->type << "\"";
        }
		else{
            cout << "\t" << now->children[i]->name;
        }
			// cout << "\t" << now->children[i]->name;
	}
	cout << endl;
	for (int i = 0; i<now->children.size(); i++)
		dfs(now->children[i]);
}
