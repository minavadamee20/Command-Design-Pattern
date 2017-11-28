

#ifndef command_h
#define command_h

class command {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
    virtual std::ostream& name(std::ostream& os) const = 0;
    
    friend std::ostream& operator<<(std::ostream& os, const command& c) {
        os << "command[";
        c.name(os);
        return os << "]";
    }
};

#endif /* command_h */
