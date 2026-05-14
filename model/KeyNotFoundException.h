//
// Created by qt55eq on 2026. 04. 18..
//

#ifndef CPPHAZIK_KEYNOTFOUNDEXCEPTION_H
#define CPPHAZIK_KEYNOTFOUNDEXCEPTION_H

#include <exception>

class KeyNotFoundException : public std::exception {
public:
    [[nodiscard]] const char* what() const noexcept override {
        return "Key not found in BinarySearchTree";
    }
};

#endif //CPPHAZIK_KEYNOTFOUNDEXCEPTION_H