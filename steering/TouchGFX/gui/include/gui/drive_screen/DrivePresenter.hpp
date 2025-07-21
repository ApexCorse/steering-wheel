#ifndef DRIVEPRESENTER_HPP
#define DRIVEPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class DriveView;

class DrivePresenter : public touchgfx::Presenter, public ModelListener
{
public:
    DrivePresenter(DriveView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~DrivePresenter() {}
    
    void setSpeed(int speed) override;
    void setMaxTemp(int maxTemp) override;
    void setAvgTemp(int avgTemp) override;
    void setBatteryLevel(int batteryLevel, int minBatteryLevel, int maxBatteryLevel) override;
    void setBatteryPower(int batteryPower, int minBatteryPower, int maxBatteryPower) override;

private:
    DrivePresenter();

    DriveView& view;
};

#endif // DRIVEPRESENTER_HPP
