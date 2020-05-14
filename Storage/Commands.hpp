class Commands 
{
	char command [20] = "Unknown";

public:
	Commands(const char* command);
	Commands();
	char* getcommand();
	void setallcommands(const char* command);


};