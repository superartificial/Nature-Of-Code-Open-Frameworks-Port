#include "ParticleSystem.h"

ParticleSystem::ParticleSystem(ofVec2f location)
{
    origin = location;
}

ParticleSystem::ParticleSystem() { }

void ParticleSystem::addParticle()
{
    /*
    Particle p = Particle(origin);
    particles.push_back(p);
    */
    /*
    Confetti c = Confetti(origin);
    c.test();
    Particle * p = &c;
    */
    try
    {
        float chance = ofRandom(0, 100);

        if(chance<33)
        {
            particles.push_back(new Confetti(origin));
        }
        else if(chance<66)
        {
            particles.push_back(new Spifetti(origin));
        }
        else
        {
            particles.push_back(new Bonfetti(origin));
        }
    }
    catch (int e)
    {
        cout << "An exception occurred. Exception Nr. " << e << '\n';
    }

}

bool ParticleSystem::isDead()
{
    return !alive;
}

void ParticleSystem::run()
{

    if(particleRate>0)
    {
        if(getChance(particleRate,500))
        {
            addParticle();
        }
        particleRate--;
    }
    if(particles.size() > 0)
    {
        // ofLog(OF_LOG_NOTICE, "Particles : " + ofToString(particles.size()) );
        particles.front()->display();

        for (std::vector<Particle*>::iterator it = particles.begin() ; !particles.empty() && it != particles.end(); it++)
        {
            (*it)->update();
            (*it)->display();
            // (*it)->test();

            if ((*it)->isDead())
            {
                particles.erase(it);
                // Particle p = (Particle)(*it);
            }

        }


    }
    else
    {
        alive = false;
    }

}

void ParticleSystem::setOrigin(int x, int y)
{
    origin = ofVec2f(x,y);
}

bool ParticleSystem::getChance(int chance,int outOf)
{
    double percentDouble = ((double)chance)/((double)outOf);
    // ofLog(OF_LOG_NOTICE, "percentDouble: " + ofToString(percentDouble) );
    double number = std::rand() / (double)RAND_MAX; /* value from [0,1] */
    return number < percentDouble;
}

void ParticleSystem::clearParticles() {
    particles.clear();
}
