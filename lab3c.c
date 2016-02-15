
const int scale = 5;

int main() 
{	
	while(1)
	{
		int isPressed = digital(15);
		
		if(isPressed == 1)
		{
			move_at_velocity(0,-600);
			move_at_velocity(3,0);
			msleep(3000);
			move_at_velocity(0,-400);
			move_at_velocity(3,-400);
			msleep(3000);
			move_at_velocity(0,0);
			move_at_velocity(3,-500);
			msleep(3000);

			
		} else {
			moveTowardsLight();
		}	

	}
	return;
	
}

void moveTowardsLight() {
	int lightValueRight = analog10(6);
	int lightValueLeft = analog10(7);

	int rightVelocity = scale * (0 - lightValueLeft + 1000);
	int leftVelocity = scale * (0 - lightValueRight + 1000);

	rightVelocity = (rightVelocity < 0) ? 0 : rightVelocity; //Min of 0 velocity
	leftVelocity = (leftVelocity < 0) ? 0 : leftVelocity; //Min of 0 velocity

	rightVelocity = (rightVelocity > 1000) ? 1000 : rightVelocity; //max of 1000 velocity
	leftVelocity = (leftVelocity > 1000) ? 1000 : leftVelocity; //max of 1000 velocity

	move_at_velocity(0, rightVelocity); // Right wheel
	move_at_velocity(3, leftVelocity); // Left wheel

	printf("Right vel: %d Left vel: %d\n",rightVelocity,leftVelocity);
}

