#pragma once

enum GameState {
	Init,
	Start,
	End
};



class Game
{
public:
	GameState  State;  //游戏状态
	unsigned int Width, Height; //游戏大小
	unsigned int level; //游戏等级
	unsigned int score; //游戏分数
	
	unsigned int FPS;

	Game(unsigned int width, unsigned int height);
	~Game();

	void init();
	void ProcessInput(unsigned char key);
    void ProcessInputSpec(unsigned int key);
	void update();
	void Render();
	void reset();
    void resetEnemyCars(); // 初始化或重置 enemyCar
    void drawCar();

	void DoCollisions();
};