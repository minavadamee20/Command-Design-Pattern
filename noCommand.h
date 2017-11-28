//
//  noCommand.h
//  command_pattern
//
//

#ifndef noCommand_h
#define noCommand_h

#include <iostream>


class noCommand : public command {
public:
    void execute() { std::cout << *this << " cannot execute"; }
    void undo()    { std::cout << *this << " cannot undo"; }
    std::ostream& name(std::ostream& os) const { return os << *this; }
    
    friend std::ostream& operator<<(std::ostream& os, const noCommand& nc) {
        return os << "noCommand[]";
    }
};

#endif /* noCommand_h */
