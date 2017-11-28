//
//  ceilingFan.h
//  command_pattern
//
//  Created by William McCarthy on 11/12/17.
//  Copyright © 2017 William McCarthy. All rights reserved.
//

#ifndef ceilingFan_h
#define ceilingFan_h


enum FANMODE { LOW, MEDIUM, HIGH };

class ceilingFan : public onOffDevice {
public:
    ceilingFan(const std::string& name ="", bool isOn=false, FANMODE mode=HIGH)
    : onOffDevice(name, "ceilingFan", "on", "off", isOn), mode_(mode) {}
    
    void setLow()    { mode_ = LOW;    on(); }
    void setMedium() { mode_ = MEDIUM; on(); }
    void setHigh()   { mode_ = HIGH;   on(); }
    
    FANMODE mode() const { return mode_; }
    std::string modeToString() const {      // overrides superclass modeToString
        std::stringstream ss;
        ss << "(";
        if (!isOn()) { ss << offMeans(); }
        else {
            switch(mode_) {
            case LOW:    ss << "LOW";           break;
            case MEDIUM: ss << "MEDIUM";        break;
            case HIGH:   ss << "HIGH";          break;
            default:     ss << "unknown mode";  break;
            }
        }
        ss << ")";
        return ss.str();
    }
    friend std::ostream& operator<<(std::ostream& os, const ceilingFan& cf) {
        return os << dynamic_cast<const onOffDevice&>(cf);
    }

private:
    FANMODE mode_;
};


#endif /* ceilingFan_h */
