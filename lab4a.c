
char direction;
void turnLeft();
void turnRight(); 

void loop() 
{
	
	while(1)
	{
		int distance = analog(1);
			
		printf("Distance: %d, Direction: %c\n",distance, direction);
		
		if ( direction == 'r' && distance > 10 ) {
			turnLeft();
		} else if (direction == 'l' && distance < 12 ) {
			turnRight();
		}
			

	}
	return;
	
}

void turnLeft() 
{	
	direction = 'l';
	move_at_velocity(0, 800); // Right wheel
	move_at_velocity(3, 200); // Left wheel
	return;
}
	
void turnRight()
{	
	direction = 'r';
	move_at_velocity(0, 200); // Right wheel
	move_at_velocity(3, 800); // Left wheel
	return;
}

int main() 
{
	turnRight();
	set_each_analog_state(0, 1, 0, 0, 0, 0, 0, 0);
	loop();
	
	return 0;
}
