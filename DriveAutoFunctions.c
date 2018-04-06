
float kp = 0.25;
float ki = 0;
float kd = 0;

int curValue = 0;
int curDif = 0;
int totalDif = 0;
int diffDif = 0;
int lastDif = 0;
int leftCurValue = 0;
int rightCurValue = 0;


void drivePID(int targetDistance)
{
	while (curValue < targetDistance)
	{
		leftCurValue = SensorValue[DL];
		rightCurValue = -SensorValue[DR];
		curValue = (leftCurValue + rightCurValue)/2;  // Fetch current sensor readings

		curDif = targetDistance - curValue;
		if (curDif < 100)
			totalDif += curDif;
		if (totalDif > 300)
			diffDif = curDif - lastDif; // Calculates pid values based on circumstances

		float motorPower = curDif*kp + totalDif *ki + diffDif*kd;
		drive(motorPower, motorPower);

		lastDif = curDif;
		delay(20);
	}

}


//float turnPConstant = 1;
//float turnIConstant = 0;
//float turnDConstant = 0;

//void gyroTurn(int target)
//{
//	int totalError = 0;
//	int lastError = 0;

//	while (SensorValue[gyro] != target )
//	{
//		int curValue = SensorValue[gyro];
//		int curError = target - curValue;
//		totalError += curError;
//		int diffError = curError - lastError;

//		float motorPower = curError * turnPConstant + totalError * turnIConstant + diffError * turnDConstant;
//		drive(motorPower, -motorPower);

//		lastError = curError;

//		if (abs(motorPower) < 7)
//			break;

//		delay(20);
//	}

//}
