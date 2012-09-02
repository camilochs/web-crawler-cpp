#ifndef HTTP_
#include "Http.h"
#endif

Http::Http()
    :_curl(nullptr),  _buffer(""){

}

std::string Http::getBuffer() const{
    return _buffer;
}
int Http::getSizeBuffer() const{
	return _buffer.size();
}

bool Http::getContent(const std::string& url){
	return setupCurl(url);
}


//Configuration cURL.
bool Http::setupCurl(const std::string& url){

	_curl = curl_easy_init();
	CURLcode result;

	if(_curl){
		curl_easy_setopt(_curl, CURLOPT_URL,  url.c_str());
		curl_easy_setopt(_curl, CURLOPT_HEADER, 1);
		curl_easy_setopt(_curl, CURLOPT_WRITEFUNCTION, Http::writer);
		curl_easy_setopt(_curl, CURLOPT_WRITEDATA, this);
		result = curl_easy_perform(_curl);
		curl_easy_cleanup(_curl);
	}
	if( result != CURLE_OK) return false;

	return true;

}
//Write buffer into a string.
void Http::writer(void *ptr, size_t size, size_t nmemb, void* userdata){

	 static_cast<Http*>(userdata)->handle_impl(static_cast<char*>(ptr), size, nmemb);
}

size_t Http::handle_impl(char* data, size_t size, size_t nmemb)
{
    int result = 0;
	if(data != nullptr){
		 _buffer.append(data, size * nmemb);
		 result =  size * nmemb;
	}
   data = nullptr;
   return result;
}
