#ifndef CONTROL_FUNCTIONS
#define CONTROL_FUNCTIONS

#include "ScreenParams.hh"
#include "GraphPlot.hh"
#include "InterfaceFunctions.hh"

namespace ARCS
{
  class ControlFunctions
  {
  public:
    enum CtrlFuncMode
    {
      CTRL_INIT,
      CTRL_LOOP,
      CTRL_EXIT,
    };

    ControlFunctions() : Screen(),
                         Graph(),
                         Interface(),
                         CmdFlag(CTRL_INIT),
                         NetworkLink(false),
                         Initializing(false) {}

    bool ControlFunction1(double t, double Tact, double Tcmp);
    //bool ControlFunction2(double t, double Tact, double Tcmp);
    //bool ControlFunction3(double t, double Tact, double Tcmp);
    void UpdateControlValue();
	void UpdateScreen(){
		Screen.UpdateOnlineSetVar();
	}
	void UpdateMode(CtrlFuncMode NewCmdFlag){
		CmdFlag = NewCmdFlag;
	}

  private:
    ScreenParams Screen;
    GraphPlot Graph;
    InterfaceFunctions Interface;
    CtrlFuncMode CmdFlag;
    bool NetworkLink;
    bool Initializing;
  };
}

#endif
