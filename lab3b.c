
const int dark = 900;		
const int light = 600;
	
void left() 
{			
	move_at_velocity(0, 500); // Right wheel
	move_at_velocity(3, 0); // Left wheel
	return;
}
	
void right()
{	
	move_at_velocity(0, 0); // Right wheel
	move_at_velocity(3, 500); // Left wheel
	return;
}

void stop()
{	
	move_at_velocity(0, 0); // Right wheel
	move_at_velocity(3, 0); // Left wheel
	return;
}

void loop() 
{
	
	while(1)
	{
		int isPressed = digital(15);
		int lightValueRight = analog10(6);
		int lightValueLeft = analog10(7);
		
		if(isPressed == 1)
		{
			move_at_velocity(0,0);
			move_at_velocity(3,0);
			msleep(2000);
			left();
		}
		
		if(lightValueRight < light)
		{
			right();
		}
		else if(lightValueLeft < light)
		{
			left();
		}
		else
		{
			stop();
		}
		
		printf("%d",isPressed);
		

		printf("Right Sensor: %d Left Sensor: %d\n",lightValueRight,lightValueLeft);

		

	}
	return;
	
}

int main() 
{

	loop();
	
	return 0;
}
