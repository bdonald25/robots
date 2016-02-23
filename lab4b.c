
char direction;
void turnLeft();
void turnRight(); 
void goStraight();

void loop() 
{
	
	while(1)
	{
		int distance = analog(1);
					
		if ( distance < 13  && distance > 9) 
		{
			goStraight();
		} 
		else if ( distance > 13) 
		{
			turnLeft();
		} 
		else if ( distance < 9 )
		{
			turnRight();
		}
		printf("Distance: %d, Direction: %c\n",distance, direction);
	}
	
	return;
	
}

void goStraight() 
{	
	if (direction != 's') 
	{
		direction = 's';
		move_at_velocity(0, 800); // Right wheel
		move_at_velocity(3, 800); // Left wheel
	}
	return;
}
	

void turnLeft() 
{	
	if (direction != 'l') 
	{
		direction = 'l';
		move_at_velocity(0, 800); // Right wheel
		move_at_velocity(3, 200); // Left wheel
	}
	return;
}
	
void turnRight()
{	
	if (direction != 'r') 
	{
		direction = 'r';
		move_at_velocity(0, 200); // Right wheel
		move_at_velocity(3, 800); // Left wheel
	}
	return;
}

int main() 
{
	turnRight();
	set_each_analog_state(0, 1, 0, 0, 0, 0, 0, 0);
	loop();
	
	return 0;
}
