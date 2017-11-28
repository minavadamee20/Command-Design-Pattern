

#ifndef deviceCommands_h
#define deviceCommands_h

typedef enum DEVICETYPE { DEVICEON, DEVICEOFF } DEVICETYPE;


template <typename device>
class deviceCommand : public command {
public:
    deviceCommand(device* dev, DEVICETYPE devicetype) : dev_(dev), devicetype_(devicetype) {}
    
    void execute() { (devicetype_ == DEVICEON ? dev_->on()  : dev_->off());    std::cout << *dev_ << "\n";  }
    void undo()    { (devicetype_ == DEVICEON ? dev_->off() : dev_->on());     std::cout << *dev_ << "\n";  }
    std::ostream& name(std::ostream& os) const { return os << *this; }
    
    friend std::ostream& operator<<(std::ostream& os, const deviceCommand& c) {
        return os << "device" << (c.devicetype_ == DEVICEON ? "On" : "Off") << "Command[" << *(c.dev_) << "]";
    }
private:
    device* dev_;
    DEVICETYPE devicetype_;
};

//	:( help
#endif /* deviceCommands_h */
