#ifndef SCREEN_PARAMS
#define SCREEN_PARAMS

#include <array>
#include "ConstParams.hh"

namespace ARCS
{
  class ScreenParams
  {
  public:
    void SetNetworkLink(const bool LinkFlag);
    void SetInitializing(const bool InitFlag);
    void SetCurrentAndPosition(
        const std::array<double, ConstParams::ACTUATOR_NUM> &Current,
        const std::array<double, ConstParams::ACTUATOR_NUM> &Position);
    void SetVarIndicator(const std::array<double, ConstParams::INDICVARS_MAX> &Vars);

    template <typename T1, typename... T2>
    void SetVarIndicator(const T1 &u1, const T2 &...u2)
    {
      if (VarIndicCount < ConstParams::INDICVARS_MAX)
      {
        VarIndicatorBuf.at(VarIndicCount) = (double)u1;
      }
      ++VarIndicCount;
      SetVarIndicator(u2...);
    }

    void SetVarIndicator()
    {
      VarIndicCount = 0;
      SetVarIndicator(VarIndicatorBuf);
    }

    void GetOnlineSetVars(std::array<double, ConstParams::ONLINEVARS_MAX> &Vars);
    void SetOnlineSetVar(const unsigned int VarNum, const double VarVal);
    void SetOnlineSetVars(const std::array<double, ConstParams::ONLINEVARS_MAX> &Vars);

    template <typename T1, typename... T2>
    void GetOnlineSetVar(T1 &u1, T2 &...u2)
    {
      if (SetVarCount < ConstParams::ONLINEVARS_MAX)
      {
        u1 = OnlineSetVar.at(SetVarCount);
      }
      ++SetVarCount;
      GetOnlineSetVar(u2...);
    }

    void GetOnlineSetVar()
    {
      SetVarCount = 0;
    }

    template <typename T1, typename... T2>
    void InitOnlineSetVar(const T1 &u1, const T2 &...u2)
    {
      if (InitSetVarCount < ConstParams::ONLINEVARS_MAX)
      {
        OnlineSetVarIni.at(InitSetVarCount) = (double)u1;
      }

      ++InitSetVarCount;
      InitOnlineSetVar(u2...);
    }

    void InitOnlineSetVar()
    {
      InitSetVarCount = 0;
      SetOnlineSetVars(OnlineSetVarIni);
    }

    void UpdateOnlineSetVar();

  private:
    std::array<double, ConstParams::INDICVARS_MAX> VarIndicatorBuf;
    size_t VarIndicCount;

    std::array<double, ConstParams::ONLINEVARS_MAX> OnlineSetVar;
    std::array<double, ConstParams::ONLINEVARS_MAX> OnlineSetVarIni;
    size_t SetVarCount;
    size_t InitSetVarCount;
  };
}

#endif
