// ---------------------------------------------------------------------------
// Webcrawler 0.0.1
//
//
//
// Parsing.h
//
//
// Author: Camilo Chacon Sartori
// ---------------------------------------------------------------------------
#ifndef PARSING_
#define PARSING_

#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <iostream>

enum HTML{
		URL,
		IMAGE
    };



class Parsing{


public:
	Parsing();
	~Parsing();

	///Return all urls of document(webpage).
	std::vector<std::string> getUrls(std::string& buffer,  HTML tag);

private:
	std::map<int, std::string> initTag_HTML() const;
	void addUrl(std::vector<std::string>& urlList, const std::string& url);

	typedef std::pair<int, std::string> _addTag;
	std::map<int, std::string> _htmlTags;


};


#endif
