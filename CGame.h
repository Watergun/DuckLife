class CGame
{
//ATTRIBUTES
public:
	//The map class
	static CMap m_Map;

	//The player class
	static CUPC m_Player;

	//All npcs in the game
	static CNPC*	m_Npcs;

//METHODS
public:
	//Con- & Destructor
	CGame();
	~CGame();

	//The move method
	bool Move(float fTime);

	//The render method
	bool Render(float fTime);
};
