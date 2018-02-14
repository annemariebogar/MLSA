/* 	MLSA Multilingual Software Analysis
	This program is part of the MLSA package under development at Fordham University Department of Computer and Information Science.
	Cparse.h is the H file for Cparse.cpp, which processes strings found in the C/C++ Island Grammar to print out a CSV with all function calls that include their ID, scope (the function they are found in), name, and all arguments
 	Author: Anne Marie Bogar
 	Date: February 14, 2018
 	this code can be copied or used and is without warrenty or support, but this header needs to be copied along with the program FU2017
 	Input: N/A
 	Output: csv file
		call_id(string),scope(string),function_name(string),argument1(string),argument2(string)...
 	for arguments, all literals are encased in <> (ex: <5>)
*/

#include <iostream>
#include <string>
#include <vector>
#include "Call.h"
using namespace std;
#ifndef CPARSE_H
#define CPARSE_H

class Cparse
{
	private:
		struct Callblock{
			int type;
			int indent;
			Callblock(int t, int i) : type(t), indent(i) {}
		};
		vector<Callblock*> calltab;
		int argtab, memtab;
		bool arg, memarg;
		string sub, mem, function;
		vector<Call*> callList;

	public:
		Cparse();
		~Cparse();
		bool checkarg(int tabcount, bool tick, bool memcall);
		void markarg(int tabcount);
		void markmemarg(int tabcount);
		void checkblock(int tabcount, bool tick);
		bool checkcall(int tabcount, bool tick, bool memcall=false);
		void addCall(int type, int tabcount, bool tick, string id);
		bool addArgument(int tabcount, bool tick, string a);
		void addOp(int tabcount, bool tick, string a);
		void addMem(int tabcount, bool tick, string attr);
		void addSub(int tabcount, bool tick);
		void addFunction(int tabcount, bool tick, string f);
		void addCallName(string name);
		void addVar(int tabcount, bool tick, string a);
		void addParmVar(int tabcount, bool tick, string a);
		void cleanUp();
		void print();
};

#endif
