// Created on Fri Jan 29 2016

int main() 
{
	printf("Hello, World!\n");
	while(1)
	{
		int isPressed = digital(15);
		int colorSeen = analog10(0);
		
		printf("%d\n",colorSeen);
		motor(0,50);
	}
	
	return 0;
}
