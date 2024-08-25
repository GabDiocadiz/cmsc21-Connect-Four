#include <SFML/Audio.hpp>

class SoundEffect {
    private:
        sf::SoundBuffer buffer;
        sf::Sound sound;
    public:
        void setSound(const char*, float volume);
        void play();
};