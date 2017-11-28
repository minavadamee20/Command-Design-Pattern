//
//  remoteControl.h
//  command_pattern
//
//

#ifndef remoteControl_h
#define remoteControl_h

#include <vector>
#include <stack>
#include "noCommand.h"


#define MAX_COMMANDS  7

class remoteControl {
public:
    remoteControl(size_t size=MAX_COMMANDS) : size_(size) {
        for (size_t i = 0; i < size_; ++i) {  commands_.push_back(new noCommand());  }
    }
	
    void setCommand(size_t index, command* cmd) {  checkValidIndex(index);   commands_[index] = cmd;  }
	void buttonPressed(size_t index) { checkValidIndex(index); command* c = commands_[index]; undoStack_.push(c);   c->execute(); }
	void undoButtonPressed(size_t index) {
		checkValidIndex(index);  command* c = commands_[index]; redoStack_.push(c);   c->undo();
	}
    
	void offButtonPressed(size_t index)
	{
		checkValidIndex(index);
		command*c = commands_[index]; undoStack_.pop();
		redoStack_.push(c); c->undo();
	}

	void undoLastCommand() {

		std::cout << std::endl << "undoing last command" << std::endl;
		command* c = undoStack_.top();	undoStack_.pop();
		redoStack_.push(c);
		c->undo();
	}

	void redoLastCommand() {
		std::cout << std::endl << "redoing last command" << std::endl;
		command* c = redoStack_.top();	redoStack_.pop();
		undoStack_.push(c); c->execute();
	}

    void executeCommands(const std::vector<int> indices) {
        std::cout << "\nexecuting commands.............\n";
        for (auto idx : indices) { buttonPressed(idx); }
    }
    void undoCommands(const std::vector<int> indices) {
        std::cout << "\nundoing commands.............\n";
        for (auto idx : indices) { undoButtonPressed(idx); }
    }
    friend std::ostream& operator<<(std::ostream& os, const remoteControl& rc) {
        os << "remoteControl[\n";
        for (size_t i = 0; i < rc.size_; ++i) {  os << "\tslot[" << i << "] = " << *(rc.commands_[i]) << "\n"; }
        return os << "]";
    }
private:
    void checkValidIndex(size_t index) const {
        if (index >= size_) { throw new std::invalid_argument("index out of range"); }
    }
    std::vector<command*> commands_;
    size_t size_;
	std::stack<command*> undoStack_;
	std::stack<command*> redoStack_;
};

#endif /* remoteControl_h */



//cerr: will not go to the file, 
