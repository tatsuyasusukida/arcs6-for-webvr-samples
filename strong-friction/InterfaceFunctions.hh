#ifndef INTERFACEFUNCTIONS
#define INTERFACEFUNCTIONS

#include <array>
#include "ConstParams.hh"
#include "WebVR.hh"

namespace ARCS
{
  class InterfaceFunctions
  {
  public:
    void ServoON() {}
    void ServoOFF() {}
    void SetZeroCurrent() {}

    void SetCurrent(const std::array<double, ConstParams::ACTUATOR_NUM> &Current)
    {
      for (int i = 0; i < ConstParams::ACTUATOR_NUM; ++i)
      {
        int axisNumber = i + 1;
        double position = MotorModels[i].calculatePosition(currentTime, Current[i]);
        setAxisRadian(axisNumber, position);
      }
    }

    void GetPosition(std::array<double, ConstParams::ACTUATOR_NUM> &Position)
    {
      for (int i = 0; i < ConstParams::ACTUATOR_NUM; ++i)
      {
        int axisNumber = i + 1;
        Position[i] = MotorModels[i].getLastPosition();
      }
    }
  };
}

#endif
