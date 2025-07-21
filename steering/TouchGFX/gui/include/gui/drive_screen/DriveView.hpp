#ifndef DRIVEVIEW_HPP
#define DRIVEVIEW_HPP

#include <gui_generated/drive_screen/DriveViewBase.hpp>
#include <gui/drive_screen/DrivePresenter.hpp>

class DriveView : public DriveViewBase
{
public:
    DriveView();
    virtual ~DriveView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    void setSpeed(int speed);
    void setMaxTemp(int maxTemp);
    void setAvgTemp(int avgTemp);
    void setBatteryLevel(int batteryLevel);
    void setBatteryPower(int batteryPower);
    void setClock(const char* clock);
    void setDriveMode(bool driveMode);
protected:
};

#endif // DRIVEVIEW_HPP
