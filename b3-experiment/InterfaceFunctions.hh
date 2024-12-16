// ARCS6 WebVR インターフェースクラス
#ifndef INTERFACEFUNCTIONS
#define INTERFACEFUNCTIONS

#include <array>
#include "ConstParams.hh"
#include "WebVR.hh"

namespace ARCS{
class InterfaceFunctions{
	public:
		void ServoON() {}
		void ServoOFF() {}
		void SetZeroCurrent() {}
		
		// 電流指令を設定する関数
		void SetCurrent(const std::array<double, ConstParams::ACTUATOR_NUM> &Current){
			for (int i = 0; i < ConstParams::ACTUATOR_NUM; ++i){
				int axisNumber = i + 1;
				double position = MotorModels[i].calculatePosition(currentTime, Current[i]);
				setAxisRadian(axisNumber, position);
			}
		}
		
		// 位置応答を取得する関数
		void GetPosition(std::array<double, ConstParams::ACTUATOR_NUM> &Position){
			for (int i = 0; i < ConstParams::ACTUATOR_NUM; ++i){
				int axisNumber = i + 1;
				Position[i] = MotorModels[i].getLastPosition();
			}
		}
		
		// 位置応答と速度応答を取得する関数
		void GetPositionAndSpeed(std::array<double, ConstParams::ACTUATOR_NUM> &Position, std::array<double, ConstParams::ACTUATOR_NUM> &Speed){
			for (size_t i = 0; i < ConstParams::ACTUATOR_NUM; ++i){
				Position[i] = MotorModels[i].getLastPosition();
				Speed[i]    = MotorModels[i].getLastAngularVelocity();
			}
		}
	};
}

#endif
