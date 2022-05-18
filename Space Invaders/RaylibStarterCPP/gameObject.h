#pragma once
/// <summary>
///			^ ~ y
///			|
///		<-	+	-> ~ x
///			|
///			v
/// the game object is the parent class to all objects required in the game
/// </summary>
class GameObject {
public:
	GameObject();
	~GameObject();


private:
	int health;
	int posY;
	int posX;

public:
	void translateObj(int xMov, int yMov);
};