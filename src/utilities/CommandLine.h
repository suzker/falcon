/*
 * CommandLine.h
 *
 *  Created on: Oct 29, 2011
 *      Author: bhatt
 *
 *      Used for commandline processing of the TREC query
 *      terminates on exit
 */

#ifndef COMMANDLINE_H_
#define COMMANDLINE_H_

#include "Library.h";
#include "../retrieve/InvertedIndex.h"
#include "../retrieve/BinaryRetrieval.h"
#include "../parser/lang/en/QueryParser.h"

using namespace std;
class CommandLine {
public:
	InvertedIndex idex;
	QueryParser qparser;
	BinaryRetrieval bret;

public:
	CommandLine();
	virtual ~CommandLine();
	void run();
	string runQuery(string query);
};

#endif /* COMMANDLINE_H_ */
