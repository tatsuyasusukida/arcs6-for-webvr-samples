#include "ScreenParams.hh"
#include "WebVR.hh"

using namespace ARCS;

void ScreenParams::SetNetworkLink(const bool LinkFlag) {}

void ScreenParams::SetInitializing(const bool InitFlag) {}

void ScreenParams::SetCurrentAndPosition(
    const std::array<double, ConstParams::ACTUATOR_NUM> &Current,
    const std::array<double, ConstParams::ACTUATOR_NUM> &Position)
{
    for (int i = 0; i < ConstParams::ACTUATOR_NUM; ++i)
    {
        int axis = i + 1;
        int status = ACTUATOR_STATUS_NORMAL;

        setActuatorStatus(axis, status, Current[i], Position[i]);
    }
}

void ScreenParams::SetVarIndicator(const std::array<double, ConstParams::INDICVARS_MAX> &Vars)
{
    for (int i = 0; i < ConstParams::INDICVARS_NUM; ++i)
    {
        setReadVariable(i, Vars[i]);
    }
}

void ScreenParams::GetOnlineSetVars(std::array<double, ConstParams::ONLINEVARS_MAX> &Vars)
{
    for (int i = 0; i < ConstParams::INDICVARS_NUM; ++i)
    {
        if (canGetWriteVariable(i))
        {
            Vars[i] = getWriteVariable(i);
        }
    }
}

void ScreenParams::SetOnlineSetVars(const std::array<double, ConstParams::ONLINEVARS_MAX> &Vars)
{
    for (int i = 0; i < ConstParams::ONLINEVARS_NUM; ++i)
    {
        setWriteVariable(i, Vars[i]);
    }
}

void ScreenParams::SetOnlineSetVar(const unsigned int VarNum, const double VarVal)
{
    setWriteVariable(VarNum, VarVal);
}

void ScreenParams::UpdateOnlineSetVar()
{
    GetOnlineSetVars(OnlineSetVar);
}
