#ifndef CONTROLLER_H
#define CONTROLLER_H

class Controller
{
public:
	Controller() :speed(300){}
	void Game();
	void Start();
	void DrawGame();
	int PlayGame();
	int GameOver();
private:
	int speed;
};

#endif //CONTROLLER_H