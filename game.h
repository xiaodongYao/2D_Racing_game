#pragma once

enum GameState {
	Init,
	Start,
	End
};



class Game
{
public:
	GameState  State;  //��Ϸ״̬
	unsigned int Width, Height; //��Ϸ��С
	unsigned int level; //��Ϸ�ȼ�
	unsigned int score; //��Ϸ����
	
	unsigned int FPS;

	Game(unsigned int width, unsigned int height);
	~Game();

	void init();
	void ProcessInput(unsigned char key);
    void ProcessInputSpec(unsigned int key);
	void update();
	void Render();
	void reset();
    void resetEnemyCars(); // ��ʼ�������� enemyCar
    void drawCar();

	void DoCollisions();
};