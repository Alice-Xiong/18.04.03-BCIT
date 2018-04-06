
float ArmPConstant = 0.98;
float ArmIConstant = 0.01;
float ArmDConstant = 0;

void ArmPotControl (int targetValue)
{
	int totalError = 0;
	int lastError = 0;

	while (SensorValue[potArm] != targetValue)
	{
		int curError = targetValue - SensorValue[potArm];
		  totalError += curError;
		int diffError = curError - lastError;

		float motorPower = curError * ArmPConstant + totalError * ArmIConstant + diffError * ArmDConstant;
		ArmPower(motorPower);

		lastError = curError;
		delay(20);

		if (abs(motorPower) < 20)
			break;

	}
}
