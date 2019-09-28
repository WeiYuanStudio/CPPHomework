//
// Created by Adam on 2019/9/28.
//
#include <exception>

using namespace std;

class outOfRange : public exception {
public:
    const char *what() const throw() {
        return "ERROR! Out of Range.\n";
    }
};

class badSize : public exception {
public:
    const char *what() const throw() {
        return "ERROR! Bad type.\n";
    };
};
