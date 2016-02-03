// Created on Fri Jan 29 2016

int main() 
{
	printf("Hello, World!\n");
	while(1)
	{
		int isPressed = digital(15);
		int colorSeen = analog10(0);
		
		if(isPressed == 1)
		{
			move_at_velocity(0,-200);
			move_at_velocity(3,-400);
			msleep(2000);
		}
		else
		{
			move_at_velocity(0,200);
			move_at_velocity(3,200);
		}

	}
	
	return 0;
}
