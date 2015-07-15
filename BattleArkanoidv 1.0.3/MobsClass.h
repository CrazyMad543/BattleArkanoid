class MobsClass {
public:
	char MobsIcon = 'M';
	int DirectionMove;
	int MobsX, MobsY;
	int Direction();
	void MoveMobs(char Map[20][30]);
	void InitLocationMobs();
	int ReturnMobsX();
	int ReturnMobsY();
	MobsClass();
	~MobsClass();
};