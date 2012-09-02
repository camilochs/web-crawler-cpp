#ifndef WEBCRAWLER_H
#define WEBCRAWLER_H

#include "Parsing.h"
#include "Http.h"
#include "Singleton.h"
#include "FileInput.h"
#include <memory>
class WebCrawler
{

    public:
        WebCrawler();
         /// Extract documents(HTML) from URLs.
         void Init(const std::vector<std::string>& docLinks);

     private:
        std::unique_ptr<Parsing> _parser;
        std::vector<std::string> _documentsHTML;
};

#endif // WEBCRAWLER_H
