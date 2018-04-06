void secondCone()
{
	drive(0,0);
	CBPower(-127);
	motor[Intake] = 80;
	ArmPower(-127);
	wait1Msec(800); // Arm down // Picks up next cone

	ArmPotControl(850);
	drive(40,40);
	CBUp(560);
	drive(0,0);
	DropCone();// Stacks second cone
	CBPower(0);

}



void thirdCone()
{
	CBPower(-127);
	motor[Intake] = 127;
	ArmPower(-127);
	wait1Msec(970); // Picks up next cone

	ArmPotControl(800);
	drive(-100,-100);
	CBUp(500);
	DropCone(); // Stacks third cone
	ArmPower(10);
}



void leftINI()
{
	motor[Intake] = 20;
	ArmPotControl(750); // Arm up
	ArmPower(10);
	mobogo(127);
	drive(127,127);
	wait1Msec(1600);// Drive forward with mobogo out and arm up

	drive(0,0);
	MGIn();
	DropCone(); // Picks up mobile goal and scores preload

	ArmPotControl(850); // Arm up for drive
	drive(127,127);
	wait1Msec(150);// Drive forward // Get in position for next cone
}



void leftFIN()
{
	mobogo(-127);
	drive(-127,127);
	wait1Msec(800);
	drive(127,127);
	wait1Msec(500);
}



//-----------------------------------------------------------//
//                                                           //
//    LEFT SIDE THREE CONES WITH MOBILE GOAL IN 5PT ZONE.    //
//                                                           //
//-----------------------------------------------------------//


void LeftTri5() // Needs testing
{
	leftINI();
	secondCone();
	thirdCone();

	drive(-127,-127);
	wait1Msec(500); // Drives back // take off 900
	drive(-127,127);
	wait1Msec(980); // Turn left a lot
	drive(0,0);

	MGOut(); // Scores mobile goal
	wait1Msec(50);
	drive(-127,-127);
	wait1Msec(500); // Back out of zones

	leftFIN();
	drive(0,0);
}



//-----------------------------------------------------------//
//                                                           //
//    LEFT SIDE THREE CONES WITH MOBILE GOAL IN 10PT ZONE.   //
//                                                           //
//-----------------------------------------------------------//


void LeftTri10()
{
	leftINI();
	secondCone();
	thirdCone();

	ArmPotControl(1000);
	drive(-127,-127);
	wait1Msec(720);
	drive(-127,127);
	wait1Msec(1030); // Turn left a lot
	drive(50,50); // Goes up to 10pt zone
	mobogo(127); // Scores mobile goal
	wait1Msec(1200);

	drive(-127,-127);
	wait1Msec(500); // Back out of zones
	mobogo(-127);
	drive(-127,-127);
	wait1Msec(500);

	drive(0,0);
}



//-----------------------------------------------------------//
//                                                           //
//    LEFT SIDE THREE CONES WITH MOBILE GOAL IN 20PT ZONE.   //
//                                                           //
//-----------------------------------------------------------//


void LeftTri20()
{
	leftINI();
	secondCone();
	thirdCone();

	drive(127,127);
	wait1Msec(750); // Fixed
	drive(127,-127);
	wait1Msec(300); // Turn left
	drive(127,127);
	wait1Msec(350); // Back up
	drive(127,-127);
	wait1Msec(650); // Turn left; line up with 20pt

	drive(127,127);
	mobogo(127);
	wait1Msec(2000); // Goes into 20pt and scores mobogo
	drive(0,0);

	drive(-127,-127);  // Back out of 20pt
	MGIn();  // Collapses mobogo intake`
	drive(0,0);
	wait1Msec(1500); // Wait till the end
}


void defence()
{
  drive(-127,-127);
  wait1Msec(7000);
  drive(0,0);
  wait1Msec(8000);
}
