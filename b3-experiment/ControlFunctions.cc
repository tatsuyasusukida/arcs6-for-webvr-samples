// ARCS6 WebVR 基本コード
#include <cmath>
#include "ControlFunctions.hh"
#include "ArcsMatrix.hh"
using namespace ARCS;
using namespace ArcsMatrix;

namespace{
	std::array<double, ConstParams::ACTUATOR_NUM> theta = {0, 0, 0, 0, 0};	// [rad]   ロボット関節位置
	std::array<double, ConstParams::ACTUATOR_NUM> omega = {0, 0, 0, 0, 0};	// [rad/s] ロボット関節速度
	std::array<double, ConstParams::ACTUATOR_NUM> iref = {0, 0, 0, 0, 0};	// [A]    ロボット関節電流指令
}

// 制御周期関数1
bool ControlFunctions::ControlFunction1(double t, double Tact, double Tcmp){
	const double Ts = ConstParams::SAMPLING_TIME[0]*1e-9;	// [s] 制御周期
	const double pi = M_PI;			// 円周率π
	static double omega_ref1 = 0;	// ←変数定義の例
	
	if (CmdFlag == CTRL_INIT){
		// 初期化モード
		Interface.ServoON();
	}
	if (CmdFlag == CTRL_LOOP){
		// リアルタイム周期モード
		Interface.GetPositionAndSpeed(theta, omega); // [rad] 位置の取得
		
		// グラフと表示器の描画
		Graph.SetTime(Tact, t);
		Graph.SetVars(0, theta[0], theta[1], theta[2], theta[3], theta[4]);	// 位置波形の描画
		Graph.SetVars(1, omega[0], omega[1], omega[2], omega[3], omega[4]);	// 速度波形の描画
		Graph.SetVars(2, iref[0], iref[1], iref[2], iref[3], iref[4]);		// 電流波形の描画
		Screen.SetVarIndicator(omega[0], omega[1], omega[2], omega[3], omega[4]);	// 速度応答値の表示
		
		iref[0] = 0.5;	//[A] 1軸目電流指令（例）
		iref[1] = 1.5*sin(2.0*pi*0.25*t);	//[A] 2軸目電流指令（例）
		iref[2] = 2.5*sin(2.0*pi*0.5*t);;	//[A] 3軸目電流指令（例）
		iref[3] = 3.0*cos(2.0*pi*1.0*t);;	//[A] 4軸目電流指令（例）
		iref[4] = 3.5*cos(2.0*pi*1.5*t);;	//[A] 5軸目電流指令（例）
		Interface.SetCurrent(iref);  // [A] 電流指令の設定
	}
	if (CmdFlag == CTRL_EXIT){
		// 終了処理モード
		Interface.SetZeroCurrent();
		Interface.ServoOFF();
	}
	return true;
}

// 以下はARCS6システム側で必要な関数
void ControlFunctions::UpdateControlValue(){
	Screen.SetCurrentAndPosition(iref, theta);
}
