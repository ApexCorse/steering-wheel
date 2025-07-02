#ifndef DRIVESCREENVIEW_HPP
#define DRIVESCREENVIEW_HPP

#include <gui_generated/drivescreen_screen/DriveScreenViewBase.hpp>
#include <gui/drivescreen_screen/DriveScreenPresenter.hpp>

class DriveScreenView : public DriveScreenViewBase
{
public:
    DriveScreenView();
    virtual ~DriveScreenView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // DRIVESCREENVIEW_HPP
