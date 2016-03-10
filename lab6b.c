// Created on Fri Feb 26 2016
void loop();
void moveFarLeft();
void moveLeft();
void moveStraight();
void moveRight();
void moveFarRight();

const int sensor_positions[5] = {2047, 1745, 1448, 1174, 900};

int xRed=75, yRed, xBlue=75, yBlue, red=0, blue=3, seesRed=0, seesBlue=0;// set up for color channel 0 (red)

int main() 
{
	set_each_analog_state(0,1,0,0,0,0,0,0);
	printf("Red Right, Blue Left\n");

	enable_servos(); //enable the servos
	loop();
	disable_servos(); //power down servos

	return 0;
}

void loop() 
{	
	int direction;

	while (black_button() == 0) //run till button is pressed
	 {
		track_update(); // process the most recent image
		if (track_count(red) > 0)
		{ // get x, y for the biggest blob the channel sees
			xRed = track_x(red,0); yRed = track_y(red,0);
			printf("Biggest red blob at (%d,%d)\n",xRed,yRed);
			seesRed = 1;
		} else {
			seesRed = 0;
		}
		
		if (track_count(blue) > 0)
		{ 
			xBlue = track_x(blue,0); yBlue = track_y(blue,0);
			printf("Biggest blue blob at (%d,%d)\n", xBlue, yBlue);
			seesBlue = 1;
		}
		else
		{
			seesBlue = 0;
		}
		
		sleep(0.2); // give print time to register

		if ((seesRed && seesBlue) || (!seesRed && !seesBlue)) //sees both or neither go straight
		{
			direction = 2;
		}
		else if (xRed > 40) //far left
		{
			direction = 4;
		}
		else if ( xBlue < 100) //far right
		{
			direction = 0;
		}
		else 
		{
			direction = 2;
		}
		
		printf("Sees Red:%d\n", seesRed);
		printf("Sees Blue:%d\n", seesBlue);

		
		switch (direction) {
			case 0:
				printf("Go Far Right\n");
				moveFarRight();
				break;
			case 1:
				printf("Go Right\n");
				moveRight();
				break;
			case 2:
				printf("Go Straight\n");
				moveStraight();
				break;
			case 3:
				printf("Go Left\n");
				moveLeft();
				break;
			case 4:
				printf("Go Far Left\n");
				moveFarLeft();
				break;
		}
	}
	return;
}

void moveFarRight() {
	move_at_velocity(0, 500); // Left wheel
	move_at_velocity(3, 100); // Right wheel
	return;
}

void moveRight() {
	move_at_velocity(0, 500); // Left wheel
	move_at_velocity(3, 300); // Right wheel
	return;
}

void moveFarLeft() {
	move_at_velocity(0, 100); // Left wheel
	move_at_velocity(3, 500); // Right wheel
	return;
}

void moveLeft() {
	move_at_velocity(0, 300); // Left wheel
	move_at_velocity(3, 500); // Right wheel
	return;
}

void moveStraight() {
	move_at_velocity(0, 500); // Right wheel
	move_at_velocity(3, 500); // Left wheel
	return;
}
