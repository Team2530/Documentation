/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <iostream>
#include <string>

#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <LiveWindow/LiveWindow.h>
#include "WPILib.h"
#include <Joystick.h>
#include <ctre/Phoenix.h>
#include "HAL/HAL.h"
#include <Encoder.h>
#include <Spark.h>
#include <networktables/NetworkTableInstance.h>

class Robot : public frc::IterativeRobot {
public:
	void RobotInit() {
		m_chooser.AddDefault(kAutoNameDefault, kAutoNameDefault);
		m_chooser.AddObject(kAutoNameCustom, kAutoNameCustom);
		frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
		LeftController = new WPI_TalonSRX(1);
		RightController = new WPI_TalonSRX(2);
		leftEncoder = new frc::Encoder(0,1, false,Encoder::CounterBase::k2X);//what k2X mean? also, 0,1 gonna change: encoder channel
		rightEncoder = new frc::Encoder(2,3, false, Encoder::CounterBase::k2X);//^^
	}

	/*
	 * This autonomous (along with the chooser code above) shows how to
	 * select
	 * between different autonomous modes using the dashboard. The sendable
	 * chooser code works with the Java SmartDashboard. If you prefer the
	 * LabVIEW Dashboard, remove all of the chooser code and uncomment the
	 * GetString line to get the auto name from the text box below the Gyro.
	 *
	 * You can add additional auto modes by adding additional comparisons to
	 * the
	 * if-else structure below with additional strings. If using the
	 * SendableChooser make sure to add them to the chooser code above as
	 * well.
	 */
	void AutonomousInit() override {
	}

	void AutonomousPeriodic() {

	}

	void TeleopInit() {
		leftEncoder->Reset();
		rightEncoder->Reset();
		leftEncoder->SetDistancePerPulse(ticksPerRevolution*diameter*pi);
		rightEncoder->SetDistancePerPulse(ticksPerRevolution*diameter*pi);
	}

	void TeleopPeriodic() {
		Joystick* stick = new frc::Joystick(0);
		double stickY = stick->GetY();
		double stickZ = stick->GetZ();
		LeftController->Set(stickY);
		RightController->Set(stickZ);
		nt::NetworkTableInstance nti;
		table = nti.GetTable("robotPosition");
		table->PutNumber("x", leftEncoder->GetDistance());
		table->PutNumber("y", rightEncoder->GetDistance());
	}

	void TestPeriodic() {}

private:
	frc::LiveWindow& m_lw = *LiveWindow::GetInstance();
	frc::SendableChooser<std::string> m_chooser;
	const std::string kAutoNameDefault = "Default";
	const std::string kAutoNameCustom = "My Auto";
	std::string m_autoSelected;
	WPI_TalonSRX* LeftController;
	WPI_TalonSRX* RightController;
	frc::Encoder* leftEncoder;
	frc::Encoder* rightEncoder;
	Joystick* GetJoystick();
	std::shared_ptr<NetworkTable> table;
	static constexpr double ticksPerRevolution = 1/1000;
	static constexpr double diameter = 6; //inches
	static constexpr double pi = 2*acos(0.0);

};

START_ROBOT_CLASS(Robot)
