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

#include "Library.h"
#include "DictionaryUtil.h"
#include "FileUtil.h"
#include "../retrieve/InvertedIndex.h"
#include "../retrieve/ForwardIndex.h"
#include "../retrieve/BinaryRetrieval.h"
#include "../parser/lang/en/QueryParser.h"
#include "../ranking/DynamicScore/Cosine.h"
#include "../ranking/StaticScore/ProfScore.h"
#include "../ranking/StaticScore/QualityScore.h"

using namespace std;
using namespace boost;
class CommandLine {
public:
	InvertedIndex idex;
	ForwardIndex fdex;
	QueryParser qparser;
	BinaryRetrieval bret;
	DictionaryUtil util;
	FileUtil fUtil;
	Cosine cosRanker;

public:


	struct KeyValue{
		string key;
		string val;
	};

	struct Query{
			size_t resultCount;
			string queryString;
			list<CommandLine::KeyValue > options;
		};


public:
	CommandLine();
	virtual ~CommandLine();
	void run();
	string runQuery(string query);
	list<size_t> runQueryWeb(string query);
	CommandLine::Query parseQuery(string query);
};

#endif /* COMMANDLINE_H_ */
