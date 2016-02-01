// Created on Fri Jan 29 2016

int main() 
{
	printf("Hello, World!\n");
	while(1)
	{
		int colorSeen = analog10(0);
		
		if(colorSeen < 500)
		{
			move_at_velocity(0,200);
			move_at_velocity(3,400);
			//msleep();
		}
		else
		{
			move_at_velocity(0,400);
			move_at_velocity(3,200);
		}

	}
	
	return 0;
}
