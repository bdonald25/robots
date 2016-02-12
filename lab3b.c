
const int scale = 5;

int main() 
{
	
	while(1)
	{
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
	return;
	
}

