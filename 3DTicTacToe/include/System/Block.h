#ifndef BLOCK_H
#define BLOCK_H


class Block
{
    public:
        /*
	 * Coordinates are going to work as: x positive is going right y positive is
	 * going down z positive is going away from us
	 */
	int corners[8] = { 0, 3, 12, 15, 48, 51, 60, 63 };
	int edge[24] = { 1, 2, 4, 7, 8, 11, 13, 14, 16, 19, 28, 31, 32,
			35, 44, 47, 49, 50, 52, 55, 56, 59, 61, 62 };
	int outerCenter[24] = { 5, 6, 9, 10, 17, 18, 20, 23, 24, 27,
			29, 30, 33, 34, 36, 39, 40, 43, 45, 46, 53, 54, 57, 58 };
	int innerCenter[8] = { 21, 22, 25, 26, 37, 38, 41, 42 };

	int x, y, z; // Coordinates of the space
	bool selected; // Whether this has been selected yet
	int priority; // How we decide which block to choose
	int team; // Which team is in control.
						// 1 for us, 2 for them, 3 for unoccupied
	int additionalPriority; // Based on "must-do" moves

	int eX = 0, eY = 0, eZ = 0, edX = 0, edY = 0, edZ = 0, eD = 0;
	int fX = 0, fY = 0, fZ = 0, fdX = 0, fdY = 0, fdZ = 0, fD = 0;

	Block(int x, int y, int z) {
		this->x = x;
		this->y = y;
		this->z = z;
		selected = false;
		team = 3;
	}

	bool isSelected() {
		return selected;
	}

	void setSelected(bool selected) {
		this->selected = selected;
	}

    int getTeam() {
		return team;
	}

	void setTeam(int team) {
		this->team = team;
	}

	int getX() {
		return x;
	}

	int getY() {
		return y;
	}

    int getZ() {
		return z;
	}

	int getPriority() {
		return priority;
	}

	void setPriority(int priority) {
		this->priority = priority;
	}

	void addPriority(int increase) {
		this->priority += increase;
	}

	int getAdditionalPriority() {
		return additionalPriority;
	}

	void setAdditionalPriority(int additionalPriority) {
		this->additionalPriority = additionalPriority;
	}
    protected:
    private:
};

#endif // BLOCK_H
