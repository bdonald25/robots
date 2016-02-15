void loop() 
{
	
	while(1)
	{
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
