#include "FileInput.h"

FileInput::FileInput()
{
}

FileInput::~FileInput()
{
}


void FileInput:: writeFile(const std::vector<std::string>& urls){

    std::ofstream writeFile;
    writeFile.open("URL-Collection.txt", std::ios::app);
    std::string buffer = "";
    for_each(begin(urls), end(urls),
             [&](const std::string& url){
                    buffer.append(url + " \n");
             });

    writeFile << buffer << std::endl;
    writeFile.close();
    std::cout << "Done";



}
