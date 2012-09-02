// ---------------------------------------------------------------------------
// Webcrawler 0.0.1
//
//
//
// Http.h
// Manage of library curl.
//
// Author: Camilo Chacon Sartori
// ---------------------------------------------------------------------------

#ifndef HTTP_
#define HTTP_

#include <iostream>
#include <string>
#include <memory>
#include <curl\curl.h>
#include <assert.h>
class Http{



	public:
        Http();

        ///Extract contents of webpage. (HTML)
		bool getContent(const std::string& url);

        ///return size _buffer;
		int getSizeBuffer() const;

        ///return _buffer.
        std::string getBuffer() const;


    private:

        ///Function is used with curl for write data into _buffer(string).
		///Call handle_impl member function for implementation.
		static void writer(void *ptr, size_t size, size_t nmemb, void* userdata);

		///Append data to _buffer(string).
		size_t handle_impl(char* data, size_t size, size_t nmemb);

        ///Set configuration curl.
		bool setupCurl(const std::string& url);


		CURL* _curl;
        std::string _buffer;
        Http(const Http&);
        Http operator=(const Http&);

};

#endif

