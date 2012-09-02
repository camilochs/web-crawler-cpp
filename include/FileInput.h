#ifndef FILEINPUT_H
#define FILEINPUT_H
#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
//#include <sstream>




class FileInput
{
    public:
        FileInput();
        virtual ~FileInput();

        ///Export the url to a file(txt).
        void writeFile(const std::vector<std::string>& urls);
    //private:

};

#endif // FILEINPUT_H
