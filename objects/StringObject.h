#pragma once

#include <string>
#include "BaseObject.h"

class StringObject : virtual public BaseObject {
public:
    StringObject();
    explicit StringObject(std::string);
    const std::string& GetValue() const;

private:
    std::string value{};
};

