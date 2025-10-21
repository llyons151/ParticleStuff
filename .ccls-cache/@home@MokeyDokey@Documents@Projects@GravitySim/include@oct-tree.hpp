#include <vector>

struct Particle {
    float pos[4];   
    float vel[4];  
    float col[4]; 
};

class OctTree{
    private:
        int bodiesPerNode = 4;
        int depth; 
        std::vector<Particle> particles;
};
