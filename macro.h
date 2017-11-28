#pragma once
#ifndef macro_h
#define macro_h
#include "command.h"
#include <initializer_list>
#include <vector>
#include <iostream>

class macroCommand :public command {
public:
	macroCommand(const std::initializer_list<command*>& li) {
		for (auto c : li) {
			commands_.push_back(c);
		}
	}
	void execute() {
		for (auto c : commands_) { c->execute(); }
	}
	
	void undo() {
		for (auto c : commands_) { c->undo(); }

	}
	std::ostream& name(std::ostream& os) const {
		return os << "macroCommand";
}
private:
	std::vector<command*> commands_;


};
#endif // macro_h


