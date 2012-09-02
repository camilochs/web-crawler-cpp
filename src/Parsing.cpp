#ifndef PARSING_
#include "Parsing.h"
#include "Filter.h"
#endif



Parsing::Parsing():_htmlTags(initTag_HTML()) {

}


//List of tag html.
std::map<int, std::string> Parsing::initTag_HTML() const{

    std::map<int, std::string> tHtmlTags;
    tHtmlTags.insert(_addTag(HTML::URL, "<a href="));
    tHtmlTags.insert(_addTag(HTML::IMAGE, "img src="));
	return tHtmlTags;
}
//add Url in vector<string>, no
void Parsing::addUrl(std::vector<std::string>& urlList, const std::string& url){

	if(!url.empty())
	{
		auto end = urlList.end();
        if(std::find(urlList.begin(), end, url) == end)   urlList.push_back(url);
	}
}

//String parser with specific tag.
std::vector<std::string> Parsing::getUrls(std::string& pattern, HTML tag){

	std::vector<std::string> urlList;
	size_t found_position = 0 , end_position = 0, init_position = 0;
	std::string _tag = _htmlTags[tag];

	while(true)
	{
		found_position  = pattern.find(_tag, found_position+1);

		if(found_position == std::string::npos) break;

		init_position = pattern.find('"', found_position + 1);
		end_position  = pattern.find('"', init_position + 1 ) - 1;

        addUrl(urlList, pattern.substr(init_position + 1, end_position - init_position) );
		//Urls.push_back( pattern.substr(init_position + 1, end_position - init_position));

		found_position = end_position + 1;
	}

	std::for_each (begin(urlList),  end(urlList),
		[](const std::string& url) {
			std::cout << url << std::endl;
		});

    return urlList;
    //urlList.clear();
	//std::cout << std::endl << "Termino";

}



Parsing::~Parsing(){

}






