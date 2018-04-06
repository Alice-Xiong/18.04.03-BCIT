
void MGOut()
{
	mobogo(127);
	wait1Msec(1500); // retime
	mobogo(0);
}

void MGIn()
{
	mobogo(-127);
	wait1Msec(1600); // retime
	mobogo(0);
}

void IntakeCone()
{
	motor[Intake] = 120;
	wait1Msec(500); // retime
	cone(CONE_HOLD);
}

void DropCone()
{
	motor[Intake] = -127;
	wait1Msec(500); // retime
	cone(CONE_HOLD);

}

void CBDown()
{
	CBPower(-100);
	wait1Msec(500);
	cone(CONE_HOLD);
}


void CBUp(int time)
{
	CBPower(120);
	wait1Msec(time);
	cone(CONE_HOLD);
}



float CBkp = 0.7;
float CBki = 0;

void CBPotControl(int targetValue)
{
	int totalError = 0;
	int lastError = 0;

	while (SensorValue[potCB] > targetValue)
	{
		int curError = targetValue - SensorValue[potCB];
		if (abs(curError) < 80)
			totalError += curError;
		int diffError = curError - lastError;

		float motorPower = - curError * CBkp - totalError * CBki;
		CBPower(motorPower);

		lastError = curError;
		delay(20);

		if (abs(motorPower) < 20)
			break;
	}
}
