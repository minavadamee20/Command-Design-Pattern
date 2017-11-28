//
//  simpleRemoteControl.h
//  command_pattern
//
//

#ifndef simpleRemoteControl_h
#define simpleRemoteControl_h

#include "command.h"


class simpleRemoteControl {
public:
    simpleRemoteControl(command* slot=nullptr) : slot_(slot) {}
    
    void setCommand(command* command) { slot_ = command; }
    void buttonPressed() { slot_->execute(); }

    friend std::ostream& operator<<(std::ostream& os, const simpleRemoteControl& src) {
        os << "src[";
        if (src.slot_ != nullptr) { os << "SLOTS:   " << *(src.slot_); }
        else { os << "no command"; }
        return os << "]";
    }
    

//private:
protected:      // accessible to children only
    command* slot_;};

#endif /* simpleRemoteControl_h */






					//QUICK NOTES ABOUT PROCTECTED MEMBER VARIABLES
/*=======================================================================================================*/
/*proctected member variables are avaliable for the children classes that later inherit from the class   |
	simpleRemoteControl. It's different from a private member variable function because private member   |
	variable functions only allow that variable to be used within the class itself and not be allowed    | 
	to be used outside the function even if it is inherited     										 |
  =======================================================================================================*/