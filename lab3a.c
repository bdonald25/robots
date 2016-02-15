int movingLeft = 1;
int crossedLine = 0;
const int black = 800;		
const int white = 400;
	
void left() 
{			
	movingLeft = 1;
	crossedLine = 0;
	move_at_velocity(0, 500); // Right wheel
	move_at_velocity(3, -50); // Left wheel
	return;
}
	
void right()
{	
	movingLeft = 0;
	crossedLine = 0;
	move_at_velocity(0, -50); // Right wheel
	move_at_velocity(3, 500); // Left wheel
	return;
}

void loop() 
{
	
	while(1)
	{
		int isPressed = digital(15);
		
		if(isPressed == 1)
		{
			move_at_velocity(0,0);
			move_at_velocity(3,0);
			msleep(2000);
			left();
		}
		
		printf("%d",isPressed);
		
		int lightValueRight = analog10(6);
		int lightValueLeft = analog10(7);
		printf("Right Sensor: %d Left Sensor: %d\n",lightValueRight,lightValueLeft);

		

	}
	return;
	
}

int main() 
{

	loop();
	
	return 0;
}
