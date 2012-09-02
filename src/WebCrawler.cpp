#include "WebCrawler.h"

WebCrawler::WebCrawler():
    _parser(nullptr), _documentsHTML(0)
{

}

void WebCrawler::Init(const std::vector<std::string>& docLinks)
{

    size_t size = docLinks.size();
    std::vector<std::string> tdocumentsHTML(0);

    std::unique_ptr<Http> http( Singleton<Http>::getInstance() );
    size_t i = 0;

    //Parallel
#pragma omp parallel for default(none) private(i) shared(docLinks, http, size, tdocumentsHTML)
    for(i = 0; i < size; ++i)
    {
#pragma omp critical
        {
            if( http.get()->getContent( docLinks[i] )  )
                tdocumentsHTML.push_back(http.get()->getBuffer());
        }
    }
    _documentsHTML = tdocumentsHTML;
    tdocumentsHTML.clear();

    //Parsing
    std::unique_ptr<Parsing> parsing ( new Parsing());
    std::vector<std::string> urls = parsing.get()->getUrls(_documentsHTML[0], HTML::URL); //_documentsHTML[0], only first page.

    //Input File
    std::unique_ptr<FileInput> fileInput ( new FileInput());
    fileInput.get()->writeFile(urls);

    /*
       for_each(begin(results), end(results),  [](const std::string& content){
                std::cout << content.size() << std::endl;
                });
    */
}




