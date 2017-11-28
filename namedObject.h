//
//  namedObject.h
//  command_pattern
//
//  Created by William McCarthy on 11/12/17.
//  Copyright © 2017 William McCarthy. All rights reserved.
//

#ifndef namedObject_h
#define namedObject_h

class namedObject {
public:
    namedObject(const std::string& name="") : name_(name) {}

    std::string name() const { return name_; }
    
    friend std::ostream& operator<<(std::ostream& os, const namedObject& no) {
        return os << "[" << no.name() << "]";
    }
    
private:
    const std::string& name_;
};

#endif /* namedObject_h */
