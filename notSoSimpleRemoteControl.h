//
//  notSoSimpleRemoteControl.h
//  command_pattern
//
//

#ifndef notSoSimpleRemoteControl_h
#define notSoSimpleRemoteControl_h

class notSoSimpleRemoteControl : public simpleRemoteControl {
public:
    notSoSimpleRemoteControl(command* slot=nullptr) : simpleRemoteControl(slot) {}
    
//    void setCommand(command* command) { slot_ = command; }    // inherited
//    void onButtonPressed() { slot_->execute(); }           // inherited
    void undoButtonPressed() { slot_->undo(); }

    friend std::ostream& operator<<(std::ostream& os, const notSoSimpleRemoteControl& nssrc) {
        return os << "nssrc[" << *dynamic_cast<const simpleRemoteControl*>(&nssrc) << "]";
    }

private:
//    command* slot_;       // inherited, but inaccessible
};


#endif /* notSoSimpleRemoteControl_h */
