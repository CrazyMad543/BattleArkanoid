class MobsClass {
public:
	char MobsIcon = 'M';
	int DirectionMove;
	int MobsX, MobsY;
	void Direction(int MoveKeyCharacter);
	void MoveMobs(char Map[20][30]);
	void InitLocationMobs();
	int ReturnMobsX();
	int ReturnMobsY();
	MobsClass();
	~MobsClass();
};