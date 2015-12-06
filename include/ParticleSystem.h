#include <vector>
#include "../ext/glm/glm.hpp"

class ParticleSystem
{
public:
	ParticleSystem(std::vector<glm::vec3> positions);
	~ParticleSystem();

	void stepPhysics(float dt);
	void matchShape(float dt);
	glm::vec3 getPosition(int i);
private:
	void updateForces(float dt);
	void updateVelocities(float dt);
	void updatePositions(float dt);

	std::vector<glm::vec3> p0; // Initial positions
	std::vector<glm::vec3> p;
	std::vector<glm::vec3> v;
	std::vector<glm::vec3> F;
};