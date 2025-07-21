#include <gui/drive_screen/DriveView.hpp>
#include <gui/drive_screen/DrivePresenter.hpp>

DrivePresenter::DrivePresenter(DriveView& v)
    : view(v)
{

}

void DrivePresenter::activate()
{

}

void DrivePresenter::deactivate()
{

}

void DrivePresenter::setSpeed(int speed)
{
    view.setSpeed(speed);
}

void DrivePresenter::setMaxTemp(int maxTemp)
{
    view.setMaxTemp(maxTemp);
}

void DrivePresenter::setAvgTemp(int avgTemp)
{
    view.setAvgTemp(avgTemp);
}

void DrivePresenter::setBatteryLevel(int batteryLevel, int minBatteryLevel, int maxBatteryLevel)
{
    const int normalizedBatteryLevel = (int) (((double)(batteryLevel - minBatteryLevel) / (maxBatteryLevel - minBatteryLevel)) * 100);
    view.setBatteryLevel(normalizedBatteryLevel);
}

void DrivePresenter::setBatteryPower(int batteryPower, int minBatteryPower, int maxBatteryPower)
{
    const int normalizedBatteryPower = (int) (((double)(batteryPower - minBatteryPower) / (maxBatteryPower - minBatteryPower)) * 100);
    view.setBatteryPower(normalizedBatteryPower);
}
