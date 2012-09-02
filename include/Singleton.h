
#include "Http.h"

template<class T>
class Singleton
{

    public:
        Singleton();
        ~Singleton();
        static T* getInstance();
    private:
        static T* _instance;
};

