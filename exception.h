#ifndef H_EXC
#define H_EXC

#include <stdexcept>

class inputExc : public std::runtime_error {

    public:
    
    inputExc(std::string text) : runtime_error(text) {}
};

#endif