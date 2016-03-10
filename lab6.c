// Created on Fri Feb 26 2016
void loop();
void moveFarLeft();
void moveLeft();
void moveStraight();
void moveRight();
void moveFarRight();

const int sensor_positions[5] = {2047, 1745, 1448, 1174, 900};

int x=75, y, color=0; // set up for color channel 0 (red)

int main() 
{
	set_each_analog_state(0,1,0,0,0,0,0,0);
	
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
		if (track_count(color) > 0)
		{ // get x, y for the biggest blob the channel sees
			x = track_x(color,0); y = track_y(color,0);
			printf("Biggest blob at (%d,%d)\n",x,y);
		}
		else
		{ 
			printf("No color match in Frame\n"); 
		}
		
		sleep(0.2); // give print time to register
	 
		printf("x: %d\n", x); 
		if (x > 130) //far left
		{
			direction = 4;
		} 
		else if (x > 90 )  //left
		{
			direction = 3;
		
		} 
		else if ( x < 20) //right
		{
			direction = 1;
		}
		else if ( x < 60) //far right
		{
			direction = 0;
		}
		else //straight
		{
			direction = 2;
		}
		
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
