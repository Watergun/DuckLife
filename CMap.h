class CMap
{
//ATTRIBUTES
private:
	//All Sourroundings
	CSurroundings* m_Surroundings;

//METHODS
public:
	//Con- & Destructor
	CMap();
	~CMap();

	//Method to load a map from a file
	bool LoadMap(const char* m_cstrFilename);

	//Get all surroundings
	CSurrounding* getSurroundings();

	//Get a specific Surrounding object
	CSurroundig* getSurroundingObject(int n_x, int n_y);
};
