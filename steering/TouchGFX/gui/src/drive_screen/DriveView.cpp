#include <gui/drive_screen/DriveView.hpp>
#include <texts/TextKeysAndLanguages.hpp>

DriveView::DriveView()
{
    setSpeed(0);
    setMaxTemp(0);
    setAvgTemp(0);
    setBatteryLevel(0);
    setBatteryPower(0);
    setClock("000 : 00 : 000");
    setDriveMode(false);
}

void DriveView::setupScreen()
{
    DriveViewBase::setupScreen();
}

void DriveView::tearDownScreen()
{
    DriveViewBase::tearDownScreen();
}

void DriveView::setSpeed(int speed)
{
   Unicode::snprintf(speedBuffer, SPEED_SIZE, "%d", speed);
   (this->speed).invalidate();
}

void DriveView::setMaxTemp(int maxTemp)
{
   Unicode::snprintf(maxTempBuffer, MAXTEMP_SIZE, "%d", maxTemp); 
   (this->maxTemp).invalidate();
}

void DriveView::setAvgTemp(int avgTemp)
{
   Unicode::snprintf(avgTempBuffer, AVGTEMP_SIZE, "%d", avgTemp); 
   (this->avgTemp).invalidate();
}

void DriveView::setBatteryLevel(int batteryLevel)
{
    (this->batteryLevel).setValue(100 - batteryLevel);
}

void DriveView::setBatteryPower(int batteryPower)
{
    (this->batteryPower).setValue(100 - batteryPower);
}

void DriveView::setClock(const char* clock) 
{
    Unicode::strncpy(clockBuffer, clock, CLOCK_SIZE);
    (this->clock).invalidate();
}

void DriveView::setDriveMode(bool driveMode) 
{
    (this->driveMode).setVisible(driveMode);
    driveModeBox.setVisible(driveMode);
}
