//
//  onOffDevice.h
//  command_pattern
//
//  Created by William McCarthy on 11/14/17.
//  Copyright © 2017 William McCarthy. All rights reserved.
//

#ifndef onOffDevice_h
#define onOffDevice_h

#include <iostream>
#include <sstream>
#include "namedObject.h"


class onOffDevice : public namedObject {
public:
    onOffDevice(const std::string& name="", const std::string deviceName="device",
                const std::string& onMeans="on", const std::string& offMeans="off",
                bool isOn=false)
    : namedObject(name), deviceName_(deviceName), onMeans_(onMeans), offMeans_(offMeans), isOn_(isOn) {}
    
    virtual void on()  { isOn_ = true; }
    virtual void off() { isOn_ = false; }
    
    bool isOn() const  { return isOn_; }
    bool isOff() const { return !isOn_; }
    
    const std::string& deviceName() const { return deviceName_; }
    virtual std::string modeToString() const {
        std::stringstream ss;
        ss << "(" << (isOn_ ? onMeans_ : offMeans_) << ")";
        return ss.str();
    }
    const std::string& onMeans()  const { return onMeans_;  }
    const std::string& offMeans() const { return offMeans_; }
    
    friend std::ostream& operator<<(std::ostream& os, const onOffDevice& ood) {
        return os << ood.name() << " " << ood.deviceName() << ood.modeToString();
    }
private:
    bool isOn_;
    std::string deviceName_;
    std::string onMeans_;
    std::string offMeans_;
};

#endif /* onOffDevice_h */
