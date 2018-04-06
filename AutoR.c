
void rightINI()
{
	motor[Intake] = 20;
	ArmPotControl(750); // Arm up
  ArmPower(10);
  drive(0,0);
  wait1Msec(20);

	mobogo(127);
	drive(127,127);
	wait1Msec(1600);// Drive forward
	drive(30,30);

	MGIn(); // Picks up mobile goal
	drive(0,0);
	DropCone(); // Scores preload
}


void rightFIN()
{
	drive(127,-127);
	wait1Msec(600);
	drive(127,127);
	wait1Msec(500);
	drive(0,0); // Get ready for picking up next mobogo
}

//--------------------------------------------------------//
//                                                        //
//  RIGHT SIDE THREE CONES WITH MOBILE GOAL IN 5PT ZONE   //
//                                                        //
//--------------------------------------------------------//

void RightTri5()
{
  rightINI();
	secondCone();
	thirdCone();

	drive(-127,-95);
	wait1Msec(500); // Drives back
	drive(127,-127);
	wait1Msec(980); // Turn left a lot
	drive(0,0);

	MGOut(); // Scores mobile goal
	wait1Msec(50);
	drive(-127,-127);
	wait1Msec(500); // Back out of zones

	rightFIN();
	drive(0,0);

}



//--------------------------------------------------------//
//                                                        //
//  RIGHT SIDE THREE CONES WITH MOBILE GOAL IN 10PT ZONE  //
//                                                        //
//--------------------------------------------------------//

void RightTri10()
{
  rightINI();
  secondCone();
  thirdCone();

  ArmPotControl(1000);
	drive(-127,-127);
	wait1Msec(750);
	drive(127,-127);
	wait1Msec(1050); // Turn right a lot
	drive(-127,-127);
	wait1Msec(180);

	drive(80,70); // Goes up to 10pt zone
	mobogo(127); // Scores mobile goal
  wait1Msec(1200);
	drive(-127,-127);
	wait1Msec(1000); // Back up

	rightFIN();
	drive(0,0); // Get ready for picking up next mobogo
}



//--------------------------------------------------------//
//                                                        //
//  RIGHT SIDE THREE CONES WITH MOBILE GOAL IN 20PT ZONE  //
//                                                        //
//--------------------------------------------------------//
void RightOne20()
{
  rightINI();

	drive(-127,-127);
	wait1Msec(700); // Back up
	drive(127,-127);
	wait1Msec(300); // Turn right
	drive(-127,-127);
	wait1Msec(780); // Back up
	drive(127,-127);
	wait1Msec(680); // Turn right; line up with 20pt

	drive(127,127);
	mobogo(127);
	wait1Msec(1900); // Goes into 20pt
 	drive(0,0);

	drive(-127,-127);  // Back out of 20pt
	MGIn();  // Collapses mobogo intake`
	drive(0,0);
	wait1Msec(1500); // Wait till the end
}



void RightTri20()
{
  rightINI();
	secondCone();
	thirdCone();

	drive(-127,-127);
	wait1Msec(750); // Back up
	drive(127,-127);
	wait1Msec(300); // Turn right
	drive(-127,-127);
	wait1Msec(450); // Back up
	drive(127,-127);
	wait1Msec(680); // Turn right; line up with 20pt

	drive(127,127);
	mobogo(127);
	wait1Msec(1900); // Goes into 20pt
 	drive(0,0);

	drive(-127,-127);  // Back out of 20pt
	MGIn();  // Collapses mobogo intake`
	drive(0,0);
	wait1Msec(1500); // Wait till the end
}
