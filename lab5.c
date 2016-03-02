// Created on Fri Feb 26 2016
void loop();
void moveFarLeft();
void moveLeft();
void moveStraight();
void moveRight();
void moveFarRight();

const int sensor_positions[5] = {2047, 1745, 1448, 1174, 900};

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
	int direction; //comparator variable

	while (1) 
	{	
		int longest_distance = 0;
		int cur_distance;
		int direction;
		int pos;
		set_servo_position(3,2047); //preset port 0 to 150
		
		for ( pos = 0; pos < 5; pos++) 
		{
			set_servo_position(3,sensor_positions[pos]); //move sensor to position
			sleep(1);
			cur_distance = analog(1);
			if (cur_distance > longest_distance) 
			{
				longest_distance = cur_distance; //longest distance we have seen
				direction = pos; //direction we will go
			}	
			printf("Distance %d: %d\n", pos, cur_distance);
		}
		
		printf("Longest distance = %d at position %d\n", longest_distance, direction);

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

void moveFarLeft() {
	move_at_velocity(0, 500); // Right wheel
	move_at_velocity(3, -500); // Left wheel
	sleep(1);
	moveStraight();
	return;
}

void moveLeft() {
	move_at_velocity(0, 500); // Right wheel
	move_at_velocity(3, -500); // Left wheel
	sleep(.5);
	moveStraight();
	return;
}

void moveFarRight() {
	move_at_velocity(0, -500); // Right wheel
	move_at_velocity(3, 500); // Left wheel
	sleep(1);
	moveStraight();
	return;
}

void moveRight() {
	move_at_velocity(0, -500); // Right wheel
	move_at_velocity(3, 500); // Left wheel
	sleep(.5);
	moveStraight();
	return;
}

void moveStraight() {
	move_at_velocity(0, 800); // Right wheel
	move_at_velocity(3, 800); // Left wheel
	sleep(2);
	move_at_velocity(0, 0); // Right wheel
	move_at_velocity(3, 0); // Left wheel
	return;
}
