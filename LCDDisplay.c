
task driverLCD()
{
	clearLCDLine(0);
	clearLCDLine(1);
	while(1)
	{
		displayLCDPos(0,0);
		displayNextLCDString("Main:");
		displayLCDPos(0,9);
		displayNextLCDNumber(nImmediateBatteryLevel);

		displayLCDPos(1,0);
		displayNextLCDString("BackUp:");
		displayLCDPos(1,9);
		displayNextLCDNumber(SensorValue[Battery]/ 0.284);

		delay(30);
	}
}



task AutoSelectionTask()
{
	int last_nLCDButtons = 0;
	int btnPressed;
	while(true)
	{
		btnPressed = nLCDButtons;
		clearLCDLine(0);
		clearLCDLine(1);

		displayLCDPos(0, 0);
		displayNextLCDString("Select an Auto: ");
		displayLCDPos(1, 0);
		displayNextLCDString(autoNames[autoMode]);

		switch(btnPressed)
		{
		case 1: // Left
			if(autoMode > 0 && last_nLCDButtons != btnPressed)
			{
				autoMode--;
			}
			break;
		case 2: // Center
			break;
		case 4: // Right
			if(autoMode < 6 && last_nLCDButtons != btnPressed)
			{
				autoMode++;
			}
			break;
		default: // Everything else
			break;
		}

		last_nLCDButtons = btnPressed;
		wait1Msec(20);
	}
}
