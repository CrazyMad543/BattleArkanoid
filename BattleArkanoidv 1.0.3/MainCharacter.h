class MainCharacter {
public:
	char MainCharacterIcon = 'Y';
	int CharacterX, CharacterY;
	int MoveCharacter(char Map[20][30]);
	void InitLocationCharacter();
	int ReturnCharacterX();
	int ReturnCharacterY();
	MainCharacter();
	~MainCharacter();
};