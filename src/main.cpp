
#include <memory>
#include "WebCrawler.h"
#include <iostream>

using namespace std;


int main(){


    vector<string> urls;

    //Example
    urls.push_back( "http://www.emol.com" );

  /*  urls.push_back( "http://www.emol.com" );
    urls.push_back( "http://www.fayerwayer.com" );
    urls.push_back( "http://www.latercera.com" );
    urls.push_back( "http://www.lasegunda.com" );
    urls.push_back( "http://www.chile.com" );
    urls.push_back( "http://www.chw.com" );
    urls.push_back( "http://www.chilecomparte.cl" );
    urls.push_back( "http://www.busuu.com" );
*/
    unique_ptr<WebCrawler> crawler(new WebCrawler());
    crawler.get()->Init(urls);
    //shared_ptr<Http> http2(Singleton<Http>::getInstance());
	//unique_ptr<Parsing> parsing( new Parsing() );
	//parsing->getUrls(page);


}
